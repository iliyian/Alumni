#include "AlumniList.h"
#include <fstream>
#include <iostream>

using namespace std;

AlumniList::AlumniList() : head(nullptr), tail(nullptr), len(0) {}

AlumniList::AlumniList(const AlumniList &other) : head(nullptr), tail(nullptr), len(0) {
  Node *cur = other.head;
  while (cur) {
    add(*(cur->getData()));
    cur = cur->getNext();
  }
}

AlumniList::~AlumniList() {
  Node *cur = head;
  while (cur) {
    Node *next = cur->getNext();
    delete cur;
    cur = next;
  }
}

AlumniList& AlumniList::operator=(const AlumniList &other) {
  if (this != &other) {
    Node *cur = head;
    while (cur) {
      Node *next = cur->getNext();
      delete cur;
      cur = next;
    }
    head = tail = nullptr;
    len = 0;

    cur = other.head;
    while (cur) {
      add(*(cur->getData()));
      cur = cur->getNext();
    }
  }
  return *this;
}

AlumniList AlumniList::searchByName(const string &name, bool fuzzy) {
  AlumniList results;
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    if (!fuzzy && data->getName() == name) {
      results.add(*data);
    } else if (fuzzy && data->getName().find(name) != string::npos) {
      results.add(*data);
    }
    cur = cur->getNext();
  }
  return results;
}

AlumniList AlumniList::searchByGrade(const int &grade, bool fuzzy) {
  AlumniList results;
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    if (!fuzzy && data->getGrade() == grade) {
      results.add(*data);
    } else if (fuzzy && to_string(data->getGrade()).find(to_string(grade)) != string::npos) {
      results.add(*data);
    }
    cur = cur->getNext();
  }
  return results;
}

AlumniList AlumniList::searchByDepartment(const string &department, bool fuzzy) {
  AlumniList results;
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    if (!fuzzy && data->getDepartment() == department) {
      results.add(*data);
    } else if (fuzzy && data->getDepartment().find(department) != string::npos) {
      results.add(*data);
    }
    cur = cur->getNext();
  }
  return results;
}

AlumniList AlumniList::searchByClassName(const string &className, bool fuzzy) {
  AlumniList results;
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    if (data) {
      if (!fuzzy && data->getClassName() == className) {
        results.add(*data);
      } else if (fuzzy && data->getClassName().find(className) != string::npos) {
        results.add(*data);
      }
    }
    cur = cur->getNext();
  }
  return results;
}

void AlumniList::add(const Alumni &alumni) {
  Node *node = new Node(new Alumni(alumni), nullptr, tail);
  if (!head) {
    head = tail = node;
  } else {
    tail->setNext(node);
    node->setPrev(tail);
    tail = node;
  }
  len++;
}

void AlumniList::remove(const Alumni &alumni) {
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    if (data->getName() == alumni.getName()) {
      if (cur->getPrev())
        cur->getPrev()->setNext(cur->getNext());
      else
        head = cur->getNext();
      if (cur->getNext())
        cur->getNext()->setPrev(cur->getPrev());
      else
        tail = cur->getPrev();
      delete cur;
      len--;
      return;
    }
    cur = cur->getNext();
  }
}

void AlumniList::update(const string &name, const Alumni &alumni) {
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    if (data->getName() == name) {
      *data = alumni;
      return;
    }
    cur = cur->getNext();
  }
}

void AlumniList::print() {
  cout << "姓名\t性别\t年龄\t年级\t院系\t班级\t地址\t电话\tQQ\t邮箱" << endl;
  cout << "----\t----\t----\t----\t----\t----\t----\t----\t--\t----" << endl;
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    cout << data->getName() << "\t" << data->getGender() << "\t" << data->getAge() << "\t" << data->getGrade() << "\t"
         << data->getDepartment() << "\t" << data->getClassName() << "\t" << data->getAddress() << "\t"
         << data->getPhone() << "\t" << data->getQQ() << "\t" << data->getEmail() << endl;
    cur = cur->getNext();
  }
}

void AlumniList::saveToFile() {
  ofstream os("alumni.txt");
  Node *cur = head;
  while (cur) {
    Alumni *data = cur->getData();
    os << data->getName() << ' ' << data->getGender() << ' ' << data->getAge() << ' ' << data->getGrade() << ' '
       << data->getDepartment() << ' ' << data->getClassName() << ' ' << data->getAddress() << ' ' << data->getPhone()
       << ' ' << data->getQQ() << ' ' << data->getEmail() << '\n';
    cur = cur->getNext();
  }
}

void AlumniList::loadFromFile() {
  this->~AlumniList();
  head = tail = nullptr;
  len = 0;
  
  ifstream is("alumni.txt");
  string name, gender, department, className, address, phone, qq, email;
  int age, grade;
  while (is >> name >> gender >> age >> grade >> department >> className >> address >> phone >> qq >> email) {
    add(Alumni(name, gender, age, grade, department, className, address, phone, qq, email));
  }
}

void AlumniList::mergeSortByName(Node *left, Node *right, int len) {
  if (len == 1) return;
  
  Node *mid = left;
  for (int i = 0; i < len / 2; i++) mid = mid->getNext();
  mergeSortByName(left, mid, len / 2);
  mergeSortByName(mid, right, len - len / 2);
  
  AlumniList temp;
  Node *p1 = left, *p2 = mid;
  
  while (p1 != mid && p2) {
    if (p1->getData()->getName() < p2->getData()->getName()) {
      temp.add(*(p1->getData()));
      p1 = p1->getNext();
    } else {
      temp.add(*(p2->getData()));
      p2 = p2->getNext();
    }
  }
  
  while (p1 != mid) {
    temp.add(*(p1->getData()));
    p1 = p1->getNext();
  }
  while (p2) {
    temp.add(*(p2->getData()));
    p2 = p2->getNext();
  }
  
  Node *cur = left;
  Node *tempCur = temp.head;
  while (true) {
    if (!cur) break;
    *(cur->getData()) = *(tempCur->getData());
    cur = cur->getNext();
    tempCur = tempCur->getNext();
  }
}

void AlumniList::mergeSortByGrade(Node *left, Node *right, int len) {
  if (len == 1) return;
  
  Node *mid = left;
  for (int i = 0; i < len / 2; i++) mid = mid->getNext();
  mergeSortByGrade(left, mid, len / 2);
  mergeSortByGrade(mid, right, len - len / 2);
  
  AlumniList temp;
  Node *p1 = left, *p2 = mid;
  
  while (p1 != mid && p2) {
    if (p1->getData()->getGrade() < p2->getData()->getGrade()) {
      temp.add(*(p1->getData()));
      p1 = p1->getNext();
    } else {
      temp.add(*(p2->getData()));
      p2 = p2->getNext();
    }
  }
  
  while (p1 != mid) {
    temp.add(*(p1->getData()));
    p1 = p1->getNext();
  }
  while (p2) {
    temp.add(*(p2->getData()));
    p2 = p2->getNext();
  }
  
  Node *cur = left;
  Node *tempCur = temp.head;
  while (true) {
    if (!cur) break;
    *(cur->getData()) = *(tempCur->getData());
    cur = cur->getNext();
    tempCur = tempCur->getNext();
  }
}

map<string, int> AlumniList::getGenderStatistics() {
  map<string, int> mp;
  Node *cur = head;
  while (cur) {
    mp[cur->getData()->getGender()]++;
    cur = cur->getNext();
  }
  return mp;
}

map<string, int> AlumniList::getDepartmentStatistics() {
  map<string, int> mp;
  Node *cur = head;
  while (cur) {
    mp[cur->getData()->getDepartment()]++;
    cur = cur->getNext();
  }
  return mp;
}

map<string, int> AlumniList::getClassNameStatistics() {
  map<string, int> mp;
  Node *cur = head;
  while (cur) {
    mp[cur->getData()->getClassName()]++;
    cur = cur->getNext();
  }
  return mp;
}

map<int, int> AlumniList::getGradeStatistics() {
  map<int, int> mp;
  Node *cur = head;
  while (cur) {
    mp[cur->getData()->getGrade()]++;
    cur = cur->getNext();
  }
  return mp;
}

map<int, int> AlumniList::getAgeStatistics() {
  map<int, int> mp;
  Node *cur = head;
  while (cur) {
    mp[cur->getData()->getAge()]++;
    cur = cur->getNext();
  }
  return mp;
}

Node *AlumniList::getHead() const {
  return head;
}

Node *AlumniList::getTail() const {
  return tail;
}

int AlumniList::getLength() const {
  return len;
}

