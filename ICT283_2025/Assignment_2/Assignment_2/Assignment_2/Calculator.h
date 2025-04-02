#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Map.h"
#include <cmath>
#include <iostream>
using namespace std;

/**
 * @class Calculator
 * @brief Calculator class for processing sensor data statistics
 *
 * This class provides various statistical calculations for sensor data.
 * All functions will return 0 if sensor data records is less than 2.
 *
 *
 * @author Kim Andrew Dela Cruz
 * @version 01
 * @date 16/02/2025 Kim Andrew Dela Cruz
 */
class Calculator {

public:
 
  /**
   * @brief Calculates the average speed
   * @param data Reference to the data to be calculated
   * @return float The average speed, returns 0 if insufficient data
   */
  float CalculateAverage(const Map<int, float> &data) const;

  /**
   * @brief Calculates the standard deviation of speed
   * @param data Reference to the data to be calculated
   * @param mean The mean speed value
   * @return float The standard deviation of speed, returns 0 if insufficient
   * data
   */
  float CalculateStandardDeviation(const Map<int, float> &data,
                                   const float mean) const;

  /**
   * @brief Calculates the total solar radiation
   * @param data Reference to the data to be calculated
   * @return float The total solar radiation, returns 0 if insufficient data
   */
  float CalculateTotalSolarRadiation(const Map<int, float> &data) const;

  /**
   * @brief Calculates the sample Pearson Correlation Coefficient (sPCC)
   * @param sensor_data_1 Reference to the first set of sensor data
   * @param sensor_data_2 Reference to the second set of sensor data
   * @return float The Pearson Correlation Coefficient, returns 0 if insufficient data
   */
  float Calculate_sPCC(const Map<int, float> &sensor_data_1,
                      const Map<int, float> &sensor_data_2);

  /**
   * @brief Calculates the Mean Absolute Deviation (MAD)
   * @param data Reference to the data to be calculated
   * @return float The Mean Absolute Deviation, returns 0 if insufficient data
   */
  float CalculateMAD(const Map<int, float> &data) const;

};
#endif
