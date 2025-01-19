#include "Change.h"

void calculateChange(Customer *record) {  // Changed to reference instead of pointer
    int totalCoinAmount = record->coinAmount;

    if (record->currency == "US$") {
        while (totalCoinAmount != 0) {
            if (totalCoinAmount >= 50) {
                totalCoinAmount -= 50;
                record->coinDeno1++;
            } else if (totalCoinAmount >= 25) {
                totalCoinAmount -= 25;
                record->coinDeno2++;
            } else if (totalCoinAmount >= 10) {
                totalCoinAmount -= 10;
                record->coinDeno3++;
            } else if (totalCoinAmount >= 1) {
                totalCoinAmount -= 1;
                record->coinDeno4++;
            }
        }
    } 
    else if (record->currency == "AU$") {
        while (totalCoinAmount != 0) {
            if (totalCoinAmount >= 50) {
                totalCoinAmount -= 50;
                record->coinDeno1++;
            } else if (totalCoinAmount >= 20) {
                totalCoinAmount -= 20;
                record->coinDeno2++;
            } else if (totalCoinAmount >= 10) {
                totalCoinAmount -= 10;
                record->coinDeno3++;
            } else if (totalCoinAmount >= 5) {
                totalCoinAmount -= 5;
                record->coinDeno4++;
            }
        }
    } 
    else if (record->currency == "EUR") {
        while (totalCoinAmount != 0) {
            if (totalCoinAmount >= 20) {
                totalCoinAmount -= 20;
                record->coinDeno1++;
            } else if (totalCoinAmount >= 10) {
                totalCoinAmount -= 10;
                record->coinDeno2++;
            } else if (totalCoinAmount >= 5) {
                totalCoinAmount -= 5;
                record->coinDeno3++;
            } else if (totalCoinAmount >= 1) {
                totalCoinAmount -= 1;
                record->coinDeno4++;
            }
        }
    } 
    else {
        cout << "Currency not found" << endl;
    }
}


void calculateAllChange(vector<Customer> *records) { 
    for (int i = 0; i < records->size(); i++) {
        calculateChange(&(*records)[i]);
    }
}
