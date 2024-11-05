#include <iostream>
#include <string>
#include "vector.h"
using namespace std;

int main() {
  Vector<string> namesOriginal;
  cout << "Orginal Names" << endl << "-------------------" << endl;
  namesOriginal.add("Kim");
  namesOriginal.add("Abigail");
  namesOriginal.add("Frank");
  namesOriginal.print();
  cout << "\nCopied Names" << endl << "-------------------" << endl;
  Vector<string> namesCopy = namesOriginal;
  namesCopy.print();
 
  return 0;
}
