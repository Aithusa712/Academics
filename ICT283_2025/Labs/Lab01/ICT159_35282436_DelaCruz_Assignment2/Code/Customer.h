#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <stdio.h>
#include <string.h>
struct Customer{
	// Store count of coins; Coin denomination value differ for each currency;
	int coinDeno4;	
	int coinDeno3;
	int coinDeno2;
	int coinDeno1;
	int coinAmount;
	char name[50];
	char currency[3];

	
}typedef Customer;

void findCustomer(Customer records[], int arraySize);
void printCustomer(Customer record);

#endif
