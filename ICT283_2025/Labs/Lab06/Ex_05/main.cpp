#include "FileHandler.h"
#include <cmath>
#include <iostream>
using namespace std; // check textbook for details of the namespace concept

float calculateMean(const WindLogType &wind_data) {
  float sum = 0.0f;
  for (int i = 0; i < wind_data.size(); ++i) {
    sum += wind_data[i].speed;
  }
  return sum / wind_data.size();
}

float calculateSSD(const WindLogType &wind_data, float mean) {
  float sum_sqrt = 0.0f;
  for (int i = 0; i < wind_data.size(); ++i) {
    float diff = wind_data[i].speed - mean;
    sum_sqrt += diff * diff;
  }
  return sqrt(sum_sqrt / (wind_data.size() - 1));
}

int main() {

  WindLogType wind_data;

  FileHandler handleFile;

  float mean = 0;
  float ssd = 0;

  handleFile.readSource("data/data_source.txt", wind_data);

  for (int i = 0; i < wind_data.size(); i++) {
    cout << "Index [" << i << "]Speed: " << wind_data[i].speed
         << ", temperature: " << wind_data[i].temperature
         << ", solar radiation: " << wind_data[i].solar_radiation << endl;
  }
  mean = calculateMean(wind_data);
  ssd = calculateSSD(wind_data, mean);
  cout << "\nThe number of floating point values (N):" << wind_data.size()
       << endl
       << "The mean of the floating point values:" << mean << endl
       << "The sample standard deviation (s):" << ssd << endl;

  return 0;
}
