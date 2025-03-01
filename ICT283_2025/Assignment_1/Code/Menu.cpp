#include "Menu.h"
#include "Calculator.h"
#include "FileHandler.h"
#include "SensorRecType.h"
#include <sstream>

// Prompt Menu prompt and handles all handle functions
void Menu::prompt(const SensorLog &sensor_data, bool &exit) const {

  // Initialize local variables
  string choice_string = "";
  int choice = 0;
  bool valid_choice = false;

  // While loop to validate correct user input
  while (!valid_choice) {

    // The prompt to be prompted
    cout << endl;
    cout << "\n1. The average wind speed and sample standard deviation for "
            "this\n"
            "wind speed given a specified month and year. (print on screen "
            "only)\n"
         << endl
         << "2. Average ambient air temperature and sample standard deviation\n"
            "for each month of a specified year. (print on screen only)\n"
         << endl
         << "3.Total solar radiation in kWh/m^2 for each month of a specified\n"
            "year. (print on screen only)\n"
         << endl
         << "4. Average wind speed(km/h), average ambient air temperature and\n"
            "total solar radiation in kWh/m^2 for each month of a specified\n"
            "year. The solar deviation is printed in () next to the average.\n"
            "(print to a file called 'WindTempSolar.csv')\n"
         << endl
         << "5. Exit. \n"
         << endl
         << "Input:";

    cin >> choice_string;

    // Try catch to catch any invalid user input such range or non-numerical
    // string
    try {
      // Check if the input the user entered contains any non digit, if yes,
      // throw choice_string (string).
      for (char c : choice_string) {
        if (!isdigit(c)) {
          throw choice_string;
        }
      }
      // If no exception has been thrown, convert the string into integer.
      choice = stoi(choice_string);

      // The condition checks if the user input is within range [1-5], if yes,
      // throw choice (integer), else assign valid_choice as 'true' to exit
      // loop.
      if (choice < 1 || choice > 5) {
        throw choice;
      } else {
        valid_choice = true;
      }
    }
    // Catch any thrown string
    catch (const string &error) {
      cout << "Error: Please enter a valid numerical number\n\n" << endl;
      cin.clear();
    }
    // Catch any thrown integer
    catch (const int &out_of_range) {
      cout << "Please enter a valid option [1-5]." << endl;
    }
  }

  // Switch case to Call a function the User has chosen.

  switch (choice) {
  case 1:
    HandleMonthlySpeed(sensor_data);
    break;
  case 2:
    HandleMonthlyTemperature(sensor_data);
    break;
  case 3:
    HandleMonthlySolarRadiation(sensor_data);
    break;
  case 4:
    HandleAllData(sensor_data);
    break;
  case 5:
    // exit is a parameter, if true, the while loop in main.cpp will break.
    exit = true;
    break;
  }
}

// Handles the Monthly speed prompt
void Menu::HandleMonthlySpeed(const SensorLog &sensor_data) const {

  // Initialize local variables

  Calculator calculate;
  string month = "";
  int month_int = 0;
  int year_int = 0;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  bool valid_month = false;

  // While loop to validate user input for month
  while (!valid_month) {

    // Prompt user for month

    cout << "Enter Month: ";
    cin >> month;

    // Try catch to check if user input is a valid month
    // if month_to_int returns 0, the month the user input is misspelled or not
    // a month, in that case, throw valid_month(bool).

    try {
      if (month_to_int(month) == 0) {
        throw valid_month;
      }
      // assign valid_month as true to exit the loop
      else {
        valid_month = true;
      }

    }
    // Catch if any bool is thrown
    catch (bool &error) {

      cout << "\nInvalid Month" << endl;
    }
  }

  // Call month_to_int routine to convert user's string month into an integer
  // (the month's index, starting from 1)

  month_int = month_to_int(month);

  // Call GetValidYear routine to prompt a user for a Year and validate if its a
  // numerical string or out of range

  year_int = GetValidYear();

  // Condition to check if the month and year contains any data, if it does,
  // calculate and prompt results
  if (ValidateMonth(sensor_data, month_int, year_int, "S")) {

    average = calculate.AverageSpeed(sensor_data, month_int, year_int);
    standard_deviation =
        calculate.StdDevSpeed(sensor_data, average, month_int, year_int);
    cout << month << " " << year_int << ":" << endl
         << "Average Speed: " << average << "km/h" << endl
         << "Sample stdev: " << standard_deviation << endl;
  }
  // If no data is found
  else {
    cout << month << " " << year_int << ": No Data" << endl;
  }
}

void Menu::HandleMonthlyTemperature(const SensorLog &sensor_data) const {
  Calculator calculate;
  int month_int = 0;
  int year_int = 0;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  bool month_exist = false;
  year_int = GetValidYear();

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year_int) {
      month_exist = true;
      break;
    }
  }
  if (month_exist) {
    cout << endl << year_int << ": " << endl;
    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {
      month_int = month_index;
      if (ValidateMonth(sensor_data, month_int, year_int, "T")) {
        average =
            calculate.AverageTemperature(sensor_data, month_int, year_int);
        standard_deviation = calculate.StdDevTemperature(sensor_data, average,
                                                         month_int, year_int);

        cout << int_to_month(month_int) << ":"
             << " average: " << average
             << " degrees C, Sample stdev: " << standard_deviation << endl;
      } else {
        cout << int_to_month(month_int) << ": No Data" << endl;
      }
    }
  } else {
    cout << year_int << ": No data";
  }
}

void Menu::HandleMonthlySolarRadiation(const SensorLog &sensor_data) const {
  Calculator calculate;
  int month_int = 0;
  int year_int = 0;
  bool month_exist = false;
  float total_solar_radiation = 0;

  year_int = GetValidYear();
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year_int) {
      month_exist = true;
      break;
    }
  }
  if (month_exist) {
    cout << endl << year_int << ": " << endl;
    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {
      month_int = month_index;
      if (ValidateMonth(sensor_data, month_int, year_int, "SR")) {
        total_solar_radiation =
            calculate.TotalSolarRadiation(sensor_data, month_int, year_int);

        cout << int_to_month(month_int) << ": " << total_solar_radiation
             << " kWh/m^2 " << endl;
      } else {
        cout << int_to_month(month_int) << ": No Data" << endl;
      }
    }
  } else {
    cout << year_int << ": No data";
  }
}

void Menu::HandleAllData(const SensorLog &sensor_data) const {

  Calculator calculate;
  FileHandler handleFile;
  ostringstream output;
  float average_speed = 0.0f;
  float stdev_speed = 0.0f;
  float average_temperature = 0.0f;
  float stdev_temperature = 0.0f;
  float total_solar_radiation = 0.0f;
  int month_int = 0;
  int year_int = 0;
  bool month_exist = false;

  year_int = GetValidYear();
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year_int) {
      month_exist = true;
    }
  }

  if (month_exist) {
    output << year_int << ": " << endl;
    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {

      month_int = month_index;

      int empty_data = 0;

      average_speed = calculate.AverageSpeed(sensor_data, month_int, year_int);
      stdev_speed = calculate.StdDevSpeed(sensor_data, average_speed, month_int,
                                          year_int);
      average_temperature =
          calculate.AverageTemperature(sensor_data, month_int, year_int);
      stdev_temperature = calculate.StdDevTemperature(
          sensor_data, average_temperature, month_int, year_int);
      total_solar_radiation =
          calculate.TotalSolarRadiation(sensor_data, month_int, year_int);

      output << int_to_month(month_int);

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
      if (empty_data == 5) {
        output << ": No Data";
      }

      output << endl;
    }
  }

  handleFile.writeToFile("WindTempSolar.csv", output.str());
}

bool Menu::ValidateMonth(const SensorLog &sensor_data, const int month,
                         const int year, const string sensor_type) const {
  if (sensor_type == "S") {
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year &&
          sensor_data[index].speed != 0) {
        return true;
      }
    }
  }
  if (sensor_type == "T") {
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year &&
          sensor_data[index].temperature != 0) {
        return true;
      }
    }
  }
  if (sensor_type == "SR") {
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year &&
          sensor_data[index].solar_radiation != 0) {
        return true;
      }
    }
  }

  if (sensor_type == "ALL") {
    for (int index = 0; index < sensor_data.size(); index++) {
      if (sensor_data[index].date.GetMonth() == month &&
          sensor_data[index].date.GetYear() == year) {
        return true;
      }
    }
  }

  return false;
}

int Menu::GetValidYear() const {
  bool valid_year;
  string year_string;
  int year_int;
  while (!valid_year) {
    cout << "\nEnter Year: ";
    cin >> year_string;

    try {

      for (char c : year_string) {
        if (!isdigit(c)) {
          throw year_string;
        }
      }
      year_int = stoi(year_string);

      if (year_int < 2005 || year_int > 2025) {
        throw year_int;
      } else {
        valid_year = true;
      }
    } catch (const string &invalid_argument) {
      cout << "Error: Please enter numeric digits only for the year.\n\n"
           << endl;
      cin.clear();
    } catch (const int &year_out_of_range) {
      cout << "Please enter a year between 2007 and 2025." << endl;
    }
  }

  cout << endl;
  return year_int;
}

// Helper function

string int_to_month(const int month) {
  string month_arr[MAX_MONTHS] = {
      " ",    "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};
  return month_arr[month];
}
int month_to_int(const string month) {
  string month_arr[MAX_MONTHS] = {
      " ",    "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};
  string month_arr_small_case[MAX_MONTHS] = {
      " ",    "january", "february",  "march",   "april",    "may",     "june",
      "july", "august",  "september", "october", "november", "december"};

  for (int index = 1; index < MAX_MONTHS; index++) {
    if (month == month_arr[index] || month == month_arr_small_case[index]) {
      return index;
    }
  }
  return 0;
}
