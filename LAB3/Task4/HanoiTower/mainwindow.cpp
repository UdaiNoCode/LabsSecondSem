#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

int MainWindow::getNumber() {
  return this->number;
};
void MainWindow::setNumber(int number) {
  this->number = number;
};

void MainWindow::on_lineEdit_editingFinished() {
  QString inputText = ui->lineEdit->text();

  bool isUInt;

  unsigned int tempNumer = inputText.toUInt(&isUInt);
  if (isUInt) {
    this->setNumber(tempNumer);
  } else {
    this->setNumber(-1);
  }
}

void MainWindow::on_pushButton_clicked() {

  if (this->number<MAX_LIMIT_OF_TOWER&& this->number> MIN_LIMIT_OF_TOWER) {
    if (number < 0) {
      ui->textEdit->setText("Error! Something went wrong!");
    } else {
      hanoi.hanoiBuild(this->getNumber(), 'A', 'B', 'C');
      QString output = hanoi.getInfo();

      ui->textEdit->setText(output);
    }
  } else {
    ui->textEdit->setText("StackOverFlow!");
  }
}
