
// Customer.cpp
#include "Customer.h"

Customer::Customer() {
  coinDeno1 = 0;
  coinDeno2 = 0;
  coinDeno3 = 0;
  coinDeno4 = 0;
  coinAmount = 0;
  name = "";
  currency = "";
}

Customer::Customer(string name, int coinAmount, string currency) {
  this->name = name;
  this->coinAmount = coinAmount;
  this->currency = currency;
  this->coinDeno1 = 0;
  this->coinDeno2 = 0;
  this->coinDeno3 = 0;
  this->coinDeno4 = 0;
}

// Getters
int Customer::getCoinDeno1() const { return coinDeno1; }
int Customer::getCoinDeno2() const { return coinDeno2; }
int Customer::getCoinDeno3() const { return coinDeno3; }
int Customer::getCoinDeno4() const { return coinDeno4; }
int Customer::getCoinAmount() const { return coinAmount; }
string Customer::getName() const { return name; }
string Customer::getCurrency() const { return currency; }

// Setters
void Customer::setCoinDeno1(int value) { coinDeno1 = value; }
void Customer::setCoinDeno2(int value) { coinDeno2 = value; }
void Customer::setCoinDeno3(int value) { coinDeno3 = value; }
void Customer::setCoinDeno4(int value) { coinDeno4 = value; }
void Customer::setCoinAmount(int amount) { coinAmount = amount; }
void Customer::setName(const string &name) { this->name = name; }
void Customer::setCurrency(const string &currency) { this->currency = currency; }

void Customer::printCustomer() const {
  cout << "\nCustomer:\n"
       << name << " " << coinAmount << " cents in " << currency << "\n\nChange";

  if (currency == "US$") {
    if (coinDeno1 != 0)
      cout << "\n50 cents: " << coinDeno1;
    if (coinDeno2 != 0)
      cout << "\n25 cents: " << coinDeno2;
    if (coinDeno3 != 0)
      cout << "\n10 cents: " << coinDeno3;
    if (coinDeno4 != 0)
      cout << "\n1 cent: " << coinDeno4;
  } else if (currency == "AU$") {
    if (coinDeno1 != 0)
      cout << "\n50 cents: " << coinDeno1;
    if (coinDeno2 != 0)
      cout << "\n20 cents: " << coinDeno2;
    if (coinDeno3 != 0)
      cout << "\n10 cents: " << coinDeno3;
    if (coinDeno4 != 0)
      cout << "\n5 cent: " << coinDeno4;
  } else if (currency == "EUR") {
    if (coinDeno1 != 0)
      cout << "\n20 cents: " << coinDeno1;
    if (coinDeno2 != 0)
      cout << "\n10 cents: " << coinDeno2;
    if (coinDeno3 != 0)
      cout << "\n5 cents: " << coinDeno3;
    if (coinDeno4 != 0)
      cout << "\n1 cent: " << coinDeno4;
  }

  cout << "\n";
}


