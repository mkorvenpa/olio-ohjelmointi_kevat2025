#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->card, &QPushButton::clicked,
            this, &MainWindow::handleCardButton);

    connect(ui->pin, &QPushButton::clicked,
            this, &MainWindow::handlePinButton);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleCardButton()
{
    reader = new Reader(this);

    connect(reader, &Reader::sendCardNum,
            this, &MainWindow::handleCardNumber);

    qDebug()<<"card button pressed";
    reader->open();
}

void MainWindow::handlePinButton()
{
    pinUi = new PinUI(this);

    connect(pinUi, &PinUI::sendPinNum,
            this, &MainWindow::handlePinNumber);
    connect(pinUi, &PinUI::PinUiTimeOut,
            this, &MainWindow::handlePinUiTimeOut);

    qDebug()<<"pin button pressed";
    pinUi->open();
}

void MainWindow::handleCardNumber(QString s)
{
    qDebug()<<"vastaanotettiin kortin numero";
    ui->cardNum->setText(s);
    reader->close();
    delete reader;
}

void MainWindow::handlePinNumber(QString s)
{
    qDebug()<<"vastaanotettiin pin numero";
    ui->pinNum->setText(s);
    pinUi->close();
    delete pinUi;
}

void MainWindow::handlePinUiTimeOut()
{
    qDebug()<<"vastaanotettiin timeout";
    pinUi->close();
    delete pinUi;
}
