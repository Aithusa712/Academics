#include "Calculator.h"
#include "SensorRecType.h"

#include <iostream>
using namespace std;

SensorLog TestData() {
  SensorLog data;
  for (int i = 0; i < 3; i++) {
    Date date;
    date.SetMonth(3);
    date.SetYear(2007);

    float speed = 4.4 + (i * 2.1);               // 4.4, 6.5, 8.6
    float temperature = 20.7 + (i * 4.4);        // 20.7, 25.1, 29.5
    float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

    SensorRecType temp;
    temp.speed = speed;
    temp.temperature = temperature;
    temp.solar_radiation = solar_radiation;
    temp.date = date;
    data.push(temp);
  }

  return data;
}

void TestSpeed(SensorLog sensor_data) {
  Calculator test;
  float mean = 0.0f;
  float standard_deviation = 0.0f;
  mean = test.AverageSpeed(sensor_data, 3, 2007);
  standard_deviation = test.StdDevSpeed(sensor_data, mean, 3, 2007);
  // 4.5 + 6.5 + 8.6 = 19.5
  // 19.5 / 3
  // mean = 6.5
  if (mean == 6.5f) {
    cout << "AverageSpeed() Test: PASS" << endl;
  } else {
    cout << "AverageSpeed() Test: FAIL" << endl;
  }
  if (standard_deviation == 2.1f) {
    cout << "StdDevSpeed() Speed TEST: PASS" << endl;
  } else {
    cout << "StdDevSpeed() Speed Test: FAIL" << endl;
  }
}

void TestTemp(SensorLog sensor_data) {
  Calculator test;
  float mean = 0.0f;
  float standard_deviation = 0.0f;
  mean = test.AverageTemperature(sensor_data, 3, 2007);
  standard_deviation = test.StdDevTemperature(sensor_data, mean, 3, 2007);
  // 20.7 + 25.1 + 29.5 = 75.3
  // 75.3 / 3
  // 25.1
  if (mean == 25.1f) {
    cout << "AverageTemperature() Test: PASS" << endl;
  } else {
    cout << "AverageTemperature() Test: FAIL" << endl;
  }
  if (standard_deviation == 4.4f) {
    cout << "StdDevTemperature() Test: PASS" << endl;
  } else {
    cout << "StdDevTemperature() Test: FAIL" << endl;
  }
}

void TestSolarRadiation(SensorLog sensor_data) {
  Calculator test;
  float total_solar_radiation = 0;
  total_solar_radiation = test.TotalSolarRadiation(sensor_data, 3, 2007);
  // 415.25 + 423.76 + 432.27
  // 1271.28 w/m^2 * (10 min / 60 min)
  // 211.88 / 10000 W/kW
  // 0.21188 or 0.2
  if (total_solar_radiation == 0.2f) {
    cout << "TotalSolarRadiation() Test: PASS" << endl;
  } else {
    cout << "TotalSolarRadiation() Test: FAIL" << endl;
  }
}

int main() {
  TestSpeed(TestData());
  TestTemp(TestData());
  TestSolarRadiation(TestData());
}
