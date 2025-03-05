#include "Calculator.h"
#include "Vector.h"
using namespace std;

/*  Calculate Average Speed   */

float Calculator::AverageSpeed(const Vector<float> &data) const {

  // Initialize local variables

  float sum = 0.0f;
  float average = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data, and check if it matches the year and
  // month parameter to get the sum of speed records

  for (int index = 0; index < data.size(); index++) {
    sum += data[index];
    data_count++;
  }

  // Check if there are more than 1 data, return 0 if data is
  // insufficient

  if (data_count < 2) {
    return 0;
  } else {
    average = sum / data_count;
    return round(10 * average) / 10.0;
  }
}

/*  Calculate Average Temperature   */

float Calculator::AverageTemperature(const Vector<float> &data) const {

  // Initialize local variables

  float sum = 0.0f;
  float average = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data, and check if it matches the year and
  // month parameter to get the sum of temperature records

  for (int index = 0; index < data.size(); index++) {

    sum += data[index];
    data_count++;
  }

  // Check if there are more than 1 data, return 0 if data is
  // insufficient

  if (data_count < 2) {
    return 0;
  } else {
    average = sum / data_count;
    return round(10 * average) / 10.0;
  }
}

/*  Calculate Sample Standard Deviation of Speed   */

float Calculator::StdDevSpeed(const Vector<float> &data,
                              const float mean) const {

  //  Initialize local variables

  float sum_square_diff = 0.0f;
  float standard_deviation = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data, and check if it matches the year and
  // month parameter to get the sum of squared difference of speed records.

  for (int index = 0; index < data.size(); index++) {

    float diff = data[index] - mean;
    sum_square_diff += diff * diff;
    data_count++;
  }

  // Check if there are more than 1 data, return 0 if data is
  // insufficient

  if (data_count < 2) {
    return 0;
  } else {
    standard_deviation = sqrt(sum_square_diff / (data_count - 1));
    return round(10 * standard_deviation) / 10.0;
  }
}

/*  Calculate Sample Standard Deviation of Temperature   */

float Calculator::StdDevTemperature(const Vector<float> &data,
                                    const float mean) const {

  // Initialize local variables

  float sum_square_diff = 0.0f;
  float standard_deviation = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data, and check if it matches the year and
  // month parameter to get the sum of squared difference of speed records.

  for (int index = 0; index < data.size(); index++) {

    float diff = data[index] - mean;
    sum_square_diff += diff * diff;
    data_count++;
  }

  // Check if there are more than 1 data, return 0 if data is
  // insufficient

  if (data_count < 2) {
    return 0;
  } else {
    standard_deviation = sqrt(sum_square_diff / (data_count - 1));

    return round(10 * standard_deviation) / 10.0;
  }
}

/*  Calculate Sample Standard Deviation of Speed   */

float Calculator::TotalSolarRadiation(const Vector<float> &data) const {
  float totalRadiation = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data, and check if it matches the year and
  // month parameter to get the sum of solar radiation

  for (int index = 0; index < data.size(); index++) {
    if (data[index] >= 100) {

      // Convert W/m^2 to kWh/m^2:
      // W/m^2 * (10minutes / 60min/hour) / 1000W/kW

      float kWh_conversion = data[index] * (10.0f / 60.0f) / 1000.0f;
      totalRadiation += kWh_conversion;
      data_count++;
    }
  }

  // Check if there are more than 1 data, return 0 if data is
  // insufficient

  if (data_count < 2) {
    return 0;
  } else {
    return round(10 * totalRadiation) / 10.0;
  }
}
