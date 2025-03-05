#include "FileHandler.h"
#include "SensorRecType.h"
#include <iostream>

using namespace std;

void TestWriteToFile() {
  FileHandler handleFile;
  handleFile.writeToFile("TestFile.txt", "hello this is the content");
  cout << "File created, Expected result:\nFilename in directory: "
          "TestFile.txt\nContent:hello this is the content "
       << endl;
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
  TestWriteToFile();
  TestReadCsv();
  TestReadSource();
}
