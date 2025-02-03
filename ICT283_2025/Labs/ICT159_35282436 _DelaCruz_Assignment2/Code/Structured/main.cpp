#include <iostream>
#include "FileHandler.h"
#include "Change.h"
#include "Customer.h"
// Function declarations
void menuPrompt(vector<Customer> *records);
void unitTest(const vector<Customer> *records);

int main() {
    vector<Customer> *records = new vector<Customer>();
    
    readChange(records);
    calculateAllChange(records);
    menuPrompt(records);
    
    return 0;
}

void menuPrompt(vector<Customer> *records) {
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
                findCustomer(records);
                break;
            case 2:
                printChange(records);
                running = false;
                break;
            case 3:  // Hidden option for unit testing
                unitTest(records);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (running);
}

void unitTest(const vector<Customer> *records) {
    cout << "\n\n\tUnit Test\n"
         << "============================" << endl;
    
    for (const auto& record : *records) {
        cout << "\nCustomer Name: |" << record.name 
             << "|\nChange: |" << record.coinAmount 
             << "|\nCurrency: |" << record.currency << "|\n";
        
        if (record.currency == "US$") {
            cout << "Coin: 50:" << record.coinDeno1 
                 << ", 25:" << record.coinDeno2 
                 << ", 10:" << record.coinDeno3 
                 << ", 1:" << record.coinDeno4;
        }
        else if (record.currency == "AU$") {
            cout << "Coin: 50:" << record.coinDeno1 
                 << ", 20:" << record.coinDeno2 
                 << ", 10:" << record.coinDeno3 
                 << ", 5:" << record.coinDeno4;
        }
        else if (record.currency == "EUR") {
            cout << "Coin: 20:" << record.coinDeno1 
                 << ", 10:" << record.coinDeno2 
                 << ", 5:" << record.coinDeno3 
                 << ", 1:" << record.coinDeno4;
        }
    }

    cout << "\n============================" << endl;
}

