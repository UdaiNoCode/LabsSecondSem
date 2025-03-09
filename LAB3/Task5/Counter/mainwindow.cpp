#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {
  int filesCount{0}, dirCount{0};

  this->path = QFileDialog::getExistingDirectory(
      this, "Выберите нужную директорию", "/home/");
  this->counter.allFilesAndDirsCount(path, filesCount, dirCount);

  ui->dirs->setText(QString::number(dirCount));
  ui->files->setText(QString::number(filesCount));
  ui->pathdInfo->setText(counter.getFileNames());
}
