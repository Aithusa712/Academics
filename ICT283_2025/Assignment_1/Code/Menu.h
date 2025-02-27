#ifndef MENU_H
#define MENU_H

#include "Calculator.h"
#include "SensorRecType.h"
#include <iostream>
using namespace std;

class Menu {
public:
  void prompt(SensorLog &sensor_data, Calculator &calculate, bool &exit);
  void HandleMonthlySpeed(SensorLog &sensor_data, Calculator &calculate);
  void HandleMonthlyTemperature(SensorLog &sensor_data, Calculator &calculate);
  void HandleMonthlySolarRadiation(SensorLog &sensor_data,
                                   Calculator &calculate);
  bool Month_Found(SensorLog &sensor_data, int month, int year);
  int Prompt_Year();
  string Int_to_Month(int month);
  int Month_to_Int(string month);
};
#endif
