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
  QString inputText = ui->lineEdit->text();
  bool intOk;
  unsigned int tempFirstArgument = inputText.toUInt(&intOk);

  if (intOk) {
    this->newAccerman.setFirstArg(tempFirstArgument);
  } else {
    this->newAccerman.setFirstArg(-1);
  }
}

void MainWindow::on_lineEdit_2_editingFinished() {
  QString inputText = ui->lineEdit->text();
  bool intOk;
  unsigned int tempSecondArgument = inputText.toUInt(&intOk);

  if (intOk) {
    this->newAccerman.setSecondArg(tempSecondArgument);
  } else {
    this->newAccerman.setSecondArg(-1);
  }
}

void MainWindow::on_pushButton_clicked() {
  int firtsArg = this->newAccerman.getFirstArg();
  int secondArg = this->newAccerman.getSecondArg();

  if (firtsArg < FIRST_ARG_LIMIT && secondArg < SECOND_ARG_LIMIT) {
    if (firtsArg >= 0 && secondArg >= 0) {
      int result = newAccerman.accermanFunction(firtsArg, secondArg);
      ui->result->setText(QString::number(result));
    } else {
      ui->result->setText("Something went wrong!");
    }
  } else {
    ui->result->setText("StackOverFlow!");
  }
}
