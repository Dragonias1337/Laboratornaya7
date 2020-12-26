
#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#endif // INCLUDE_HEADER_HPP_



#include <fstream>
#include <map>
#include <string>
#include <vector>
using std::ifstream;
using std::ofstream;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::pair;

struct Book
{
  std::string Author;
  std::string Title;
  int Year;
};

enum Score
{
  Unsatisfactorily = 2,
  Satisfactorily=3,
  Good=4,
  Excellent=5
};

struct Student
{
  std::string Name;
  int Year;
  std::map<std::string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& filename, const vector<string>& data);

void loadFromFile(const string& filename, vector<string>& outData);

void saveToFile(const string& filename, const vector<Book>& data);

void loadFromFile(const string& filename, vector<Book>& outData);

void saveToFile(const string& filename, const Groups& groups);

void loadFromFile(const string& filename, Groups& outGroups);
