#include "Menu.h"

void Menu::prompt(SensorLog &sensor_data, Calculator &calculate, bool &exit) {

  int choice = 0;

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

  cin >> choice;

  switch (choice) {
  case 1:
    HandleMonthlySpeed(sensor_data, calculate);
    break;
  case 2:
    HandleMonthlyTemperature(sensor_data, calculate);
    break;
  case 3:
    HandleMonthlySolarRadiation(sensor_data, calculate);
    break;
  case 4:
    // TODO: Print All to WindSolarTemp.csv

    break;
  case 5:
    exit = true;
    break;
  }
}

void Menu::HandleMonthlySpeed(SensorLog &sensor_data, Calculator &calculate) {
  string month = "";
  int month_int = 0;
  int year_int = 0;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  bool found = false;
  bool valid_month = false;
  while (!valid_month) {
    cout << "Enter Month: ";
    cin >> month;
    if (Month_to_Int(month) != 0) {
      valid_month = true;
    } else {
      cout << "\n!!!Enter Valid Month!!!" << endl;
    }
  }
  month_int = Month_to_Int(month);
  year_int = Prompt_Year();

  // TODO: Add an assumption in my report: For every month that is available
  // there is at least at the minimum of two records logged

  found = Month_Found(sensor_data, month_int, year_int);
  if (found) {
    average = calculate.AverageSpeed(sensor_data, month_int, year_int);
    standard_deviation =
        calculate.StdDevSpeed(sensor_data, average, month_int, year_int);
    cout << month << year_int << ":" << endl
         << "Average Speed: " << average << endl
         << "Sample stdev: " << standard_deviation << endl;
  } else {
    cout << month << year_int << ": No Data" << endl;
  }
}

void Menu::HandleMonthlyTemperature(SensorLog &sensor_data,
                                    Calculator &calculate) {
  int month_int = 0;
  int year_int = 0;
  float average = 0.0f;
  float standard_deviation = 0.0f;
  bool found = false;
  year_int = Prompt_Year();

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year_int) {
      found = true;
      break;
    }
  }
  if (found) {
    cout << endl << year_int << ": " << endl;
    for (int index = 0; index < 12; index++) {
      month_int = index + 1;
      if (Month_Found(sensor_data, month_int, year_int)) {
        average =
            calculate.AverageTemperature(sensor_data, month_int, year_int);
        standard_deviation = calculate.StdDevTemperature(sensor_data, average,
                                                         month_int, year_int);

        cout << Int_to_Month(month_int) << ":"
             << "average: " << average
             << " degrees C, Sample stdev: " << standard_deviation << endl;
      } else {
        cout << Int_to_Month(month_int) << ": No Data" << endl;
      }
    }
  } else {
    cout << year_int << ": No data";
  }
}

void Menu::HandleMonthlySolarRadiation(SensorLog &sensor_data,
                                       Calculator &calculate) {
  int month_int = 0;
  int year_int = 0;
  bool found = false;
  float total_solar_radiation = 0;

  year_int = Prompt_Year();
  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetYear() == year_int) {
      found = true;
      break;
    }
  }
  if (found) {
    cout << endl << year_int << ": " << endl;
    for (int index = 0; index < 12; index++) {
      month_int = index + 1;
      if (Month_Found(sensor_data, month_int, year_int)) {
        total_solar_radiation =
            calculate.TotalSolarRadiation(sensor_data, month_int, year_int);

        cout << Int_to_Month(month_int) << ": " << total_solar_radiation
             << " kWh/m^2 " << endl;
      } else {
        cout << Int_to_Month(month_int) << ": No Data" << endl;
      }
    }
  } else {
    cout << year_int << ": No data";
  }
}

bool Menu::Month_Found(SensorLog &sensor_data, int month, int year) {

  for (int index = 0; index < sensor_data.size(); index++) {
    if (sensor_data[index].date.GetMonth() == month &&
        sensor_data[index].date.GetYear() == year) {
      return true;
    }
  }
  return false;
}

int Menu::Prompt_Year() {
  bool valid_year;
  string year_string;
  int year_int;
  while (!valid_year) {
    cout << "\nEnter Year (numeric only): ";
    cin >> year_string;

    try {
      year_int = stoi(year_string);

      if (year_int < 2007 || year_int > 2025) {
        cout << "Please enter a year between 2007 and 2025." << endl;
      } else {
        valid_year = true;
      }
    } catch (const invalid_argument &) {
      cout << "Error: Please enter numeric digits only for the year.\n\n"
           << endl;
      cin.clear();
    }
  }
  return year_int;
}
string Menu::Int_to_Month(int month) {
  string month_arr[12] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};
  return month_arr[month - 1];
}
int Menu::Month_to_Int(string month) {
  string month_arr[12] = {"January",   "February", "March",    "April",
                          "May",       "June",     "July",     "August",
                          "September", "October",  "November", "December"};
  string month_arr_small_case[12] = {
      "january", "february", "march",     "april",   "may",      "june",
      "july",    "august",   "september", "october", "november", "december"};

  for (int index = 0; index < 12; index++) {
    if (month == month_arr[index] || month == month_arr_small_case[index]) {
      return index + 1;
    }
  }
  return 0;
}
