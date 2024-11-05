
#include <iostream>
#include <iterator>
#include <map>
#include <string>

using std::cout;
using std::endl;
using std::map;
using std::string;

typedef map<string, string> NameToContact;

int main()
{
    NameToContact phonebook;
    phonebook["Snoopy"] = "9992345";
    phonebook["Charlie"] = "+6194238234";
    phonebook["Marcie"] = "+6048219234";
    phonebook["Linus"] = "+6013249685";

    string name;
    string contact;
    for(auto iter = phonebook.begin(); iter!= phonebook.end(); iter++)
    {
        name = iter->first;
        contact = iter->second;
        cout << name << "'s contact number is " << contact << endl;
    }
    return 0;
}
