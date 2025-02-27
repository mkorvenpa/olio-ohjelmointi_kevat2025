#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setGameInfoText("Select playtime and press start game!", 10);

    pQTimer = new QTimer(this);
    pQTimer->setInterval(1000);

    connect(ui->switchToP2Button,&QPushButton::clicked,this,&MainWindow::switchP2Handler);
    connect(ui->swichToP1Button,&QPushButton::clicked,this,&MainWindow::switchP1Handler);
    connect(ui->startButton,&QPushButton::clicked,this,&MainWindow::StartHandler);
    connect(ui->stopButton,&QPushButton::clicked,this,&MainWindow::StopHandler);
    connect(ui->button120sec,&QPushButton::clicked,this,&MainWindow::time120secHandler);
    connect(ui->button5min,&QPushButton::clicked,this,&MainWindow::time5minHandler);

    connect(pQTimer, &QTimer::timeout,this, &MainWindow::timeout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if(currentPlayer==1){
        player1Time--;
        if(player1Time==0){
            pQTimer->stop();
            MainWindow::setGameInfoText("Player 2 won!", 20);
        }
    }
    else{
        player2Time--;
        if(player2Time==0){
            pQTimer->stop();
            MainWindow::setGameInfoText("Player 1 won!", 20);
        }
    }
    MainWindow::updateProgressBar();
}

void MainWindow::StartHandler()
{
    currentPlayer=1;
    pQTimer->start();
    MainWindow::setGameInfoText("Game ongoing", 15);
}

void MainWindow::StopHandler()
{
    pQTimer->stop();
    player1Time=0;
    player2Time=0;
    gameTime=0;
    MainWindow::setGameInfoText("Game ended, select new playtime", 10);
    MainWindow::updateProgressBar();
}

void MainWindow::switchP1Handler()
{
    currentPlayer=1;
}

void MainWindow::switchP2Handler()
{
    currentPlayer=2;
}

void MainWindow::time120secHandler()
{
    gameTime = 120;
    player1Time = gameTime;
    player2Time = gameTime;
    ui->P1progressBar->setRange(0,gameTime);
    ui->P1progressBar->setValue(player1Time);
    ui->P2progressBar->setRange(0,gameTime);
    ui->P2progressBar->setValue(player2Time);

    MainWindow::setGameInfoText("Ready to play!",12);
}

void MainWindow::time5minHandler()
{
    gameTime = 300;
    player1Time = gameTime;
    player2Time = gameTime;
    ui->P1progressBar->setRange(0,gameTime);
    ui->P1progressBar->setValue(player1Time);
    ui->P2progressBar->setRange(0,gameTime);
    ui->P2progressBar->setValue(player2Time);

    MainWindow::setGameInfoText("Ready to play!",12);
}

void MainWindow::updateProgressBar()
{
    ui->P1progressBar->setValue(player1Time);
    ui->P2progressBar->setValue(player2Time);
}

void MainWindow::setGameInfoText(QString a, short b){
    QFont font= ui->label->font();
    font.setPointSize(b);
    ui->label->setFont(font);
    ui->label->setText(a);
}
