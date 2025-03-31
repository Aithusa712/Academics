#include "Results.h"
#include "Collection.h"
#include "SensorRecType.h"

void Results::DisplayAverageStdevSpeed(const SensorLog &sensor_data, int month,
                                       int year) const {
  Calculator calculate;
  Collection collect;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  Map<int, float> speedData;

  // Condition to check if the month and year contain any data
  if (collect.CheckSpeed(sensor_data, year, month)) {

    // Perform in-order traversal using a custom function
    speedData = collect.GetSpeedData(sensor_data, year, month);

    // Calculate average and standard deviation
    average = calculate.CalculateAverage(speedData);
    standard_deviation =
        calculate.CalculateStandardDeviation(speedData, average);

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
  Collection collect;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  float totalTemp = 0.0f;
  bool dataFound = false;
  Map<int, float> tempData;

  // Loop through the sensor data vector struct to
  // find if there is any data on
  // the year the user entered

  for (int index = 1; index < MAX_MONTHS; index++) {
    int targetMonth = index;
    dataFound = collect.CheckTemp(sensor_data, year, targetMonth);
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

      if (collect.CheckTemp(sensor_data, year, month_index)) {
        tempData = collect.GetTempData(sensor_data, year, month_index);
        // Call functions from the Calculator class
        average = calculate.CalculateAverage(tempData);
        standard_deviation =
            calculate.CalculateStandardDeviation(tempData, average);
        // Print Results
        cout << int_to_month(month_index) << ":"
             << " average: " << average
             << " degrees C, Sample stdev: " << standard_deviation << endl;
      }
      // If the month has no Data
      else {
        cout << int_to_month(month_index) << ": No Data" << endl;
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
  Collection collect;
  float total_solar_radiation = 0;
  bool dataFound = false;
  float totalSolar = 0.0f;
  Map<int, float> solarData;
  // Loop through the sensor data vector struct to find if there is any data on
  // the year the user entered

  for (int index = 1; index < MAX_MONTHS; index++) {
    dataFound = collect.CheckSolar(sensor_data, year, index);
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

      // Loop through all sensor_data elements and insert Solar Radiation data
      // that matches the month and year parameter to float vector

      // Check if there is data for the current month index
      // The "SR" inside the ValidateMonth parameter stands for Solar Radiation

      if (collect.CheckSolar(sensor_data, year, month_index)) {

        solarData = collect.GetSolarData(sensor_data, year, month_index);

        // Call function from the Calculator Class

        total_solar_radiation =
            calculate.CalculateTotalSolarRadiation(solarData);
Map<int, float> sPCC_Data;

        // Print Results

        cout << int_to_month(month_index) << ": " << total_solar_radiation
             << " kWh/m^2 " << endl;
      }
      // If the month has no Data
      else {
        cout << int_to_month(month_index) << ": No Data" << endl;
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
  Collection collect;
  FileHandler handleFile;
  ostringstream output;
  float average_speed = 0.0f;
  float stdev_speed = 0.0f;
  float average_temperature = 0.0f;
  float stdev_temperature = 0.0f;
  float total_solar_radiation = 0.0f;
  float mad_speed = 0.0f;
  float mad_temperature = 0.0f;
  bool dataFound = false;

  Map<int, float> speedData;
  Map<int, float> tempData;
  Map<int, float> solarData;
  Map<int, float> sPCCData;

  // Loop throughtemperature_datatemperature_data the sensor data vector struct
  // to find if there is any data on the year the user entered
  for (int index = 1; index < MAX_MONTHS; index++) {
    dataFound = collect.CheckAll(sensor_data, year, index);

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
      // month_index = the current month to calculate results for

      // empty data counter - if empty data = 0, that means there is no data for
      // the entire month

      int empty_data = 0;

      // Loop through all sensor_data elements and insert all relevant data that
      // matches the month and year parameter to float vector

      speedData = collect.GetSpeedData(sensor_data, year, month_index);
      tempData = collect.GetTempData(sensor_data, year, month_index);
      solarData = collect.GetSolarData(sensor_data, year, month_index);

      // Call functions from the calculate class
      //
      // Average Speed
      average_speed = calculate.CalculateAverage(speedData);
      // Sample Standard Deviation Speed
      stdev_speed =
          calculate.CalculateStandardDeviation(speedData, average_speed);
      // Average Temperature
      average_temperature = calculate.CalculateAverage(tempData);
      // Sample Standard Deviation Temperature
      stdev_temperature =
          calculate.CalculateStandardDeviation(tempData, average_temperature);
      // Total solar Radiation
      total_solar_radiation = calculate.CalculateTotalSolarRadiation(solarData);

      mad_speed = calculate.CalculateMAD(speedData);
      mad_temperature = calculate.CalculateMAD(tempData);

      // Print month name to output stream

      output << int_to_month(month_index);

      // Check if value is empty, if it is add 1 to empty_data, if not print
      // result to output stream

      if (average_speed != 0) {
        output << "," << average_speed;

      } else {
        empty_data++;
      }
      if (stdev_speed != 0) {
        output << "(" << stdev_speed << ", " << mad_speed << ")";
      } else {
        empty_data++;
      }
      if (average_temperature != 0) {
        output << "," << average_temperature;
      } else {
        empty_data++;
      }
      if (stdev_temperature != 0) {
        output << "(" << stdev_temperature << ", " << mad_temperature << ")";
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
void Results::Display_sPCC(const SensorLog &sensor_data,
                           const int month) const {

  Calculator calculate;
  Collection collect;
  Map<int, float> speedData;
  Map<int, float> tempData;
  Map<int, float> solarData;

  Map<int, float> sPCC_Data;
  // Condition to check if the month and year contain any data

  // Perform in-order traversal using a custom function
  collect.Get_sPCC_Data(sensor_data, month, speedData, tempData, solarData);

  // Calculate average and standard deviation

  // Print Results
  cout << int_to_month(month) << endl
       << "S_T: " << calculate.Calculate_sPCC(speedData, tempData) << endl
       << "S_R: " << calculate.Calculate_sPCC(speedData, solarData) << endl
       << "T_R: " << calculate.Calculate_sPCC(tempData, solarData) << endl;
}

string int_to_month(const int month) {
  string month_arr[MAX_MONTHS] = {
      " ",    "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};
  return month_arr[month];
}
