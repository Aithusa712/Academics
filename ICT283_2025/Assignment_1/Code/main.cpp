#include "Calculator.h"
#include "FileHandler.h"
#include "SensorRecType.h"
#include <cmath>
#include <iostream>
#include <ostream>
using namespace std; // check textbook for details of the namespace concept

void prompt(SensorLog &sensor_data, bool &exit);
int Prompt_Year(string year, bool &valid_year);
int Month_to_Int(string month);

int main() {
  SensorLog sensor_data;
  FileHandler handleFile;
  handleFile.readSource("data/data_source.txt", sensor_data);
  bool exit = false;

  while (!exit) {
    prompt(sensor_data, exit);
  }

  return 0;
}

void prompt(SensorLog &sensor_data, bool &exit) {

  cout
      << "1. The average wind speed and sample standard deviation for this\n"
         "wind speed given a specified month and year. (print on screen only)\n"
      << endl
      << "2. Average ambient air temperature and sample standard deviation\n"
         "for each month of a specified year. (print on screen only)\n"
      << endl
      << "3.Total solar radiation in lWh/m^2 for each month of a specified\n"
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

  string month = "";
  string year = "";
  int month_int = 0;
  int year_int = 0;
  int choice;
  bool valid_month = false;
  bool valid_year = false;
  cin >> choice;

  switch (choice) {
  case 1:

    while (!valid_month) {
      cout << "Enter Month: ";
      cin >> month;
      if (Month_to_Int(month) != 0) {
        valid_month = true;
      } else {
        cout << "\n!!!Enter Valid Month!!!";
      }
    }
    month_int = Month_to_Int(month);
    year_int = Prompt_Year(year, valid_year);

    break;
  case 2:

    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    exit = true;
    break;
  }
}

int Prompt_Year(string year, bool valid_year) {
  int yearNum;
  while (!valid_year) {
    cout << "\nEnter Year (numeric only): ";
    cin >> year;

    try {
      yearNum = stoi(year);

      if (yearNum < 1900 || yearNum > 2100) {
        cout << "Please enter a year between 1900 and 2100." << endl;
      } else {
        valid_year = true;
      }
    } catch (const invalid_argument &) {
      cout << "Error: Please enter numeric digits only for the year.\n\n"
           << endl;
      cin.clear();
    }
  }
  return yearNum;
}

int Month_to_Int(string month) {
  string month_arr[12] = {"January",   "February", "March",     "April",
                          "May",       "June",     "July",      "August",
                          "September", "October",  " November", "December"};
  string month_arr_small[12] = {
      "january", "february", "march",     "april",   "may",       "june",
      "july",    "august",   "september", "october", " november", "december"};
  for (int index = 0; index < 12; index++) {
    if (month == month_arr[index]) {
      return index + 1;
    }
  }
  return 0;
}

void unitTesting(SensorLog &sensor_data) {
  // Unit Testing
  for (int i = 0; i < sensor_data.size(); i++) {
    cout << "Index [" << i << "]Speed: " << sensor_data[i].speed
         << ", temperature: " << sensor_data[i].temperature
         << ", solar radiation: " << sensor_data[i].solar_radiation << endl;
  }
}
