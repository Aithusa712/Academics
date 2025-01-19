#include "Customer.h"
void printCustomer(Customer record) {
  printf("\nCustomer:\n%s %d cents in %s \n\nChange", record.name,
         record.coinAmount, record.currency);
  if (strcmp(record.currency, "US$") == 0) {
    if (record.coinDeno1 != 0) {
      printf("\n50 cents: %d", record.coinDeno1);
    }
    if (record.coinDeno2 != 0) {
      printf("\n25 cents: %d", record.coinDeno2);
    }
    if (record.coinDeno3 != 0) {
      printf("\n10 cents: %d", record.coinDeno3);
    }
    if (record.coinDeno4 != 0) {
      printf("\n1 cent: %d", record.coinDeno4);
    }
  }
  if (strcmp(record.currency, "AU$") == 0) {
    if (record.coinDeno1 != 0) {
      printf("\n50 cents: %d", record.coinDeno1);
    }
    if (record.coinDeno2 != 0) {
      printf("\n20 cents: %d", record.coinDeno2);
    }
    if (record.coinDeno3 != 0) {
      printf("\n10 cents: %d", record.coinDeno3);
    }
    if (record.coinDeno4 != 0) {
      printf("\n5 cent: %d", record.coinDeno4);
    }


  }
  if (strcmp(record.currency, "EUR") == 0) {
    if (record.coinDeno1 != 0) {
      printf("\n20 cents: %d", record.coinDeno1);
    }
    if (record.coinDeno2 != 0) {
      printf("\n10 cents: %d", record.coinDeno2);
    }
    if (record.coinDeno3 != 0) {
      printf("\n5 cents: %d", record.coinDeno3);
    }
    if (record.coinDeno4 != 0) {
      printf("\n1 cent: %d", record.coinDeno4);
    }


  }

  printf("\n");
};

void findCustomer(Customer records[], int arraySize) {
  int found = 0;
  char name[50];
  printf("Name: ");
  scanf("%49s", name);
  for (int i = 0; i < arraySize; i++) {
    if ((strcmp(name, records[i].name) == 0)) {
      found++;
      
    printCustomer(records[i]);
    }
  }

  if (found == 0) { 
    printf("Not found");
  }
}
