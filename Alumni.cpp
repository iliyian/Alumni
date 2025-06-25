#include "Alumni.h"

void Alumni::setName(const string &name) {
  this->name = name;
}

void Alumni::setGender(const string &gender) {
  this->gender = gender;
}

void Alumni::setAge(const int &age) {
  this->age = age;
}

void Alumni::setGrade(const int &grade) {
  this->grade = grade;
}

void Alumni::setDepartment(const string &department) {
  this->department = department;
}

void Alumni::setClassName(const string &className) {
  this->className = className;
}

void Alumni::setAddress(const string &address) {
  this->address = address;
}

void Alumni::setPhone(const string &phone) {
  this->phone = phone;
}

void Alumni::setQQ(const string &qq) {
  this->qq = qq;
}

void Alumni::setEmail(const string &email) {
  this->email = email;
}

string Alumni::getName() const {
  return name;
}

string Alumni::getGender() const {
  return gender;
}

int Alumni::getAge() const {
  return age;
}

int Alumni::getGrade() const {
  return grade;
}

string Alumni::getDepartment() const {
  return department;
}

string Alumni::getClassName() const {
  return className;
}

string Alumni::getAddress() const {
  return address;
}

string Alumni::getPhone() const {
  return phone;
}

string Alumni::getQQ() const {
  return qq;
}

string Alumni::getEmail() const {
  return email;
}

Alumni::Alumni() : name(""), gender(""), age(0), grade(0), department(""), className(""), address(""), phone(""), qq(""), email("") {}

Alumni::Alumni(const string &name, const string &gender, const int &age, const int &grade, const string &department,
               const string &className, const string &address, const string &phone, const string &qq, const string &email)
    : name(name), gender(gender), age(age), grade(grade), department(department), className(className), address(address), phone(phone), qq(qq), email(email) {}

Alumni::~Alumni() {}

