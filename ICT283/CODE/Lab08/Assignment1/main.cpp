#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Date.h"
#include "Time.h"
#include "vector.h"
#include "WindRecType.h"
#include "CSVReader.h"
#include "WindDataCalculator.h"

using namespace std;



//------------------------------------------------------------------------------
//                            main
//------------------------------------------------------------------------------

string trim(const string& input)
{
    string result;
    for (char ch : input)
    {
        if (ch != ' ' && ch != '\t' && ch != '\n')
        {
            result += ch;
        }
    }
    return result;
}

int main()
{


    WindlogType wind_data;          // Create an empty WindlogType record

    WindDataCalculator calculate;   // Create an instance of calculate and CsvReader
    CsvReader read;
    string filename;                // Declare variable to store the filename inside data_source.txt
    int choice;                     // Declare variable to store choice for the switch case
    bool loop = true;               // Declare variable to store the while loop condition variable

    fstream file("data/data_source.txt"); // open the file
    string temp="";
    while(getline(file, filename))        // Retrieve filename to be read
    {

    temp=filename.substr(0, filename.size()-1);

    read.readCSV(temp, wind_data);    // Read the file and store to wind data
    temp = "";
    }


    //Loop until exit
    while (loop)
    {
        //User prompt
        cout << "\n\n1. Calculate Average wind speed and sample standard deviation \n"
             << "     for a specific month of a year. (Month and Year)" << endl;
        cout << "\n2. Average ambient air temperature and sample standard deviation \n"
             << "     for each month of a specific year. (Year)" << endl;
        cout << "\n3. Total solar radiation for each month of a specific year (Year)" << endl;
        cout << "\n4. Average wind speed, average ambient air temperature, and \n"
             << "     total solar radiation temperature for each month of a specific year. (Year)" << endl;
        cout << "\n5. Exit. \n\n" << endl;
        cout << "\n         Please Select an option: " ;
        cin  >> choice;
        cout << endl << endl;

        //Switch to select which function to call
        switch (choice)
        {
        case 1:
            //Calculate the average windspeed and standard deviation of one specific month and year
            calculate.calculateAvgSpeed(wind_data);
            break;
        case 2:
            //Calculate the average wind temperature and standard deviation for each month of a specific year
            calculate.calculateAvgTemp(wind_data);
            break;
        case 3:
            //Calculate the average wind solar radiation for each month of a specific year
            calculate.calculateAvgSR(wind_data);
            break;
        case 4:
            //Calculate everything and store data into csv file
            calculate.calculateAll(wind_data);
            break;
        case 5:
            //break loop to Exit program
            loop = false;
            break;

        default:
            break;
        }

    }


    return 0;
}
