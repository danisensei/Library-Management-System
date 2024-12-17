#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>

namespace Ui {
class addbook;
}

class addbook : public QWidget
{
    Q_OBJECT

public:
    explicit addbook(QWidget *parent = nullptr);
    ~addbook();

private:
    Ui::addbook *ui;
};

#endif // ADDBOOK_H
