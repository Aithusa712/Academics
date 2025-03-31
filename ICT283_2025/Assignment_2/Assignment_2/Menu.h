#ifndef MENU_H
#define MENU_H
#include "Results.h"
#include "SensorRecType.h"
#include <iostream>
using namespace std;

/**
 * @class Menu
 * @brief Handles user interaction
 *
 * This class provides functionality to display menus, and process user input.
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
   * @brief Gets and validate Month Input of user
   * @return Valid Month 
   */

  int GetValidMonth() const;

  /**
   * @brief Gets and validates year input from user
   * @return Valid year between 2005-2025
   */
  int GetValidYear() const;
};

#endif
