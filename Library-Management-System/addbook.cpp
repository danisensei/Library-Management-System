#include "addbook.h"
#include "ui_addbook.h"

addbook::addbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addbook)
{
    ui->setupUi(this);
}

addbook::~addbook()
{
    delete ui;
}
