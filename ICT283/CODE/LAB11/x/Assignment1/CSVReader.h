#ifndef CSVREADER_H
#define CSVREADER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "vector.h"
#include "WindRecType.h"

using namespace std;

/**
 * \file CSVReader.h
 * \brief Header file for the CsvReader class.
 */

/**
 * \class CsvReader
 * \brief CsvReader class handles the reading of csv files
 */

class CsvReader
{
public:
    /**
    * @brief  Read csv file
    *
    * This function will read the filename path from the parameter string and store all the data into wind_data
    * @param filename - the path of the filename of the csv file
    * @return void
    */
    void readCSV(const string& filename, WindlogBST& wind_data);
    /**
    * @brief Remove whitespace, newline in a string
    *
    * This function will take in a string parameter and remove any whitespace, newline, tab in the string and returns it
    * @param input - the string to be trimmed
    * @return string
    */
    string trim(const string& input);
};





#endif // CSVREADER_H
