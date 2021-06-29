#pragma once
#include "VariableResistor.h"
class ThrottlePositionSensor:
    public VariableResistor
{
  using VariableResistor::VariableResistor;
public:
    //virtual OBD2_FRAME createFrame(int CAN_ID) override;
    //MotorTemperatureSensor(int pin, int PID);
    virtual int getHumanReadableValue() override;
};
