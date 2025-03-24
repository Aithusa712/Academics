#include "Bst.h"
#include <iostream>
using namespace std;
struct Record {
  float x;
  float y;
  int key;
  bool operator<(const Record &other) const {
    if (key < other.key) {
      return true;
    } else {
      return false;
    }
  }

   bool operator>(const Record &other) const {
    if (key > other.key) {
      return true;
    } else {
      return false;
    }
  }


  bool operator==(const Record &other) const {
    if (key == other.key) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
    Record test0;
    test0.key = 0;
    test0.x = 15;
    test0.y = 52;
    
    Record test1;
    test1.key = 1;
    test1.x = 23;
    test1.y = 32;

    Record test2;
    test2.key = 2;
    test2.x = 10;
    test2.y = 50;

    Record test3;
    test3.key = 3;
    test3.x = 11;
    test3.y = 55;
    
    Bst<Record> testTree;
    testTree.Insert(test2);
    testTree.Insert(test3);
    testTree.Insert(test0);
    testTree.Insert(test1);

    Record target;
    target.key = 0;
    cout << "Expected key 0 Key ["<<testTree.Get(target).key<<"]: x value: "<<testTree.Get(target).x << " y value: " << testTree.Get(target).y << endl;


  target.key = 1;
    cout << "Expected key 1 Key ["<<testTree.Get(target).key<<"]: x value: "<<testTree.Get(target).x << " y value: " << testTree.Get(target).y << endl;



  target.key = 2;
    cout << "Expected key 2 Key ["<<testTree.Get(target).key<<"]: x value: "<<testTree.Get(target).x << " y value: " << testTree.Get(target).y << endl;

  target.key = 3;
    cout << "Expected key 3 Key ["<<testTree.Get(target).key<<"]: x value: "<<testTree.Get(target).x << " y value: " << testTree.Get(target).y << endl;

}
