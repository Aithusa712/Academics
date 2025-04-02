#include "SensorRecType.h"
bool SensorRecType::operator<(const SensorRecType &other) const {

  if (date.GetYear() < other.date.GetYear())
    return true;
  if (date.GetYear() > other.date.GetYear())
    return false;

  if (date.GetMonth() < other.date.GetMonth())
    return true;
  if (date.GetMonth() > other.date.GetMonth())
    return false;

  if (date.GetDay() < other.date.GetDay())
    return true;
  if (date.GetDay() > other.date.GetDay())
    return false;

  if (time.GetHours() < other.time.GetHours())
    return true;
  if (time.GetHours() > other.time.GetHours())
    return false;

  if (time.GetMinutes() < other.time.GetMinutes())
    return true;
  if (time.GetMinutes() > other.time.GetMinutes())
    return false;

  // If needed, extend comparison to other fields
  return false;
}

bool SensorRecType::operator==(const SensorRecType &other) const {
    return date.GetYear() == other.date.GetYear() &&
           date.GetMonth() == other.date.GetMonth() &&
           date.GetDay() == other.date.GetDay() &&
           time.GetHours() == other.time.GetHours() &&
           time.GetMinutes() == other.time.GetMinutes();
  }


  bool SensorRecType::operator>(const SensorRecType &other) const {
    return other < *this; // Utilize < operator
  }
