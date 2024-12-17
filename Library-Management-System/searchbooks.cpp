#include "searchbooks.h"
#include "ui_searchbooks.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"

searchbooks::searchbooks(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchbooks)
{
    ui->setupUi(this);
}

searchbooks::~searchbooks()
{
    delete ui;
}

void searchbooks:: on_backbutton_clicked()
{
    mainmenu *backwidget= new mainmenu();
    backwidget->setAttribute(Qt::WA_DeleteOnClose);
    backwidget->show();
    this->hide();
}
