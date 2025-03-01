#include "Calculator.h"
#include <cmath>
using namespace std;

float Calculator::AverageSpeed(const SensorLog &sensor_data, const int month,
                               const int year) const {
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
  if (count < 2) {
    return 0;
  } else {
    average = sum / count;
    return round(10 * average) / 10.0;
  }
}
float Calculator::AverageTemperature(const SensorLog &sensor_data,
                                     const int month, const int year) const {
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

  if (count < 2) {
    return 0;
  } else {
    average = sum / count;
    return round(10 * average) / 10.0;
  }
}

float Calculator::AverageSolarRadiation(const SensorLog &sensor_data,
                                        const int month, const int year) const {

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
  if (count < 2) {
    return 0;
  } else {
    average = sum / count;

    return round(10 * average) / 10.0;
  }
}

// STD DEV CALCULATION

float Calculator::StdDevSpeed(const SensorLog &sensor_data, const float mean,
                              const int month, const int year) const {
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
  if (count < 2) {
    return 0;
  } else {
    standard_deviation = sqrt(sum_sqrt / (count - 1));
    return round(10 * standard_deviation) / 10.0;
  }
}
float Calculator::StdDevTemperature(const SensorLog &sensor_data,
                                    const float mean, const int month,
                                    const int year) const {
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
  if (count < 2) {
    return 0;
  } else {
    standard_deviation = sqrt(sum_sqrt / (count - 1));

    return round(10 * standard_deviation) / 10.0;
  }
}
float Calculator::TotalSolarRadiation(const SensorLog &sensor_data,
                                      const int month, const int year) const {
  float totalRadiation = 0.0f;
  int count = 0;
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year &&
        sensor_data[index].date.GetMonth() == month &&
        sensor_data[index].solar_radiation >= 100) {
      // Convert W/m² to kWh/m²:
      // W/m² × 10minutes ÷ 60min/hour ÷ 1000W/kW
      float kWh_conversion =
          sensor_data[index].solar_radiation * (10.0f / 60.0f) / 1000.0f;
      totalRadiation += kWh_conversion;
      count++;
    }
  }
  if (count < 2) {
    return 0;
  } else {
    return round(10 * totalRadiation) / 10.0;
  }
}
