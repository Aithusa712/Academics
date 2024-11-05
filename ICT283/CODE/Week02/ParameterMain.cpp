#include <iostream>
using namespace std;

void Func1(int number);        // pass by value
void Func2(int &number);       // pass by reference
void Func3(const int& number); // pass by constant reference 
void Func4(int *ptr);       // pass by pointer
int main()
{
    int num = 8;
    cout << "Initial num = " << num << endl;
    Func1(num);
    cout << "After Func1(), num = " << num << endl;
    Func2(num);
    cout << "After Func2(), num = " << num << endl;
    Func3(num);
    cout << "After Func3(), num = " << num << endl;
    Func4(&num);
    cout << "After Func4(), num = " << num << endl;
    return 0;
}

void Func4(int *ptr)
{
    *ptr = 13;
    cout << "   -- Func4(), number = " << *ptr << endl; //
}

void Func3(const int& number)
{
    //number = 12;   // modification/write NOT OK
    cout << "   -- Func3(), number = " << number << endl; // reading OK
}

void Func2(int &number)
{
number = 11;
    cout << "   -- Func2(), number = " << number << endl;
}

void Func1(int number)
{
    number = 10;
    cout << "   -- Func1(), number = " << number << endl;
}
/*
Find out about the following:
It is possible to declare a pointer with no initial value?  NO

Is it possible to declare a reference which does not contain an initial value? NO

A pointer variable can be changed to point to something else. 
Can this be done with a reference? NO

A pointer can be set to contain the NULL (or nullptr) value. 
Can you make a reference NULL (or nullptr)? [1] NO

Can you do pointer like arithmetic on references? NO
*/