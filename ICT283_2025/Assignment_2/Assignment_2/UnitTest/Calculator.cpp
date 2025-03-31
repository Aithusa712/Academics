#include "Calculator.h"
using namespace std; 

/*  Calculate Average Speed   */

float Calculator::CalculateAverage(const Map<int, float> &data) const {

  // Initialize local variables

  float sum = 0.0f;
  float average = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data and get the sum

  for (int index = 0; index < data.Size(); index++) {
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

float Calculator::CalculateStandardDeviation(const Map<int, float> &data,
                                             const float mean) const {

  //  Initialize local variables

  float sum_square_diff = 0.0f;
  float standard_deviation = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data, and check if it matches the year and
  // month parameter to get the sum of squared difference of speed records.

  for (int index = 0; index < data.Size(); index++) {

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

float Calculator::CalculateTotalSolarRadiation(
    const Map<int, float> &data) const {
  float totalRadiation = 0.0f;
  int data_count = 0;

  // Loop through all the sensor data, and check if it matches the year and
  // month parameter to get the sum of solar radiation

  for (int index = 0; index < data.Size(); index++) {
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

float Calculator::Calculate_sPCC(const Map<int, float> &data_1,
                                const Map<int, float> &data_2) {
  int data_size = 0;
  float spcc = 0.0f;
  if (data_1.Size() != data_2.Size()) {
    return -1;
  } else {
    data_size = data_1.Size();
  }
  float average_1 = CalculateAverage(data_1);
  float average_2 = CalculateAverage(data_2);
  float numerator = 0.0f;
  float denominator1 = 0.0f;
  float denominator2 = 0.0f;

  for (int i = 0; i < data_1.Size(); ++i) {
    float value_1 = 0.0f;
    float value_2 = 0.0f;
    value_1 = data_1[i];
    value_2 = data_2[i];

    numerator += (value_1 - average_1) * (value_2 - average_2);
    denominator1 += pow(value_1 - average_1, 2);
    denominator2 += pow(value_2 - average_2, 2);
  }
  spcc = numerator / sqrt(denominator1 * denominator2);
  return round(spcc * 100) / 100.0;
}

float Calculator::CalculateMAD(const Map<int, float> &data) const {
  float mad = 0.0f;
  float value = 0.0f;
  float average = CalculateAverage(data);
  for (int i = 0; i < data.Size(); ++i) {
    value = data[i];
    mad += fabs(value - average);
  }
  mad /= data.Size();
  return round(mad * 10) / 10.0;
}
