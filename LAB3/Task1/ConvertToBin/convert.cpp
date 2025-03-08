#include "convert.h"
#include <qdebug.h>

Convert::Convert() {}

template QString Convert::translateToBin<int>(int);
template QString Convert::translateToBin<double>(double);

QString Convert::intToBin(int number) {
  if (number == 0) {
    return "0";
  }
  return intToBin(number / 2) + QString::number(number % 2);
}

QString Convert::doubleToBin(double number, int mantiss) {
  if (mantiss == 0) {
    return "";
  }
  return QString::number(static_cast<int>(number * 2)) +
         doubleToBin(number * 2 - static_cast<int>(number * 2), mantiss - 1);
}

template <typename T>
QString Convert::translateToBin(T value) {
  QString firsrBite = "0";
  if (value < 0) {
    firsrBite = "1";
    value *= -1;
  }

  if (std::is_same_v<T, int>) {
    return intToBin(value).insert(1, "|").replace(0, 1, firsrBite);
  } else if (std::is_same_v<T, double>) {

    int intPart = static_cast<int>(value);
    double doublePart = value - intPart;

    QString tempBin = intToBin(intPart);
    int exponentNumber = (tempBin.length() - 2) + EXP_STEP;
    qDebug() << tempBin;
    QString expBin = intToBin(exponentNumber);
    QString mantissa = tempBin.remove(0, 2) + doubleToBin(doublePart);

    return firsrBite + "|" + expBin + "|" + mantissa;
  }
  return "Unsupported type";
}
