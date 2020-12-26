
#include "header.hpp"

void saveToFile(const string& filename, const Groups& groups)
{
  ofstream out(filename);
  if (out.is_open())
  {
    for (const auto & group : groups)
    {
      out << group.first << '|';
      for (auto i : group.second){
        out << i.Name << '|' << i.Year << '|';
        for (auto & it2 : i.RecordBook)
        {
          out << it2.first << '|' << it2.second << '|';
        }
      }
      out << endl;
    }
    out.close();
  }
}

void loadFromFile(const string& filename, Groups& outGroups)
{
  outGroups.clear();
  ifstream in(filename);
  if (in.is_open()){
    string gr, line, str;
    vector<Student> stud;
    Score mark;
    int n = 0;
    while (getline(in, line)){
      gr = line.substr(0, line.find('|'));
      line.erase(0, line.find('|')+1);
      while (!line.empty()) {
        stud.resize(++n);
        stud[n-1].Name = line.substr(0, line.find('|'));
        line.erase(0, line.find('|') + 1);
        int year = 0;
        for (unsigned int q = 0; q < line.find('|'); q++)
        {
          year *=10;
          year += static_cast<int>(line[0]) - 48;
        }
        stud[n-1].Year = year;
        line.erase(0, line.find('|') + 1);
        str = line.substr(0, line.find('|'));
        while (str.size() == 1) {
          line.erase(0, line.find('|') + 1);
          mark = static_cast<Score>(static_cast<int>(line[0]) - 48);
          line.erase(0, line.find('|') + 1);
          stud[n-1].RecordBook.insert(pair<string, Score>(str, mark));
          str = line.substr(0, line.find('|'));
        }
      }
      outGroups.insert(pair<string, vector<Student>>(gr, stud));
      stud.clear();
      n = 0;
    }
    in.close();
  }
}

