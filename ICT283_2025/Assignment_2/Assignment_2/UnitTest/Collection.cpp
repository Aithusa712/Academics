#include "Collection.h"
int Collection::targetMonth = 0;
int Collection::targetYear = 0;
bool Collection::targetFound = false;
bool Collection::dataFound = false;

Map<int, float> Collection::speedData;
Map<int, float> Collection::tempData;
Map<int, float> Collection::solarData;
Map<int, float> Collection::sPCCData;

static bool dataFound = false; ///< Flag indicating if any data was found.
Map<int, float> Collection::GetSpeedData(const SensorLog &data, const int year,
                                         const int month) {
  speedData.Clear();
  targetYear = year;
  targetMonth = month;
  data.inOrder(CollectSpeedData);
  return speedData;
}

Map<int, float> Collection::GetTempData(const SensorLog &data, const int year,
                                        const int month) {
  tempData.Clear();
  targetYear = year;
  targetMonth = month;
  data.inOrder(CollectTempData);
  return tempData;
}

Map<int, float> Collection::GetSolarData(const SensorLog &data, const int year,
                                         const int month) {
  solarData.Clear();
  targetYear = year;
  targetMonth = month;
  data.inOrder(CollectSolarData);
  return solarData;
}

void Collection::Get_sPCC_Data(const SensorLog &data, int month,
                               Map<int, float> &speedData,
                               Map<int, float> &tempData,
                               Map<int, float> &solarData) {
  this->speedData.Clear();
  this->tempData.Clear();
  this->solarData.Clear();
  targetMonth = month;
  data.inOrder(collect_sPCC_data);
  speedData = this->speedData;
  tempData = this->tempData;
  solarData = this->solarData;
}

void Collection::CollectSpeedData(SensorRecType &record) {
  if (record.date.GetMonth() == targetMonth &&
      record.date.GetYear() == targetYear) {
    speedData.Insert(speedData.Size(), record.speed);
  }
}
void Collection::CollectTempData(SensorRecType &record) {
  if (record.date.GetMonth() == targetMonth &&
      record.date.GetYear() == targetYear) {
    tempData.Insert(tempData.Size(), record.temperature);
  }
}

void Collection::CollectSolarData(SensorRecType &record) {
  if (record.date.GetMonth() == targetMonth &&
      record.date.GetYear() == targetYear) {
    solarData.Insert(solarData.Size(), record.solar_radiation);
  }
}

void Collection::collect_sPCC_data(SensorRecType &record) {
  if (record.date.GetMonth() == targetMonth) {
    speedData.Insert(speedData.Size(), record.speed);
    tempData.Insert(tempData.Size(), record.temperature);
    solarData.Insert(solarData.Size(), record.solar_radiation);
  }
}

bool Collection::CheckSpeed(const SensorLog &data, const int year,
                            const int month) {
  dataFound = false;
  targetYear = year;
  targetMonth = month;
  data.inOrder(CheckSpeedData);
  return dataFound;
}

bool Collection::CheckTemp(const SensorLog &data, const int year,
                           const int month) {
  dataFound = false;
  targetYear = year;
  targetMonth = month;
  ;
  data.inOrder(CheckTempData);
  return dataFound;
}

bool Collection::CheckSolar(const SensorLog &data, const int year,
                            const int month) {
  dataFound = false;
  targetYear = year;
  targetMonth = month;
  data.inOrder(CheckSolarData);
  return dataFound;
}

bool Collection::CheckAll(const SensorLog &data, const int year,
                          const int month) {
  dataFound = false;
  targetYear = year;
  targetMonth = month;
  data.inOrder(CheckAllData);
  return dataFound;
}

void Collection::CheckSpeedData(SensorRecType &record) {
  if (record.date.GetMonth() == targetMonth &&
      record.date.GetYear() == targetYear && record.speed != 0) {
    dataFound = true;
  }
}

void Collection::CheckTempData(SensorRecType &record) {
  if (record.date.GetMonth() == targetMonth &&
      record.date.GetYear() == targetYear && record.temperature != 0) {
    dataFound = true;
  }
}

void Collection::CheckSolarData(SensorRecType &record) {
  if (record.date.GetMonth() == targetMonth &&
      record.date.GetYear() == targetYear && record.solar_radiation != 0) {
    dataFound = true;
  }
}

void Collection::CheckAllData(SensorRecType &record) {
  if (record.date.GetYear() == targetYear &&
      record.date.GetMonth() == targetMonth &&
      (record.speed != 0 || record.temperature != 0 ||
       record.solar_radiation != 0)) {
    dataFound = true;
  }
}
