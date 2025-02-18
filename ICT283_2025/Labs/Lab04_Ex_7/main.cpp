#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

float GetMean(vector<float> *dataArray) {
  float mean = 0;
  for (int i = 0; i < dataArray->size(); i++) {
    mean += dataArray->at(i);
  }
  mean /= dataArray->size();

  return mean;
}

float GetSSD(float &mean, vector<float> *dataArray) {
  float ssd = 0;

  for (int i = 0; i < dataArray->size(); i++) {
    ssd += ((dataArray->at(i) - mean)) * ((dataArray->at(i) - mean));
  }

  return sqrt(ssd / (dataArray->size() - 1));
}

void ExtractData(vector<float> *dataArray) {
  string line = "";
  ifstream file;
  file.open("data.txt");

  while (getline(file, line)) {
    string temp = "";
    istringstream ss(line);
    while (ss >> temp) {
      float fTemp = stof(temp);
      dataArray->push_back(fTemp);
    }
  }
}

int main() {
  vector<float> *dataArray = new vector<float>();

  ExtractData(dataArray);

  float mean = GetMean(dataArray);

  float ssd = GetSSD(mean, dataArray);

  cout << "The number of floating point values (N):" << dataArray->size()
       << endl
       << "The mean of the floating point values:" << mean << endl
       << "The sample standard deviation (s):" << ssd << endl;

  dataArray->clear();

  return 0;
}
