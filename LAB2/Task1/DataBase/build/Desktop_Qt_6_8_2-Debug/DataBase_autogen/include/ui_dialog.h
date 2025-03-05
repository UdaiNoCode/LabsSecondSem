/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *nextDate;
    QLabel *PrevDay;
    QLabel *IsLeak;
    QLabel *WeekNum;
    QLabel *label_10;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(377, 396);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(100, 340, 171, 41));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label = new QLabel(Dialog);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 40, 101, 18));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 80, 191, 18));
        label_3 = new QLabel(Dialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(20, 120, 191, 18));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(20, 160, 191, 18));
        label_5 = new QLabel(Dialog);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(20, 200, 191, 18));
        nextDate = new QLabel(Dialog);
        nextDate->setObjectName("nextDate");
        nextDate->setGeometry(QRect(240, 40, 66, 18));
        PrevDay = new QLabel(Dialog);
        PrevDay->setObjectName("PrevDay");
        PrevDay->setGeometry(QRect(240, 80, 66, 18));
        IsLeak = new QLabel(Dialog);
        IsLeak->setObjectName("IsLeak");
        IsLeak->setGeometry(QRect(240, 120, 66, 18));
        WeekNum = new QLabel(Dialog);
        WeekNum->setObjectName("WeekNum");
        WeekNum->setGeometry(QRect(240, 160, 66, 18));
        label_10 = new QLabel(Dialog);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(240, 200, 66, 18));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "Next day date:", nullptr));
        label_2->setText(QCoreApplication::translate("Dialog", "Previous day date:", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "IsLeap:", nullptr));
        label_4->setText(QCoreApplication::translate("Dialog", "Week Number:", nullptr));
        label_5->setText(QCoreApplication::translate("Dialog", "DaysTillYourBithday:", nullptr));
        nextDate->setText(QCoreApplication::translate("Dialog", "Info", nullptr));
        PrevDay->setText(QCoreApplication::translate("Dialog", "Info", nullptr));
        IsLeak->setText(QCoreApplication::translate("Dialog", "Info", nullptr));
        WeekNum->setText(QCoreApplication::translate("Dialog", "Info", nullptr));
        label_10->setText(QCoreApplication::translate("Dialog", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
