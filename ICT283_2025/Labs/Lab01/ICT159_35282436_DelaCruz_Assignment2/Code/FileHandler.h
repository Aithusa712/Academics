#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

void removeNewline(char *str);
void readChange(Customer records[], int *arraySize);
void printChange(Customer records[], int arraySize);

#endif
