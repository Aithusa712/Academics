#include <iostream>
using namespace std;

int main()
{
    cout << "-- Playing with Pointers --" << endl;
    int *ptr = nullptr;
    //int *ptr;
    //ptr = nullptr;   // Declare a pointer to an int 
    cout <<  "Addr of ptr: " << &ptr<< endl;
    cout <<  "Contents of ptr: "<< ptr << endl;

    ptr = new int;  // attempt to allocate heap memory

    if (ptr != nullptr)
    {
    *ptr = 1000;    // store 1000 at location ptr is pointing to
    cout << "Value of *ptr: " << *ptr << endl;
    cout <<  "Contents of ptr after new: "<< ptr << endl;
    }
    else
    {
        cout << "Unaable to allocate, not enough memory!"<<endl;
    }
    delete ptr; // return to OS
    ptr = nullptr;

    return 0;

 

}