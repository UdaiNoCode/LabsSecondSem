#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "accerman.h"

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

  void on_lineEdit_2_editingFinished();

  void on_pushButton_clicked();

 private:
  Ui::MainWindow* ui;

 private:
  Accerman newAccerman;
  const int FIRST_ARG_LIMIT = 4;
  const int SECOND_ARG_LIMIT = 12;
};
#endif  // MAINWINDOW_H
