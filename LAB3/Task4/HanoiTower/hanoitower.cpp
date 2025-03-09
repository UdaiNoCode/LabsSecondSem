#include "hanoitower.h"

HanoiTower::HanoiTower() {}

void HanoiTower::hanoiBuild(int n, char from, char to, char au) {
  if (n == 0) {
    return;
  }

  hanoiBuild(n - 1, from, au, to);

  this->outputInfo.append("Move disk " + QString::number(n) + " from rod " +
                          from + " to rod " + to + "\n");

  hanoiBuild(n - 1, au, to, from);
}

QString HanoiTower::getInfo() {
  return this->outputInfo;
}
