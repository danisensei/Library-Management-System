#include "deletebook.h"
#include "ui_deletebook.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"

deletebook::deletebook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletebook)
{
    ui->setupUi(this);
}

deletebook::~deletebook()
{
    delete ui;
}

void deletebook::on_backbutton_clicked()
{
    qDebug() <<"back button clicked";
    mainmenu *backwidget= new mainmenu();
    backwidget->setAttribute(Qt::WA_DeleteOnClose);
    backwidget->show();
    this->hide();
}
