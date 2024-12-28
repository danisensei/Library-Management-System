#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>

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
    void on_backbutton_clicked();

private:
    Ui::returnbook *ui;
};

#endif // RETURNBOOK_H
