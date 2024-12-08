#include "registerform.h"
#include "ui_registerform.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

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

void RegisterForm::on_RegisterButton_clicked()
{
    QString username = ui->UsernameField->text();
    QString email = ui->EmailTextField->text();
    QString password = ui->PasswordField->text();

    if (username.isEmpty() || email.isEmpty() || password.isEmpty()) {
        qDebug() << "Please fill all fields!";
        return;
    }


    QFile file("users.txt");

    if (!file.exists()) {
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Failed to create file!";
            return;
        }
        qDebug() << "File created successfully!";
        file.close();
    }


    if (!file.open(QIODevice::Append | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QTextStream out(&file);
    out << username << "," << email << "," << password << "\n";

    file.close();
    qDebug() << "Registration successful!";

    ui->UsernameField->clear();
    ui->EmailTextField->clear();
    ui->PasswordField->clear();
}

void RegisterForm::on_CancelButton_clicked()
{
    qDebug() << "Cancel!";
}
