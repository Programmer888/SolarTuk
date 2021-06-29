#include "VehicleController.h"

VariableResistor *throttlePositionSensor;
VariableResistor *steeringwheelPositionSensor;
VariableResistor *motorTemperatureSensor1;
VariableResistor *motorSpeedSensor;

VehicleController::VehicleController(int id)
{
  this->CAN_ID = id;
  Serial.begin(115200);
  Serial.println("INIT");

  throttlePositionSensor = new ThrottlePositionSensor(A0, THROTTLE_POSITION);
  steeringwheelPositionSensor = new SteeringPositionSensor(A1, STEERING_POSITION);
  motorSpeedSensor = new VariableResistor(A2, VEHICLE_SPEED);
  motorTemperatureSensor1 = new MotorTemperatureSensor(A3, ENGINE_OIL_TEMPERATURE);
  
  this->sensors[0] = throttlePositionSensor;
  this->sensors[1] = steeringwheelPositionSensor;
  this->sensors[2] = motorSpeedSensor;
  this->sensors[3] = motorTemperatureSensor1;;
}

void VehicleController::loop()
{
  CANCOM::instance().receive();
  //CANCOM::instance().sendMessage(sensor->createFrame(this->CAN_ID));
  for(int i = 0; i < SENSOR_COUNT; i++)
  {
    Serial.print("Sensor");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(this->sensors[i]->getValue());
    Serial.print(" || ");
    Serial.print(this->sensors[i]->getHumanReadableValue());
    Serial.print("\t");
    CANCOM::instance().sendMessage(this->sensors[i]->createFrame(this->CAN_ID));  
    delay(100);
  }

  Serial.println();

  if (motorTemperatureSensor1->getHumanReadableValue() > 100) //Engine temperature is too high
  {
    Serial.println("Engine too hot!");
    OBD2_FRAME frame = { };
    frame.id = CAN_ID;
    frame.mode = 0x41;
    frame.PID = ENGINE_LIGHT;
    frame.A = 255;
    frame.B = 0xAA;
    frame.C = 0xAA;
    frame.D = 0xAA;
    CANCOM::instance().sendMessage(frame);
  }
  /*int i = 1;
  Serial.print("Sensor");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(this->sensors[i]->getValue());*/
  delay(1000);
}
