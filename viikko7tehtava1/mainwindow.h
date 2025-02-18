#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <qstring.h>
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

public slots:
    void countNumber();
    void resetNumber();

private:
    Ui::MainWindow *ui;
    int counter=0;
};
#endif // MAINWINDOW_H
