#include <iostream>
#include <cmath>
#include "Calculator.h"
#include "Map.h"  // Assuming this is the custom Map class header

void testCalculateAverage() {
    Calculator calculator;
    Map<int, float> data;

    // Test case 1: Normal case
    data.Insert(0, 1.0f);
    data.Insert(1, 2.0f);
    data.Insert(2, 3.0f);
    float result = calculator.CalculateAverage(data);
    if (std::fabs(result - 2.0f) < 1e-6) {
        std::cout << "CalculateAverage Normal Case: Passed\n";
    } else {
        std::cout << "CalculateAverage Normal Case: Failed\n";
    }

    // Test case 2: Single value
    data.Clear();
    data.Insert(0, 10.0f);
    result = calculator.CalculateAverage(data);
    if (result == 0.0f) {
        std::cout << "CalculateAverage Single Value: Passed\n";
    } else {
        std::cout << "CalculateAverage Single Value: Failed\n";
    }

    // Test case 3: Empty map
    data.Clear();
    result = calculator.CalculateAverage(data);
    if (result == 0.0f) {
        std::cout << "CalculateAverage Empty: Passed\n";
    } else {
        std::cout << "CalculateAverage Empty: Failed\n";
    }
}

void testCalculateStandardDeviation() {
    Calculator calculator;
    Map<int, float> data;

    // Test case: Normal case
    data.Insert(0, 2.0f);
    data.Insert(1, 4.0f);
    data.Insert(2, 4.0f);
    data.Insert(3, 4.0f);
    data.Insert(4, 5.0f);
    data.Insert(5, 5.0f);
    data.Insert(6, 7.0f);
    data.Insert(7, 9.0f);
    float mean = 5.0f;
    float result = calculator.CalculateStandardDeviation(data, mean);
    if (std::fabs(result - 2.0f) < 0.1f) {
        std::cout << "CalculateStandardDeviation Normal Case: Passed\n";
    } else {
        std::cout << "CalculateStandardDeviation Normal Case: Failed\n";
    }
}

void testCalculate_sPCC() {
    Calculator calculator;
    Map<int, float> data1, data2;

    // Test case: Normal case
    data1.Insert(0, 1.0f);
    data1.Insert(1, 2.0f);
    data1.Insert(2, 3.0f);
    data2.Insert(0, 4.0f);
    data2.Insert(1, 5.0f);
    data2.Insert(2, 6.0f);
    float result = calculator.Calculate_sPCC(data1, data2);
    if (std::fabs(result - 1.0f) < 1e-6) {
        std::cout << "Calculate_sPCC Normal Case: Passed\n";
    } else {
        std::cout << "Calculate_sPCC Normal Case: Failed\n";
    }

    // Test case: Size mismatch
    data1.Clear();
    data2.Clear();
    data1.Insert(0, 1.0);
    data1.Insert(1, 2.0f);
    data2.Insert(0, 4.0f);
    result = calculator.Calculate_sPCC(data1, data2);
    if (result == -1.0f) {
        std::cout << "Calculate_sPCC Size Mismatch: Passed\n";
    } else {
        std::cout << "Calculate_sPCC Size Mismatch: Failed\n";
    }
}

int main() {
    testCalculateAverage();
    testCalculateStandardDeviation();
    testCalculate_sPCC();
    return 0;
}
