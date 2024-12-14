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
    ui->usertable->setRowCount(0);
    ui->usertable->setColumnCount(3);
    ui->usertable->setHorizontalHeaderLabels({"Name", "Email", "ID"});

    User *current = userList.getHead();
    int row = 0;

    while (current)
    {
        ui->usertable->insertRow(row);
        ui->usertable->setItem(row, 0, new QTableWidgetItem(current->name));
        ui->usertable->setItem(row, 1, new QTableWidgetItem(current->email));
        ui->usertable->setItem(row, 2, new QTableWidgetItem(current->id));

        current = current->next;
        row++;
    }
}

void editusers::saveToFile()
{
    userList.clearList();

    for (int row = 0; row < ui->usertable->rowCount(); ++row)
    {
        QString name = ui->usertable->item(row, 0)->text();
        QString email = ui->usertable->item(row, 1)->text();
        QString id = ui->usertable->item(row, 2)->text();

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
