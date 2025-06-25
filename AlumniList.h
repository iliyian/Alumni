#ifndef ALUMNI_LIST_H
#define ALUMNI_LIST_H

#include "Alumni.h"
#include "Node.h"
#include <map>

class AlumniList {
private:
  Node *head;
  Node *tail;
  int len;
public:
  AlumniList();
  AlumniList(const AlumniList &other);
  ~AlumniList();
  AlumniList& operator=(const AlumniList &other);
  void add(const Alumni &alumni);
  void remove(const Alumni &alumni);
  void update(const string &name, const Alumni &alumni);
  AlumniList searchByName(const string &name, bool fuzzy = false);
  AlumniList searchByGrade(const int &grade, bool fuzzy = false);
  AlumniList searchByDepartment(const string &department, bool fuzzy = false);
  AlumniList searchByClassName(const string &className, bool fuzzy = false);
  void print();
  void saveToFile();
  void loadFromFile();
  void mergeSortByName(Node *left, Node *right, int len);
  void mergeSortByGrade(Node *left, Node *right, int len);
  map<string, int> getGenderStatistics();
  map<string, int> getDepartmentStatistics();
  map<string, int> getClassNameStatistics();
  map<int, int> getGradeStatistics();
  map<int, int> getAgeStatistics();
  Node *getHead() const;
  Node *getTail() const;
  int getLength() const;
};

#endif