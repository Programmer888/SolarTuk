#include "ThrottlePositionSensor.h"



int ThrottlePositionSensor::getHumanReadableValue()
{
  return this->getValue() * 100/255;
}
