#include "data.h"

Data::Data(QString inputData) {
  QDate date = QDate::fromString(inputData, "dd.MM.yyyy");
  this->date = date;
}

QDate Data::getDate() {
  return this->date;
}

QString Data::nextDay() {
  qint64 stepDay = 1;
  QDate curentDay = getDate();
  return curentDay.addDays(stepDay).toString("dd.MM.yyyy");
}
QString Data::previousDate() {
  qint64 stepDay = -1;
  QDate curentDay = getDate();
  return curentDay.addDays(stepDay).toString("dd.MM.yyyy");
};
QString Data::isLeap() {
  QDate curentDay = getDate();
  if (curentDay.isLeapYear(curentDay.year())) {
    return "True";
  }
  return "False";
};
QString Data::weekNumber() {
  QDate curentDate = getDate();
  int yearNumber = 0;
  int weekNumber = curentDate.weekNumber(&yearNumber);

  return QString::number(weekNumber);
};
