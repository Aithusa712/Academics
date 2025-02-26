#include "Calculator.h"
#include <cmath>
using namespace std;

float Calculator::AverageSpeed(SensorLog &sensor_data, int month, int year) {
  float sum = 0.0f;
  float average = 0.0f;
  int count = 0;

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month) {
      sum += sensor_data[index].speed;
      count++;
    }
  }

  average = sum / count;
  return average;
}
float Calculator::AverageTemperature(SensorLog &sensor_data, int month,
                                     int year) {
  float sum = 0.0f;
  float average = 0.0f;
  int count = 0;

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month) {
      sum += sensor_data[index].temperature;
      count++;
    }
  }

  average = sum / count;
  return average;
}
float Calculator::AverageSolarRadiation(SensorLog &sensor_data, int month,
                                        int year) {

  float sum = 0.0f;
  float average = 0.0f;
  int count = 0;

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month) {
      sum += sensor_data[index].solar_radiation;
      count++;
    }
  }

  average = sum / count;
  return average;
}

// STD DEV CALCULATION

float Calculator::StdDevSpeed(SensorLog &sensor_data, float mean, int month,
                              int year) {
  float sum_sqrt = 0.0f;
  float standard_deviation = 0.0f;
  int count = 0;
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month) {
      float diff = sensor_data[index].speed - mean;
      sum_sqrt += diff * diff;
      count++;
    }
  }
  standard_deviation = sqrt(sum_sqrt / (count - 1));
  return standard_deviation;
}
float Calculator::StdDevTemperature(SensorLog &sensor_data, float mean,
                                    int month, int year) {
  float sum_sqrt = 0.0f;
  float standard_deviation = 0.0f;
  int count = 0;
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month) {
      float diff = sensor_data[index].temperature - mean;
      sum_sqrt += diff * diff;
      count++;
    }
  }
  standard_deviation = sqrt(sum_sqrt / (count - 1));
  return standard_deviation;
}
float Calculator::StdDevSolarRadiation(SensorLog &sensor_data, float mean,
                                       int month, int year) {
  float sum_sqrt = 0.0f;
  float standard_deviation = 0.0f;
  int count = 0;
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month) {
      float diff = sensor_data[index].solar_radiation - mean;
      sum_sqrt += diff * diff;
      count++;
    }
  }
  standard_deviation = sqrt(sum_sqrt / (count - 1));
  return standard_deviation;
}
