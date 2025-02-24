#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , player1Time(0)
    , player2Time(0)
    , currentPlayer(1)
    , gameTime(0)
{
    ui->setupUi(this);
    pQTimer = new QTimer(this);

    connect(pQTimer, &QTimer::timeout, this, &MainWindow::timeout);
    connect(ui->start, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->stop, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(ui->switch1, &QPushButton::clicked, this, &MainWindow::switchTurn);
    connect(ui->switch2, &QPushButton::clicked, this, &MainWindow::switchTurn);
    connect(ui->sec, &QPushButton::clicked, this, &MainWindow::setTime);
    connect(ui->min, &QPushButton::clicked, this, &MainWindow::setTime);

    setGameInfoText("Select playtime and press start game");
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if (currentPlayer == 1) {
        if (player1Time > 0) {
            player1Time--;
            ui->progressBar->setValue((player1Time * 100) / gameTime);
        }
        if (player1Time == 0) {
            setGameInfoText("Player 2 WON!!!");
            QTimer::singleShot(30000, this, &MainWindow::resetGame);
        }
    } else {
        if (player2Time > 0) {
            player2Time--;
            ui->progressBar_2->setValue((player2Time * 100) / gameTime);
        }
        if (player2Time == 0) {
            setGameInfoText("Player 1 WON!!!");
            QTimer::singleShot(30000, this, &MainWindow::resetGame);
        }
    }
}

void MainWindow::startGame()
{
    setGameInfoText("Game ongoing");
    pQTimer->start(1000);
}

void MainWindow::stopGame()
{
    pQTimer->stop();
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    setGameInfoText("New game via start button");
}

void MainWindow::switchTurn()
{
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
}

void MainWindow::setTime() {
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if(button == ui->sec) {
    gameTime = 120;
    } else if(button == ui->min) {
        gameTime = 300;
    }
    player1Time = gameTime;
    player2Time = gameTime;
    ui->progressBar->setValue(100);
    ui->progressBar_2->setValue(100);
    setGameInfoText("Ready to play");
}

void MainWindow::setGameInfoText(QString text)
{
    ui->gameStatus->setText(text);
}

void MainWindow::resetGame()
{
    ui->progressBar->setValue(0);
    ui->progressBar_2->setValue(0);
    setGameInfoText("New game via start button");
}
