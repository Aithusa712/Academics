// StackTest.cpp
// normal comments here - not doxygen comments
// Tests Stack classes
//
// Nicola Ritter
// modified smr
//
//
//--------------------------------------------------------

#include "Stack1.h"  // Our minimal Stack, not the STL stack. Include our files first

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

int main()
{
	string str;
	CharStack temp;

	Input (str);
	Reverse (str, temp); // check lecture material, notes at the bottom and refactor
	Output (temp);

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
