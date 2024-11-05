
#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 50;
typedef char StringType[SIZE +1];
int Count(const StringType &str1, const StringType &str2);

int main()
{
    StringType str1 = "This is history";
    StringType str2 ="is";

    int numOccurences = Count (str1, str2);
    cout << "There are " << numOccurences << " " << str2 << ".";
    return 0;
}



int Count (const StringType &str1, const StringType &str2)
{
	int counter = 0;

	// Prime the while loop by looking for a first occurrence
	const char *ptr = strstr(str1, str2);

	// While we have found an occurrence of str2 in str1
	while (ptr != NULL)
	{
		counter++;
        cout << "ptr is now pointing to the start of: " << ptr << endl;
		ptr++; // go to the next char in str1. why? See next line
        cout << " --> after ptr++, ptr is now pointing to the start of: " << ptr << endl;
		ptr = strstr (ptr, str2);
	}

	return counter;
}