#include "SensorRecType.h"
#include "Vector.h"
#include <iostream>
using namespace std;

void TestVectorInt() {
  Vector<int> test;
  test.push(5);
  test.push(9);
  test.push(3);

  int test_1 = test[0];
  int test_2 = test[1];
  int test_3 = test[2];

  if (test_1 == 5 && test_2 == 9 && test_3 == 3) {
    cout << "TestVectorInt() Test: PASS" << endl;
  } else {
    cout << "TestVectorInt() Test: FAIL" << endl;
  }
}

void TestVectorSensor() {
  Vector<SensorRecType> test;
  for (int i = 0; i < 3; i++) {
    SensorRecType temp;

    temp.speed = 5 + (i * 5);             // 5, 10, 15
    temp.temperature = 15 + (i * 15);     // 15, 30, 45
    temp.solar_radiation = 10 + (i * 10); // 10, 20, 30

    test.push(temp);
  }

  if (test[1].speed == 10 && test[2].temperature == 45 &&
      test[0].solar_radiation == 10) {
    cout << "TestVectorSensor() Test: PASS" << endl;
  } else {

    cout << "TestVectorSensor() Test: FAIL" << endl;
  }
}
int main() {

  TestVectorInt();
  TestVectorSensor();
}
