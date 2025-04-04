#include "Results.h"
#include "Vector.h"

void Results::DisplayAverageStdevSpeed(const SensorLog &sensor_data,
                                       const int month, const int year) const {

  Calculator calculate;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  Vector<float> data;

  // Condition to check if the month and year contains any data, if it does,
  // calculate and prompt results
  // The "S" in the ValidateMonth parameter stands for Speed
  if (ValidateMonth(sensor_data, month, year, "S")) {

    // Loop through all sensor_data elements and insert Speed data that matches
    // the month and year parameter to float vector
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year) {
        data.push(sensor_data[index].speed);
      }
    }

    // Call functions from the Calculator class
    average = calculate.AverageSpeed(data);
    standard_deviation = calculate.StdDevSpeed(data, average);

    // Print Results
    cout << int_to_month(month) << " " << year << ":" << endl
         << "Average Speed: " << average << "km/h" << endl
         << "Sample stdev: " << standard_deviation << endl;
  }
  // If no data is found
  else {
    cout << int_to_month(month) << " " << year << ": No Data" << endl;
  }
}

void Results::DisplayAverageStdevTemperature(const SensorLog &sensor_data,
                                             const int year) const {

  Calculator calculate;

  float average = 0.0f;
  float standard_deviation = 0.0f;
  int month = 0;
  bool month_exist = false;
  Vector<float> data;
  // Loop through the sensor data vector struct to
  // find if there is any data on
  // the year the user entered

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year) {
      month_exist = true;
      break;
    }
  }

  // If month exist for that year

  if (month_exist) {

    // Print the year
    cout << endl << year << ": " << endl;

    // Loop through all the months of a year
    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {
      // Clear Data after each month
      data.Clear();

      // month_index = the month to be validated
      month = month_index;

      // Loop through all sensor_data elements and insert Temperature data that
      // matches the month and year parameter to float vector
      for (int index = 0; index < sensor_data.size(); index++) {
        if (sensor_data[index].date.GetMonth() == month &&
            sensor_data[index].date.GetYear() == year) {
          data.push(sensor_data[index].temperature);
        }
      }

      // Check if there is data for the current month index
      // The "T" inside the ValidateMonth parameter stands for temperature

      if (ValidateMonth(sensor_data, month, year, "T")) {

        // Call functions from the Calculator class
        average = calculate.AverageTemperature(data);
        standard_deviation = calculate.StdDevTemperature(data, average);
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
  Vector<float> data;
  bool month_exist = false;
  // Loop through the sensor data vector struct to find if there is any data on
  // the year the user entered

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year) {
      month_exist = true;
      break;
    }
  }

  // If month exists for that year

  if (month_exist) {

    // Print the year
    cout << endl << year << ": " << endl;

    // Loop through all the months
    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {

      // Clear data after each month
      data.Clear();

      // month_index = the month to be validated

      month = month_index;

      // Loop through all sensor_data elements and insert Solar Radiation data
      // that matches the month and year parameter to float vector

      for (int index = 0; index < sensor_data.size(); index++) {
        if (sensor_data[index].date.GetMonth() == month &&
            sensor_data[index].date.GetYear() == year) {
          data.push(sensor_data[index].solar_radiation);
        }
      }
      // Check if there is data for the current month index
      // The "SR" inside the ValidateMonth parameter stands for Solar Radiation

      if (ValidateMonth(sensor_data, month, year, "SR")) {

        // Call function from the Calculator Class

        total_solar_radiation = calculate.TotalSolarRadiation(data);

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
  Vector<float> speed_data;
  Vector<float> temperature_data;
  Vector<float> solar_radiation_data;

  // Loop through the sensor data vector struct to find if there is any data on
  // the year the user entered
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year) {
      month_exist = true;
    }
  }

  // Check if there is data for the current month index
  // The "SR" inside the ValidateMonth parameter stands for Solar Radiation

  if (month_exist) {

    // Print year to output stream

    output << year << ": " << endl;

    // Loop through all the months

    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {
      // Clear Vector data after each month
      speed_data.Clear();
      temperature_data.Clear();
      solar_radiation_data.Clear();

      // month_index = the current month to calculate results for

      month = month_index;

      // empty data counter - if empty data = 0, that means there is no data for
      // the entire month

      int empty_data = 0;

      // Loop through all sensor_data elements and insert all relevant data that
      // matches the month and year parameter to float vector

      for (int index = 0; index < sensor_data.size(); index++) {
        if (sensor_data[index].date.GetMonth() == month &&
            sensor_data[index].date.GetYear() == year) {
          speed_data.push(sensor_data[index].speed);
          temperature_data.push(sensor_data[index].temperature);
          solar_radiation_data.push(sensor_data[index].solar_radiation);
        }
      }
      // Call functions from the calculate class

      // Average Speed
      average_speed = calculate.AverageSpeed(speed_data);
      // Sample Standard Deviation Speed
      stdev_speed = calculate.StdDevSpeed(speed_data, average_speed);
      // Average Temperature
      average_temperature = calculate.AverageTemperature(temperature_data);
      // Sample Standard Deviation Temperature
      stdev_temperature =
          calculate.StdDevTemperature(temperature_data, average_temperature);
      // Total solar Radiation
      total_solar_radiation =
          calculate.TotalSolarRadiation(solar_radiation_data);

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

bool Results::ValidateMonth(const SensorLog &sensor_data, const int month,
                            const int year, const string sensor_type) const {

  // Check which sensor_type was given in the parameter
  // S for Speed
  // T for Temperature
  // SR for Solar Radiation

  if (sensor_type == "S") {
    // Loop through all sensor records and return true if a speed record exists
    // for the year and month that was given in the parameter
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year &&
          sensor_data[index].speed != 0) {
        return true;
      }
    }
  }
  if (sensor_type == "T") {
    // Loop through all sensor records and return true if a temperature record
    // exists for the year and month that was given in the parameter
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year &&
          sensor_data[index].temperature != 0) {
        return true;
      }
    }
  }
  if (sensor_type == "SR") {
    // Loop through all sensor records and return true if a Solar Radiation
    // record exists for the year and month that was given in the parameter
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year &&
          sensor_data[index].solar_radiation != 0) {
        return true;
      }
    }
  }
  // Else return false
  return false;
}

string int_to_month(const int month) {
  string month_arr[MAX_MONTHS] = {
      " ",    "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};
  return month_arr[month];
}
