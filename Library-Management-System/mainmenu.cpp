#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "mainwindow.h"
#include "adduser.h"
#include "deleteuser.h"
#include "ui_deleteuser.h"
#include "ui_registerform.h"
#include "viewusers.h"
#include "ui_viewusers.h"
#include "editusers.h"
#include "ui_editusers.h"
#include "addbook.h"
#include "ui_addbook.h"
#include "deletebook.h"
#include "ui_deletebook.h"


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
    qDebug() << "Delete User button clicked!";

    deleteuser *deleteUserWidget = new deleteuser();
    deleteUserWidget->setAttribute(Qt::WA_DeleteOnClose);
    deleteUserWidget->show();
    this->hide();
}

void mainmenu :: on_edituserbutton_clicked()
{
    qDebug() << "edit user";
    editusers *editUsersWidget = new editusers();
    editUsersWidget->setAttribute(Qt::WA_DeleteOnClose);
    editUsersWidget->show();
    this->hide();
}

void mainmenu::on_viewusersbutton_clicked()
{
    qDebug() << "View Users button clicked!";

    viewusers *viewUsersWidget = new viewusers();
    viewUsersWidget->setAttribute(Qt::WA_DeleteOnClose);
    viewUsersWidget->show();
    this->hide();

}


void mainmenu::on_addbookbutton_clicked()
{
    qDebug() << "Add Book button clicked!";

    addbook *addbookwidget = new addbook(&books);
    addbookwidget->setAttribute(Qt::WA_DeleteOnClose);
    addbookwidget->show();
    this->hide();
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
