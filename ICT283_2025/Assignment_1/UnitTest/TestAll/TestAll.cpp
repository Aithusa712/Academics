#include "Calculator.h"
#include "FileHandler.h"
#include "Results.h"
#include "SensorRecType.h"
#include "Vector.h"

using namespace std;

void TestVectorInt() {
  Vector<int> test;
  test.push(5);
  test.push(9);
  test.push(3);

  int test_1 = test[0];
  int test_2 = test[1];
  int test_3 = test[2];

  if (test_1 == 5 && test_2 == 9 && test_3 == 3) {
    cout << "TestVectorInt() Test: PASS" << endl;
  } else {
    cout << "TestVectorInt() Test: FAIL" << endl;
  }
}

void TestVectorSensor() {
  Vector<SensorRecType> test;
  for (int i = 0; i < 3; i++) {
    SensorRecType temp;

    temp.speed = 5 + (i * 5);             // 5, 10, 15
    temp.temperature = 15 + (i * 15);     // 15, 30, 45
    temp.solar_radiation = 10 + (i * 10); // 10, 20, 30

    test.push(temp);
  }

  if (test[1].speed == 10 && test[2].temperature == 45 &&
      test[0].solar_radiation == 10) {
    cout << "TestVectorSensor() Test: PASS" << endl;
  } else {

    cout << "TestVectorSensor() Test: FAIL" << endl;
  }
}

void TestSetGetDay() {
  Date test;
  test.SetDay(10);

  if (test.GetDay() == 10) {
    cout << "GetDay() SetDay() Test: PASS" << endl;
  } else {
    cout << "GetDay() SetDay() Test: FAIL" << endl;
  }
}
void TestSetGetMonth() {
  Date test;
  test.SetMonth(8);

  if (test.GetMonth() == 8) {
    cout << "GetMonth() SetMonth() Test: PASS" << endl;
  } else {
    cout << "GetMonth() SetMonth() Test: FAIL" << endl;
  }
}
void TestSetGetYear() {
  Date test;
  test.SetYear(2025);
  if (test.GetYear() == 2025) {
    cout << "GetYear() SetYear() Test: PASS" << endl;
  } else {
    cout << "GetYear() SetYear() Test: FAIL" << endl;
  }
}

void TestSetGetMinutes() {
  Time test;
  test.SetMinutes(30);
  if (test.GetMinutes() == 30) {
    cout << "GetMinutes() SetMinutes() Test: PASS" << endl;
  } else {
    cout << "GetMinutes() SetMinutes() Test: FAIL" << endl;
  }
}

void TestSetGetHours() {
  Time test;
  test.SetHours(12);

  if (test.GetHours() == 12) {
    cout << "GetHours() SetHours() Test: PASS" << endl;
  } else {
    cout << "GetHours() SetHours() Test: FAIL" << endl;
  }
}

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
void TestWriteToFile() {
  FileHandler handleFile;
  handleFile.writeToFile("TestFile.txt", "hello this is the content");
  ifstream file("TestFile.txt");
  string line;
  getline(file, line);
  if (line == "hello this is the content") {
    cout << "TestWriteToFile() Test: PASS" << endl;
  } else {
    cout << "TestWriteToFile() Test: PASS" << endl;
  }
}

void TestReadCsv() {
  SensorLog testVector;
  FileHandler handleFile;
  handleFile.readCSV("UnitTestData.csv", testVector);
  if (testVector[0].speed == 22 && testVector[0].temperature &&
      testVector[0].solar_radiation == 22) {
    cout << "TestReadCsv() Test: PASS" << endl;
  } else {
    cout << "TestReadCsv() Test: FAIL" << endl;
  }
}

void TestReadSource() {
  SensorLog testVector;
  FileHandler handleFile;
  handleFile.readSource("Source.txt", testVector);
  if (testVector[0].speed == 22 && testVector[0].temperature &&
      testVector[0].solar_radiation == 22) {
    cout << "TestReadSource() Test: PASS" << endl;
  } else {
    cout << "TestReadSource() Test: FAIL" << endl;
  }
}

int main() {
  // Test Vector
  TestVectorInt();
  TestVectorSensor();

  // Test Date and Time;
  TestSetGetDay();
  TestSetGetMonth();
  TestSetGetYear();
  TestSetGetMinutes();
  TestSetGetHours();

  // Test Calculator
  TestSpeed();
  TestTemp();
  TestSolarRadiation();

  // Results
  TestValidateMonth(TestData());

  // File Handler
  TestWriteToFile();
  TestReadCsv();
  TestReadSource();

  cout << "================================\n Manually check output here and "
          "in .txt/.csv outputs in cwd of main program"
       << endl;

  TestDisplaySpeed(TestData());
  TestDisplayTemperature(TestData());
  TestDisplaySolarRadiation(TestData());
  TestPrintAll(TestData());
}
