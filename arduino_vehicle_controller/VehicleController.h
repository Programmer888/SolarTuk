#include "Arduino.h"
#include "CANCOM.h"
#include "VariableResistor.h"
#include "MotorTemperatureSensor.h"
#include "ThrottlePositionSensor.h"
#include "SteeringPositionSensor.h"

#define SENSOR_COUNT 4

class VehicleController {

  
  
public:
  VehicleController(int id);
  void loop();

private:
  int CAN_ID;
  
  VariableResistor *sensors[SENSOR_COUNT];
};
