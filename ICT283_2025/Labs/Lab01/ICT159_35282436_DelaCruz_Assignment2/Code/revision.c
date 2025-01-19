// #include <string.h>
#include "FileHandler.h"
#include "Change.h"
#include "Customer.h"
#include <stdio.h>
#include <string.h>

void menuPrompt(Customer records[], int arraySize);
void unitTest(Customer records[], int arraySize);

int main() {

  int arraySize = 0;

  Customer records[100];
  readChange(records, &arraySize);
  calculateAllChange(records, arraySize);

  menuPrompt(records, arraySize);
}

void menuPrompt(Customer records[], int arraySize) {
  int endLoop = 0;
  do {
    int choice = 0;

    printf("\n\n1.) Enter Name\n2.) Exit\n"
           "\nChoice :");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      findCustomer(records, arraySize);
      break;
    case 2:
      printChange(records, arraySize);
      endLoop++;
      break;
    case 3:
      unitTest(records, arraySize);
      break;
    }

  } while (endLoop == 0);
}

void unitTest(Customer records[], int arraySize) {

  printf("\n\n\tUnit Test\n============================");
  for (int i = 0; i < arraySize; i++) {
    printf("\n\nCustomer Name: |%s|\nChange: |%d|\nCurrency: |%s|\n",
           records[i].name, records[i].coinAmount, records[i].currency);
    if (strcmp(records[i].currency, "US$") == 0) {
      printf("Coin: 50:%d, 20:%d, 10:%d, 1:%d", records[i].coinDeno1,
             records[i].coinDeno2, records[i].coinDeno3, records[i].coinDeno4);
    }
    if (strcmp(records[i].currency, "AU$") == 0) {
      printf("Coin: 50:%d, 20:%d, 10:%d, 5:%d", records[i].coinDeno1,
             records[i].coinDeno2, records[i].coinDeno3, records[i].coinDeno4);
    }
    if (strcmp(records[i].currency, "EUR") == 0) {
      printf("Coin: 20:%d, 10:%d, 5:%d, 1:%d", records[i].coinDeno1,
             records[i].coinDeno2, records[i].coinDeno3, records[i].coinDeno4);
    }
  }

  printf("\n============================");
}
