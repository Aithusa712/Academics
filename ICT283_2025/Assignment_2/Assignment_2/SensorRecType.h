#ifndef SENSOR_REC_TYPE_H
#define SENSOR_REC_TYPE_H
#include "Bst.h"
#include "Date.h"
#include "Time.h"
#include <ctime>
/**
 * @brief Structure representing a sensor record with environmental measurements
 */
struct SensorRecType {
  Date date;             /**< Date of the sensor reading */
  Time time;             /**< Time of the sensor reading */
  float speed;           /**< Speed measurement in m/s */
  float temperature;     /**< Temperature measurement in degrees Celsius */
  float solar_radiation; /**< Solar radiation measurement in W/m² */

  bool operator==(const SensorRecType &other) const {
    return date.GetYear() == other.date.GetYear() &&
           date.GetMonth() == other.date.GetMonth() &&
           date.GetDay() == other.date.GetDay() &&
           time.GetHours() == other.time.GetHours() &&
           time.GetMinutes() == other.time.GetMinutes();
  }

  bool operator<(const SensorRecType &other) const {
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

  bool operator>(const SensorRecType &other) const {
    return other < *this; // Utilize < operator
  }
};
/**
 * @brief Vector container for storing sensor records
 * @typedef SensorLog
 * @details Collection of sensor records stored chronologically
 */
typedef Bst<SensorRecType> SensorLog;
#endif
