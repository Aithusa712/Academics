#include "Change.h"

void Change::calculateChange(Customer& record) {
    int totalCoinAmount = record.getCoinAmount();
    int deno1 = 0, deno2 = 0, deno3 = 0, deno4 = 0;

    if (record.getCurrency() == "US$") {
        while (totalCoinAmount != 0) {
            if (totalCoinAmount >= 50) {
                totalCoinAmount -= 50;
                deno1++;
            } else if (totalCoinAmount >= 25) {
                totalCoinAmount -= 25;
                deno2++;
            } else if (totalCoinAmount >= 10) {
                totalCoinAmount -= 10;
                deno3++;
            } else if (totalCoinAmount >= 1) {
                totalCoinAmount -= 1;
                deno4++;
            }
        }
    } 
    else if (record.getCurrency() == "AU$") {
        while (totalCoinAmount != 0) {
            if (totalCoinAmount >= 50) {
                totalCoinAmount -= 50;
                deno1++;
            } else if (totalCoinAmount >= 20) {
                totalCoinAmount -= 20;
                deno2++;
            } else if (totalCoinAmount >= 10) {
                totalCoinAmount -= 10;
                deno3++;
            } else if (totalCoinAmount >= 5) {
                totalCoinAmount -= 5;
                deno4++;
            }
        }
    } 
    else if (record.getCurrency() == "EUR") {
        while (totalCoinAmount != 0) {
            if (totalCoinAmount >= 20) {
                totalCoinAmount -= 20;
                deno1++;
            } else if (totalCoinAmount >= 10) {
                totalCoinAmount -= 10;
                deno2++;
            } else if (totalCoinAmount >= 5) {
                totalCoinAmount -= 5;
                deno3++;
            } else if (totalCoinAmount >= 1) {
                totalCoinAmount -= 1;
                deno4++;
            }
        }
    } 
    else {
        cout << "Currency not found" << endl;
        return;
    }

    // Set the calculated denominations
    record.setCoinDeno1(deno1);
    record.setCoinDeno2(deno2);
    record.setCoinDeno3(deno3);
    record.setCoinDeno4(deno4);
}

void Change::calculateAllChange(vector<Customer>& records) {
    for (auto& record : records) {
        calculateChange(record);
    }
}

void Change::findCustomer(const vector<Customer>& records) {
  string searchName;
  cout << "Name: ";
  cin >> searchName;

  bool found = false;

  for (const auto &customer : records) {
    if (searchName == customer.getName()) {
      found = true;
      customer.printCustomer();
    }
  }

  if (!found) {
    cout << "Not found" << endl;
  }
}
