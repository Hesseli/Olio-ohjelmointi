/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    QProgressBar *progressBar_2;
    QPushButton *switch1;
    QPushButton *switch2;
    QPushButton *start;
    QPushButton *stop;
    QPushButton *sec;
    QPushButton *min;
    QLabel *gameStatus;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(120, 70, 161, 31));
        progressBar->setValue(24);
        progressBar_2 = new QProgressBar(centralwidget);
        progressBar_2->setObjectName("progressBar_2");
        progressBar_2->setGeometry(QRect(550, 70, 161, 31));
        progressBar_2->setValue(24);
        switch1 = new QPushButton(centralwidget);
        switch1->setObjectName("switch1");
        switch1->setGeometry(QRect(120, 120, 151, 51));
        switch2 = new QPushButton(centralwidget);
        switch2->setObjectName("switch2");
        switch2->setGeometry(QRect(550, 120, 151, 51));
        start = new QPushButton(centralwidget);
        start->setObjectName("start");
        start->setGeometry(QRect(200, 370, 151, 51));
        stop = new QPushButton(centralwidget);
        stop->setObjectName("stop");
        stop->setGeometry(QRect(450, 370, 151, 51));
        sec = new QPushButton(centralwidget);
        sec->setObjectName("sec");
        sec->setGeometry(QRect(300, 300, 75, 31));
        min = new QPushButton(centralwidget);
        min->setObjectName("min");
        min->setGeometry(QRect(430, 300, 75, 31));
        gameStatus = new QLabel(centralwidget);
        gameStatus->setObjectName("gameStatus");
        gameStatus->setGeometry(QRect(18, 240, 761, 32));
        gameStatus->setMinimumSize(QSize(0, 31));
        gameStatus->setStyleSheet(QString::fromUtf8("font: 700 18pt \"Segoe UI\";"));
        gameStatus->setAlignment(Qt::AlignCenter);
        gameStatus->setWordWrap(false);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        switch1->setText(QCoreApplication::translate("MainWindow", "Swich player", nullptr));
        switch2->setText(QCoreApplication::translate("MainWindow", "Swich player", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "START GAME", nullptr));
        stop->setText(QCoreApplication::translate("MainWindow", "STOP GAME", nullptr));
        sec->setText(QCoreApplication::translate("MainWindow", "120 sec", nullptr));
        min->setText(QCoreApplication::translate("MainWindow", "5 min", nullptr));
        gameStatus->setText(QCoreApplication::translate("MainWindow", "Game ongoing", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
