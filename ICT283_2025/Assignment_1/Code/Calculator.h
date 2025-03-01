#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "SensorRecType.h"
#include <iostream>
using namespace std;

class Calculator {

public:
  float AverageSpeed(const SensorLog &sensor_data, const int month,
                     const int year) const;
  float AverageTemperature(const SensorLog &sensor_data, const int month,
                           const int year) const;
  float AverageSolarRadiation(const SensorLog &sensor_data, const int month,
                              const int year) const;

  float StdDevSpeed(const SensorLog &sensor_data, float mean, const int month,
                    const int year) const;
  float StdDevTemperature(const SensorLog &sensor_data, const float mean,
                          const int month, const int year) const;
  float TotalSolarRadiation(const SensorLog &sensor_data, const int month,
                            const int year) const;
};
#endif
