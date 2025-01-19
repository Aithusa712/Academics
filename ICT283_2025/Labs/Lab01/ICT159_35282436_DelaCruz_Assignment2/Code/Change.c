#include "Change.h"
void calculateChange(Customer *record) {
    int totalCoinAmount = record->coinAmount;

    if (strcmp(record->currency, "US$") == 0) {
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
    } else if (strcmp(record->currency, "AU$") == 0) {
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
    } else if (strcmp(record->currency, "EUR") == 0) {
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
    } else {
        printf("Currency not found\n");
    }
}

void calculateAllChange(Customer *records, int arraySize) {
  for (int i = 0; i < arraySize; i++) {
    calculateChange(&records[i]);
  }
}
