#include "Calculator.h"
#include "FileHandler.h"
#include "Menu.h"
#include "SensorRecType.h"
#include <iostream>
#include <ostream>
using namespace std; // check textbook for details of the namespace concept

void unitTesting(const SensorLog &sensor_data);

int main() {
  SensorLog sensor_data;
  FileHandler handleFile;
  Calculator calculate;
  Menu menu;
  bool exit = false;

  handleFile.readSource("data/data_source.txt", sensor_data);

  while (!exit) {
    menu.prompt(sensor_data, exit);
  }

  return 0;
}

void unitTesting(const SensorLog &sensor_data) {
  // Unit Testing
  for (int i = 0; i < sensor_data.size(); i++) {
    cout << "Index [" << i << "]Speed: " << sensor_data[i].speed
         << ", temperature: " << sensor_data[i].temperature
         << ", solar radiation: " << sensor_data[i].solar_radiation << endl;
  }
}
