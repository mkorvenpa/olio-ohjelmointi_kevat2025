#ifndef PINUI_H
#define PINUI_H

#include <QDialog>
#include <QTimer>

namespace Ui {
class PinUI;
}

class PinUI : public QDialog
{
    Q_OBJECT

public:
    explicit PinUI(QWidget *parent = nullptr);
    ~PinUI();
private slots:
    void handlePinNum();
    void timeOut();
    void enterPinNumHandler();
    void deleteBtnHandler();
    void cancelBtnHandler();
signals:
    void sendPinNum(QString);
    void PinUiTimeOut();

private:
    Ui::PinUI *ui;
    QTimer *timer;
    QString number;
};

#endif // PINUI_H
