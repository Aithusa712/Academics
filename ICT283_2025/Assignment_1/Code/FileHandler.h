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

class FileHandler {

public:
  void readSource(const string &filename, SensorLog &sensor_data) const;
  void readCSV(const string &filename, SensorLog &sensor_data) const;
  void writeToFile(const string &filename, const string &content) const;
};

#endif
