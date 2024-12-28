#include "returnbook.h"
#include "ui_returnbook.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"

returnbook::returnbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::returnbook)
{
    ui->setupUi(this);
}

returnbook::~returnbook()
{
    delete ui;
}

void returnbook::on_backbutton_clicked()
{
    mainmenu *back = new mainmenu();
    back->show();
    this->close();
}

