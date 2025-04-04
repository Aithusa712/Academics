#include "WindDataCalculator.h"
#include <cmath>
#include <iostream>
#include <fstream>
#include "Date.h"
#include "Time.h"

//This function returns a record of only the month and year defined by the year and month parameter.
WindlogType WindDataCalculator::GetMonthlyData(const WindlogType& wind_data, const string& year, const string& month)
{
    //Create a new record
    WindlogType wind_data_month;
    //iterate all records in the original record
    for(int i = 0; i < wind_data.size(); i++)
    {
        //Compare the year and date parameters to the orignal record's year and date
        if(wind_data.get(i).getDate().GetYear() == year && wind_data.get(i).getDate().GetMonth() == month)
        {
            //if date matches push the values and instances of the original wind data record to the new record
            wind_data_month.push(wind_data.get(i));


        }

    }
    //return the new record which only contains a month worth of data
    return wind_data_month;
}

//------------------------------------------------------------------------------

//Function to calculate average speed of a specific month of a year
void WindDataCalculator::calculateAvgSpeed(const WindlogType& wind_data)
{
    string yearInput;  //Declare a variable store user input
    string monthInput; //Declare a variable store user input
    bool loop = true;  //Declare and initialize a bool variable to break the loop
    float avg;         //Declare a float variable to store average
    float sstd;        //Declare a float variable to store standard deviation

    while(loop)
    {
        //Prompt user for month
        cout << "\n\nEnter a month (January, February,...): " ;
        cin >> monthInput;


        //Check if month is correct value by calling the check month function.
        if(checkMonth(monthInput))
        {
            //break loop if month is correct
            loop = false;
        }
        else
        {
            //Print and loop again
            cout<< "\n\nInvalid Month. Please Try Again \n\n";
        }
    }


    //Prompt user for year
    cout << "\nEnter a Year:  " ;
    cin >> yearInput;
    //Retrieve the the record for that month and year
    WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, monthInput);

    //Call function to calculate for average and Standard deviation
    avg = calculateAvg(MonthlyData, 1);
    sstd = calculateStd(MonthlyData, avg, 1);

    //If average is less than 0 that means the record is empty and have no data.
    //Print out results
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

//Function to calculate average temperature of a all the months of a year
void WindDataCalculator::calculateAvgTemp(const WindlogType& wind_data)
{
    string yearInput; //Declare a variable store user input

    //Create an array of month. I used array and not a vector because we know
    //how many months there are in a year
    string month[] = {"January", "February", "March",
                      "April", "May", "June","July", "August", "September",
                      "October", "November", "December"
                     };
    float avg = 0.0f;  //Declare a float variable to store average
    float sstd = 0.0f; //Declare a float variable to standard deviation

    //Prompt user for year
    cout << "\nEnter a Year:  " ;
    cin >> yearInput;

    //Print out year
    cout << "\n\n"<< yearInput << ": \n";
    //Iterate for all the months of a year
    for(int i=0; i<12; i++)
    {
        //Get monthly data
        WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, month[i]);
        //Calculate average of monthly data
        avg = calculateAvg(MonthlyData, 2);
        //calculate standard deviation of monthly data
        sstd = calculateStd(MonthlyData, avg,2);

        //Check if record is empty
        //Print out results
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

//Function to calculate average solar radiation of a all the months of a year
void WindDataCalculator::calculateAvgSR(const WindlogType& wind_data)
{
    //Declare a variable store user input
    string yearInput;

    //Create an array of month. I used array and not a vector because we know
    //how many months there are in a year
    string month[] = {"January", "February", "March",
                      "April", "May", "June","July", "August", "September",
                      "October", "November", "December"
                     };
    float avg = 0.0f;   //Declare a float variable to store average

    //Prompt User for year
    cout << "\nEnter a Year: " ;
    cin >> yearInput;

    //Print out year
    cout << "\n\n"<< yearInput << ": \n";

    //Iterate for all the months of a year
    for(int i=0; i<12; i++)
    {
        //Get monthly data
        WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, month[i]);
        //calculate average
        avg = calculateAvg(MonthlyData, 3);

        //Check if record is empty
        //Print out results
        if (avg > 0)
        {
            //convert value to kWh/m^2
            float totalEnergyWh = avg * (10.0f / 60.0f);
            float totalEnergyKWh = totalEnergyWh / 1000.0f;
            //round off to 3 decimal points and store it back to avg
            avg = int(totalEnergyKWh * 1000 + 0.5) / 1000.0;

            cout << month[i] << ": ";
            cout << "Average: " << avg << " kWh/m^2"<<endl;

        }
        else
        {
            cout << month[i] << ": ";

            cout << "No Data"<<endl;
        }
    }


}


//------------------------------------------------------------------------------

//Function to calculate average wind speed, temperature, solar radiation
//and print it out to a csv file
void WindDataCalculator::calculateAll(const WindlogType& wind_data)
{

    string yearInput; //Declare a variable store user input

    //Create an array of month. I used array and not a vector because we know
    //how many months there are in a year
    string month[] = {"January", "February", "March",
                      "April", "May", "June","July", "August", "September",
                      "October", "November", "December"
                     };

    float avgSpeed = 0.0f;  //Declare a float variable to store average wind speed
    float avgTemp = 0.0f;   //Declare a float variable to store average wind temperature
    float avgSR = 0.0f;     //Declare a float variable to store average solar radiation
    float sstdSpeed = 0.0f; //Declare a float variable to store standard deviation of wind speed
    float sstdTemp = 0.0f;  //Declare a float variable to store standard deviation of wind temperature
    bool NoYear = true;     //Declare a bool to check if there is no available data for the year entered

    //create a file output
    ofstream output("WindTempSolar.csv");

    //Prompt user for year
    cout << "\nEnter a Year: " ;
    cin >> yearInput;

    //Output the year
    output << yearInput << ":";

    //Iterate for all the months of the year to check if there is no data
    for(int i = 0; i < wind_data.size(); i++)
    {
        if(wind_data.get(i).getDate().GetYear() == yearInput)
        {
            NoYear = false;
            break;
        }
    }
    //Check if there is data for the year the user entered
    if(!NoYear)
    {
        //Iterate for all the months of the year
        for(int i=0; i<12; i++)
        {
            //Get monthly data
            WindlogType MonthlyData =  GetMonthlyData(wind_data, yearInput, month[i]);
            bool NoMonth = true; //Declare bool variable to check if there is no month in the data

            //Calculate all the data
            avgSpeed = calculateAvg(MonthlyData, 1);
            sstdSpeed = calculateStd(MonthlyData, avgSpeed, 1);
            avgTemp = calculateAvg(MonthlyData, 2);
            sstdTemp = calculateStd(MonthlyData, avgTemp, 2);
            avgSR = calculateAvg(MonthlyData, 3);

            //Output the month
            output <<"\n"<< month[i] << ",";
            //Check if avg is greater than 0, if it is, it means the type of
            //data is not available for that month. Output the data and set the value of NoMonth as false
            if (avgSpeed > 0 )
            {
                output << roundOff(avgSpeed)<< "(" << roundOff(sstdSpeed) << ")" << ",";
                NoMonth = false;

            }
            if (avgTemp > 0 )
            {
                output <<roundOff(avgTemp)<< "(" << roundOff(sstdTemp) << ")";
                NoMonth = false;
            }
            if (avgSR > 0 )
            {
                //Convert value to kWh/m^2
                float totalEnergyWh = avgSR * (10.0f / 60.0f);
                float totalEnergyKWh = totalEnergyWh / 1000.0f;
                avgSR = int(totalEnergyKWh * 1000 + 0.5) / 1000.0;
                output << "," << avgSR;
                NoMonth = false;
            }

            //If all of the data is missing for that month it will output "No data"
            if (NoMonth)
            {

                output << "No Data";
            }
        }
    }
    //If there is no available data for all the months of that year it will output "No data"
    else
    {
        output << " No Data" << "\n" ;
    }



}

//------------------------------------------------------------------------------

/*
 * Calculates the average data in the wind_data vector.
 * wind_data contains the records of wind data.
 * option is the option of what type of data do you want to get the average of.
 * if int option 1 = calculate average speed.
 * if int option 2 = calculate average temperature.
 * if int option 3 = calculate average solar radiation.
 */
float WindDataCalculator::calculateAvg(const WindlogType& wind_data, int option)
{
    if (option == 1)
    {
        float sum = 0.0f;
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sum += wind_data.get(i).getSpeed();
        }
        return sum / wind_data.size();
    }
    if (option == 2)
    {
        float sum = 0.0f;
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sum += wind_data.get(i).getTemperature();
        }
        return sum / wind_data.size();
    }

    if (option == 3)
    {
        float sum = 0.0f;
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sum += wind_data.get(i).getSolarRadiation();
        }
        return sum / wind_data.size();
    }
    cout << "\nError: Not a suitable integer value";
    return 1;
}

//------------------------------------------------------------------------------
/*
 * Calculates the Sample standard deviation of data from the wind_data vector.
 * wind_data contains the records of wind data.
 * option is the option of what type of data do you want to get the standard deviation of.
 * if int option 1 = calculate average speed.
 * if int option 2 = calculate average temperature.
 */

float WindDataCalculator::calculateStd(const WindlogType& wind_data, float avg, int option)
{
    float sd = 0.0f;
    if(option == 1)
    {
        for (int i = 0; i < wind_data.size(); ++i)
        {
            sd += pow(wind_data.get(i).getSpeed() - avg,2);
        }
        sd = sqrt(sd/wind_data.size());
        return sd;
    }
    if(option == 2)
    {

        for (int i = 0; i < wind_data.size(); ++i)
        {
            sd += pow(wind_data.get(i).getSpeed() - avg,2);
        }
        sd = sqrt(sd/wind_data.size());
        return sd;
    }

    cout << "\nError: Not a suitable integer value";
    return 1;
    return 1;


}


//------------------------------------------------------------------------------
//                          Other Functions
//------------------------------------------------------------------------------

//This functions check if monthInput is the correct value and converts the lowercase
//months in to the standard format that the program understands
bool WindDataCalculator::checkMonth(string& monthInput)
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

//Rounds off a float to 2 decimal points
float WindDataCalculator::roundOff(float num)
{
    return int(num * 10 + 0.5) / 10.0;
}
