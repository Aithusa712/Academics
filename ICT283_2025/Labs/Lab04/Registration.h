#ifndef REGISTRATION_H
#define REGISTRATION_H

#include "Result.h"
#include <iostream>

using namespace std;

/**
 * @class Registration
 * @brief  Contain student details and results for all unit
 *
 * Registration stores and retrieves student Id, semester, number of units the
 * student have, and an Array of Results which contains a Unit details and marks
 * for that unit.
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
 */

const int MaxResults = 10;

class Registration {
public:
  Registration();
  /**
   * @brief  Returns the sum of credits from each Unit object from the Array of
   * Result object
   *
   *
   *
   * @return int
   */
  int GetCredits() const;
  /**
   * @brief  Returns the value of studentId stored in this class
   *
   *
   *
   * @return long
   */
  long GetStudentId() const;
  /**
   * @brief  Returns the value of semester stored in this class
   *
   *
   *
   * @return int
   */
  int GetSemester() const;
  /**
   * @brief  Returns the value of count stored in this class
   *
   *
   * @return int
   */
  int GetCount() const;
  /**
   * @brief  Returns a Result object
   * Returns a targeted (idx parameter) Result object from an Array of Result
   *
   * @param idx - the index number of a Result Array to return
   * @return Result
   */
  Result GetResult(int idx) const;

  /**
   * @brief  Allocate a Result object into the target index of a Result Object
   * Array inside this class
   *
   *
   * @param idx - index number of a Result Array to allocate values
   * @param res - Result object to allocate into the target Result Object Array
   * index
   * @return void
   */
  void SetResult(int idx, Result &res);
  /**
   * @brief  Set the count value stored in this class
   *
   *
   * @param count - the value to be allocated
   * @return void
   */
  void SetCount(int count);
  /**
   * @brief  Set the semester value stored in this class
   *
   *
   *
   * @param semester - the value to be allocated
   * @return void
   */
  void SetSemester(int semester);
  /**
   * @brief  Set the studentId value stored in this class
   *
   * @param studentId - the value to be allocated
   * @return void
   */
  void SetStudentId(long studentId);

private:
  /// student ID number
  long m_studentId;
  /// semester year
  int m_semester;
  /// number of units
  int m_count;
  /// array of Results
  Result m_result[MaxResults];
};
/// overloading the << operator
ostream &operator<<(ostream &os, const Registration &registration);
/// overloading the >> operator
istream &operator>>(istream &input, Registration &registration);
#endif
