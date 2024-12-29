#include "viewusers.h"
#include "ui_viewusers.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "LinkedList.h"
#include <QStandardItemModel>

viewusers::viewusers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::viewusers)
{
     ui->setupUi(this);


    userList.loadFromFile("addedusers.txt");


    loadUserTable();


}

viewusers::~viewusers()
{
    delete ui;
}

void viewusers :: on_backbutton_clicked()
{
    qDebug() <<"back button clicked";
    mainmenu *backbuttonwidget= new mainmenu();
    backbuttonwidget->setAttribute(Qt::WA_DeleteOnClose);
    backbuttonwidget->show();
    this->hide();
}

void viewusers::loadUserTable()
{
    QStandardItemModel *model = new QStandardItemModel(this);


    model->setHorizontalHeaderLabels({"Name", "Email", "ID"});


    User *current = userList.getHead();
    while (current)
    {
        QList<QStandardItem*> row;
        row << new QStandardItem(current->name)
            << new QStandardItem(current->email)
            << new QStandardItem(current->id);
        model->appendRow(row);
        current = current->next;
    }

    ui->usertable->setModel(model);
}
