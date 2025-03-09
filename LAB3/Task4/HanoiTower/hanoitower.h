#ifndef HANOITOWER_H
#define HANOITOWER_H
#include <QString>

class HanoiTower {
 public:
  HanoiTower();

 public:
  void hanoiBuild(int n, char from, char to, char aux);
  QString getInfo();

 private:
  QString outputInfo;
};

#endif  // HANOITOWER_H
