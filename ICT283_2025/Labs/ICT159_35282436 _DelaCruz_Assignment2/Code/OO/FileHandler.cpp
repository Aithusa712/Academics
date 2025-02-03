#include "FileHandler.h"

void FileHandler::readChange(vector<Customer>& records) { 
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

        // Search for existing customer with same name and currency
        for (int i = 0; i < records.size(); i++) {
            if (name == records[i].getName() && currency == records[i].getCurrency()) {
                found = true;
                foundIndex = i;
                break;
            }
        }

        if (records.empty()) { // first record
            records.push_back(Customer(name, stoi(change), currency));
        } 
        else if (!found) { // no existing record found
            records.push_back(Customer(name, stoi(change), currency));
        } 
        else { // Existing record found; add change to existing record
            int newAmount = records[foundIndex].getCoinAmount() + stoi(change);
            records[foundIndex].setCoinAmount(newAmount);
        }
    }

    file.close();  
}

void FileHandler::printChange(const vector<Customer>& records) {
    ofstream outFile("change.csv");
    
    if (!outFile.is_open()) {
        cout << "Error opening file for writing" << endl;
        return;
    }

    for (const auto& record : records) {
        outFile << record.getName() << ", the change for " 
                << record.getCoinAmount() << " cents in " 
                << record.getCurrency() << " is "
                << record.getCoinDeno1() << ", "
                << record.getCoinDeno2() << ", "
                << record.getCoinDeno3() << ", "
                << record.getCoinDeno4() << "\n";
    }

    outFile.close();
}

