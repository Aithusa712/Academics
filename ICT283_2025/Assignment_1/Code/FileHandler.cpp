#include "FileHandler.h"

void FileHandler::writeToFile(const string &filename,
                              const string &content) const {
  ofstream outputFile;

  outputFile.open(filename);

  if (!outputFile.is_open()) {
    cerr << "Error: Could not open file '" << filename << "' for writing."
         << endl;
  }

  outputFile << content;

  outputFile.close();
}

void FileHandler::readSource(const string &filename,
                             SensorLog &sensor_data) const {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error Opening file " << filename << endl;
  }
  string temp_name;
  while (getline(file, temp_name)) {
    readCSV(temp_name, sensor_data);
  }
}

void FileHandler::readCSV(const string &filename,
                          SensorLog &sensor_data) const {
  ifstream file("data/" + filename);
  // error handling
  if (!file.is_open()) {
    cerr << "Error opening file " << filename << endl;
    return;
  }
  string token = "";
  string line = "";
  getline(file, line);
  int S_Index = -1;  // Initialize to -1 in case "S" is not found
  int T_Index = -1;  // Initialize to -1 in case "S" is not found
  int SR_Index = -1; // Initialize to -1 in case "S" is not found

  Vector<string> vecHeader;

  istringstream ss(line);

  //  TODO:  Check if running a unix file format csv file in windows causes
  //  any issues
  while (getline(ss, token, ',')) {
    vecHeader.push(token);
  }

  ss.clear();

  for (int i = 0; i < vecHeader.size(); i++) {

    string header = vecHeader[i];
    if (header == "S") {
      S_Index = i;
    }
    if (header == "T") {
      T_Index = i;
    }
    if (header == "SR") {
      SR_Index = i;
    }
  }

  while (getline(file, line)) {
    stringstream ss(line);
    string s_speed = "";
    string s_temperature = "";
    string s_solar_radiation = "";
    string skip = "";
    string sDate = "";
    string sTime = "";
    int day = 0;
    int year = 0;
    int month = 0;
    int hours = 0;
    int minutes = 0;
    float f_speed = 0.0f;
    float f_temperature = 0.0f;
    float f_solar_radiation = 0.0f;

    // Extract Date and time from wast column

    // Extract Speed from wast column

    for (int i = 0; i < vecHeader.size(); ++i) {
      if (i == 0) {
        getline(ss, sDate, ' ');
        getline(ss, sTime, ',');
      } else if (i == S_Index) {
        getline(ss, s_speed, ',');

      } else if (i == T_Index) {
        getline(ss, s_temperature, ',');
      } else if (i == SR_Index) {
        getline(ss, s_solar_radiation, ',');
      }

      else {
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
    f_speed = stof(s_speed);
    f_temperature = stof(s_temperature);
    f_solar_radiation = stof(s_solar_radiation);
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

    // Create temporary WindRecType to store object and push to sensor_data
    SensorRecType tempData;
    tempData.date = date;
    tempData.time = time;
    tempData.speed = f_speed;
    tempData.temperature = f_temperature;
    tempData.solar_radiation = f_solar_radiation;
    sensor_data.push(tempData);
  }

  file.close();
}
