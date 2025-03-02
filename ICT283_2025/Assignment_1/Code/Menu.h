#ifndef MENU_H
#define MENU_H
#include "Calculator.h"
#include "FileHandler.h"
#include "Results.h"
#include "SensorRecType.h"
#include <iostream>
using namespace std;

/**
 * @class Menu
 * @brief Handles user interaction and data processing for weather sensor
 * information
 *
 * This class provides functionality to display menus, process user input,
 * and perform various calculations on weather sensor data including wind speed,
 * temperature, and solar radiation measurements.
 *
 * @author Kim Andrew Dela Cruz
 * @version 01
 * @date 16/02/2025 Kim Andrew Dela Cruz
 */
class Menu {
public:
  /**
   * @brief Displays main menu and handles user input
   * @param sensor_data Reference to sensor log containing all data
   * @param exit Reference to boolean flag controlling program termination
   */

  void prompt(const SensorLog &sensor_data, bool &exit) const;
  /**
   * @brief Calculates and displays average wind speed and standard deviation
   * for specified month/year
   * @param sensor_data Reference to sensor log containing all data
   */

  void HandleMonthlySpeed(const SensorLog &sensor_data) const;
  /**
   * @brief Calculates and displays average temperature and standard deviation
   * for each month of specified year
   * @param sensor_data Reference to sensor log containing all data
   */

  void HandleMonthlyTemperature(const SensorLog &sensor_data) const;
  /**
   * @brief Calculates and displays total solar radiation for each month of
   * specified year
   * @param sensor_data Reference to sensor log containing all data
   */

  void HandleMonthlySolarRadiation(const SensorLog &sensor_data) const;
  /**
   * @brief Writes wind speed, temperature and solar radiation data to
   * WindTempSolar.csv
   * @param sensor_data Reference to sensor log containing all data
   */

  void HandleAllData(const SensorLog &sensor_data) const;
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
  /**
   * @brief Gets and validates year input from user
   * @return Valid year between 2005-2025
   */
  int GetValidYear() const;
};

/**
 * @brief Converts month name to month number
 * @param month String containing month name
 * @return Month number (1-12), 0 if invalid
 */
string int_to_month(const int month);
/**
 * @brief Converts month name to month number
 * @param month String containing month name
 * @return Month number (1-12), 0 if invalid
 */
int month_to_int(const string month);
#endif
