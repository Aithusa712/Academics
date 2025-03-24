#include <iostream>
#include <fstream>
#include <sstream>
#include "Date.h"
#include "intBst.h"

using namespace std;

void readCSV(const string& filename, intBst<Date>& dateTree, int& record) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    string line;
    getline(file, line);  // Assuming first line is header
    int cnt;
    while (getline(file, line)) {
    cout << cnt << " " << endl;

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

int main() {
    int record = 1;
    intBst<Date> dateTree;
    ifstream file("data/data_source.txt");
    if (!file.is_open()) {
        cerr << "Error opening data_source.txt" << endl;
        return 1;
    }

    string filename;
    while (getline(file, filename)) {
        filename = "data/" + filename.substr(0, filename.size()-1);
        readCSV(filename, dateTree, record);
    }
    file.close();

    // Test BST operations
/*
    Date searchDate;
    searchDate.SetDate("17", "08", "2020");

    Date searchDate2;
    searchDate2.SetDate("16", "07", "2021");

    Date searchDate3;
    searchDate3.SetDate("16", "08", "2022");

    intBst<Date> dateTree;

    dateTree.Insert(searchDate);
    dateTree.Insert(searchDate2);
    dateTree.Insert(searchDate2);

    */

    ofstream output("travers.csv");
    cout << "In-order traversal: ";
    dateTree.printInOrder();
    cout << endl;

    cout << "Pre-order traversal: ";
    dateTree.printPreOrder();
    cout << endl;

    cout << "Post-order traversal: ";
    dateTree.printPostOrder();
    cout << endl;

    // Example search
    Date searchDate1;
    searchDate1.SetDate("1", "03", "2015"); // Example date
    if (dateTree.SearchTree(searchDate1)) {
        cout << "Found the date: " << searchDate1 << endl;
    } else {
        cout << "Date not found." << endl;
    }



    cout << "records: "<< record;

    return 0;
}
