#include "Customer.h"


void printCustomer(const Customer *record) {
    cout << "\nCustomer:\n" << record->name << " " 
         << record->coinAmount << " cents in " 
         << record->currency << "\n\nChange";

    if (record->currency == "US$") {
        if (record->coinDeno1 != 0) {
            cout << "\n50 cents: " << record->coinDeno1;
        }
        if (record->coinDeno2 != 0) {
            cout << "\n25 cents: " << record->coinDeno2;
        }
        if (record->coinDeno3 != 0) {
            cout << "\n10 cents: " << record->coinDeno3;
        }
        if (record->coinDeno4 != 0) {
            cout << "\n1 cent: " << record->coinDeno4;
        }
    }
    else if (record->currency == "AU$") {
        if (record->coinDeno1 != 0) {
            cout << "\n50 cents: " << record->coinDeno1;
        }
        if (record->coinDeno2 != 0) {
            cout << "\n20 cents: " << record->coinDeno2;
        }
        if (record->coinDeno3 != 0) {
            cout << "\n10 cents: " << record->coinDeno3;
        }
        if (record->coinDeno4 != 0) {
            cout << "\n5 cent: " << record->coinDeno4;
        }
    }
    else if (record->currency == "EUR") {
        if (record->coinDeno1 != 0) {
            cout << "\n20 cents: " << record->coinDeno1;
        }
        if (record->coinDeno2 != 0) {
            cout << "\n10 cents: " << record->coinDeno2;
        }
        if (record->coinDeno3 != 0) {
            cout << "\n5 cents: " << record->coinDeno3;
        }
        if (record->coinDeno4 != 0) {
            cout << "\n1 cent: " << record->coinDeno4;
        }
    }

    cout << "\n";
}


void findCustomer(const vector<Customer> *records) {
    string name;
    cout << "Name: ";
    cin >> name;
    
    bool found = false;
    
    for (size_t i = 0; i < records->size(); i++) {
        if (name == (*records)[i].name) {
            found = true;
            printCustomer(&(*records)[i]);
        }
    }

    if (!found) {
        cout << "Not found" << endl;
    }
}

