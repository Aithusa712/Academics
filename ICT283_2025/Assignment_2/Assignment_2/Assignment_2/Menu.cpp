#include "Menu.h"
#include "Results.h"
#include "SensorRecType.h"

// Prompt Menu prompt and handles all handle functions
void Menu::prompt(const SensorLog &sensor_data, bool &exit) const {

  // Initialize local variables
  string choice_string = "";
  int choice = 0;
  bool valid_choice = false;
  Results result;
  int year = 0;
  int month = 0;

  // While loop to validate correct user input
  while (!valid_choice) {

    // The prompt to be prompted
    cout << endl;
    cout
        << "\n1. The average wind speed and sample standard deviation for"
           "\nthis wind speed given a specified month and year. (print on screen "
           "\nonly)"
        << endl
        << "\n2. Average ambient air temperature and sample standard deviation"
           "\nfor each month of a specified year. (print on screen only)"
        << endl
        << "\n3. sPCC calculation is carried out for a user specified month and "
           "\ncombinations of two data fields."
           "\n\n  The combinations are:"
           "\n  a. Average Wind Speed (S) and Ambient Air Temperature (T)."
           "\n     This is called S_T."
           "\n  b. Average Wind Speed (S) and Solar Radiation (R). This is"
           "\n     called S_R."
           "\n  c. Ambient Air Temperature (T) and Solar Radiation (R). This "
           "\n     is called T_R.\n"
        << endl
        << "4.Average wind speed (km/h), average ambient air temperature and \n"
           "total solar radiation in kWh/m2 for each month of a specified \n"
           "year. The standard deviation stdev, and Mean Absolute Deviation \n"
           "mad is printed as (stdev, mad ) next to the average. (print to a \n"
           "file called “WindTempSolar.csv”).\n"
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
    month = GetValidMonth();
    year = GetValidYear();
    result.DisplayAverageStdevSpeed(sensor_data, month, year);
    break;
  case 2:
    // Call GetValidYear routine to prompt a user for a Year and validate if its
    // a numerical string or out of range

    year = GetValidYear();
    result.DisplayAverageStdevTemperature(sensor_data, year);

    break;
  case 3:
    // Call GetValidYear routine to prompt a user for a Year and validate if its
    // a numerical string or out of range
    month = GetValidMonth();
    result.Display_sPCC(sensor_data, month);
    break;
  case 4:
    // Call GetValidYear routine to prompt a user for a Year and validate if its
    // a
    // numerical string or out of range

    year = GetValidYear();
    result.PrintAll(sensor_data, year);
    break;
  case 5:
    // exit is a parameter, if true, the while loop in main.cpp will break.
    exit = true;
    break;
  }
}

// Handles the Monthly speed prompt
int Menu::GetValidMonth() const {

  // Initialize local variables

  string month_string = "";
  bool valid_month = false;
  int month = 0;


  const string month_arr_uppercase[MAX_MONTHS] = {
      " ",    "January", "February",  "March",   "April",    "May",     "June",
      "July", "August",  "September", "October", "November", "December"};

  const string month_arr_lowercase[MAX_MONTHS] = {
      " ",    "january", "february",  "march",   "april",    "may",     "june",
      "july", "august",  "september", "october", "november", "december"};

  // While loop to validate user input for month
  while (!valid_month) {

    // Prompt user for month

    cout << "Enter Month: ";
    cin >> month_string;

    for (int month_index = 1; month_index < MAX_MONTHS; month_index++) {
      if (month_string == month_arr_lowercase[month_index] ||
          month_string == month_arr_uppercase[month_index]) {
        valid_month = true;
        month = month_index;
        break;
      }
    }

    if (!valid_month) {

      cout << "\nInvalid Month" << endl;
    }
  }

  // Call GetValidYear routine to prompt a user for a Year and validate if its a
  // numerical string or out of range

  return month;
}

// Prompt User for an input with validation
int Menu::GetValidYear() const {

  // Initialize local variables
  bool valid_year = false;
  string year_string = "";
  int year_int = 0;

  // Break loop if year is validated, else, repeat
  while (!valid_year) {

    // Prompt User for year
    cout << "\nEnter Year: ";
    cin >> year_string;

    try {
      // Loop through all the char of the string and check if it's a digit
      for (char c : year_string) {
        if (!isdigit(c)) {
          // Throw a string exception
          throw year_string;
        }
      }
      // If all characters are numerical, convert string to integer
      year_int = stoi(year_string);

      // Check if user input is within range
      if (year_int < 2005 || year_int > 2025) {
        // Throw a integer exception
        throw year_int;
      }
      // year is validated, assign valid_year = true to exit loop
      else {
        valid_year = true;
      }
    }
    // Catch any string exception
    catch (const string &invalid_argument) {
      cout << "Error: Please enter numeric digits only for the year.\n\n"
           << endl;
      cin.clear();
    }
    // Catch any integer exception
    catch (const int &year_out_of_range) {
      cout << "Please enter a year between 2007 and 2025." << endl;
    }
  }

  cout << endl;
  return year_int;
}
