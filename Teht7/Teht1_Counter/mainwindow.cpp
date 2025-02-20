#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Count,&QPushButton::clicked,this,&MainWindow::countClick);
    connect(ui->Reset,&QPushButton::clicked,this,&MainWindow::resetClick);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countClick()
{
    qDebug()<<"Count vastaanotettu";
    counter++;
    ui->laatikko->setText(QString::number(counter));
}

void MainWindow::resetClick()
{
    qDebug()<<"Reset vastaanotettu";
    counter = 0;
    ui->laatikko->clear();
}
