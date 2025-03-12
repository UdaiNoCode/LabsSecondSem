#ifndef DATA_H
#define DATA_H

#include <QDate>
#include <QString>

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
    QString duration();
    QString DaysTillYourBithday(QDate birthsday);
};

#endif	// DATA_H
