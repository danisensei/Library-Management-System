#include "editusers.h"
#include "ui_editusers.h"
#include "mainmenu.h"
#include <QDebug>
#include <QStandardItemModel>
#include <QMessageBox>

editusers::editusers(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editusers)
{
    ui->setupUi(this);

    userList.loadFromFile("addedusers.txt");
    loadUserTable();
}

editusers::~editusers()
{
    delete ui;
}

void editusers::loadUserTable()
{
    QStandardItemModel *model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"Name", "Email", "ID"});

    User *current = userList.getHead();

    while (current)
    {
        QList<QStandardItem *> row;
        row.append(new QStandardItem(current->name));
        row.append(new QStandardItem(current->email));
        row.append(new QStandardItem(current->id));

        model->appendRow(row);

        current = current->next;
    }

    ui->usertable->setModel(model);
}

void editusers::saveToFile()
{
    userList.clearList();

    QStandardItemModel *model = qobject_cast<QStandardItemModel *>(ui->usertable->model());

    if (!model) {
        return;
    }

    for (int row = 0; row < model->rowCount(); ++row)
    {
        QString name = model->item(row, 0)->text();
        QString email = model->item(row, 1)->text();
        QString id = model->item(row, 2)->text();

        userList.addUser(name, email, id);
    }

    userList.saveToFile("addedusers.txt");

    QMessageBox::information(this, "Success", "User data saved successfully!");
}

void editusers::on_backbutton_clicked()
{
    qDebug() << "Back button clicked";
    mainmenu *mainMenu = new mainmenu();
    mainMenu->show();
    this->close();
}

void editusers::on_savebutton_clicked()
{
    qDebug() << "Save button clicked";
    saveToFile();
}
