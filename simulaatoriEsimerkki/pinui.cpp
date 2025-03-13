#include "pinui.h"
#include "pinui.h"
#include "ui_pinui.h"

PinUI::PinUI(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PinUI)
{
    qDebug()<<"pinUI luotu";
    ui->setupUi(this);
    connect(ui->pin, &QPushButton::clicked,
            this, &PinUI::handlePinNum);

    connect(ui->pushButton1, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton2, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton3, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton4, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton5, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton6, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton7, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton8, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton9, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);
    connect(ui->pushButton0, &QPushButton::clicked,
            this, &PinUI::enterPinNumHandler);

    connect(ui->buttonDelete, &QPushButton::clicked,
            this, &PinUI::deleteBtnHandler);
    connect(ui->buttonCancel, &QPushButton::clicked,
            this, &PinUI::cancelBtnHandler);
    connect(ui->buttonEnter, &QPushButton::clicked,
            this, &PinUI::handlePinNum);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout,
            this, &PinUI::timeOut);
    timer->start(10000);
}

PinUI::~PinUI()
{
    qDebug()<<"pinUI tuhottu";
    delete ui;
}

void PinUI::handlePinNum()
{
    timer->start(10000);
    qDebug()<<"PinUIn slot funktiossa";
    emit sendPinNum(number);
}

void PinUI::timeOut()
{
    qDebug()<<"PinUi timeout handler";
    emit PinUiTimeOut();
}

void PinUI::enterPinNumHandler()
{
    timer->start(10000);
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString numberName = button->objectName();
    number = number + numberName.at(10);
    ui->pinNumLineEdit->setText(number);
}

void PinUI::deleteBtnHandler()
{
    timer->start(10000);
    int pos = number.length();
    number.remove(pos-1,1);
    ui->pinNumLineEdit->setText(number);
}

void PinUI::cancelBtnHandler()
{
    emit sendPinNum("");
}
