#include "Date.h"
#include "Time.h"

#include <iostream>

using namespace std;

void TestSetGetDay() {
  Date test;
  test.SetDay(10);

  if (test.GetDay() == 10) {
    cout << "GetDay() SetDay() Test: PASS" << endl;
  } else {
    cout << "GetDay() SetDay() Test: FAIL" << endl;
  }
}
void TestSetGetMonth() {
  Date test;
  test.SetMonth(8);

  if (test.GetMonth() == 8) {
    cout << "GetMonth() SetMonth() Test: PASS" << endl;
  } else {
    cout << "GetMonth() SetMonth() Test: FAIL" << endl;
  }
}
void TestSetGetYear() {
  Date test;
  test.SetYear(2025);
  if (test.GetYear() == 2025) {
    cout << "GetYear() SetYear() Test: PASS" << endl;
  } else {
    cout << "GetYear() SetYear() Test: FAIL" << endl;
  }
}

void TestSetGetMinutes() {
  Time test;
  test.SetMinutes(30);
  if (test.GetMinutes() == 30) {
    cout << "GetMinutes() SetMinutes() Test: PASS" << endl;
  } else {
    cout << "GetMinutes() SetMinutes() Test: FAIL" << endl;
  }
}

void TestSetGetHours() {
  Time test;
  test.SetHours(12);

  if (test.GetHours() == 12) {
    cout << "GetHours() SetHours() Test: PASS" << endl;
  } else {
    cout << "GetHours() SetHours() Test: FAIL" << endl;
  }
}

int main() {
  TestSetGetDay();
  TestSetGetMonth();
  TestSetGetYear();
  TestSetGetMinutes();
  TestSetGetHours();
}
