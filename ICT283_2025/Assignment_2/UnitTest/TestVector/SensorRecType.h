#ifndef SENSOR_REC_TYPE_H
#define SENSOR_REC_TYPE_H
#include "Date.h"
#include "Time.h"
#include "Vector.h"
/**
 * @brief Structure representing a sensor record with environmental measurements
 */
typedef struct {
  Date date;             /**< Date of the sensor reading */
  Time time;             /**< Time of the sensor reading */
  float speed;           /**< Speed measurement in m/s */
  float temperature;     /**< Temperature measurement in degrees Celsius */
  float solar_radiation; /**< Solar radiation measurement in W/m² */
} SensorRecType;

/**
 * @brief Vector container for storing sensor records
 * @typedef SensorLog
 * @details Collection of sensor records stored chronologically
 */
typedef Vector<SensorRecType> SensorLog;
#endif
