#ifndef DATE_H
#define DATE_H

#include <iomanip>
#include <iostream>
using namespace std;

/**
 * @class Date
 * @brief  Contains date data in integer form
 *
 * Date class Stores and retrieves date data in integer form. 
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
 */


class Date {
public:
  /**
   * @brief Constructor
   * @details Initializes date with default values
   */
  Date();
  
  /**
   * @brief  Returns the m_day value
   *
   * Returns the m_day value stored in this class
   *
   * @return int
   */
  int GetDay() const;
   /**
   * @brief  Returns the m_month value
   *
   * Returns the m_month value stored in this class
   *
   * @return int
   */ 
  int GetMonth() const;
    /**
   * @brief  Returns the m_year value
   *
   * Returns the m_year value stored in this class
   *
   * @return int
   */
  int GetYear() const;
  /**
   * @brief  Set the m_day value stored in this class
   *
   *
   * @param day - the value to be allocated
   * @return void
   */
  void SetDay(int day);
   /**
   * @brief  Set the m_month value stored in this class
   *
   *
   * @param month - the value to be allocated
   * @return void
   */
  void SetMonth(int month);
    /**
   * @brief  Set the m_year value stored in this class
   *
   *
   * @param year - the value to be allocated
   * @return void
   */
  void SetYear(int year);

private:
  int m_day; ///< contains the day value

  int m_month;  ///< contains the month value

  int m_year; ///< contains the year value

}

/// overloading the << operator
ostream &operator<<(ostream &os, const Date &date);
/// overloading the >> operator
istream &operator>>(istream &input, Date &date);

#endif
