#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qstring.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->countButton,&QPushButton::clicked,
            this,&MainWindow::countNumber);
    connect(ui->resetButton,&QPushButton::clicked,
            this,&MainWindow::resetNumber);
    QString teksti = QString::number(counter);
    ui->lineEdit->setText(teksti);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::countNumber()
{
    counter++;
    QString teksti = QString::number(counter);
    ui->lineEdit->setText(teksti);
}

void MainWindow::resetNumber()
{
    counter=0;
    QString teksti = QString::number(counter);
    ui->lineEdit->setText(teksti);
}
