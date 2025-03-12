#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QCalendarWidget>
#include <QFile>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include "data.h"
#include "dialog.h"

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
  void on_pushButton_clicked();

  void on_tableWidget_cellClicked(int row, int column);

  void on_pushButton_5_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_6_clicked();

  void on_pushButton_4_clicked();

 private:
  Ui::MainWindow* ui;
  Dialog* infoDialog;

 private:
  QString opened_file_path;
  QVector<Data> dates;
  size_t isActive;
  QDate birthdayDay;

 public:
  void updateTable();
  void setActive(size_t active);
  size_t getActive();
  void setInfo();
  void appendInfo();
  void newPath();
  void deleteInfo(size_t index);
  QDate getBirhday();
};
#endif  // MAINWINDOW_H
