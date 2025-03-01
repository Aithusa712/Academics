#ifndef SENSOR_REC_TYPE_H
#define SENSOR_REC_TYPE_H
#include "Date.h"
#include "Time.h"
#include "Vector.h"

typedef struct {
  Date date;
  Time time;
  float speed;
  float temperature;
  float solar_radiation;
} SensorRecType;

typedef Vector<SensorRecType> SensorLog;
#endif
