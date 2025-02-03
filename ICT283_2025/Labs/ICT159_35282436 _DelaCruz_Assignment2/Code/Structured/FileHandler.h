#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>
#include "Customer.h"
using namespace std;


string removeNewline(string str);
void readChange(vector<Customer> *records);
void printChange(const vector<Customer> *records);

#endif // FILEHANDLER_H
