#ifndef READER_H
#define READER_H

#include <QDialog>

namespace Ui {
class Reader;
}

class Reader : public QDialog
{
    Q_OBJECT

public:
    explicit Reader(QWidget *parent = nullptr);
    ~Reader();

private slots:
    void handleCardNum();
    void enterCardNumHandler();
    void deleteBtnHandler();
    void cancelBtnHandler();

signals:
    void sendCardNum(QString);

private:
    Ui::Reader *ui;
    QString number;
};

#endif // READER_H
