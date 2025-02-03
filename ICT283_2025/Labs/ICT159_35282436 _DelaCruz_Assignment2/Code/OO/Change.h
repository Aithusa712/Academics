// Change.h
#ifndef CHANGE_H
#define CHANGE_H

#include <vector>
#include <iostream>
#include "Customer.h"
using namespace std;
class Change {
public:

    // Public member functions
    void calculateChange(Customer& record);
    void calculateAllChange(vector<Customer>& records);
    static void findCustomer(const vector<Customer>& records);
};

#endif // CHANGE_H

