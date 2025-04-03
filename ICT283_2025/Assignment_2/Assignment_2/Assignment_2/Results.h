#ifndef RESULTS_H
#define RESULTS_H

#include "Bst.h"
#include "Collection.h"
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

/**
 * @brief Displays the average speed and standard deviation.
 *
 * @param sensor_data The sensor log containing data.
 * @param month The month for which to display the data.
 * @param year The year for which to display the data.
 */
public:
  void DisplayAverageStdevSpeed(const SensorLog &sensor_data, const int month,
                                const int year) const;

/**
 * @brief Displays the average temperature and standard deviation.
 *
 * @param sensor_data The sensor log containing data.
 * @param year The year for which to display the data.
 */
  void DisplayAverageStdevTemperature(const SensorLog &sensor_data,
                                      const int year) const;

/**
 * @brief Displays the total solar radiation.
 *
 * @param sensor_data The sensor log containing data.
 * @param year The year for which to display the data.
 */
  void DisplayTotalSolarRadiation(const SensorLog &sensor_data,
                                  const int year) const;

/**
 * @brief Prints all available data from the sensor log.
 *
 * @param sensor_data The sensor log containing data.
 * @param year The year for which to print the data.
 */
  void PrintAll(const SensorLog &sensor_data, const int year) const;

/**
 * @brief Displays the specific sPCC data for the month.
 *
 * @param sensor_data The sensor log containing data.
 * @param month The month for which to display the PCC data.
 */
  void Display_sPCC(const SensorLog &sensor_data, const int month) const;

};

/**
 * @brief Converts month index into a readable month string
 * @param month_index the month index to convert into month string
 * @return the string named value of the month
 */
string int_to_month(const int month_index);

bool CheckDate(const SensorLog &sensor_data, const int year, const int month);

#endif
