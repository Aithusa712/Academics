#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

const int SIZE = 8;

typedef vector<int> IntVector;

typedef vector<IntVector> IntTable; //vector of vectors of integers

void Display(const IntVector& numbers);

void Display2(const IntVector& numbers);

void Display3(const IntVector& numbers);

void DisplayTable(const IntTable& table);

int main()
{
    //0. data store + init

    srand(time(NULL)); // randomize it with a changing "seed", use time
    IntVector numbers;
    IntTable table;
    

    //1. Input put in another functions

    for (int i = 0; i < SIZE; i++)
    {
        numbers.push_back(rand() % 100); // 0 to 99
    }

    for (int i = 0; i < SIZE; i++)
    {
        table.push_back(numbers); // create a SIZE x SIZE 2d array, using the same array
    }                             // making a copy of numbers eact time, using the copy constructor.

    //table[0][0] *= -1;
    //table[SIZE-1][SIZE-1] *= -1; // demonstrate that each row is different 
    
    //3. Output

    Display3(numbers);

    cout << endl << endl;
    DisplayTable(table);    // Print the 2d Array

}



void Display(const IntVector& numbers)
{

    cout << "[";
    for (unsigned i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << " ";
    }
    
    cout << "]";
}

void Display2(const IntVector& numbers)
{
    for(IntVector::const_iterator citer = numbers.begin(); citer != numbers.end(); citer++)
    {
        cout << *citer << " - ";
    }
    cout << endl;
}


void Display3(const IntVector& numbers)
{
    for (int numbers:numbers)
    {
        cout << numbers << ", ";
    }
    cout << endl;
}


void DisplayTable(const IntTable& table)
{
    for(unsigned row = 0; row < table.size(); row++)
    {
        for(unsigned col = 0; col < table[row].size(); col++)
        {
            cout << table[row][col] << " ";
        }
        cout << endl; 
    }
}