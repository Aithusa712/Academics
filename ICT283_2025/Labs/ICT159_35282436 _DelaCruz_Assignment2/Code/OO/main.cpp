#include "Change.h"
#include "Customer.h"
#include "FileHandler.h"
#include <iostream>
using namespace std;
// Function declarations
void menuPrompt(vector<Customer> &records, FileHandler &fileHandler,
                Change &changeCalculator);
void unitTest(const vector<Customer> &records);

int main() {
  vector<Customer> records;
  FileHandler fileHandler;
  Change changeCalculator;

  fileHandler.readChange(records);
  changeCalculator.calculateAllChange(records);
  menuPrompt(records, fileHandler, changeCalculator);

  return 0;
}

void menuPrompt(vector<Customer> &records, FileHandler &fileHandler,
                Change &changeCalculator) {
  bool running = true;

  do {
    int choice;

    cout << "\n\n1.) Enter Name\n"
         << "2.) Exit\n"
         << "\nChoice: ";

    if (!(cin >> choice)) {
      cout << "Invalid input. Please enter a number." << endl;
      cin.clear();
      continue;
    }

    switch (choice) {
    case 1:
      changeCalculator.findCustomer(records);
      break;
    case 2:
      fileHandler.printChange(records);
      running = false;
      break;
            case 3:

      unitTest(records);
      break;
    default:
      cout << "Invalid choice. Please try again." << endl;
      break;
    }

  } while (running);
}

void unitTest(const vector<Customer> &records) {
  cout << "\n\n\tUnit Test\n"
       << "============================" << endl;

  for (const auto &record : records) {
    cout << "\nCustomer Name: |" << record.getName() << "|\nChange: |"
         << record.getCoinAmount() << "|\nCurrency: |" << record.getCurrency()
         << "|\n";

    if (record.getCurrency() == "US$") {
      cout << "Coin: 50:" << record.getCoinDeno1()
           << ", 25:" << record.getCoinDeno2()
           << ", 10:" << record.getCoinDeno3()
           << ", 1:" << record.getCoinDeno4();
    } else if (record.getCurrency() == "AU$") {
      cout << "Coin: 50:" << record.getCoinDeno1()
           << ", 20:" << record.getCoinDeno2()
           << ", 10:" << record.getCoinDeno3()
           << ", 5:" << record.getCoinDeno4();
    } else if (record.getCurrency() == "EUR") {
      cout << "Coin: 20:" << record.getCoinDeno1()
           << ", 10:" << record.getCoinDeno2()
           << ", 5:" << record.getCoinDeno3()
           << ", 1:" << record.getCoinDeno4();
    }
  }

  cout << "\n============================" << endl;
}
