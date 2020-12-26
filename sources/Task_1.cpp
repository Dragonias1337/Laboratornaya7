
#include "header.hpp"

void saveToFile(const string& filename, const vector<string>& data){
  ofstream out(filename);
  if (out.is_open()) {
    for (auto i : data) {
      out << i << endl;
    }
    out.close();
  }
}

void loadFromFile(const string& filename, vector<string>& outData){
  outData.clear();
  ifstream in(filename);
  if (in.is_open()){
    string line;
    int n = 0;
    while (getline(in, line)) {
      outData.resize(++n);
      outData[n-1] = line;
    }
    in.close();
  }
}
