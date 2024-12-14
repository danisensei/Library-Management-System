#ifndef DELETEUSER_H
#define DELETEUSER_H

#include <QWidget>
#include "LinkedList.h"

namespace Ui {
class deleteuser;
}

class deleteuser : public QWidget
{
    Q_OBJECT

public:
    explicit deleteuser(QWidget *parent = nullptr);
    ~deleteuser();

private slots:
    void onDeleteButtonClicked();
    void on_backbutton_clicked();

private:
    Ui::deleteuser *ui;
    LinkedList userList;
    void loadUserTable();
    void saveUserData();
};

#endif // DELETEUSER_H
