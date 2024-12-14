#include "deleteuser.h"
#include "ui_deleteuser.h"
#include "LinkedList.h"
#include <QStandardItemModel>
#include "mainmenu.h"
#include "ui_mainmenu.h"

deleteuser::deleteuser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::deleteuser)
{
    ui->setupUi(this);


    userList.loadFromFile("addedusers.txt");


    loadUserTable();


    connect(ui->deletebutton, &QPushButton::clicked, this, &deleteuser::onDeleteButtonClicked);
}

deleteuser::~deleteuser()
{
    delete ui;
}

void deleteuser::loadUserTable() {
    QStandardItemModel *model = new QStandardItemModel(this);


    model->setHorizontalHeaderLabels({"Name", "Email", "ID"});


    User *current = userList.getHead();
    while (current) {
        QList<QStandardItem*> row;
        row << new QStandardItem(current->name)
            << new QStandardItem(current->email)
            << new QStandardItem(current->id);
        model->appendRow(row);
        current = current->next;
    }

    ui->usertable->setModel(model);
}

void deleteuser::onDeleteButtonClicked() {
    QString idToDelete = ui->deleteidtextbox->text().trimmed();

    if (idToDelete.isEmpty()) {
        qDebug() << "ID field is empty.";
        return;
    }


    if (userList.removeUser(idToDelete)) {
        qDebug() << "User with ID" << idToDelete << "deleted.";
        saveUserData();
        loadUserTable();
    } else {
        qDebug() << "User with ID" << idToDelete << "not found.";
    }
}
void deleteuser::on_backbutton_clicked()
{
    qDebug() <<"back button clicked";
    mainmenu *backwidget= new mainmenu();
    backwidget->setAttribute(Qt::WA_DeleteOnClose);
    backwidget->show();
    this->hide();
}

void deleteuser::saveUserData()
{
    userList.saveToFile("addedusers.txt");
}
