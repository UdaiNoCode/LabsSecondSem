#include "data.h"

Data::Data(QString inputData) {
    QDate date = QDate::fromString(inputData, "dd.MM.yyyy");
    this->date = date;
}

QDate Data::getDate() {
    return this->date;
}

QString Data::nextDay() {
    qint64 step_day = 1;
    QDate curent_day = getDate();
    return curent_day.addDays(step_day).toString("dd.MM.yyyy");
}
QString Data::previousDate() {
    qint64 step_day = -1;
    QDate current_day = getDate();
    return current_day.addDays(step_day).toString("dd.MM.yyyy");
};
QString Data::isLeap() {
    QDate curent_day = getDate();
    if (curent_day.isLeapYear(curent_day.year())) {
        return "True";
    }
    return "False";
};
QString Data::weekNumber() {
    QDate curent_date = getDate();
    int year_number = 0;
    int week_number = curent_date.weekNumber(&year_number);

    return QString::number(week_number);
};

QString Data::duration() {
    QDate now_date = QDate::currentDate();
    int days_diff = getDate() >= now_date ? getDate().daysTo(now_date)
                                          : now_date.daysTo(getDate());
    return QString::number(abs(days_diff));
}

QString Data::DaysTillYourBithday(QDate birthday) {
    if (birthday.isValid()) {
        int days_diff = getDate() >= birthday ? getDate().daysTo(birthday)
                                              : birthday.daysTo(getDate());
        return QString::number(abs(days_diff));
    }
    return "Info";
}
