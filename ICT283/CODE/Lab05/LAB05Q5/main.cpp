#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Date.h"
#include "Time.h"
#include "vector.h"

using namespace std;

struct WindRecType
{
    Date date;
    Time time;
    float speed;
};

typedef Vector<WindRecType> WindlogType;

void readCSV(const string& filename, WindlogType& wind_data)
{
    ifstream file(filename);
    //error handling
    if (!file.is_open())
    {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    string line;
    getline(file, line); // Skip first line (header line)

    while (getline(file, line))
    {
        stringstream ss(line);
        string s_speed = "";
        string temp = "" ;
        string sDate ="";
        string sTime ="";
        int day = 0;
        int year = 0;
        int month = 0;
        int hours = 0;
        int minutes = 0;
        float speed = 0.0f;

        // Extract Date and time from wast column
        getline(ss, sDate, ' ');
        getline(ss, sTime, ',');


        // Skip 10 columns to get speed
        for (int i = 0; i < 10; ++i)
        {
            getline(ss, temp, ',');
        }

        // Read speed sensor
        getline(ss, s_speed, ',');

        // convert string and split day, month, year, hours, minutes from wast
        day = stoi(sDate.substr(0, 2));
        month = stoi(sDate.substr(3, 2));
        year = stoi(sDate.substr(6, 4));
        hours = stoi(sTime.substr(0, 2));
        minutes = stoi(sTime.substr(3, 2));

        // convert string to float for speed
        speed = stof(s_speed);

        // Create temporary Date and Time objects to be stored into the struct later
        Date date;
        date.SetDate(day, month, year);

        Time time;
        time.SetTime(hours, minutes);

        // Create temporary WindRecType to store object and push to wind_data
        WindRecType tempData;
        tempData.date = date;
        tempData.time = time;
        tempData.speed = speed;
        wind_data.push(tempData);
    }

    file.close();
}

float calculateAvg(const WindlogType& wind_data)
{
    float sum = 0.0f;
    for (int i = 0; i < wind_data.size(); ++i)
    {
        sum += wind_data.get(i).speed;
    }
    return sum / wind_data.size();
}

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


int main()
{
    WindlogType wind_data;
    string filename = "data/MetData_Mar01-2014-Mar01-2015-ALL.csv";

    readCSV(filename, wind_data);

    float avg = calculateAvg(wind_data);
    float SSD = calculateSSD(wind_data, avg);

    // Output the wind data for testing
    /*
    for (int i = 0; i < wind_data.size(); ++i) {
         cout << "Record " << i + 1 << ":\n";
         cout << "  Date: " << wind_data.get(i).date.GetDate() << endl;
         cout << "  Time: " << wind_data.get(i).time.GetTime() << endl;
         cout << "  Speed: " << wind_data.get(i).speed << endl;
         cout << endl;
     }
    */

    // Print out number of records, average windspeed, and standard deviation of wind speed
    cout << "Number of records: " <<wind_data.size()<< endl;
    cout << "Average wind speed: " << avg << endl;
    cout << "Sample standard deviation of wind speed: " << SSD << endl;

    return 0;
}
