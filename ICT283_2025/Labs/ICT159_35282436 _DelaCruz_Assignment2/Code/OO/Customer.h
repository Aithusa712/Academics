#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Customer {
public:
  Customer();
  Customer(string name, int coinAmount, string currency);
  void printCustomer() const;

  int getCoinDeno1() const;
  int getCoinDeno2() const;
  int getCoinDeno3() const;
  int getCoinDeno4() const;
  int getCoinAmount() const;
  string getName() const;
  string getCurrency() const;

  void setCoinDeno1(int value);
  void setCoinDeno2(int value);
  void setCoinDeno3(int value);
  void setCoinDeno4(int value);
  void setCoinAmount(int amount);
  void setName(const string &name);
  void setCurrency(const string &currency);

private:
  int coinDeno4;
  int coinDeno3;
  int coinDeno2;
  int coinDeno1;
  int coinAmount;
  string name;
  string currency;
};

#endif // CUSTOMER_H
