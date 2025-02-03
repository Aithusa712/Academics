#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Customer {
  int coinDeno4;
  int coinDeno3;
  int coinDeno2;
  int coinDeno1;
  int coinAmount;
  string name;
  string currency;

  Customer(string name, int coinAmount, string currency) {
    this->name = name;
    this->coinAmount = coinAmount;
    this->currency = currency;
    this->coinDeno1 = 0;
    this->coinDeno2 = 0;
    this->coinDeno3 = 0;
    this->coinDeno4 = 0;
  }
} typedef Customer;

void printCustomer(const Customer *record);
void findCustomer(const vector<Customer> *records);

#endif // CUSTOMER_H
