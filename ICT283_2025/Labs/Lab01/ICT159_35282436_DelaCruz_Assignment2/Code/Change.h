#ifndef CHANGE_H
#define CHANGE_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Customer.h"

void calculateChange(Customer *record);
void calculateAllChange(Customer *records, int arraySize);

#endif
