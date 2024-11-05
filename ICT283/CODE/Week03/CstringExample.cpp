#include <iostream>
#include <cstring>
using namespace std;

const int SIZE = 10;
typedef char StringType[SIZE +1];

int main()
{
    StringType str1 = "Mountain";
    cout << str1 << endl;
    cout << strlen(str1) << endl;
    str1[4] = toupper(str1[4]);
    str1[7] = toupper(str1[7]);
    cout << str1 << endl;
    str1[2] = '\0';
    cout << str1 << endl;
    strcpy(str1, "Bukit");
    cout << str1 << endl;

    strncpy(str1, "Mummy", 3);
    cout << str1 << endl;
    return 0;
}