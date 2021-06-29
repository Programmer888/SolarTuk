#pragma once

#include "Arduino.h"
#include "OBD2.h"

class Sensor {

  
  
public:
  //VariableResistor(int pin);
  virtual int getValue() = 0;
  virtual int getHumanReadableValue() = 0;
  virtual OBD2_FRAME createFrame(int CAN_ID) = 0;
private:
  
};  
