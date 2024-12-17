#include "deletebook.h"
#include "ui_deletebook.h"

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
