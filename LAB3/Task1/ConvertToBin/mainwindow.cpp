#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "convert.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_InputNumber_editingFinished() {
  QString inputText = ui->InputNumber->text();
  setConvertNumber(inputText);
  qDebug() << this->converNumber;
}

void MainWindow::setConvertNumber(QString input) {

  Convert transalte;
  bool okInt, okDouble;
  double toDouble = input.toDouble(&okDouble);
  int toInt = input.toInt(&okInt);

  if (okInt) {
    this->converNumber = transalte.translateToBin(toInt);
  } else if (okDouble) {
    this->converNumber = transalte.translateToBin(toDouble);
  } else {
    this->converNumber = "Something went wrong!";
  }
};

void MainWindow::on_pushButton_clicked() {
  ui->Output->setText(this->converNumber);
}
