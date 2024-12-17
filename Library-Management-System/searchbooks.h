#ifndef SEARCHBOOKS_H
#define SEARCHBOOKS_H

#include <QWidget>

namespace Ui {
class searchbooks;
}

class searchbooks : public QWidget
{
    Q_OBJECT

public:
    explicit searchbooks(QWidget *parent = nullptr);
    ~searchbooks();

private slots:
    void on_backbutton_clicked();

private:
    Ui::searchbooks *ui;
};


#endif // SEARCHBOOKS_H
