#ifndef RESULT_H
#define RESULT_H

#include "Unit.h"
#include "Date.h"


using namespace std;

/**
 * @class Result
 * @brief  Contains marks and a unit object
 *
 * Result class stores and retrieves unit objects and marks for that specific
 * unit
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


class Result {
public:
  /**
   * @brief Constructor
   * @details Initializes Result with default values
   */
  Result();
  /**
   * @brief  Returns the credit value
   *
   * Returns the credit value stored in the Unit object stored in this class
   * by calling the function "GetCredits" from the Unit class.
   *
   * @return int
   */
  int GetCredits() const;
  /**
   * @brief  Returns a Unit object stored in this class
   *
   *
   *
   * @return Unit
   */
  Unit GetUnit() const;

  /**
   * @brief  Returns the Date object stored in this class
   *
   * I use this to access other function that is a part of the Date class
   *
   * @return Date
   */  
  Date GetDate() const;
  /**
   * @brief  Returns the value of marks stored in this class
   *
   *
   *
   * @return int
   */
  int GetMarks() const;

  /**
   * @brief  Sets a Unit Object into the Unit object stored in this class
   *
   *
   * @param unit - the object to be stored
   * @return void
   */
  void SetUnit(Unit &unit);
  /**
   * @brief  Sets the marks value stored in this class
   *
   *
   * @param marks - the value to be allocated
   * @return void
   */
  void SetMarks(int marks);
    /**
   * @brief  Sets the date value stored in this class
   *
   *
   * @param Date - the value to be allocated
   * @return void
   */
  void SetDate(Date& date);
   /**
   * @brief  converts the three integer parameters into string
   *
   * @param day - the day value to be allocated
   * @param month - the month value to be allocated
   * @param year - the year value to be allocated
   *
   * @return string
   */ 
  string ConvertDate (int day, int month, int year) const;
private:
  /// contains unit details
  Unit m_unit;
  /// contains date details
  Date m_date;
  /// marks
  int m_marks;
};
/// overloading the << operator
ostream &operator<<(ostream &os, const Result &R);
/// overloading the << operator
istream &operator>>(istream &input, Result &R);

#endif
