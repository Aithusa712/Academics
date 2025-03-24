#include "Bst.h"
#include "Date.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

void readCSV(const string &filename, Bst<Date> &dateTree, int &record) {
  ifstream file(filename);
  if (!file.is_open()) {
    cerr << "Error opening file " << filename << endl;
    return;
  }

  string line;
  getline(file, line); // Assuming first line is header
  while (getline(file, line)) {

    record++;
    stringstream ss(line);
    string day, month, year;
    getline(ss, day, '/');
    getline(ss, month, '/');
    getline(ss, year, ' ');

    if (!day.empty() && !month.empty() && !year.empty()) {
      Date date;
      date.SetDate(day, month, year);
      dateTree.Insert(date);
    }
  }
  file.close();
}

void PrintNode(Date &date) { cout << "[" << date << "]" << endl; }

int main() {
  int record = 1;
  Bst<Date> dateTree;

  /*readCSV("data.txt", dateTree, record);*/
  /**/
  ifstream file("data/data_source.txt");
  if (!file.is_open()) {
    cerr << "Error opening data_source.txt" << endl;
    return 1;
  }

  string filename;
  while (getline(file, filename)) {
    filename = "data/" + filename.substr(0, filename.size() - 1);
    readCSV(filename, dateTree, record);
  }

  cout << "---------Traversal---------";
  cout << endl;

  cout << "In-order traversal: \n";
  dateTree.printInOrder(PrintNode);
  cout << endl;

  // cout << "Pre-order traversal: ";
  // dateTree.printPreOrder(PrintNode);
  cout << endl;

  // cout << "Post-order traversal: ";
  // dateTree.printPostOrder(PrintNode);
  // cout << endl;

  cout << endl;
  cout << "---------Search Tree---------";
  cout << endl;

  // Example search
  // 19/05/2021
  Date searchDate1;
  searchDate1.SetDate("05", "19", "2021"); // Example date
  cout << "Target Date: " << searchDate1 << endl;
  if (dateTree.SearchTree(searchDate1)) {
    cout << "Found the date: " << searchDate1 << endl;
  } else {
    cout << "Date not found." << endl;
  }

  Date searchDate2;
  searchDate2.SetDate("19", "05", "2021"); // Example date
  cout << "Target Date: " << searchDate2 << endl;
  if (dateTree.SearchTree(searchDate2)) {
    cout << "Found the date: " << searchDate2 << endl;
  } else {
    cout << "Date not found." << endl;
  }
  cout << endl;
  cout << "---------Deleting Tree---------";
  cout << endl;

  dateTree.DeleteTree();

  cout << "In-order traversal:  ";
  dateTree.printInOrder(PrintNode);
  cout << endl;

  cout << "Pre-order traversal: ";
  dateTree.printPreOrder(PrintNode);
  cout << endl;

  cout << "Post-order traversal: ";
  dateTree.printPostOrder(PrintNode);
  cout << endl;

  cout << "records: " << record;

  return 0;
}
