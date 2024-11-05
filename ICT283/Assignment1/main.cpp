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
    float temperature;
    float solarRadiation;
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
    int sr_idx = 0;
    int s_idx = 0;
    int t_idx = 0;
    int count = 0;
    /*Skip first line (header line) */
    
    getline(file, line);
    string temp;
    stringstream ss(line);
    
    while (getline(ss, temp, ','))
    {
  
        if(temp == "SR")
        {
        sr_idx = count-1;
        }
        if(temp == "S")
        {
        s_idx = count-1;
        }
        if(temp == "T")
        {
        t_idx = count-1;
        }
        count++;
    }
    
        
    
    int test=0;
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
        Vector <string> sensor;
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
        
        

        while (getline(ss,temp, ','))
        {
            sensor.push(temp);
        }

        cout << "line " << test << " Speed idx is " << s_idx << " speed is " << sensor.get(s_idx) << endl; 
        cout << "line " << test << " temp idx is " << t_idx << " speed is " << sensor.get(t_idx) << endl;
        cout << "line " << test << " SR idx is " << sr_idx << " speed is " << sensor.get(sr_idx) << endl;  
        test++;
        /*
        * Retrieve speed from the CSV and store it in the variables inside the loop
        */
        s_speed = sensor.get(s_idx);

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


WindlogType GetMonthlyData(const WindlogType& wind_data, const string& year, const string& month)
{
    WindlogType wind_data_month;
    for(int i = 0; i < wind_data.size(); i++)
    {
        if(wind_data.get(i).date.GetYear() == year && wind_data.get(i).date.GetMonth() == month)
        {
            wind_data_month.push(wind_data.get(i)); 
            
            
        }
        
    }

    return wind_data_month;
}

void CalculateMonthlySpeed(const WindlogType& wind_data)
{
    string year;
    string month[] = {"January", "February", "March", 
    "April", "May", "June","July", "August", "September",
    "October", "November", "December"};

    float avg;
    float SSD;
    //cout << "\n\n Enter a month (January, February, .....) : " ;
    //cin >> month;

    cout << "\nEnter a Year (YYYY ex. 2020,2021,...) :  " ; 
    cin >> year;

    cout << "\n\n"<< year << ": ";
    for(int i=0; i<12; i++)
    {
        WindlogType MonthlyData =  GetMonthlyData(wind_data, year, month[i]);
        avg = calculateAvg(MonthlyData);
        SSD = calculateSSD(MonthlyData, avg);
        
        
        if (avg > 0)
        {
        cout << "\n" << month[i] << ": "; 
        cout << "\n\nAverage wind speed: " << avg << endl;
        cout << "Sample stdev: " << SSD << endl;
        }
        else
        {
            cout << "\n\n" << month[i] << ": "; 

            cout << "No Data" << "\n" <<endl;
        }
    }
    


    



    




}

int main()
{
    WindlogType wind_data;  /* Create a empty WindlogType record */
    //MetData-31-3a.csv
    //MetData_Mar01-2014-Mar01-2015-ALL.csv
    string filename = "data/MetData-31-3a.csv";
    int choice;
    bool loop = true;
    readCSV(filename, wind_data);
    float avg = calculateAvg(wind_data);
    float SSD = calculateSSD(wind_data, avg);

    /*
    // Test data *//*
    for (int i = 0; i < wind_data.size(); ++i) {
         cout << "Record " << i + 1 << ":\n";
         cout << "  Date: " << wind_data.get(i).date.GetDate() << endl;
         cout << "  Time: " << wind_data.get(i).time.GetTime() << endl;
         cout << "  Speed: " << wind_data.get(i).speed << endl;
         cout << endl;
     }


    while (loop)
   {
        cout << "\n1. Calculate Average wind speed and sample standard deviation \n   for a specific month of a year. (Month and Year)" << endl;
        cout << "\n2. Average ambient air temperature and sample standard deviation \n   for each month of a specific year. (Year)" << endl;
        cout << "\n3. Total solar radiation for each month of a specific year (Year)" << endl;
        cout << "\n4. Average wind speed, average ambient air temperature, and \n   total solar radiation temperature for each month of a specific year. (Year)" << endl; 
        cout << "\n5. Exit. \n\n" << endl;
        cout << "Please Select an option: " ;
        cin  >> choice;
        cout << endl; 

        switch (choice)
        {
        case 1:
            //CalculateMonthlySpeed(wind_data);
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        case 4:
            
            break;
        case 5:
            loop = false;
            break;
        
        default:
            break;
        }
    
   }

    cout << endl; 

    cout << "Number of records: " <<wind_data.size()<< endl;
    cout << "Average wind speed: " << avg << endl;
    cout << "Sample standard deviation of wind speed: " << SSD << endl;
*/
    return 0;
}
