#include <iostream>
#include "AlumniList.h"
#include "Menu.h"
using namespace std;

int main() {
  AlumniList list;
  
  cout << "欢迎使用校友管理系统！" << endl;
  cout << "正在从文件加载数据..." << endl;
  list.loadFromFile();
  cout << "数据加载完成！" << endl;
  
  Menu::run(list);
  return 0;
}
