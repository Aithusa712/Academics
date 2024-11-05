/*
 * main.cpp
 * This file contains the functions to read the wind data from the CSV file and calculates the average and Sample standard deviation of wind speed from the file
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Date.h"
#include "Time.h"
#include "vector.h"


using namespace std;

/*
 * a struct to store the information from the CSV file. It includes 2 objects from 2 different classes
 */
struct WindRecType
{
    Date date;
    Time time;
    float speed;
};

/*
 * A vector of WindRecType struct.
 */
typedef Vector<WindRecType> WindlogType;


/*
 *  Reads the filename from the parameter which contains the path to the CSV file and stores the information to the vector
 */

void readCSV(const string& filename, WindlogType& wind_data)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    string line;
    getline(file, line); /*Skip first line (header line) */

    while (getline(file, line))
    {

        stringstream ss(line);
        string s_speed = "";    /*Stores the speed in string data type*/
        string temp = "" ;      /*a temporary string, used to skip columns*/
        string  day = "";       /* Stores the day*/
        string  year = "";      /*Stores the year*/
        string  month = "";     /*Stores the month*/
        string  hours = "";     /* Stores the hours*/
        string  minutes = "";   /*tores the minutes*/
        float speed = 0.0f;

        /*
         * Retrieve the wast data from the CSV and store it in the variables inside the loop
         */

        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year, ' ');
        getline(ss, hours, ':');
        getline(ss, minutes, ',');

        /*
         * skip columns
         */

        for (int i = 0; i < 10; ++i)
        {
            getline(ss, temp, ',');
        }

        /*
        * Retrieve speed from the CSV and store it in the variables inside the loop
        */
        getline(ss, s_speed, ',');

        /*
         * Convert the string speed into float and store into the float speed variable
         */
        speed = stof(s_speed);
        /*
        * Create Date and Time objects. Use the setter methods to insert and store data into the object
        */

        Date date;
        date.SetDate(day, month, year);

        Time time;
        time.SetTime(hours, minutes);
        /*
        * Create temp WindRecType to store object and push into the wind_data vector
        */
        WindRecType record;
        record.date = date;
        record.time = time;
        record.speed = speed;
        wind_data.push(record);
    }
    /**
     * Close file to clear up memory
     */
    file.close();
}

/*
 * Calculates the average speed of all the speed in the wind_data vector.
 *
 * wind_data contains the records of wind data.
 * The average speed of all the speed in the wind_data/
 */
float calculateAvg(const WindlogType& wind_data)
{
    float sum = 0.0f;
    for (int i = 0; i < wind_data.size(); ++i)
    {
        sum += wind_data.get(i).speed;
    }
    return sum / wind_data.
           size();
}

/*
 *  Calculates the Sample standard deviation of wind speed from the wind_data vector.
    wind_data contains the records of wind data.
    The Sample standard deviation of wind speed from the wind_data vector
 */
float calculateSSD(const WindlogType& wind_data, float mean)
{
    float sum_sqrt = 0.0f;
    for (int i = 0; i < wind_data.size(); ++i)
    {
        float diff = wind_data.get(i).speed - mean;
        sum_sqrt += diff * diff;
    }
    return sqrt(sum_sqrt/ (wind_data.size() - 1));
}

/*
 *         This is the main function that uses all the other function to read and calculate for the average
           wind speed and sample standard deviation from CSV which path is stored in the string filename.
 *         return 0 after displaying the Average wind speed and sample standard deviation of wind speed
 */

int main()
{
    WindlogType wind_data;  /* Create a empty WindlogType record */
    string filename = "data/MetData_Mar01-2014-Mar01-2015-ALL.csv";

    readCSV(filename, wind_data);
    float avg = calculateAvg(wind_data);
    float SSD = calculateSSD(wind_data, avg);

    /*
    // Test data
    for (int i = 0; i < wind_data.size(); ++i) {
         cout << "Record " << i + 1 << ":\n";
         cout << "  Date: " << wind_data.get(i).date.GetDate() << endl;
         cout << "  Time: " << wind_data.get(i).time.GetTime() << endl;
         cout << "  Speed: " << wind_data.get(i).speed << endl;
         cout << endl;
     }
    */


    cout << "Number of records: " <<wind_data.size()<< endl;
    cout << "Average wind speed: " << avg << endl;
    cout << "Sample standard deviation of wind speed: " << SSD << endl;

    return 0;
}
