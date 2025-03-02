#ifndef RESULTS_H
#define RESULTS_H

#include "Calculator.h"
#include "FileHandler.h"
#include "SensorRecType.h"
#include <iostream>
using namespace std;

const int MAX_MONTHS = 13;

class Results {

public:
  void DisplayAverageStdevSpeed(const SensorLog &sensor_data, const int month,
                                const int year) const;

  void DisplayAverageStdevTemperature(const SensorLog &sensor_data,
                                      const int year) const;

  void DisplayTotalSolarRadiation(const SensorLog &sensor_data,
                                  const int year) const;

  void PrintAll(const SensorLog &sensor_data, const int year) const;

  bool ValidateMonth(const SensorLog &sensor_data, const int month,
                     const int year, const string sensor_type) const;
};

string int_to_month(const int month);

#endif
