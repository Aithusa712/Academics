#include "FileHandler.h"
#include "Customer.h"

void removeNewline(char *str) {
  size_t len = strlen(str); // Get the length of the string

  // Check if the last character is a newline
  if (len > 0 && str[len - 1] == '\n') {
    str[len - 1] = '\0'; // Replace newline with null terminator
  }
}
void readChange(Customer records[], int *arraySize) {

  FILE *fptr;
  char tempString[100];
  int currentRecordSize = 0;
  fptr = fopen("coins.txt", "r");
  while (fgets(tempString, 100, fptr)) {
    int found = 0;
    int foundIndex = 0;
    // printf("%s", tempString);
    char *token = strtok(tempString, " ");
    char *tempName = token;
    token = strtok(NULL, " ");
    char *tempChange = token;
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    char *tempCurrency = token;
    removeNewline(tempCurrency);

    // Algo to find existing customer record
    for (int i = 0; i <= currentRecordSize; i++) {
      if ((strcmp(tempName, records[i].name) == 0) &&
          (strcmp(tempCurrency, records[i].currency) == 0)) {
        found++;
        foundIndex = i;
        break;
      }
    }

    if (currentRecordSize == 0) { // first count record
      strcpy(records[currentRecordSize].name, tempName);
      records[currentRecordSize].coinAmount = atoi(tempChange);
      strcpy(records[currentRecordSize].currency, tempCurrency);
      (*arraySize)++;
      currentRecordSize++;

    } else if (found == 0) { // no existing record found
      strcpy(records[currentRecordSize].name, tempName);
      records[currentRecordSize].coinAmount = atoi(tempChange);
      strcpy(records[currentRecordSize].currency, tempCurrency);
      (*arraySize)++;
      currentRecordSize++;

    } else { // Existing record found; add change to existing record.
      records[foundIndex].coinAmount += atof(tempChange);
    }
  }
}

void printChange(Customer records[], int arraySize) {
  FILE *fptr;
  fptr = fopen("change.csv", "w");
  for (int i = 0; i < arraySize; i++) {
    fprintf(fptr, "%s, the change for %d cents in %s is %d, %d, %d, %d\n",
            records[i].name, records[i].coinAmount, records[i].currency,
            records[i].coinDeno1, records[i].coinDeno2, records[i].coinDeno3,
            records[i].coinDeno4);
  }
}
