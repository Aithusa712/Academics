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
  //  NOTE:  When running in a linux or unix based environment make sure file
  //  format of the csv file is set to unix
  //         else it will retrieve the '\r'

  //  TODO:  Remove the trim function if converting csv files into UNIX format
  //  does not cause any issue in windows

  string trim(const std::string &input) {

    string result;
    for (char c : input) {
      if (c != '\r' && c != '\t' && c != '\n') {
        result += c;
      }
    }
    return result;
  }
  void readSource(const string &filename, SensorLog &sensor_data);
  void readCSV(const string &filename, SensorLog &sensor_data);
};

#endif
