#include "reader.h"
#include "ui_reader.h"
#include "QDebug"

Reader::Reader(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Reader)
{
    qDebug()<<"reader luotu";
    ui->setupUi(this);
    connect(ui->card, &QPushButton::clicked,
            this, &Reader::handleCardNum);

    connect(ui->pushButton1, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton2, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton3, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton4, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton5, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton6, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton7, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton8, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton9, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);
    connect(ui->pushButton0, &QPushButton::clicked,
            this, &Reader::enterCardNumHandler);

    connect(ui->buttonDelete, &QPushButton::clicked,
            this, &Reader::deleteBtnHandler);
    connect(ui->buttonCancel, &QPushButton::clicked,
            this, &Reader::cancelBtnHandler);
    connect(ui->buttonEnter, &QPushButton::clicked,
            this, &Reader::handleCardNum);
}

Reader::~Reader()
{
    qDebug()<<"reader tuhottu";
    delete ui;
}

void Reader::handleCardNum()
{
    qDebug()<<"Readerin slot funktiossa";
    emit sendCardNum(number);
}

void Reader::enterCardNumHandler()
{
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString numberName = button->objectName();
    number = number + numberName.at(10);
    ui->cardNumLineEdit->setText(number);
}

void Reader::deleteBtnHandler()
{
    int pos = number.length();
    number.remove(pos-1,1);
    ui->cardNumLineEdit->setText(number);
}

void Reader::cancelBtnHandler()
{
    emit sendCardNum("");
}
