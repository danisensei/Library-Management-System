#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include "adduser.h"
#include "ui_registerform.h"

mainmenu::mainmenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu::on_adduserbutton_clicked()
{
    qDebug() << "Add User button clicked!";

    adduser *addUserWidget = new adduser();
    addUserWidget->setAttribute(Qt::WA_DeleteOnClose);
    addUserWidget->show();
    this->hide();

}

void mainmenu :: on_deleteuserbutton_clicked()
{
    qDebug() << "delete user";
}

void mainmenu :: on_edituserbutton_clicked()
{
    qDebug() << "edit user";
}

void mainmenu :: on_viewusersbutton_clicked()
{
    qDebug() << "viewusers!";
}

void mainmenu :: on_addbookbutton_clicked()
{
    qDebug() << "addbooks!";
}

void mainmenu :: on_deletebookbutton_clicked()
{
    qDebug() << "deletebook!";
}

void mainmenu :: on_editbookbutton_clicked()
{
    qDebug() << "editbook!";
}

void mainmenu :: on_viewbooksbutton_clicked()
{
    qDebug() << "viewbooks";
}

void mainmenu :: on_issuebookbutton_clicked()
{
    qDebug() << "issuebook!";
}

void mainmenu :: on_returnbookbutton_clicked()
{
    qDebug() << "returnbook!";
}
void mainmenu :: on_logoutbutton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}
