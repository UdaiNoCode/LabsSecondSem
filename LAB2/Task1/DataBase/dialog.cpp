#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent), ui(new Ui::Dialog) {
  ui->setupUi(this);
}

Dialog::~Dialog() {
  delete ui;
}

void Dialog::setLabelNextDay(QString in) {
  ui->nextDate->setText(in);
};

void Dialog::setUpdate() {
  this->update();
};
void Dialog::setLabelPrevDay(QString in) {
  ui->PrevDay->setText(in);
};
void Dialog::setLabelIsLeak(QString in) {
  ui->IsLeak->setText(in);
};
void Dialog::setLabelWeekNum(QString in) {
  ui->WeekNum->setText(in);
};
