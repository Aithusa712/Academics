#include "FileHandler.h"
#include <cmath>
#include <iostream>
#include <ostream>
using namespace std; // check textbook for details of the namespace concept

float calculateMean(const SensorLog &sensor_data) {
  float sum = 0.0f;
  for (int i = 0; i < sensor_data.size(); ++i) {
    sum += sensor_data[i].speed;
  }
  return sum / sensor_data.size();
}

float calculateSSD(const SensorLog &sensor_data, float mean) {
  float sum_sqrt = 0.0f;
  for (int i = 0; i < sensor_data.size(); ++i) {
    float diff = sensor_data[i].speed - mean;
    sum_sqrt += diff * diff;
  }
  return sqrt(sum_sqrt / (sensor_data.size() - 1));
}

int main() {
  SensorLog sensor_data;
  FileHandler handleFile;
  handleFile.readSource("data/data_source.txt", sensor_data);

  float mean = 0;
  float ssd = 0;

  cout << "1. The average wind speed and sample standard deviation for this "
          "wind speed given a specified month and year. (print on screen only)"
       << endl
       << "2. Average ambient air temperature and sample standard deviation "
          "for each month of a specified year. (print on screen only)"
       << endl
       << "3.Total solar radiation in lWh/m^2 for each month of a specified "
          "year. (print on screen only)"
       << endl
       << "4. Average wind speed(km/h), average ambient air temperature and "
          "total solar radiation in kWh/m^2 for each month of a specified "
          "year. The solar deviation is printed in () next to the average. "
          "(print to a file called 'WindTempSolar.csv')"
       << endl
       << "5. Exit. " << endl;

  // Unit Testing
  for (int i = 0; i < sensor_data.size(); i++) {
    cout << "Index [" << i << "]Speed: " << sensor_data[i].speed
         << ", temperature: " << sensor_data[i].temperature
         << ", solar radiation: " << sensor_data[i].solar_radiation << endl;
  }

  return 0;
}
