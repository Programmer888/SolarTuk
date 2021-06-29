#include "SteeringPositionSensor.h"



int SteeringPositionSensor::getHumanReadableValue()
{
  return (this->getValue() * 100/180) - 90;
}
