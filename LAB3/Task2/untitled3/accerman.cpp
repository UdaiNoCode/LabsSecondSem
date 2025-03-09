#include "accerman.h"

Accerman::Accerman() {}

int Accerman::accermanFunction(int first, int second) {

  if (first == 0) {
    return second + 1;
  } else if (second == 0) {
    return accermanFunction(first - 1, 1);
  } else {
    return accermanFunction(first - 1, accermanFunction(first, second - 1));
  }
}

void Accerman::setFirstArg(int first) {
  this->firstArgument = first;
}

void Accerman::setSecondArg(int second) {
  this->secondArgument = second;
}

int Accerman::getFirstArg() {
  return this->firstArgument;
}

int Accerman::getSecondArg() {
  return this->secondArgument;
}
