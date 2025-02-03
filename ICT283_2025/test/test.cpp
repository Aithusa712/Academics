#include <iostream>
#include <string>
using namespace std;

int main() {
  string str;

  cout << "Enter a string: ";
  getline(cin, str);

  cout << endl << "The characters in your string were: " << endl;

  for (string::iterator itr = str.begin(); itr != str.end(); itr++) {
    cout << *itr << endl;
  }

  cout << endl;
  return 0;
}
