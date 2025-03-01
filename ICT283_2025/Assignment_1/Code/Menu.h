#ifndef MENU_H
#define MENU_H
#include "Calculator.h"
#include "FileHandler.h"
#include "SensorRecType.h"
#include <iostream>
using namespace std;

const int MAX_MONTHS = 13;

class Menu {
public:
  void prompt(const SensorLog &sensor_data, bool &exit) const;
  void HandleMonthlySpeed(const SensorLog &sensor_data) const;
  void HandleMonthlyTemperature(const SensorLog &sensor_data) const;
  void HandleMonthlySolarRadiation(const SensorLog &sensor_data) const;
  void HandleAllData(const SensorLog &sensor_data) const;
  bool ValidateMonth(const SensorLog &sensor_data, const int month,
                     const int year) const;
  int GetValidYear() const;
};
string int_to_month(const int month);
int month_to_int(const string month);
#endif
