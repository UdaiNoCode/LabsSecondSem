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

    opened_file_path = QFileDialog::getOpenFileName(
        nullptr, "Выберите файл", "", "Текстовые файлы (*.txt);;Все файлы (*)");

    if (opened_file_path.isEmpty()) {
        QMessageBox::critical(nullptr, "Ошибка", "Файл не выбран");
    }

    QFile opened_file(opened_file_path);
    if (!opened_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Ошибка", "Не удалось открыть файл");
        return;
    }
    dates.clear();

    QTextStream in(&opened_file);
    while (!in.atEnd()) {
        QString inLine = in.readLine();
        dates.append(inLine);
    }
    updateTable();
    opened_file.close();
}

void MainWindow::updateTable() {

    ui->tableWidget->model()->removeRows(0, ui->tableWidget->rowCount());

    size_t table_size = dates.size();

    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setRowCount(table_size);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(
        QHeaderView::Stretch);


    for (size_t i = 0; i < table_size; i++) {
        QString date_string = dates[i].getDate().toString("dd.MM.yyyy");

        auto item = new QTableWidgetItem(date_string);
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
    size_t active_row = getActive();
    QString next_day = dates[active_row].nextDay();
    QString previous_day = dates[active_row].previousDate();
    QString is_leap = dates[active_row].isLeap();
    QString week_number = dates[active_row].weekNumber();
    QString duration = dates[active_row].duration();
    QString till_birth = dates[active_row].DaysTillYourBithday(getBirhday());

    infoDialog->setLabelNextDay(next_day);
    infoDialog->setLabelPrevDay(previous_day);
    infoDialog->setLabelIsLeak(is_leap);
    infoDialog->setLabelWeekNum(week_number);
    infoDialog->setLabelDuration(duration);
    infoDialog->setLabelBirthday(till_birth);
}

void MainWindow::on_pushButton_3_clicked() {

    if (dates.empty()) {
        return;
    }

    size_t curent_position = getActive();


    if (curent_position == 0) {
        dates.erase(dates.begin() + curent_position);
        setActive(getActive());
    } else {
        setActive(getActive() - 1);
        dates.erase(dates.begin() + curent_position);
    }
    deleteInfo(curent_position);  //need to edit
    updateTable();

    setInfo();	//Need to do better
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
        QDate selected_date = calendar.selectedDate();

        if (selected_date.isValid()) {
            dates.append(selected_date.toString("dd.MM.yyyy"));
            updateTable();
            dialog.close();
        }
    });

    dialog.exec();

    appendInfo();
}

void MainWindow::newPath() {
    QString deafult_path = QDir::homePath();
    QString filter = tr("Text Files (*.txt);;All Files (*)");

    opened_file_path = QFileDialog::getSaveFileName(this, tr("Создать файл"),
                                                    deafult_path, filter);


    if (opened_file_path != "") {
        opened_file_path += ".txt";
    }

    if (!opened_file_path.isEmpty()) {
        QFile file(opened_file_path);
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

    if (opened_file_path.isEmpty()) {
        QMessageBox::information(nullptr, "Предупреждение",
                                 "Создайте новый файл");
        newPath();
        if (opened_file_path.isEmpty()) {
            dates.clear();
            updateTable();
            return;
        }
        qDebug() << opened_file_path;
    }

    QFile file(opened_file_path);
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
    if (opened_file_path.isEmpty()) {
        return;
    }

    if (dates.empty()) {
        return;
    }
    QFile file(opened_file_path);

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
        QDate selected_date = calendar.selectedDate();

        if (selected_date.isValid()) {
            this->birthdayDay = selected_date;
            updateTable();
            dialog.close();
        }
    });

    dialog.exec();
}

void MainWindow::on_pushButton_4_clicked() {
    QDialog dialog(this);
    QVBoxLayout layout(&dialog);
    QCalendarWidget calendar;
    QPushButton button("Choose");

    layout.addWidget(&calendar);
    layout.addWidget(&button);

    //Create labmda function for control pressing button


    connect(&button, &QPushButton::clicked, [&]() {
        QDate selected_date = calendar.selectedDate();

        if (selected_date.isValid()) {
            dates[this->isActive] = selected_date.toString("dd.MM.yyyy");
            updateTable();
            setInfo();
            dialog.close();
        }
    });

    dialog.exec();
}
