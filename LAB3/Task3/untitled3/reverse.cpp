#include "reverse.h"

Reverse::Reverse() {}

int Reverse::reverse(int number, int result) {
  if (number == 0) {
    return result;
  } else {
    return reverse(number / 10, result * 10 + number % 10);
  }
}
