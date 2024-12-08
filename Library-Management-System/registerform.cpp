#include "registerform.h"
#include "ui_registerform.h"

RegisterForm::RegisterForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegisterForm)
{
    ui->setupUi(this);
}

RegisterForm::~RegisterForm()
{
    delete ui;
}
