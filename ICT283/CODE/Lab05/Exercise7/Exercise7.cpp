#include <iostream> 
#include <fstream>  //header file for file handling
#include <cmath>    //header file for the square root function
#include "vector.h"

using namespace std;

    //declare function prototypes
void calculateMean(const Vector<float>& dataArray, int size, float& mean);
void calculateStdDev(const Vector<float>& dataArray, int size, float mean, float& stdDev);

int main()
{
    //declare and intialize variables 
    int count = 0;
    float mean = 0.0f;
    float stdDev = 0.0f;

    // Open file and check if it exists
    ifstream file("data.txt");
    if (!file)
        {
        cerr << "Error: Cannot find File" << endl;
        return 1;
        }

    // Read the first line which contains the number of floating-point values
    file >> count;
    Vector<float> dataArray(count);
    float value;
    // Read the floating-point values into dataArray
    for (int i = 0; i < count; ++i)
    {

        file >> value;
        dataArray.push(value);
    }
    // Close the file
    file.close();

    // Call funtctions to calculate mean and standard deviation
    calculateMean(dataArray, count, mean);
    
    calculateStdDev(dataArray, count, mean, stdDev);

    // Print the results
    cout << "The number of floating point values (N): " << count << endl
         << "The mean of the floating point values: " << mean << endl
         << "The sample standard deviation (s): " << stdDev << endl;

    // Clean up dynamic memory


    return 0;
}

// Function to calculate the mean
void calculateMean(const Vector<float>& dataArray, int size, float& mean) 
{
    float sum = 0.0;

    for (int i = 0; i < size; ++i) 
    {
        sum += dataArray.get(i);
    }
    mean = sum / size;
}

// Function to calculate the standard deviation
void calculateStdDev(const Vector<float>& dataArray, int size, float mean, float& stdDev) 
{
    float sum = 0.0;
    
    //
    for (int i = 0; i < size; ++i) 
    {
        sum += (dataArray.get(i) - mean) * (dataArray.get(i) - mean);
    }
    stdDev = sqrt(sum / (size - 1));
}

