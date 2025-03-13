#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "reader.h"
#include "pinui.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void handleCardButton();
    void handlePinButton();
    void handleCardNumber(QString);
    void handlePinNumber(QString);
    void handlePinUiTimeOut();
private:
    Ui::MainWindow *ui;
    Reader * reader;
    PinUI * pinUi;
};
#endif // MAINWINDOW_H
