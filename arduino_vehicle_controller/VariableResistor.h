#pragma once

#include "Arduino.h"
#include "Sensor.h"
#include "OBD2.h"

class VariableResistor : public Sensor{

  
  
public:
  VariableResistor(int pin, int PID);
  virtual int getValue() override;
  virtual OBD2_FRAME createFrame(int CAN_ID) override;
  virtual int getHumanReadableValue() override;
private:
  int pin;
  int PID;
};
