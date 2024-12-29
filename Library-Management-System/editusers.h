#ifndef EDITUSERS_H
#define EDITUSERS_H

#include <QWidget>
#include "LinkedList.h"

namespace Ui
{
class editusers;
}

class editusers : public QWidget
{
    Q_OBJECT

public:
    explicit editusers(QWidget *parent = nullptr);
    ~editusers();
    void loadUserTable();
    void saveToFile();

private slots:
    void on_backbutton_clicked();
    void on_savebutton_clicked();

private:
    Ui::editusers *ui;
    LinkedList userList;
};

#endif // EDITUSERS_H
