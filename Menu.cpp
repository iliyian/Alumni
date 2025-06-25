#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::show() {
  cout << "\n=== 校友管理系统 ===" << endl;
  cout << "1. 添加校友信息" << endl;
  cout << "2. 删除校友信息" << endl;
  cout << "3. 修改校友信息" << endl;
  cout << "4. 查询校友信息" << endl;
  cout << "5. 显示所有校友" << endl;
  cout << "6. 排序校友信息" << endl;
  cout << "7. 统计信息" << endl;
  cout << "8. 从文件加载" << endl;
  cout << "0. 退出系统" << endl;
  cout << "请选择操作: ";
}

void Menu::run(AlumniList &list) {
  int choice;
  while (true) {
    show();
    cin >> choice;
    switch (choice) {
      case 1:
        addAlumni(list);
        break;
      case 2:
        deleteAlumni(list);
        break;
      case 3:
        updateAlumni(list);
        break;
      case 4:
        searchAlumni(list);
        break;
      case 5:
        cout << "\n=== 所有校友信息 ===" << endl;
        list.print();
        break;
      case 6:
        sortAlumni(list);
        break;
      case 7:
        showStatistics(list);
        break;
      case 8:
        list.loadFromFile();
        cout << "数据已从文件重新加载！" << endl;
        break;
      case 0:
        cout << "正在保存数据..." << endl;
        list.saveToFile();
        cout << "数据已保存，感谢使用，再见！" << endl;
        return;
      default:
        cout << "无效选择，请重新输入！" << endl;
    }
  }
}

void Menu::addAlumni(AlumniList &list) {
  string name, gender, department, className, address, phone, qq, email;
  int age, grade;
  cout << "\n=== 添加校友信息 ===" << endl;
  cout << "姓名: ";
  cin >> name;
  cout << "性别: ";
  cin >> gender;
  cout << "年龄: ";
  cin >> age;
  cout << "年级: ";
  cin >> grade;
  cout << "院系: ";
  cin >> department;
  cout << "班级: ";
  cin >> className;
  cout << "地址: ";
  cin >> address;
  cout << "电话: ";
  cin >> phone;
  cout << "QQ: ";
  cin >> qq;
  cout << "邮箱: ";
  cin >> email;
  Alumni alumni(name, gender, age, grade, department, className, address, phone, qq, email);
  list.add(alumni);
  cout << "添加成功！" << endl;
  list.saveToFile();
}

void Menu::deleteAlumni(AlumniList &list) {
  string name;
  cout << "\n=== 删除校友信息 ===" << endl;
  cout << "请输入要删除的校友姓名: ";
  cin >> name;
  Alumni temp(name, "", 0, 0, "", "", "", "", "", "");
  list.remove(temp);
  cout << "删除完成！" << endl;
  list.saveToFile();
}

void Menu::updateAlumni(AlumniList &list) {
  string name, gender, department, className, address, phone, qq, email;
  int age, grade;
  cout << "\n=== 修改校友信息 ===" << endl;
  cout << "请输入要修改的校友姓名: ";
  cin >> name;
  cout << "新的性别: ";
  cin >> gender;
  cout << "新的年龄: ";
  cin >> age;
  cout << "新的年级: ";
  cin >> grade;
  cout << "新的院系: ";
  cin >> department;
  cout << "新的班级: ";
  cin >> className;
  cout << "新的地址: ";
  cin >> address;
  cout << "新的电话: ";
  cin >> phone;
  cout << "新的QQ: ";
  cin >> qq;
  cout << "新的邮箱: ";
  cin >> email;
  Alumni newAlumni(name, gender, age, grade, department, className, address, phone, qq, email);
  list.update(name, newAlumni);
  cout << "修改成功！" << endl;
  list.saveToFile();
}

void Menu::searchAlumni(AlumniList &list) {
  cout << "\n=== 查询校友信息 ===" << endl;
  cout << "1. 按姓名查询" << endl;
  cout << "2. 按年级查询" << endl;
  cout << "3. 按院系查询" << endl;
  cout << "4. 按班级查询" << endl;
  cout << "请选择查询方式: ";
  int choice;
  cin >> choice;
  string key;
  AlumniList results;
  bool fuzzy;
  switch (choice) {
    case 1:
      cout << "请输入姓名: ";
      cin >> key;
      cout << "是否使用模糊查询？(1-是, 0-否): ";
      cin >> fuzzy;
      results = list.searchByName(key, fuzzy);
      break;
    case 2:
      cout << "请输入年级: ";
      cin >> key;
      cout << "是否使用模糊查询？(1-是, 0-否): ";
      cin >> fuzzy;
      results = list.searchByGrade(stoi(key), fuzzy);
      break;
    case 3:
      cout << "请输入院系: ";
      cin >> key;
      cout << "是否使用模糊查询？(1-是, 0-否): ";
      cin >> fuzzy;
      results = list.searchByDepartment(key, fuzzy);
      break;
    case 4:
      cout << "请输入班级: ";
      cin >> key;
      cout << "是否使用模糊查询？(1-是, 0-否): ";
      cin >> fuzzy;
      results = list.searchByClassName(key, fuzzy);
      break;
    default:
      cout << "无效选择！" << endl;
      return;
  }
  if (results.getLength() == 0) {
    cout << "未找到匹配的校友信息！" << endl;
  } else {
    cout << "\n查询结果:" << endl;
    results.print();
  }
}

void Menu::sortAlumni(AlumniList &list) {
  cout << "\n=== 排序校友信息 ===" << endl;
  cout << "1. 按姓名排序" << endl;
  cout << "2. 按年级排序" << endl;
  cout << "请选择排序方式: ";
  int choice;
  cin >> choice;
  switch (choice) {
    case 1:
      list.mergeSortByName(list.getHead(), list.getTail(), list.getLength());
      cout << "按姓名排序完成！" << endl;
      break;
    case 2:
      list.mergeSortByGrade(list.getHead(), list.getTail(), list.getLength());
      cout << "按年级排序完成！" << endl;
      break;
    default:
      cout << "无效选择！" << endl;
      return;
  }
  list.saveToFile();
}

void Menu::showStatistics(AlumniList &list) {
  cout << "\n=== 统计信息 ===" << endl;
  cout << "1. 性别统计" << endl;
  cout << "2. 院系统计" << endl;
  cout << "3. 班级统计" << endl;
  cout << "4. 年级统计" << endl;
  cout << "5. 年龄统计" << endl;
  cout << "请选择统计类型: ";
  int choice;
  cin >> choice;
  switch (choice) {
    case 1: {
      auto mp = list.getGenderStatistics();
      cout << "性别统计:" << endl;
      for (auto &[k, v]: mp) {
        cout << k << ": " << v << "人" << endl;
      }
      break;
    }
    case 2: {
      auto mp = list.getDepartmentStatistics();
      cout << "院系统计:" << endl;
      for (auto &[k, v]: mp) {
        cout << k << ": " << v << "人" << endl;
      }
      break;
    }
    case 3: {
      auto mp = list.getClassNameStatistics();
      cout << "班级统计:" << endl;
      for (auto &[k, v]: mp) {
        cout << k << ": " << v << "人" << endl;
      }
      break;
    }
    case 4: {
      auto mp = list.getGradeStatistics();
      cout << "年级统计:" << endl;
      for (auto &[k, v]: mp) {
        cout << k << "级: " << v << "人" << endl;
      }
      break;
    }
    case 5: {
      auto mp = list.getAgeStatistics();
      cout << "年龄统计:" << endl;
      for (auto &[k, v]: mp) {
        cout << k << "岁: " << v << "人" << endl;
      }
      break;
    }
    default:
      cout << "无效选择！" << endl;
  }
}
