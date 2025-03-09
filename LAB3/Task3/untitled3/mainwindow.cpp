#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_lineEdit_editingFinished() {
  QString inputNumber = ui->lineEdit->text();
  bool isInt;
  bool minus = false;

  int tempNumber = inputNumber.toInt(&isInt);

  if (isInt) {
    if (tempNumber < 0) {
      minus = true;
      tempNumber *= -1;
    }
    tempNumber = reverser->reverse(tempNumber);
    tempNumber = minus ? tempNumber *= -1 : tempNumber;

    setNumber(tempNumber);
  }
}

void MainWindow::setNumber(int number) {
  this->number = number;
};
int MainWindow::getNumber() {
  return this->number;
};

void MainWindow::on_pushButton_clicked() {
  QString outPut = QString::number(getNumber());
  ui->Result->setText(outPut);
}
