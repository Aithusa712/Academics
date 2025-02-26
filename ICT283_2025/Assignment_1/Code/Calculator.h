#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "SensorRecType.h"
#include <iostream>
using namespace std;

class Calculator {

public:
  float AverageSpeed(SensorLog &sensor_data, int month, int year);
  float AverageTemperature(SensorLog &sensor_data, int month, int year);
  float AverageSolarRadiation(SensorLog &sensor_data, int month, int year);

  float StdDevSpeed(SensorLog &sensor_data, float mean, int month, int year);
  float StdDevTemperature(SensorLog &sensor_data, float mean, int month,
                          int year);
  float StdDevSolarRadiation(SensorLog &sensor_data, float mean, int month,
                             int year);
};
#endif
