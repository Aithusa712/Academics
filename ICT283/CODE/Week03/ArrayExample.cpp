#include <iostream>

using namespace std;

const int SIZE = 10; // size of array 
const int END = -1;  // exit flag

typedef int IntArray[SIZE]; // a new type -> an array of 10 integers 

int Input(IntArray& numbers); // return count and an array of numbers (by reference) from user input
void Output(int size, const IntArray& numbers);  //number is read-only
int main ()
{
    // 0. Create the data store
    IntArray numbers; // numbers is an array of 10 integers on the stack.

    // 1. Input
    int numberCount = Input(numbers);
    cout << "Number of items: " << numberCount << endl;
    // 2. Processing - no further processing
    
    // 3. Output
    Output(numberCount, numbers);
    return 0;


}   

void Output(int size, const IntArray& numbers)
{

    cout << "Address of numbers: " << &numbers << endl;
    cout << "Contents of numbers: " << numbers << endl;
    for(int i = 0; i<size; i++)
    {
        cout << "Address and contents of element " << i << " = >"
        << &numbers[i]  << " : " << numbers[i] <<endl;
    }
}
int Input(IntArray& numbers)
{
    cout << "Enter up to " << SIZE << " integers. " << END << " to exit " << endl;
    
    int index = 0;
    int num; 
    cout << "Number? ";
    cin >> num;

    while(num != END && index <= SIZE-1)
    {
        numbers[index] = num;
        index++;
        if(index < SIZE)
        {
            cout << "Number? ";
            cin >> num;
        }
    }
    
    return index; // return the count of items entered
}