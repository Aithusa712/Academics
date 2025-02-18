#ifndef UNIT_H
#define UNIT_H

#include <iostream>

using namespace std;

/**
 * @class Unit
 * @brief  Contains unit detail
 *
 * Unit details include marks, unit name, and unit id
 *
 *
 *
 *
 *
 * @author Kim Andrew Dela Cruz
 * @version 01
 * @date 03/02/2025
 *
 *
 *
 *
 */

class Unit {
public:
  /**
   * @brief Constructor
   * @details Initializes Unit with default values
   */
  Unit();
  /**
   * @brief  Returns the value stored in unitName
   *
   *
   *
   * @return string
   */
  string GetUnitName() const;
  /**
   * @brief  Returns the value stored in unitId
   *
   *
   *
   * @return string
   */
  string GetUnitId() const;
  /**
   * @brief  Returns the value stored in credits
   *
   *
   *
   * @return int
   */
  int GetCredits() const; // Get the number of credits.

  /**
   * @brief  Sets the unitName value stored in this class
   *
   *
   * @param unitName - the value to be allocated
   * @return void
   */
  void SetUnitName(const string unitName);
  /**
   * @brief  Sets the unitId value stored in this class
   *
   *
   * @param unitId - the value to be allocated
   * @return void
   */
  void SetUnitId(const string unitId);
  /**
   * @brief  Sets the credits value stored in this class
   *
   *
   * @param credits - the value to be allocated
   * @return void
   */
  void SetCredits(const int credits);

private:
  /// unit Name
  string m_unitName;
  /// unit ID
  string m_unitId;
  /// credits
  int m_credits;
};
/// overloading the << operator
ostream &operator<<(ostream &os, const Unit &unit);
/// overloading the >> operator
istream &operator>>(istream &input, Unit &unit);

#endif
