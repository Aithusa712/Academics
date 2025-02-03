#include "FileHandler.h"
#include <fstream>
#include <sstream>
#include <string>


void readChange(vector<Customer> *records) { 
    string tempString;
    
    ifstream file("coins.txt");
    if (!file.is_open()) { 
        cout << "Error opening file" << endl;
        return;
    }

    while (getline(file, tempString)) {
        istringstream ss(tempString);
        
        string name;
        string change;
        string currency;
        string skip;
        
        ss >> name >> change >> skip >> skip >> currency;
        bool found = false; 
        int foundIndex = -1; 

        for (int i = 0; i < records->size(); i++) {
            if (name == (*records)[i].name && currency == (*records)[i].currency) {
                found = true;
                foundIndex = i;
                break;
            }
        }

        if (records->empty()) { // first record
            records->push_back(Customer(name, stoi(change), currency));
        } 
        else if (!found) { // no existing record found
            records->push_back(Customer(name, stoi(change), currency));
        } 
        else { // Existing record found; add change to existing record
            (*records)[foundIndex].coinAmount += stoi(change);
        }
    }

    file.close();  
}


void printChange(const vector<Customer> *records) {
    ofstream outFile("change.csv");
    
    if (!outFile.is_open()) {
        cout << "Error opening file for writing" << endl;
        return;
    }

    for (const auto& record : *records) {  // Using range-based for loop
        outFile << record.name << ", the change for " 
                << record.coinAmount << " cents in " 
                << record.currency << " is "
                << record.coinDeno1 << ", "
                << record.coinDeno2 << ", "
                << record.coinDeno3 << ", "
                << record.coinDeno4 << "\n";
    }

    outFile.close();
}
