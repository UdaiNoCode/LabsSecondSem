#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), isActive(0) {
  ui->setupUi(this);

  ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

  infoDialog = new Dialog(this);
}

MainWindow::~MainWindow() {
  delete ui;
}

void MainWindow::on_pushButton_clicked() {

  opened_file = QFileDialog::getOpenFileName(
      nullptr, "Выберите файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");

  if (opened_file.isEmpty()) {
    QMessageBox::critical(nullptr, "Ошибка", "Файл не выбран");
  }

  QFile openedFile(opened_file);
  if (!openedFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
    return;
  }
  dates.clear();

  QTextStream in(&openedFile);
  while (!in.atEnd()) {
    QString inLine = in.readLine();
    dates.append(inLine);
  }
  updateTable();
  openedFile.close();
}

void MainWindow::updateTable() {

  ui->tableWidget->model()->removeRows(0, ui->tableWidget->rowCount());

  size_t tableSize = dates.size();

  ui->tableWidget->setColumnCount(1);
  ui->tableWidget->setRowCount(tableSize);
  ui->tableWidget->horizontalHeader()->setSectionResizeMode(
      QHeaderView::Stretch);

  for (size_t i = 0; i < tableSize; i++) {
    QString dateString = dates[i].getDate().toString("dd.MM.yyyy");

    QTableWidgetItem* item = new QTableWidgetItem(dateString);
    qDebug() << item;

    ui->tableWidget->setItem(i, 0, item);
  }
}

void MainWindow::on_tableWidget_cellClicked(int row, int column) {
  setActive(row);
  qDebug() << row;
  setInfo();
}

void MainWindow::on_pushButton_5_clicked() {
  infoDialog->show();
}

void MainWindow::setActive(size_t active) {
  this->isActive = active;
};
size_t MainWindow::getActive() {
  return this->isActive;
};

void MainWindow::setInfo() {
  size_t activeRow = getActive();
  QString nextDay = dates[activeRow].nextDay();
  QString previousDay = dates[activeRow].previousDate();
  QString isLeap = dates[activeRow].isLeap();
  QString weekNumber = dates[activeRow].weekNumber();
  QString duration = dates[activeRow].duration();
  QString tillBitrh = dates[activeRow].DaysTillYourBithday(getBirhday());

  infoDialog->setLabelNextDay(nextDay);
  infoDialog->setLabelPrevDay(previousDay);
  infoDialog->setLabelIsLeak(isLeap);
  infoDialog->setLabelWeekNum(weekNumber);
  infoDialog->setLabelDuration(duration);
  infoDialog->setLabelBirthday(tillBitrh);
}

void MainWindow::on_pushButton_3_clicked() {

  if (dates.empty()) {
    return;
  }

  size_t curentPosition = getActive();
  setActive(getActive() - 1);
  dates.erase(dates.begin() + curentPosition);
  deleteInfo(curentPosition);  //need to edit
  updateTable();

  setInfo();  //Need to do better
}

void MainWindow::on_pushButton_2_clicked() {
  QDialog dialog(this);
  QVBoxLayout layout(&dialog);
  QCalendarWidget calendar;
  QPushButton button("Choose");

  layout.addWidget(&calendar);
  layout.addWidget(&button);

  //Create labmda function for control pressing button
  connect(&button, &QPushButton::clicked, [&]() {
    QDate selectedDate = calendar.selectedDate();

    if (selectedDate.isValid()) {
      dates.append(selectedDate.toString("dd.MM.yyyy"));
      updateTable();
      dialog.close();
    }
  });

  dialog.exec();

  appendInfo();
}

void MainWindow::newPath() {
  QString defaultPath = QDir::homePath();
  QString filter = tr("Text Files (*.txt);;All Files (*)");

  opened_file = QFileDialog::getSaveFileName(this, tr("Создать файл"),
                                             defaultPath, filter);
  if (opened_file != "") {
    opened_file += ".txt";
  }

  if (!opened_file.isEmpty()) {
    QFile file(opened_file);
    if (file.open(QIODevice::WriteOnly)) {
      file.close();
    } else {
      QMessageBox::critical(nullptr, "Ошибка", "Ошибка создания файла");
    }
  } else {
    QMessageBox::critical(nullptr, "Ошибка", "Ошибка создания файла");
  }
}

void MainWindow::appendInfo() {
  if (dates.empty()) {
    QMessageBox::warning(this, "Ошибка", "Нет данных для сохранения!");
    return;
  }

  if (opened_file.isEmpty()) {
    QMessageBox::information(nullptr, "Предупреждение", "Создайте новый файл");
    newPath();
    if (opened_file.isEmpty()) {
      dates.clear();
      updateTable();
      return;
    }
    qDebug() << opened_file;
  }

  QFile file(opened_file);
  if (!file.open(QIODevice::Append | QIODevice::Text)) {
    QMessageBox::critical(this, "Ошибка",
                          "Не удалось открыть файл для записи!");
    return;
  }

  QTextStream out(&file);
  out << dates[dates.size() - 1].getDate().toString("dd.MM.yyyy") << '\n';

  file.close();
}

void MainWindow::deleteInfo(size_t index) {
  qDebug() << index;
  if (opened_file.isEmpty()) {
    return;
  }

  if (dates.empty()) {
    return;
  }
  QFile file(opened_file);

  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QMessageBox::critical(this, "Ошибка",
                          "Не удалось открыть файл для удаления!");
    return;
  }

  QTextStream edit(&file);
  for (auto data : dates) {
    edit << data.getDate().toString("dd.MM.yyyy") << '\n';
  }
  file.close();
}

QDate MainWindow::getBirhday() {
  return this->birthdayDay;
};

void MainWindow::on_pushButton_6_clicked() {
  QDialog dialog(this);
  QVBoxLayout layout(&dialog);
  QCalendarWidget calendar;
  QPushButton button("Choose");

  layout.addWidget(&calendar);
  layout.addWidget(&button);

  //Create labmda function for control pressing button
  connect(&button, &QPushButton::clicked, [&]() {
    QDate selectedDate = calendar.selectedDate();

    if (selectedDate.isValid()) {
      this->birthdayDay = selectedDate;
      updateTable();
      dialog.close();
    }
  });

  dialog.exec();
}
