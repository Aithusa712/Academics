#include "Calculator.h"
#include <cmath>
using namespace std;

// TODO: Remove sqrt() and cmath. Add round off
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
  return roundOff(average);
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
  return roundOff(average);
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
  return roundOff(average);
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
  return roundOff(standard_deviation);
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
  return roundOff(standard_deviation);
}
float Calculator::TotalSolarRadiation(SensorLog &sensor_data, int month,
                                      int year) {
  float totalRadiation = 0.0f;

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month &&
        sensor_data[index].solar_radiation >= 100) {
      // Convert W/m² to kWh/m²:
      // W/m² × 10minutes ÷ 60min/hour ÷ 1000W/kW
      float kWh_conversion =
          sensor_data[index].solar_radiation * (10.0f / 60.0f) / 1000.0f;
      totalRadiation += kWh_conversion;
    }
  }

  return roundOff(totalRadiation);
}
// TODO: Add assumption: all values are positive
float roundOff(float &value) { return (int)(value * 10.0f + 0.5f) / 10.0f; }
