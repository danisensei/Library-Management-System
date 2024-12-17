#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QWidget>

namespace Ui {
class deletebook;
}

class deletebook : public QWidget
{
    Q_OBJECT

public:
    explicit deletebook(QWidget *parent = nullptr);
    ~deletebook();

private slots:
    void on_backbutton_clicked();

private:
    Ui::deletebook *ui;
};

#endif // DELETEBOOK_H
