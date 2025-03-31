#include "Calculator.h"
#include "FileHandler.h"
#include "Results.h"
#include "SensorRecType.h"

using namespace std;

void TestBstInt() {
  Bst<int> test;
  test.Insert(5);
  test.Insert(9);
  test.Insert(3);

  int test_1 = test.Get(5);
  int test_2 = test.Get(9);
  int test_3 = test.Get(3);

  if (test_1 == 5 && test_2 == 9 && test_3 == 3) {
    cout << "TestVectorInt() Test: PASS" << endl;
  } else {
    cout << "TestVectorInt() Test: FAIL" << endl;
  }
}

void TestBstSensor() {
  Bst<SensorRecType> test;
  for (int i = 0; i < 3; i++) {
    SensorRecType temp;

    temp.speed = 5 + (i * 5);             // 5, 10, 15
    temp.temperature = 15 + (i * 15);     // 15, 30, 45
    temp.solar_radiation = 10 + (i * 10); // 10, 20, 30

    temp.date.SetDay(i);

    test.Insert(temp);
  }

  SensorRecType target_test_1;
  SensorRecType target_test_2;
  SensorRecType target_test_3;

  target_test_1.date.SetDay(0);

  target_test_2.date.SetDay(1);

  target_test_3.date.SetDay(2);

  if (test.Get(target_test_2).speed == 10 &&
      test.Get(target_test_3).temperature == 45 &&
      test.Get(target_test_1).solar_radiation == 10) {
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
  cout << "hello";
  Date test;
  // Results
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

void TestCalculateAverageStd() {

  Map<int, float> data;
  for (int i = 0; i < 3; i++) {
    float speed = 4.4 + (i * 2.1); // 4.4, 6.5, 8.6
    // float temperature = 20.7 + (i * 4.4);        // 20.7, 25.1, 29.5
    // float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

    data.Insert(data.Size(), speed);
  }
  Calculator test;
  float mean = 0.0f;
  float standard_deviation = 0.0f;
  mean = test.CalculateAverage(data);
  standard_deviation = test.CalculateStandardDeviation(data, mean);
  // 4.5 + 6.5 + 8.6 = 19.5
  // 19.5 / 3
  // mean = 6.5
  if (mean == 6.5f) {
    cout << "CalculateAverage() Test: PASS" << endl;
  } else {
    cout << "CalculateAverage() Test: FAIL" << endl;
  }
  if (standard_deviation == 2.1f) {
    cout << "CalculateStdev() Speed TEST: PASS" << endl;
  } else {
    cout << "CalculateStdev() Speed Test: FAIL" << endl;
  }
}

void TestSolarRadiation() {

  Calculator test;
  Map<int, float> data;
  for (int i = 0; i < 3; i++) {
    // float speed = 4.4 + (i * 2.1); // 4.4, 6.5, 8.6
    // float temperature = 20.7 + (i * 4.4);        // 20.7, 25.1, 29.5
    float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

    data.Insert(data.Size(), solar_radiation);
  }
  // Results
  float total_solar_radiation = 0;
  total_solar_radiation = test.CalculateTotalSolarRadiation(data);
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

void TestCalculateMad() {

  Map<int, float> data;
  for (int i = 0; i < 3; i++) {
    float speed = 4.4 + (i * 2.1); // 4.4, 6.5, 8.6
    // float temperature = 20.7 + (i * 4.4);        // 20.7, 25.1, 29.5
    // float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

    data.Insert(data.Size(), speed);
  }
  Calculator test;
  float mad = 0.0f;
  mad = test.CalculateMAD(data);
 
  if (mad == 1.4f) {
    cout << "CalculateMad() Test: PASS" << endl;
  } else {
    cout << "CalculateMad() Test: FAIL" << endl;
  }
}
void TestCalculate_sPCC() {

  Map<int, float> x_data;
  Map<int, float> y_data;
  for (int i = 0; i < 5; i++) {
    float x_value = 4.4 + (i * 2.1); // 4.4, 6.5, 8.6, 10.7, 12.8
    float y_value = 20.7 + (i * 4.4); // 20.7, 25.1, 29.5

    x_data.Insert(x_data.Size(), x_value);
    y_data.Insert(y_data.Size(), y_value);
  }
  Calculator test;
  float x_y_sPCC = 0.0f;
  x_y_sPCC = test.Calculate_sPCC(x_data, y_data);
 
  if (x_y_sPCC == 1) {
    cout << "Calculate_sPCC() Test: PASS" << endl;
  } else {
    cout << "Calculate_sPCC() Test: FAIL" << endl;
  }
}



void TestDisplaySpeed(const SensorLog sensor_data) {
  Results test;
  test.DisplayAverageStdevSpeed(sensor_data, 1, 2007);
  cout << "\nSpeed Displayed, Expected Result: \nAverage: 6.5km/h\nSample "
          "Standard Deviation: 2.1 "
       << endl;
}

void TestDisplayTemperature(const SensorLog sensor_data) {
  Results test;
  test.DisplayAverageStdevTemperature(sensor_data, 2007);
  cout << "\nTemperature Displayed, Expected Result: \nAll Months have "
          "Data\nAverage:25.1 degrees C\nSample Standard Deviation: 4.4"
       << endl;
}

void TestDisplaySolarRadiation(const SensorLog sensor_data) {
  Results test;
  test.DisplayTotalSolarRadiation(sensor_data, 2007);
  cout << "\nSolar Radiation Displayed, Expected Result: \nAll Months have "
          "Data\nTotal Solar Radiation: 0.2f"
       << endl;
}

void TestPrintAll(const SensorLog sensor_data) {
  Results test;
  test.PrintAll(sensor_data, 2007);
  cout << "\nWindTempSolar.csv created, Expected Result: \nAll Months have "
          "data\nEach Row: 6.5(2.1, 1.4),25.1(4.4, 2.9),0.2"
       << endl;
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

  SensorLog testData;
  SensorRecType targetData;
  targetData.date.SetDay(2);
  targetData.date.SetMonth(22);
  targetData.date.SetYear(2222);
  targetData.time.SetMinutes(22);
  targetData.time.SetHours(22);
  FileHandler handleFile;
  handleFile.readCSV("UnitTestData.csv", testData);
  if (testData.Get(targetData).speed == 22 &&
      testData.Get(targetData).temperature == 22 &&
      testData.Get(targetData).solar_radiation == 22) {
    cout << "TestReadCsv() Test: PASS" << endl;
  } else {
    cout << "TestReadCsv() Test: FAIL" << endl;
  }
}

void TestReadSource() {

  SensorLog testData;
  SensorRecType targetData;
  targetData.date.SetDay(2);
  targetData.date.SetMonth(22);
  targetData.date.SetYear(2222);
  targetData.time.SetMinutes(22);
  targetData.time.SetHours(22);
  FileHandler handleFile;
  handleFile.readSource("Source.txt", testData);
  if (testData.Get(targetData).speed == 22 &&
      testData.Get(targetData).temperature == 22 &&
      testData.Get(targetData).solar_radiation == 22) {
    cout << "TestReadCsv() Test: PASS" << endl;
  } else {
    cout << "TestReadCsv() Test: FAIL" << endl;
  }
}

SensorLog TestData(){
  SensorLog data;

  for (int month_index = 1; month_index < 13; month_index++) {
    for (int i = 0; i < 3; i++) {

      float speed = 4.4 + (i * 2.1);               // 4.4, 6.5, 8.6
      float temperature = 20.7 + (i * 4.4);        // 20.7, 25.1, 29.5
      float solar_radiation = 415.25 + (i * 8.51); // 415.25, 423.76, 432.27

      SensorRecType temp;
      temp.speed = speed;
      temp.temperature = temperature;
      temp.solar_radiation = solar_radiation;
      temp.date.SetDay(i);
      temp.date.SetMonth(month_index);
      temp.date.SetYear(2007);
      data.Insert(temp);
    }
  }
  return data;
}

int main() {
  // Test Vector
  TestBstInt();
  TestBstSensor();

  // Test Date and Time;
  TestSetGetDay();
  TestSetGetMonth();
  TestSetGetYear();
  TestSetGetMinutes();
  TestSetGetHours();

  // Test Calculator
  TestCalculateAverageStd();
  TestSolarRadiation();
  TestCalculateMad();
  TestCalculate_sPCC();

  // File Handler
  TestWriteToFile();
  TestReadSource();
  TestReadCsv();

  cout << "================================\n Manually check output here and "
          "in .txt/.csv outputs in cwd of main program"
       << endl;




  TestDisplaySpeed(TestData());
  TestDisplayTemperature(TestData());
  TestDisplaySolarRadiation(TestData());
  TestPrintAll(TestData());
}
