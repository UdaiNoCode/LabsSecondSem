#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "hanoitower.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget* parent = nullptr);
  ~MainWindow();

 private slots:
  void on_lineEdit_editingFinished();

  void on_pushButton_clicked();

 private:
  Ui::MainWindow* ui;

 private:
  int number;
  HanoiTower hanoi;

 private:
  int getNumber();
  void setNumber(int number);

 private:
  const int MAX_LIMIT_OF_TOWER = 20;
  const int MIN_LIMIT_OF_TOWER = 2;
};
#endif  // MAINWINDOW_H
