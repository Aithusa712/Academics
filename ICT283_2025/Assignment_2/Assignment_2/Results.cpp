#include "Results.h"
#include "SensorRecType.h"
int Results::targetMonth = 0;
int Results::targetYear = 0;
bool Results::targetFound = false;

Vector<float> Results::speedData;
Vector<float> Results::tempData;
Vector<float> Results::solarData;

bool Results::dataFound = false;


void Results::CollectSpeedData(SensorRecType &record) {
    if (record.date.GetMonth() == targetMonth &&
        record.date.GetYear() == targetYear) {
      speedData.push(record.speed);
    }
  }
void Results::CollectTempData(SensorRecType &record) {
    if (record.date.GetMonth() == targetMonth &&
        record.date.GetYear() == targetYear) {
      tempData.push(record.temperature);
    }
  }

  void Results::CollectSolarData(SensorRecType &record) {
    if (record.date.GetMonth() == targetMonth &&
        record.date.GetYear() == targetYear) {
      solarData.push(record.solar_radiation);
    }
  }

  void Results::CollectAllData(SensorRecType &record) {
    if (record.date.GetMonth() == targetMonth &&
        record.date.GetYear() == targetYear) {
      speedData.push(record.speed);
      tempData.push(record.temperature);
      solarData.push(record.solar_radiation);
    }
  }
  void Results::CheckSpeed(SensorRecType &record) {
    if (record.date.GetMonth() == targetMonth &&
        record.date.GetYear() == targetYear && record.speed != 0) {
      dataFound = true;
    }
  }

  void Results::CheckTemp(SensorRecType &record) {
    if (record.date.GetMonth() == targetMonth &&
        record.date.GetYear() == targetYear && record.temperature != 0) {
      dataFound = true;
    }
  }

  void Results::CheckSolar(SensorRecType &record) {
    if (record.date.GetMonth() == targetMonth &&
        record.date.GetYear() == targetYear && record.solar_radiation != 0) {
      dataFound = true;
    }
  }

  void Results::CheckAll(SensorRecType &record) {
    if (record.date.GetYear() == targetYear &&
        record.date.GetMonth() == targetMonth &&
        (record.speed != 0 || record.temperature != 0 ||
         record.solar_radiation != 0)) {
      dataFound = true;
    }
  }


void GetMonthlyData(const SensorLog &sensor_data, const int month,
                    const int day) {}

void Results::DisplayAverageStdevSpeed(const SensorLog &sensor_data,
                                       const int month, const int year) const {
  Calculator calculate;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  speedData.Clear();
  targetMonth = month;
  targetYear = year;
  dataFound = false;

  sensor_data.printInOrder(CheckSpeed);

  // Condition to check if the month and year contain any data
  if (dataFound) {

    // Perform in-order traversal using a custom function
    sensor_data.printInOrder(CollectSpeedData);

    // Calculate average and standard deviation
    average = calculate.AverageSpeed(speedData);
    standard_deviation = calculate.StdDevSpeed(speedData, average);

    // Print Results
    cout << int_to_month(month) << " " << year << ":" << std::endl
         << "Average Speed: " << average << " km/h" << std::endl
         << "Sample stdev: " << standard_deviation << std::endl;
  } else {
    // If no data is found
    cout << int_to_month(month) << " " << year << ": No Data" << std::endl;
  }
}

void Results::DisplayAverageStdevTemperature(const SensorLog &sensor_data,
                                             const int year) const {

  Calculator calculate;

  float average = 0.0f;
  float standard_deviation = 0.0f;
  float totalTemp = 0.0f;
  int month = 0;
  tempData.Clear();
  targetYear = year;
  dataFound = false;
  // Loop through the sensor data vector struct to
  // find if there is any data on
  // the year the user entered

  for (int index = 1; index < MAX_MONTHS; index++) {
    targetMonth = index;
    sensor_data.printInOrder(CheckTemp);
    if (dataFound) {
      break;
    }
  }
  // If month exist for that year

  if (dataFound) {
    // Print the year
    cout << endl << year << ": " << endl;

    // Loop through all the months of a year
    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {
      // Clear Data after each month
      tempData.Clear();
      dataFound = false;
      // month_index = the month to be validated
      month = month_index;
      targetMonth = month_index;
      // Loop through all sensor_data elements and insert Temperature data that
      // matches the month and year parameter to float vector
      sensor_data.printInOrder(CheckTemp);

      // Check if there is data for the current month index
      // The "T" inside the ValidateMonth parameter stands for temperature

      if (dataFound) {
        sensor_data.printInOrder(CollectTempData);
        // Call functions from the Calculator class
        average = calculate.AverageTemperature(tempData);
        standard_deviation = calculate.StdDevTemperature(tempData, average);
        // Print Results
        cout << int_to_month(month) << ":"
             << " average: " << average
             << " degrees C, Sample stdev: " << standard_deviation << endl;
      }
      // If the month has no Data
      else {
        cout << int_to_month(month) << ": No Data" << endl;
      }
    }
  }
  // If entire year has no Data
  else {
    cout << year << ": No data";
  }
}

void Results::DisplayTotalSolarRadiation(const SensorLog &sensor_data,
                                         const int year) const {

  Calculator calculate;
  int month = 0;
  float total_solar_radiation = 0;
  bool month_exist = false;
  float totalSolar = 0.0f;
  targetMonth = 0;
  targetYear = year;
  solarData.Clear();
  dataFound = false;
  // Loop through the sensor data vector struct to find if there is any data on
  // the year the user entered

  for (int index = 1; index < MAX_MONTHS; index++) {
    targetMonth = index;
    sensor_data.printInOrder(CheckSolar);
    if (dataFound) {
      break;
    }
  }

  // If month exists for that year

  if (dataFound) {

    // Print the year
    cout << endl << year << ": " << endl;

    // Loop through all the months
    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {

      // month_index = the month to be validated

      month = month_index;
      targetMonth = month;
      solarData.Clear();
      dataFound = false;
      // Loop through all sensor_data elements and insert Solar Radiation data
      // that matches the month and year parameter to float vector

      sensor_data.printInOrder(CheckSolar);

      // Check if there is data for the current month index
      // The "SR" inside the ValidateMonth parameter stands for Solar Radiation

      if (dataFound) {

        sensor_data.printInOrder(CollectSolarData);
        // Call function from the Calculator Class

        total_solar_radiation = calculate.TotalSolarRadiation(solarData);

        // Print Results

        cout << int_to_month(month) << ": " << total_solar_radiation
             << " kWh/m^2 " << endl;
      }
      // If the month has no Data
      else {
        cout << int_to_month(month) << ": No Data" << endl;
      }
    }
  }
  // If the entire year has no Data
  else {
    cout << year << ": No data";
  }
}

void Results::PrintAll(const SensorLog &sensor_data, const int year) const {

  Calculator calculate;
  FileHandler handleFile;
  ostringstream output;
  float average_speed = 0.0f;
  float stdev_speed = 0.0f;
  float average_temperature = 0.0f;
  float stdev_temperature = 0.0f;
  float total_solar_radiation = 0.0f;
  int month = 0;
  bool month_exist = false;
  targetMonth = 0;
  targetYear = year;
  speedData.Clear();
  tempData.Clear();
  solarData.Clear();
  dataFound = false;

  // Loop throughtemperature_datatemperature_data the sensor data vector struct
  // to find if there is any data on the year the user entered
  for (int index = 1; index < MAX_MONTHS; index++) {
    targetMonth = index;
    sensor_data.printInOrder(CheckAll);

    if (dataFound) {
      break;
    }
  }

  // Check if there is data for the current month index
  // The "SR" inside the ValidateMonth parameter stands for Solar Radiation

  if (dataFound) {
    // Print year to output stream
    output << year << ": " << endl;

    // Loop through all the months

    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {
      // Clear Vector data after each month
      speedData.Clear();
      tempData.Clear();
      solarData.Clear();

      // month_index = the current month to calculate results for
      month = month_index;
      targetMonth = month;

      // empty data counter - if empty data = 0, that means there is no data for
      // the entire month

      int empty_data = 0;

      // Loop through all sensor_data elements and insert all relevant data that
      // matches the month and year parameter to float vector

      sensor_data.printInOrder(CollectAllData);

      // Call functions from the calculate class

      // Average Speed
      average_speed = calculate.AverageSpeed(speedData);
      // Sample Standard Deviation Speed
      stdev_speed = calculate.StdDevSpeed(speedData, average_speed);
      // Average Temperature
      average_temperature = calculate.AverageTemperature(tempData);
      // Sample Standard Deviation Temperature
      stdev_temperature =
          calculate.StdDevTemperature(tempData, average_temperature);
      // Total solar Radiation
      total_solar_radiation = calculate.TotalSolarRadiation(solarData);

      // Print month name to output stream

      output << int_to_month(month);

      // Check if value is empty, if it is add 1 to empty_data, if not print
      // result to output stream

      if (average_speed != 0) {
        output << "," << average_speed;

      } else {
        empty_data++;
      }
      if (stdev_speed != 0) {
        output << "(" << stdev_speed << ")";
      } else {
        empty_data++;
      }
      if (average_temperature != 0) {
        output << "," << average_temperature;
      } else {
        empty_data++;
      }
      if (stdev_temperature != 0) {
        output << "(" << stdev_temperature << ")";
      } else {
        empty_data++;
      }
      if (total_solar_radiation != 0) {
        output << "," << total_solar_radiation;
      } else {
        empty_data++;
      }
      // If empty data is equal to 5 that means there is no data available
      if (empty_data == 5) {
        output << ": No Data";
      }

      output << endl;
    }
  }

  // Call FileHandler class, send the filename to insert the output stream into

  handleFile.writeToFile("WindTempSolar.csv", output.str());
}

string int_to_month(const int month) {
  string month_arr[MAX_MONTHS] = {
      " ",    "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};
  return month_arr[month];
}
