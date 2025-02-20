#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->N0,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N1,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N2,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N3,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N4,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N5,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N6,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N7,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N8,&QPushButton::clicked,this,&MainWindow::numbers);
    connect(ui->N9,&QPushButton::clicked,this,&MainWindow::numbers);

    connect(ui->minus,&QPushButton::clicked,this,&MainWindow::operators);
    connect(ui->plus,&QPushButton::clicked,this,&MainWindow::operators);
    connect(ui->multiply,&QPushButton::clicked,this,&MainWindow::operators);
    connect(ui->divide,&QPushButton::clicked,this,&MainWindow::operators);

    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearEnter);
    connect(ui->enter,&QPushButton::clicked,this,&MainWindow::clearEnter);

    currentOperator = "";
    currentBox = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numbers() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString buttonText = button->text();

        if (currentBox == 1) {
            ui->Box1->setText(ui->Box1->text() + buttonText);
        } else if (currentBox == 2) {
            ui->Box2->setText(ui->Box2->text() + buttonText);
        }
    }
}

void MainWindow::operators() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());
    if (button) {
        currentOperator = button->text();
        currentBox = 2;
    }
}

void MainWindow::clearEnter() {
    QPushButton* button = qobject_cast<QPushButton*>(sender());

    if (button->text() == "Clear") {
        ui->Box1->clear();
        ui->Box2->clear();
        ui->Box3->clear();
    } else if (button->text() == "Enter") {

        double num1 = ui->Box1->text().toDouble();
        double num2 = ui->Box2->text().toDouble();
        double result = 0;

        if (currentOperator == "-") {
            result = num1 - num2;
        } else if (currentOperator == "+") {
            result = num1 + num2;
        } else if (currentOperator == "*") {
            result = num1 * num2;
        } else if (currentOperator == "/") {
            result = num1 / num2;
        }

        ui->Box3->setText(QString::number(result));

        currentBox = 1;
        currentOperator = "";
    }
}
