#ifndef COLLECTION_H
#define COLLECTION_H

#include "Map.h"
#include "SensorRecType.h"

/**
 * @class Collection
 * @brief Class to collect and manage sensor data over time, to be used as the
 * function for a function pointer parameter in the BST class.
 */
class Collection {
public:
  /**
   * @brief Retrieve speed data for a specific year and month.
   * @param data The data map to retrieve speed data from.
   * @param year The year of the data to retrieve.
   * @param month The month of the data to retrieve.
   * @return A map of speed data for the specified year and month.
   */
  Map<int, float> GetSpeedData(const SensorLog &data, const int year,
                               const int month);

  /**
   * @brief Retrieve temperature data for a specific year and month.
   * @param data The data map to retrieve temperature data from.
   * @param year The year of the data to retrieve.
   * @param month The month of the data to retrieve.
   * @return A map of temperature data for the specified year and month.
   */
  Map<int, float> GetTempData(const SensorLog &data, const int year,
                              const int month);

  /**
   * @brief Retrieve solar data for a specific year and month.
   * @param data The data map to retrieve solar data from.
   * @param year The year of the data to retristatic eve.
   * @param month The month of the data to retrieve.
   * @return A map of solar data for the specified year and month.
   */
  Map<int, float> GetSolarData(const SensorLog &data, const int year,
                               const int month);

  /**
   * @brief Retrieve sPCC data for a specific month.
   *
   * This function retrieves the sPCC data from the provided data map
   * for the specified month and fills the output maps with speed,
   * temperature, and solar data.
   *
   * @param data The sensor log data map to retrieve sPCC data from.
   * @param month The month of the data to retrieve (0-11 for January-December).
   * @param speedDataIn Output map to store speed data for the specified month.
   * @param tempDataIn Output map to store temperature data for the specified
   * month.
   * @param solarDataIn Output map to store solar data for the specified month.
   * @return void
   */
  void Get_sPCC_Data(const SensorLog &data, int month,
                     Map<int, float> &speedDataIn, Map<int, float> &tempDataIn,
                     Map<int, float> &solarDataIn);

private:
  static int targetMonth;  ///< The target month for data collection.
  static int targetYear;   ///< The target year for data collection.
  static bool targetFound; ///< Flag indicating if the target data was found.
  static bool dataFound;   ///< Flag indicating if any data was found.

  static Map<int, float> speedData; ///< Map containing speed data.
  static Map<int, float> tempData;  ///< Map containing temperature data.
  static Map<int, float> solarData; ///< Map containing solar data.
  static Map<int, float> sPCCData;  ///< Map containing sPCC data.

  /**
   * @brief Collect speed data from a sensor record.
   * @param record The sensor record to collect data from.
   */
  static void CollectSpeedData(SensorRecType &record);

  /**
   * @brief Collect temperature data from a sensor record.
   * @param record The sensor record to collect data from.
   */
  static void CollectTempData(SensorRecType &record);

  /**
   * @brief Collect solar data from a sensor record.
   * @param record The sensor record to collect data from.
   */
  static void CollectSolarData(SensorRecType &record);

  /**
   * @brief Collect sPCC data from a sensor record.
   * @param record The sensor record to collect data from.
   */
  static void collect_sPCC_data(SensorRecType &record);
};

#endif
