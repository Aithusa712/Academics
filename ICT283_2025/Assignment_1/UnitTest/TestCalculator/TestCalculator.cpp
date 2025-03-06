#include "Calculator.h"

#include <iostream>
using namespace std;

void TestSpeed() {

  Vector<float> data;
  for (int i = 0; i < 3; i++) {
    float speed = 4.4 + (i * 2.1); // 4.4, 6.5, 8.6
    // float temperature = 20.7 + (i * 4.4);        // 20.7, 25.1, 29.5
    // float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

    data.push(speed);
  }
  Calculator test;
  float mean = 0.0f;
  float standard_deviation = 0.0f;
  mean = test.AverageSpeed(data);
  standard_deviation = test.StdDevSpeed(data, mean);
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

void TestTemp() {
  Calculator test;
  Vector<float> data;
  for (int i = 0; i < 3; i++) {
    // float speed = 4.4 + (i * 2.1); // 4.4, 6.5, 8.6
    float temperature = 20.7 + (i * 4.4); // 20.7, 25.1, 29.5
    // float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

    data.push(temperature);
  }
  float mean = 0.0f;
  float standard_deviation = 0.0f;
  mean = test.AverageTemperature(data);
  standard_deviation = test.StdDevTemperature(data, mean);
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

void TestSolarRadiation() {

  Calculator test;
  Vector<float> data;
  for (int i = 0; i < 3; i++) {
    // float speed = 4.4 + (i * 2.1); // 4.4, 6.5, 8.6
    // float temperature = 20.7 + (i * 4.4);        // 20.7, 25.1, 29.5
    float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

    data.push(solar_radiation);
  }
  float total_solar_radiation = 0;
  total_solar_radiation = test.TotalSolarRadiation(data);
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
  TestSpeed();
  TestTemp();
  TestSolarRadiation();
}
