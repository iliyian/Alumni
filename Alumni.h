#ifndef ALUMNI_H
#define ALUMNI_H

#include <string>
using namespace std;

class Alumni {
private:
  string name;
  string gender;
  int age;
  int grade;
  string department;
  string className;
  string address;
  string phone;
  string qq;
  string email;

public:
  Alumni();
  Alumni(const string &name, const string &gender, const int &age, const int &grade, const string &department,
         const string &className, const string &address, const string &phone, const string &qq, const string &email);
  ~Alumni();
  void setName(const string &name);
  void setGender(const string &gender);
  void setAge(const int &age);
  void setGrade(const int &grade);
  void setDepartment(const string &department);
  void setClassName(const string &className);
  void setAddress(const string &address);
  void setPhone(const string &phone);
  void setQQ(const string &qq);
  void setEmail(const string &email);
  string getName() const;
  string getGender() const;
  int getAge() const;
  int getGrade() const;
  string getDepartment() const;
  string getClassName() const;
  string getAddress() const;
  string getPhone() const;
  string getQQ() const;
  string getEmail() const;
};


#endif // ALUMNI_H
