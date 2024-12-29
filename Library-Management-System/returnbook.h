#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

namespace Ui {
class returnbook;
}

class returnbook : public QWidget
{
    Q_OBJECT

public:
    explicit returnbook(QWidget *parent = nullptr);
    ~returnbook();

private slots:
    //void on_returnButton_clicked();

private:
    Ui::returnbook *ui;

};

#endif // RETURNBOOK_H
