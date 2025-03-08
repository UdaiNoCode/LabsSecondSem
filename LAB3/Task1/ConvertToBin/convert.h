#ifndef CONVERT_H
#define CONVERT_H

#include <QString>

constexpr int MANTISSA_LENGHT = 52;
constexpr int EXP_STEP = 1023;

class Convert {
 public:
  Convert();

 private:
  QString intToBin(int number);
  QString doubleToBin(double number, int mantiss = MANTISSA_LENGHT);

 public:
  template <typename T>
  QString translateToBin(T value);
};

#endif  // CONVERT_H
