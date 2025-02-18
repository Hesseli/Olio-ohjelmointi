#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->N1,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N2,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N3,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N4,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N5,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N6,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N7,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N8,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N9,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->N0,&QPushButton::clicked,this,&MainWindow::numberClicks);
    connect(ui->Nclear,&QPushButton::clicked,this,&MainWindow::clearClick);
    connect(ui->Nenter,&QPushButton::clicked,this,&MainWindow::enterClick);
    connect(ui->Nplus,&QPushButton::clicked,this,&MainWindow::operClicks);
    connect(ui->Nminus,&QPushButton::clicked,this,&MainWindow::operClicks);
    connect(ui->Nmulti,&QPushButton::clicked,this,&MainWindow::operClicks);
    connect(ui->Ndivide,&QPushButton::clicked,this,&MainWindow::operClicks);

    currentBox = 1;
    currentOperation = "";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClicks()
{
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();

        if (currentBox == 1) {
            ui->laatikko1->setText(ui->laatikko1->text() + buttonText);
        } else if (currentBox == 2) {
            ui->laatikko2->setText(ui->laatikko2->text() + buttonText);
        }
    }
}

void MainWindow::operClicks() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        currentOperation = button->text();
        currentBox = 2;
    }
}

void MainWindow::clearClick() {
    ui->laatikko1->clear();
    ui->laatikko2->clear();
    ui->laatikko3->clear();
    currentBox = 1;
    currentOperation = "";
}

void MainWindow::enterClick() {
    double num1 = ui->laatikko1->text().toDouble();
    double num2 = ui->laatikko2->text().toDouble();
    double result = 0;

    if (currentOperation == "+") {
        result = num1 + num2;
    }
    else if (currentOperation == "-") {
        result = num1 - num2;
    }
    else if (currentOperation == "*") {
        result = num1 * num2;
    }
    else if (currentOperation == "/") {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            ui->laatikko3->setText("Error");
            return;
        }
    }

    ui->laatikko3->setText(QString::number(result));

    currentBox = 1;
    currentOperation = "";
}
