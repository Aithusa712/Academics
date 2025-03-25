#ifndef RESULTS_H
#define RESULTS_H

#include "Bst.h"
#include "Calculator.h"
#include "FileHandler.h"
#include "SensorRecType.h"
#include "Map.h"
#include <iostream>
using namespace std;

const int MAX_MONTHS = 13;

/**
 * @class Results
 * @brief Handles the output of results
 *
 * This class provides the functionality of displaying results either in the
 * terminal console or into a file.
 *
 *
 * @author Kim Andrew Dela Cruz
 * @version 01
 * @date 16/02/2025 Kim Andrew Dela Cruz
 */
class Results {

public:
  /**
   * @brief Calculates and displays average wind speed and standard deviation
   * for specified month/year
   * @param sensor_data Reference to sensor log containing all data
   * @param month the specific month to calculate
   * @param year the year to display
   */
  void DisplayAverageStdevSpeed(const SensorLog &sensor_data, const int month,
                                const int year) const;
  /**
   * @brief Calculates and displays average temperature and standard deviation
   * for each month of specified year
   * @param sensor_data Reference to sensor log containing all data
   * @param year the year to display
   */
  void DisplayAverageStdevTemperature(const SensorLog &sensor_data,
                                      const int year) const;
  /**
   * @brief Calculates and displays total solar radiation for each month of
   * specified year
   * @param sensor_data Reference to sensor log containing all data
   * @param year the year to display
   */
  void DisplayTotalSolarRadiation(const SensorLog &sensor_data,
                                  const int year) const;
  /**
   * @brief Writes wind speed, temperature and solar radiation data to
   * WindTempSolar.csv
   * @param sensor_data Reference to sensor log containing all data
   * @param year the year to display
   */

  void PrintAll(const SensorLog &sensor_data, const int year) const;
  /**
   * @brief Checks if data exists for specified month and year
   * @param sensor_data Reference to sensor log containing all data
   * @param month Month to validate
   * @param year Year to validate
   * @param sensor_type to validate
   * @return true if data exists, false otherwise
   */
  bool ValidateMonth(const SensorLog &sensor_data, const int month,
                     const int year, const string sensor_type) const;

private:
  static int targetMonth;
  static int targetYear;
  static bool targetFound;

  static Map<int, float> speedData;
  static Map<int, float> tempData;
  static Map<int, float> solarData;

  static bool dataFound;

  static void CollectSpeedData(SensorRecType &record);

  static void CollectTempData(SensorRecType &record);

  static void CollectSolarData(SensorRecType &record);

  static void CollectAllData(SensorRecType &record);

  static void CheckSpeed(SensorRecType &record);

  static void CheckTemp(SensorRecType &record);

  static void CheckSolar(SensorRecType &record);

  static void CheckAll(SensorRecType &record);
};

/**
 * @brief Converts month index into a readable month string
 * @param month_index the month index to convert into month string
 * @return the string named value of the month
 */
string int_to_month(const int month_index);

#endif
