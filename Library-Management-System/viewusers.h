#ifndef VIEWUSERS_H
#define VIEWUSERS_H

#include <QWidget>
#include "LinkedList.h"

namespace Ui
{
class viewusers;
}

class viewusers : public QWidget
{
    Q_OBJECT

public:
    explicit viewusers(QWidget *parent = nullptr);
    ~viewusers();
    void loadUserTable();
private slots:
    void on_backbutton_clicked();

private:
    Ui::viewusers *ui;
    LinkedList userList;

};

#endif // VIEWUSERS_H
