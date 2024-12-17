#include "editbook.h"
#include "ui_editbook.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"

editbook::editbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editbook)
{
    ui->setupUi(this);
}

editbook::~editbook()
{
    delete ui;
}

void editbook:: on_backbutton_clicked()
{
    mainmenu *backbutton= new mainmenu();
    backbutton->setAttribute(Qt::WA_DeleteOnClose);
    backbutton->show();
    this->hide();


}
