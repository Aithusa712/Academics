#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include "Vector.h"
using namespace std;

float GetMean(Vector<float>& dataArray) {
  float mean = 0;
  for (int i = 0; i < dataArray.size(); i++) {
    float tempData = dataArray[i];
    mean += tempData;
  }
  mean /= dataArray.size();

  return mean;
}

float GetSSD(float &mean, Vector<float>& dataArray) {
  float ssd = 0;

  for (int i = 0; i < dataArray.size(); i++) {
    ssd += ((dataArray[i] - mean)) * ((dataArray[i] - mean));
  }

  return sqrt(ssd / (dataArray.size() - 1));
}

void ExtractData(Vector<float>& dataArray) {
  string line = "";
  ifstream file;
  file.open("data.txt");

  while (getline(file, line)) {
    string temp = "";
    istringstream ss(line);
    while (ss >> temp) {
      float fTemp = stof(temp);
      dataArray.push(fTemp);
      cout <<"Data Array Pushed;" << fTemp << endl;
    }
  }
}

int main() {
  Vector<float> dataArray;

  ExtractData(dataArray);
  
  for (int i = 0; i<dataArray.size(); i++){
    cout << "Index [" << i <<"]: " << dataArray[i] << endl;
  }

  float mean = GetMean(dataArray);

  float ssd = GetSSD(mean, dataArray);

  cout << "The number of floating point values (N):" << dataArray.size()
       << endl
       << "The mean of the floating point values:" << mean << endl
       << "The sample standard deviation (s):" << ssd << endl;

  dataArray.Clear();

  return 0;
}
