// StackTest.cpp
// normal comments here - not doxygen comments
// Tests Stack class
//
// smr
//

The key concepts in these tests is the data structure is tested for stability and usage.


//--------------------------------------------------------

#include "Stack.h"  // Our minimal Stack, not the STL stack. Include our files first

#include <iostream>  // Then include others, after leaving a blank line
#include <string>

// Be careful with what we expose
// exposing only the specific items used
// saves us the hassle to have to write std::cout everytime,, .. etc
using std::cout;
using std::endl;
using std::cin;
using std::string;

//--------------------------------------------------------

typedef Stack<char> CharStack;

//--------------------------------------------------------

void Input (string &str);
void Reverse (const string &str, CharStack &temp);
void Output (CharStack &temp);

//--------------------------------------------------------

void Test0_Typical_use (string str);
void Test1_CopyConstruct (string str);
void Test2_AssignOperator (string str);
void Test3_smallStack (string str);
void Test4_destructor (string str);


//--------------------------------------------------------

int main()
{
    string str;
    Input (str);

    cout << "Test0_Typical_use" << endl;
    Test0_Typical_use (str);
    cout << "Test1_CopyConstruct" << endl;
    Test1_CopyConstruct (str);
    cout << "Test2_AssignOperator" << endl;
    Test2_AssignOperator (str);
    cout << "Test3_smallStack" << endl;
    Test3_smallStack (str);

    cout << "Test4_destructor" << endl; // done last as assert will terminate as expected
    Test4_destructor (str);


    cout << endl;

    return 0;
}

//--------------------------------------------------------
void Input (string &str)
{
    cout << "Enter a string, then press <Enter>: ";
    getline(cin,str);
}

//--------------------------------------------------------
void Reverse (const string &str, CharStack &temp)
{
    bool okay = true;
    for (unsigned index = 0; index < str.length() && okay; index++)
    {
        okay = temp.Push(str[index]);
    }
}

//--------------------------------------------------------
void Output (CharStack &temp)
{
    bool okay;
    char ch;

    cout << "Your string reversed is: ";
    okay = temp.Pop(ch);
    while (okay)
    {
        cout << ch;
        okay = temp.Pop(ch);
    }
    cout << endl;
}


//--------------------------------------------------------

void Test0_Typical_use (string str)
{

    CharStack temp;

    Reverse (str, temp); // check lecture material, notes at the bottom and refactor

    Output (temp);

    cout << endl;
}

//--------------------------------------------------------
void Test1_CopyConstruct (string str)
{

    CharStack temp;

    Reverse (str, temp); // check lecture material, notes at the bottom and refactor

    CharStack temp1(temp);

    temp1.Push('Z');

    Output (temp);

    Output (temp1);

    cout << endl;
}

//--------------------------------------------------------
void Test2_AssignOperator (string str)
{

    CharStack temp;

    Reverse (str, temp);

    CharStack temp1;

    temp1 = temp;

    temp1.Push('Z');

    Output (temp);

    Output (temp1);

    cout << endl;
}

//--------------------------------------------------------

void Test3_smallStack (string str)
{

    CharStack temp(3);

    cout << "Empty: " << temp.Empty() << endl;
    cout << "Full: " <<temp.Full() << endl;

    Reverse (str, temp);

    cout << "Empty: " << temp.Empty() << endl;
    cout << "Full: " <<temp.Full() << endl;

    Output (temp);

    cout << "Empty: " << temp.Empty() << endl;
    cout << "Full: " <<temp.Full() << endl;

    cout << endl;
}

void Test4_destructor (string str)
{

    CharStack temp;

    temp.~Stack();  // destructor called

    Reverse (str, temp);  // should crash in this call as assert will terminate

    Output (temp);

    cout << endl;
}


//--------------------------------------------------------
