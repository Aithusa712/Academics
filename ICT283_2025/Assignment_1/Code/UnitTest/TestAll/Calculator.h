#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "SensorRecType.h"
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
   * @brief Calculates the average speed for a given month and year
   * @param sensor_data Reference to the sensor log data
   * @param month The month to calculate for
   * @param year The year to calculate for
   * @return float The average speed, returns 0 if insufficient data
   */
  float AverageSpeed(const SensorLog &sensor_data, const int month,
                     const int year) const;

  /**
   * @brief Calculates the average temperature for a given month and year
   * @param sensor_data Reference to the sensor log data
   * @param month The month to calculate for
   * @param year The year to calculate for
   * @return float The average temperature, returns 0 if insufficient data
   */
  float AverageTemperature(const SensorLog &sensor_data, const int month,
                           const int year) const;

  /**
   * @brief Calculates the standard deviation of speed for a given month and
   * year
   * @param sensor_data Reference to the sensor log data
   * @param mean The mean speed value
   * @param month The month to calculate for
   * @param year The year to calculate for
   * @return float The standard deviation of speed, returns 0 if insufficient
   * data
   */
  float StdDevSpeed(const SensorLog &sensor_data, float mean, const int month,
                    const int year) const;

  /**
   * @brief Calculates the standard deviation of temperature for a given month
   * and year
   * @param sensor_data Reference to the sensor log data
   * @param mean The mean temperature value
   * @param month The month to calculate for
   * @param year The year to calculate for
   * @return float The standard deviation of temperature, returns 0 if
   * insufficient data
   */
  float StdDevTemperature(const SensorLog &sensor_data, const float mean,
                          const int month, const int year) const;

  /**
   * @brief Calculates the total solar radiation for a given month and year
   * @param sensor_data Reference to the sensor log data
   * @param month The month to calculate for
   * @param year The year to calculate for
   * @return float The total solar radiation, returns 0 if insufficient data
   */
  float TotalSolarRadiation(const SensorLog &sensor_data, const int month,
                            const int year) const;
};
#endif
