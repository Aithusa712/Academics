#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Date.h"
#include "Time.h"
#include "WindRecType.h"
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
  void readCSV(const string &filename, WindLogType &wind_data) {
    ifstream file(filename);
    // error handling
    if (!file.is_open()) {
      cerr << "Error opening file " << filename << endl;
      return;
    }
    string token = "";
    string line = "";
    getline(file, line);
    int sIndex = -1; // Initialize to -1 in case "S" is not found
    Vector<string> vecHeader;

    istringstream ss(line);

    /*int ctest = 0;*/

    //  TODO:  Check if running a unix format csv file in windows causes any
    //  issues
    while (getline(ss, token, ',')) {
      vecHeader.push(token);

      /*cout*/
      /*    << "Header" << ctest << " = [" << token << "]"*/
      /*    << endl; // TODO: Remove this line and use a unit testing file
       * instead*/
      /*ctest++;*/
    }

    ss.clear();

    for (int i = 0; i < vecHeader.size(); i++) {

      string header = vecHeader[i];
      if (header == "S") {
        sIndex = i;
        break;
      }
    }

    while (getline(file, line)) {
      stringstream ss(line);
      string s_speed = "";
      string skip = "";
      string sDate = "";
      string sTime = "";
      int day = 0;
      int year = 0;
      int month = 0;
      int hours = 0;
      int minutes = 0;
      float speed = 0.0f;

      // Extract Date and time from wast column

      // Extract Speed from wast column

      for (int i = 0; i < vecHeader.size(); ++i) {
        if (i == 0) {
          getline(ss, sDate, ' ');
          getline(ss, sTime, ',');
        } else if (i == sIndex) {
          getline(ss, s_speed, ',');
        } else {
          getline(ss, skip, ',');
        }
      }

      // convert string and split day, month, year, hours, minutes from wast
      day = stoi(sDate.substr(0, 2));
      month = stoi(sDate.substr(3, 2));
      year = stoi(sDate.substr(6, 4));
      hours = stoi(sTime.substr(0, 2));
      minutes = stoi(sTime.substr(3, 2));

      // convert string to float for speed
      speed = stof(s_speed);

      // Create temporary Date and Time objects to be stored into the struct
      // later
      //
      Date date;
      date.SetDay(day);
      date.SetMonth(month);
      date.SetYear(year);

      Time time;
      time.SetHours(hours);
      time.SetMinutes(minutes);

      // Create temporary WindRecType to store object and push to wind_data
      WindRecType tempData;
      tempData.date = date;
      tempData.time = time;
      tempData.speed = speed;
      wind_data.push(tempData);
    }

    file.close();
  }

private:
};

#endif
