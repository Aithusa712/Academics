#include "FileHandler.h"

/*    Write to file, filename and the content to be inserted into the filename
 * is specified by the parameter    */

void FileHandler::writeToFile(const string &filename,
                              const string &content) const {

  // Initialize local variables

  ofstream outputFile;

  // Open file
  outputFile.open(filename);

  // Error handling
  if (!outputFile.is_open()) {
    cerr << "Error: Could not open file '" << filename << "' for writing."
         << endl;
  }

  // Insert content to output file
  outputFile << content;

  // Close file
  outputFile.close();
}

/*    read a file specified in the parameter that contains the name/s of other
 * files and call readCSV to insert data from the file into sensor_data   */

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

/*    Open a file, read each line, parse the line to extract sensor data and
 * push to sensor_data */

void FileHandler::readCSV(const string &filename,
                          SensorLog &sensor_data) const {

  // Initialize local variables
  string token = "";
  string line = "";
  int S_Index = -1;  // Initialize to -1 in case "S" is not found
  int T_Index = -1;  // Initialize to -1 in case "T" is not found
  int SR_Index = -1; // Initialize to -1 in case "SR" is not found
  Map<int,string> mapHeader;

  // Open file

  ifstream file("data/" + filename);

  // Error handling

  if (!file.is_open()) {
    cerr << "Error opening file " << filename << endl;
    return;
  }

  // Get the first line of the file (header) and insert into 'line' (variable)
  getline(file, line);

  istringstream ss(line);
  // Extract the header of the file and push it into a header vector

  while (getline(ss, token, ',')) {
    mapHeader.Insert(mapHeader.Size(), token);
  }

  ss.clear();

  // Loop through the header vector to find the index of a specific sensor

  for (int i = 0; i < mapHeader.Size(); i++) {

    string header = mapHeader[i];
    // S = Speed
    if (header == "S") {
      S_Index = i;
    }
    // T = Temperature
    if (header == "T") {
      T_Index = i;
    }
    // SR = Solar Radiation
    if (header == "SR") {
      SR_Index = i;
    }
  }
  // Go through the remaining lines and extract the sensor data
  while (getline(file, line)) {

    // initialize temporary variables
    istringstream ss(line);
    if (line.empty() || line == "\r" || line == "\n") {
      continue;
    }
    string s_speed = "";
    string s_temperature = "";
    string s_solar_radiation = "";
    string skip = "";
    string sDate = "";
    string sTime = "";
    string sDay = "";
    string sMonth = "";
    string sYear = "";
    string sHour = "";
    string sMinute = "";

    int day = 0;
    int year = 0;
    int month = 0;

    int hours = 0;
    int minutes = 0;

    float f_speed = 0.0f;
    float f_temperature = 0.0f;
    float f_solar_radiation = 0.0f;

    // Loop through all the columns
    for (int i = 0; i < mapHeader.Size(); ++i) {

      // Extract Date and time from wast column

      if (i == 0) {
        getline(ss, sDate, ' ');
        getline(ss, sTime, ',');

        istringstream dateStream(sDate);
        getline(dateStream, sDay, '/');
        getline(dateStream, sMonth, '/');
        getline(dateStream, sYear);

        istringstream timeStream(sTime);
        getline(timeStream, sHour, ':');
        getline(timeStream, sMinute);

      }
      // Extract speed data
      else if (i == S_Index) {
        getline(ss, s_speed, ',');
        if (s_speed.empty()) {
          s_speed = "0";
        }
      }
      // Extract temperature data
      else if (i == T_Index) {
        getline(ss, s_temperature, ',');
        if (s_temperature.empty()) {
          s_temperature = "0";
        }

      }
      // Extract solar radiation data
      else if (i == SR_Index) {
        getline(ss, s_solar_radiation, ',');
        if (s_solar_radiation.empty()) {
          s_solar_radiation = "0";
        }
      }
      // Skip Column
      else {
        getline(ss, skip, ',');
      }
    }

    // convert string to int day, month, year, hours, minutes from wast
    // Format of sDate = DD/MM/YYYY
    // Format of sTime = HH:MM

    day = stoi(sDay);
    month = stoi(sMonth);
    year = stoi(sYear);
    hours = stoi(sHour);
    minutes = stoi(sMinute);

    // convert string to float and check if empty
    // For speed
    if (!s_speed.empty()) {
      f_speed = stof(s_speed);
    } else {
      f_speed = 0.0f;
    }

    // For temperature (use the same pattern)
    if (!s_temperature.empty()) {
      f_temperature = stof(s_temperature);
    } else {
      f_temperature = 0.0f;
    }

    // For solar radiation
    if (!s_solar_radiation.empty()) {
      f_solar_radiation = stof(s_solar_radiation);
    } else {
      f_solar_radiation = 0.0f;
    }

    // Create temporary Date and Time objects

    Date date;
    date.SetDay(day);
    date.SetMonth(month);
    date.SetYear(year);

    Time time;
    time.SetHours(hours);
    time.SetMinutes(minutes);

    // Create temporary SensorRecType struct
    SensorRecType tempData;

    // insert temporary data into the temporary SensorRecType struct
    tempData.date = date;                         // date - object
    tempData.time = time;                         // time - object
    tempData.speed = f_speed;                     // speed - float
    tempData.temperature = f_temperature;         // temperature - float
    tempData.solar_radiation = f_solar_radiation; // solar radiation - float

    // Push temporary struct into Parameter SensorLog BST Struct
    cout << "Pushing data dd/mm/yyyy speed temp solar: " << tempData.date.GetDay() << " " << tempData.date.GetMonth() << " " << tempData.date.GetYear() << " " << tempData.speed << " " << tempData.temperature << " " << tempData.solar_radiation << endl;
    sensor_data.Insert(tempData);
  }

  // Close file
  file.close();
}
