#include "CSVReader.h"


// This function is used to read the csv file and store the data into the wind_data record
void CsvReader::readCSV(const string& filename, WindlogType& wind_data)
{

    //Delcare a string variable to store the filpath
int ct = 0;
    //Open the csv file
    ifstream file("data/"+filename);

    //Error handling to check if filpath exists
    if (!file.is_open())
    {
        cerr << "Error opening file " << "|"+filename+"|" << endl;
        return;
    }
    //Declare the variable to store each line in the csv
    string line ="";
    //Declare the variable to temporarily hold the data.
    string temp = "";
    int sr_idx = -1;    //Declare and initialize the solar radiation index
    int s_idx = -1;     //Declare and initialize the speed index
    int t_idx = -1;     //Declare and initialize the temperature index
    //Read the firstline
    getline(file, line);
    //Create a string stream of line
    stringstream ss(line);
    //Create a string vector
    Vector<string> header;
    string atemp;


    //While loop to iterate until end of line
    while (getline(ss, temp, ',' ))
    {


        //Trim the temp to get rid of any unwanted newline or whitespace.
        //This is to make the comparing of index more accurate.
        //Push the trimmed string temp, which contains the first value of the csv
        //into the header vector
        header.push(trim(temp));
        temp = "";

    }

    //For Loop to get the position/index of speed/temp/solar radiation by looping
    //and comparing the header values
    for(int i=0; i < header.size(); i++)
    {

        //Ex. if header.get(i) is SR that means the no. of iteration is the index number to find SR

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

    //Loop until end of file
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
        string  minutes = "";   /*Stores the minutes*/
        Vector <float> sensor;
        float speed = 0.0f;
        float temperature = 0.0f;
        float solarRadiation = 0.0f;


        //Extract the first column, wast.
        getline(ss, day, '/');
        getline(ss, month, '/');
        getline(ss, year, ' ');
        getline(ss, hours, ':');
        getline(ss, minutes, ',');

        //Extract the remaining columns inserting them into the sensor float vector
        while (getline(ss,temp, ','))
        {
            temp = trim(temp);
            if(temp != "N/A")
            {

            f_temp = stof(temp);
            sensor.push(f_temp);
            }
            else
            {
            sensor.push(0);
            }


        }

        //This is to check the line is empty. If there is no date, there will be no data
        if (!day.empty()&&!month.empty()&&!year.empty())
        {

    cout <<ct;
    ct++;
            //all index gets a -1 because we skiped 1 column
            //Store the values into their variables
            speed = sensor.get(s_idx-1);
            temperature = sensor.get(t_idx-1);
            solarRadiation = sensor.get(sr_idx-1);
            //Create a new instance of date and time and store the wast data
            Date date;
            date.SetDate(day, month, year);
            Time time;
            time.SetTime(hours, minutes);
            /*
            * Create temp WindRecType to store object and push into the wind_data vector
            */
            WindRecType record;
            record.setDate(date);
            record.setTime(time);
            record.setSpeed(speed);
            record.setTemperature(temperature);
            record.setSolarRadiation(solarRadiation);
            wind_data.push(record);


        }

    }
    /*
     * Close file to clear up memory
     */
    file.close();
}

string CsvReader::trim(const string& input)
{
    string result;
    for (char ch : input)
    {
        if (ch != ' ' && ch != '\t' && ch != '\n' && ch!= '\r' && ch!='\0')
        {
            result += ch;
        }
    }
    return result;
}
