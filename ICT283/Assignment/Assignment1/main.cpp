#include <iostream>
#include <fstream>
#include <sstream>
#include <cmath>
#include "Date.h"
#include "Time.h"
#include "vector.h"


using namespace std;

/*
 * a struct to store the information from the CSV file.
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


//------------------------------------------------------------------------------
//                    Function Declarations
//------------------------------------------------------------------------------
float roundOff(float num);
string trim(const string& input);
void readCSV(const string& filename, WindlogType& wind_data);
void calculateAvgSpeed(const WindlogType& wind_data);
void calculateAvgTemp(const WindlogType& wind_data);
void calculateAvgSR(const WindlogType& wind_data);
void calculateAll(const WindlogType& wind_data);
float calculateAvg(const WindlogType& wind_data, int option);
float calculateStd(const WindlogType& wind_data, float avg, int option);
WindlogType GetMonthlyData(const WindlogType& wind_data, const string& year, const string& month);
bool checkMonth(string& monthInput);


//------------------------------------------------------------------------------
//                            main
//------------------------------------------------------------------------------


int main()
{
    WindlogType wind_data;  /* Create a empty WindlogType record */
    string filename;
    fstream file("data/data_source.txt");
    getline(file, filename);
    int choice;
    bool loop = true;
    readCSV(filename, wind_data);

    while (loop)
    {
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

        switch (choice)
        {
        case 1:
            calculateAvgSpeed(wind_data);
            break;
        case 2:
            calculateAvgTemp(wind_data);
            break;
        case 3:
            calculateAvgSR(wind_data);
            break;
        case 4:
            calculateAll(wind_data);
            break;
        case 5:
            loop = false;
            break;

        default:
            break;
        }

    }


    return 0;
}

//------------------------------------------------------------------------------
//                          Functions
//------------------------------------------------------------------------------


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

//------------------------------------------------------------------------------

void readCSV(const string& filename, WindlogType& wind_data)
{
    string filepath = "data/" + filename;
    ifstream file(filepath);
    if (!file.is_open())
    {
        cerr << "Error opening file " << filename << endl;
        return;
    }
    string line;
    string temp = "";
    int sr_idx = -1;
    int s_idx = -1;
    int t_idx = -1;
    /*Skip first line (header line) */
    getline(file, line);
    stringstream ss(line);
    Vector<string> header;
    while (getline(ss, temp, ','))
    {
        header.push(trim(temp));
        temp = "";

    }
    int count = 0;
    for(int i=0; i < header.size(); i++)
    {



        if(header.get(i)== "SR")
        {
            sr_idx = i;
        }
        if(header.get(i) == "S")
        {
            s_idx = i;
        }
        if(header.get(i) == "T")
        {
            t_idx = i;

        }


    }


    while (getline(file, line))
    {

        stringstream ss(line);
        string s_speed = "";    /*Stores the speed in string data type*/
        string s_temperature = "";
        string s_solarRadiation = "";
        float f_temp = 0.0f;
        string temp = "" ;      /*a temporary string, used to skip columns*/
        string cleanTemp ="";
        string  day = "";       /* Stores the day*/
        string  year = "";      /*Stores the year*/
        string  month = "";     /*Stores the month*/
        string  hours = "";     /* Stores the hours*/
        string  minutes = "";   /*tores the minutes*/
        Vector <float> sensor;
        float speed = 0.0f;
        float temperature = 0.0f;
        float solarRadiation = 0.0f;



        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year, ' ');
        getline(ss, hours, ':');
        getline(ss, minutes, ',');

        while (getline(ss,temp, ','))
        {

            f_temp = stof(temp);
            sensor.push(f_temp);
        }

        if (!day.empty()&&!month.empty()&&!year.empty())
        {
            speed = sensor.get(s_idx-1);
            temperature = sensor.get(t_idx-1);
            solarRadiation = sensor.get(sr_idx-1);

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
            record.temperature = temperature;
            record.solarRadiation = solarRadiation;
            wind_data.push(record);
        }

    }
    /*
     * Close file to clear up memory
     */
    file.close();
}

//------------------------------------------------------------------------------

void calculateAvgSpeed(const WindlogType& wind_data)
{
    string yearInput;
    string monthInput;
    bool loop = true;
    float avg;
    float sstd;

    while(loop)
    {
        cout << "\n\nEnter a month (January, February,...): " ;
        cin >> monthInput;



        if(checkMonth(monthInput))
        {
            loop = false;
        }
        else
        {
            cout<< "\n\nInvalid Month. Please Try Again \n\n";
        }
    }



    cout << "\nEnter a Year:  " ;
    cin >> yearInput;

    WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, monthInput);
    avg = calculateAvg(MonthlyData, 1);
    sstd = calculateStd(MonthlyData, avg, 1);


    if (avg > 0)
    {
        cout << "\n" << monthInput << " " << yearInput << ": ";
        cout << "\n\nAverage wind speed: " << roundOff(avg) << "km/h" << endl;
        cout << "Sample stdev: " << roundOff(sstd) << endl;
    }
    else
    {
        cout << "\n" << monthInput << " " << yearInput << ": ";

        cout << "No Data" << "\n" <<endl;
    }

}


//------------------------------------------------------------------------------

void calculateAvgTemp(const WindlogType& wind_data)
{
    string yearInput;
    string month[] = {"January", "February", "March",
                      "April", "May", "June","July", "August", "September",
                      "October", "November", "December"
                     };
    float avg;
    float sstd;

    cout << "\nEnter a Year:  " ;
    cin >> yearInput;

    cout << "\n\n"<< yearInput << ": \n";
    for(int i=0; i<12; i++)
    {
        WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, month[i]);
        avg = calculateAvg(MonthlyData, 2);
        sstd = calculateStd(MonthlyData, avg,2);


        if (avg > 0)
        {
            cout << month[i] << ": ";
            cout << "Average: " << roundOff(avg) << " degrees C" ;
            cout << ", stdev: " << roundOff(sstd) << endl;
        }
        else
        {
            cout << month[i] << ": ";

            cout << "No Data"<<endl;
        }
    }


}


//------------------------------------------------------------------------------

void calculateAvgSR(const WindlogType& wind_data)
{
    string yearInput;
    string month[] = {"January", "February", "March",
                      "April", "May", "June","July", "August", "September",
                      "October", "November", "December"
                     };
    float avg = 0.0f;
    float sstd = 0.0f;

    cout << "\nEnter a Year: " ;
    cin >> yearInput;

    cout << "\n\n"<< yearInput << ": \n";
    for(int i=0; i<12; i++)
    {
        WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, month[i]);
        avg = calculateAvg(MonthlyData, 3);


        if (avg > 0)
        {
            cout << month[i] << ": ";
            cout << "Average: " << roundOff(avg)<< " kWh/m^2"<<endl;

        }
        else
        {
            cout << month[i] << ": ";

            cout << "No Data"<<endl;
        }
    }


}


//------------------------------------------------------------------------------

void calculateAll(const WindlogType& wind_data)
{
    string yearInput;
    string month[] = {"January", "February", "March",
                      "April", "May", "June","July", "August", "September",
                      "October", "November", "December"
                     };
    float avgSpeed = 0.0f;
    float avgTemp = 0.0f;
    float avgSR = 0.0f;
    float sstdSpeed = 0.0f;
    float sstdTemp = 0.0f;
    bool NoYear = true;

    cout << "\nEnter a Year: " ;
    cin >> yearInput;

    cout << "\n\n"<< yearInput << ":";
    for(int i = 0; i < wind_data.size(); i++)
    {
        if(wind_data.get(i).date.GetYear() == yearInput)
        {
            NoYear = false;
            break;
        }
    }
    if(!NoYear)
    {
        for(int i=0; i<12; i++)
        {
            WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, month[i]);
            bool NoMonth = true;

            avgSpeed = calculateAvg(MonthlyData, 1);
            sstdSpeed = calculateStd(MonthlyData, avgSpeed, 1);
            avgTemp = calculateAvg(MonthlyData, 2);
            sstdTemp = calculateStd(MonthlyData, avgTemp, 2);
            avgSR = calculateAvg(MonthlyData, 3);


            cout <<"\n"<< month[i] << ",";
            if (avgSpeed > 0 )
            {
                cout << roundOff(avgSpeed)<< "(" << roundOff(sstdSpeed) << ")" << ",";
                NoMonth = false;

            }
            if (avgTemp > 0 )
            {
                cout <<roundOff(avgTemp)<< "(" << roundOff(sstdTemp) << ")";
                NoMonth = false;
            }
            if (avgSR > 0 )
            {
                cout << "," << roundOff(avgSR);
                NoMonth = false;
            }

            if (NoMonth)
            {

                cout << "No Data";
            }
        }
    }
    else
    {
        cout << " No Data" << "\n" ;
    }

    cout << endl;

}

//------------------------------------------------------------------------------

/*
 * Calculates the average speed of all the speed in the wind_data vector.
 *
 * wind_data contains the records of wind data.
 * The average speed of all the speed in the wind_data.
 */
float calculateAvg(const WindlogType& wind_data, int option)
{
    if (option == 1)
    {
        float sum = 0.0f;
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sum += wind_data.get(i).speed;
        }
        return sum / wind_data.size();
    }
    if (option == 2)
    {
        float sum = 0.0f;
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sum += wind_data.get(i).temperature;
        }
        return sum / wind_data.size();
    }

    if (option == 3)
    {
        float sum = 0.0f;
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sum += wind_data.get(i).solarRadiation;
        }
        return sum / wind_data.size();
    }
}

//------------------------------------------------------------------------------
/*
 *  Calculates the Sample standard deviation of wind speed from the wind_data vector.
    wind_data contains the records of wind data.
    The Sample standard deviation of wind speed from the wind_data vector
 */

float calculateStd(const WindlogType& wind_data, float avg, int option)
{
    float sd = 0.0f;
    if(option == 1)
    {
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sd += pow(wind_data.get(i).speed - avg,2);
        }
        sd = sqrt(sd/wind_data.size());
        return sd;
    }
    if(option == 2)
    {

        for (int i = 0; i < wind_data.size(); ++i)
        {
            sd += pow(wind_data.get(i).speed - avg,2);
        }
        sd = sqrt(sd/wind_data.size());
        return sd;
    }


}


//------------------------------------------------------------------------------
//                          Other Functions
//------------------------------------------------------------------------------

bool checkMonth(string& monthInput)
{
    if (monthInput == "january" || monthInput == "January")
    {
        monthInput = "January";
        return true;
    }
    else if (monthInput == "february" || monthInput == "February")
    {
        monthInput = "February";
        return true;
    }
    else if (monthInput == "march" || monthInput == "March")
    {
        monthInput = "March";
        return true;
    }
    else if (monthInput == "april" || monthInput == "April")
    {
        monthInput = "April";
        return true;
    }
    else if (monthInput == "may" || monthInput == "May")
    {
        monthInput = "May";
        return true;
    }
    else if (monthInput == "june" || monthInput == "June")
    {
        monthInput = "June";
        return true;
    }
    else if (monthInput == "july" || monthInput == "July")
    {
        monthInput = "July";
        return true;
    }
    else if (monthInput == "august" || monthInput == "August")
    {
        monthInput = "August";
        return true;
    }
    else if (monthInput == "september" || monthInput == "September")
    {
        monthInput = "September";
        return true;
    }
    else if (monthInput == "october" || monthInput == "October")
    {
        monthInput = "October";
        return true;
    }
    else if (monthInput == "november" || monthInput == "November")
    {
        monthInput = "November";
        return true;
    }
    else if (monthInput == "december" || monthInput == "December")
    {
        monthInput = "December";
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------

float roundOff(float num)
{
    return int(num * 10 + 0.5) / 10.0;
}

//------------------------------------------------------------------------------

string trim(const string& input)
{
    string result;
    for (char ch : input)
    {
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch != '\r')
        {
            result += ch;
        }
    }
    return result;
}

//------------------------------------------------------------------------------
