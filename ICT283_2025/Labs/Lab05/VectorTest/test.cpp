#include "Vector.h"
#include <iostream>
using namespace std;

int main() {
  /*
Vector<int> *testPtr = new Vector<int>();

  for (int i = 0; i < 10; i++){
          testPtr->push(i);
  }

  for (int i = 0; i <testPtr->size(); i++){
          cout << testPtr->get(i);
  }
  */

  Vector<string> test;
  string temp[]= {"hello", "bonjour", "Bye", "Au Revoir"};

  for (int i = 0; i < 3 ; i++) {
    test.push(temp[i]);
  }
  for (int i = 0; i < test.size(); i++) {
    cout << test[i] << endl;
  }
}
