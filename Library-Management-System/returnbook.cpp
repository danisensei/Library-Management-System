#include "returnbook.h"
#include "ui_returnbook.h"

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
