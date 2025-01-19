#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "Customer.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

class FileHandler {
public:
  string removeNewline(string str);
  void readChange(vector<Customer> &records);
  void printChange(const vector<Customer> &records);
};
#endif // FILEHANDLER_H
