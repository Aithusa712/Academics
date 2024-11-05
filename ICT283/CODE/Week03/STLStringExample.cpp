#include <iostream>
#include <string>
using namespace std;

int main()
{
    string name = "King Kong";
    name = "Bundy";
    cout << name << endl;
    string name2 = "Bundy";

    if(name==name2)
    {
        cout<<"Both names are the same" <<endl;
    }
    string name3 = "Donky Kong";
    cout << name3[4] << endl;
    //cout << name3[12] << endl;
    return 0;
}