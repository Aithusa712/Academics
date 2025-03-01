#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Date.h"
#include "SensorRecType.h"
#include "Time.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
/**
 * @class FileHandler
 * @brief Handles file operations for sensor data including reading source
 * files, CSV parsing, and writing output
 *
 * @author Kim Andrew Dela Cruz
 * @version 01
 * @date 16/02/2025 Kim Andrew Dela Cruz
 */

class FileHandler {

public:
  /**
   * @brief reads a source file containing a list of csv filenames
   * @param filename the path to the source file to read
   * @param sensor_data reference to a sensorlog object where the parsed data
   * will be stored
   * @throws output error message to cerr if file cannot be opened
   */

  void readSource(const string &filename, SensorLog &sensor_data) const;
  /**
   * @brief Reads and parses a CSV file containing sensor measurements
   * @param filename The name of the CSV file to read (will be prefixed with
   * "data/")
   * @param sensor_data Reference to a SensorLog object where the data will be
   * stored
   * @details Parses CSV files with headers including "S" (speed), "T"
   * (temperature), and "SR" (solar radiation) along with timestamp information.
   * Data is stored as SensorRecType objects.
   * @throws output error message to cerr if file cannot be opened
   */

  void readCSV(const string &filename, SensorLog &sensor_data) const;
  /**
   * @brief Writes content to a specified file
   * @param filename The path to the file where content will be written
   * @param content The string content to write to the file
   * @throws May output error message to cerr if file cannot be opened for
   * writing
   */

  void writeToFile(const string &filename, const string &content) const;
};

#endif
