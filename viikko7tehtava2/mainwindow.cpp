#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    state = 0;

    connect(ui->N0,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N1,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N2,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N3,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N4,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N5,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N6,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N7,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N8,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);
    connect(ui->N9,&QPushButton::clicked,this,&MainWindow::numberClickedHandler);

    connect(ui->enter,&QPushButton::clicked,this,&MainWindow::enterHandler);
    connect(ui->clear,&QPushButton::clicked,this,&MainWindow::clearHandler);

    connect(ui->add0,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->sub1,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->mul2,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
    connect(ui->div3,&QPushButton::clicked,this,&MainWindow::addSubMulDivClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::numberClickedHandler()
{
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString numberName = button->objectName();
    qDebug()<<numberName.at(1);

    if(state == 0){
        ui->num1->setText(ui->num1->text()+numberName.at(1));
    }
    else{
        ui->num2->setText(ui->num2->text()+numberName.at(1));
    }
}

void MainWindow::clearHandler()
{
    state = 0;
    ui->num1->setText("");
    ui->num2->setText("");
    ui->result->setText("");
}

void MainWindow::enterHandler()
{
    number1 = ui->num1->text();
    qDebug()<<number1;
    number2 = ui->num2->text();
    qDebug()<<number2;
    float finalNum1 = number1.toFloat();
    float finalNum2 = number2.toFloat();
    if (operand==0){
        result = finalNum1 + finalNum2;
    }
    else if (operand==1){
        result = finalNum1 - finalNum2;
    }
    else if (operand==2){
        result = finalNum1 * finalNum2;
    }
    else if (operand==3){
        result = finalNum1 / finalNum2;
    }
    ui->result->setText(QString::number(result));
}

void MainWindow::addSubMulDivClickHandler()
{
    state = 1;
    QPushButton * button = qobject_cast<QPushButton *>(sender());
    QString operandName = button->objectName();
    qDebug()<<operandName;
    QString operandNum = operandName.at(3);
    operand = operandNum.toShort();
}
