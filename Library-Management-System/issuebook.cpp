#include "issuebook.h"
#include "ui_issuebook.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"

issuebook::issuebook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::issuebook)
{
    ui->setupUi(this);
}

issuebook::~issuebook()
{
    delete ui;
}

void issuebook::on_backbutton_clicked()
{
    mainmenu *backwidget = new mainmenu();
    backwidget->show();
    this->close();

}

