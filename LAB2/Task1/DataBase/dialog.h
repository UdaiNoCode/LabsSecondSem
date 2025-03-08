#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
  Q_OBJECT

 public:
  explicit Dialog(QWidget* parent = nullptr);
  ~Dialog();

 private:
  Ui::Dialog* ui;

 public:
  void setLabelNextDay(QString in);
  void setLabelPrevDay(QString in);
  void setLabelIsLeak(QString in);
  void setLabelWeekNum(QString in);
  void setUpdate();
  void setLabelDuration(QString in);
  void setLabelBirthday(QString in);
};

#endif  // DIALOG_H
