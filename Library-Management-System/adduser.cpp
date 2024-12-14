#include "adduser.h"
#include "ui_adduser.h"
#include "LinkedList.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"

static LinkedList userList;

adduser::adduser(QWidget* parent)
    : QWidget(parent), ui(new Ui::adduser) {
    ui->setupUi(this);

    userList.loadFromFile("addedusers.txt");
}

adduser::~adduser() {
    delete ui;
    userList.saveToFile("addedusers.txt");
}

void adduser::on_backbutton_clicked()
{
    qDebug() <<"back button clicked";
    mainmenu *backwidget= new mainmenu();
    backwidget->setAttribute(Qt::WA_DeleteOnClose);
    backwidget->show();
    this->hide();
}

void adduser::on_addubutton_clicked() {
    QString name = ui->namefield->text();
    QString email = ui->mailfield->text();
    QString id = ui->idfield->text();

    if (name.isEmpty() || email.isEmpty() || id.isEmpty()) {
        qDebug() << "Please fill in all fields.";
        return;
    }

    userList.addUser(name, email, id);
    userList.saveToFile("addedusers.txt");

    ui->namefield->clear();
    ui->mailfield->clear();
    ui->idfield->clear();
}
