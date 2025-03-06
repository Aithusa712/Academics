#ifndef time_H
#define time_H

#include <iostream>
using namespace std;

/**
 * @class Time
 * @brief  Contains time data in integer form
 *
 * Time class Stores and retrieves time data in integer form.
 *
 *
 *
 *
 * @author Kim Andrew Dela Cruz
 * @version 01
 * @date 16/02/2025 Kim Andrew Dela Cruz
 *
 *
 *
 */

class Time {
public:
  /**
   * @brief Constructor
   * @details Initializes time with default values
   */
  Time();

  /**
   * @brief  Returns the m_minutes value
   *
   * Returns the m_minutes value stored in this class
   *
   * @return int
   */
  int GetMinutes() const;
  /**
   * @brief  Returns the m_hours value
   *
   * Returns the m_hours value stored in this class
   *
   * @return int
   */
  int GetHours() const;
  /**
   * @brief  Returns the m_year value
   *
   * Returns the m_year value stored in this class
   *
   * @return int
   */

  void SetMinutes(int minutes);
  /**
   * @brief  Set the m_hours value stored in this class
   *
   *
   * @param hours - the value to be allocated
   * @return void
   */
  void SetHours(int hours);

private:
  int m_minutes; ///< contains the minutes value

  int m_hours; ///< contains the hours value
};

/// overloading the << operator
ostream &operator<<(ostream &os, const Time &time);
/// overloading the >> operator
istream &operator>>(istream &input, Time &time);
/// Helper Function to convert the time's integer form into readable string
string ConvertTime(int minutes, int hours, int year);

#endif
