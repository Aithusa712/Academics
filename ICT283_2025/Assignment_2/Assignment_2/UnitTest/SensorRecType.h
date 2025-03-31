#ifndef SENSOR_REC_TYPE_H
#define SENSOR_REC_TYPE_H
#include "Bst.h"
#include "Date.h"
#include "Time.h"
/**
 * @brief Structure representing a sensor record with environmental measurements
 */
struct SensorRecType {
  Date date;             /**< Date of the sensor reading */
  Time time;             /**< Time of the sensor reading */
  float speed;           /**< Speed measurement in m/s */
  float temperature;     /**< Temperature measurement in degrees Celsius */
  float solar_radiation; /**< Solar radiation measurement in W/m² */
  
  /**
   * @brief Equality operator for SensorRecType.
   * 
   * This operator checks if the current SensorRecType instance is
   * equal to another SensorRecType instance.
   *
   * @param other The SensorRecType instance to compare against.
   * @return true if both SensorRecType instances are equal, false otherwise.
   */ 
  bool operator==(const SensorRecType &other) const;

  /**
   * @brief Less-than operator for SensorRecType.
   * 
   * This operator checks if the current SensorRecType instance is
   * less than another SensorRecType instance.
   *
   * @param other The SensorRecType instance to compare against.
   * @return true if the current instance is less than the other, false otherwise.
   */ 
  bool operator<(const SensorRecType &other) const;

  /**
   * @brief Greater-than operator for SensorRecType.
   * 
   * This operator checks if the current SensorRecType instance is
   * greater than another SensorRecType instance.
   *
   * @param other The SensorRecType instance to compare against.
   * @return true if the current instance is greater than the other, false otherwise.
   */ 
  bool operator>(const SensorRecType &other) const;
};


/**
 * @brief Binary Search Tree container for storing sensor records
 * @typedef SensorLog
 * @details Collection of sensor records stored chronologically
 */
typedef Bst<SensorRecType> SensorLog;
#endif 
