#ifndef MENU_H
#define MENU_H

#include "AlumniList.h"

class Menu {
public:
  static void show();
  static void run(AlumniList &list);
private:
  static void addAlumni(AlumniList &list);
  static void deleteAlumni(AlumniList &list);
  static void updateAlumni(AlumniList &list);
  static void searchAlumni(AlumniList &list);
  static void sortAlumni(AlumniList &list);
  static void showStatistics(AlumniList &list);
};

#endif // MENU_H
