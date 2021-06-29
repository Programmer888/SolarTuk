#include "VariableResistor.h"

VariableResistor::VariableResistor(int pin, int PID)
{
  this->pin = pin;
  this->PID = PID;
  pinMode(pin, INPUT);
}
  
int VariableResistor::getValue()
{
  int analog = analogRead(pin);
  int value = map(analog, 0, 1023, 0, 255);
  
  return value;
}

int VariableResistor::getHumanReadableValue()
{
  return this->getValue();
}

OBD2_FRAME VariableResistor::createFrame(int CAN_ID)
{
  OBD2_FRAME frame = { };
  frame.id = CAN_ID;
  frame.mode = 0x41;
  frame.PID = this->PID;
  frame.A = this->getValue();
  frame.B = 0xAA;
  frame.C = 0xAA;
  frame.D = 0xAA;

  return frame;
}
