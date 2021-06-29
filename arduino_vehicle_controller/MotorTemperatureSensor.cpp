#include "MotorTemperatureSensor.h"


int MotorTemperatureSensor::getHumanReadableValue()
{
  return this->getValue() - 40;
}
