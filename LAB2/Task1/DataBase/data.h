#ifndef DATA_H
#define DATA_H

#include <QDate>
#include <QString>
#include <ranges>
#include <vector>

class Data {
 private:
  QDate date;

 public:
  Data(QString inpuData);

 public:
  QString nextDay();
  QString previousDate();
  QString isLeap();
  QString weekNumber();
  QDate getDate();
};

#endif  // DATA_H
