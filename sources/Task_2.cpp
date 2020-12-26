
#include "header.hpp"

void saveToFile(const string& filename, const vector<Book>& data)
{
  ofstream out(filename);
  if (out.is_open()) {
    for (const auto& i : data)
    {
      out << i.Author << endl << i.Title << endl << i.Year << endl;
    }
    out.close();
  }
}

void loadFromFile(const string& filename, vector<Book>& outData)
{
  outData.clear();
  ifstream in(filename);
  if (in.is_open()){
    string line;
    int n = 0;
    while (getline(in, line))
    {
      outData.resize(++n);
      outData[n-1].Author = line;
      getline(in, outData[n-1].Title);
      in >> outData[n-1].Year;
      in.ignore();
    }
    in.close();
  }
}
