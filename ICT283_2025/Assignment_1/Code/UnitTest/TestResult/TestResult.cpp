#include "Results.h"
#include "SensorRecType.h"
#include <iostream>

using namespace std;

SensorLog TestData() {
  SensorLog data;
  for (int month_index = 1; month_index < 13; month_index++) {
    for (int i = 0; i < 3; i++) {

      Date date;
      date.SetMonth(month_index);
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
  }
  return data;
}

void TestDisplaySpeed(SensorLog sensor_data) {
  Results test;
  test.DisplayAverageStdevSpeed(sensor_data, 1, 2007);
  cout << "\nSpeed Displayed, Expected Result: \nAverage: 6.5km/h\nSample "
          "Standard Deviation: 2.1 "
       << endl;
}

void TestDisplayTemperature(SensorLog sensor_data) {
  Results test;
  test.DisplayAverageStdevTemperature(sensor_data, 2007);
  cout << "\nTemperature Displayed, Expected Result: \nAll Months have "
          "Data\nAverage:25.1 degrees C\nSample Standard Deviation: 4.4"
       << endl;
}

void TestDisplaySolarRadiation(SensorLog sensor_data) {
  Results test;
  test.DisplayTotalSolarRadiation(sensor_data, 2007);
  cout << "\nSolar Radiation Displayed, Expected Result: \nAll Months have "
          "Data\nTotal Solar Radiation: 0.2f"
       << endl;
}

void TestPrintAll(SensorLog sensor_data) {
  Results test;
  test.PrintAll(sensor_data, 2007);
  cout << "\nWindTempSolar.csv created, Expected Result: \nAll Months have "
          "data\nEach Row:6.5(2.1),25.1(4.4),0.2"
       << endl;
}

void TestValidateMonth(SensorLog sensor_data) {
  Results test;

  if (test.ValidateMonth(sensor_data, 3, 2007, "T")) {
    cout << "ValidateMonth() Test: PASS" << endl;
  } else {
    cout << "ValidateMonth() Test: FAIL" << endl;
  }
}
int main() {
  TestValidateMonth(TestData());
  TestDisplaySpeed(TestData());
  TestDisplayTemperature(TestData());
  TestDisplaySolarRadiation(TestData());
  TestPrintAll(TestData());
}
