#include "registerform.h"
#include "ui_registerform.h"
#include "mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMessageBox>

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

    if (username.isEmpty() || email.isEmpty() || password.isEmpty())
    {
        qDebug() << "Please fill all fields!";
        QMessageBox::warning(this, "Input Error", "Please fill all fields!");
        return;
    }

    QFile file("users.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Failed to open file for reading.";
        QMessageBox::warning(this, "File Error", "Failed to open user data file.");
        return;
    }

    QTextStream in(&file);
    QString line;
    bool emailExists = false;

    while (!in.atEnd()) {
        line = in.readLine();
        QStringList parts = line.split(",");

        if (parts.size() == 3) {
            QString existingEmail = parts[1];
            if (existingEmail == email) {
                emailExists = true;
                break;
            }
        }
    }
    file.close();

    if (emailExists) {
        qDebug() << "Email already exists!";
        QMessageBox::warning(this, "Registration Error", "This email is already registered.");
        return;
    }

    if (!file.open(QIODevice::Append | QIODevice::Text))
    {
        qDebug() << "Failed to open file for writing.";
        QMessageBox::warning(this, "File Error", "Failed to open user data file for writing.");
        return;
    }

    QTextStream out(&file);
    out << username << "," << email << "," << password << "\n";

    file.close();
    qDebug() << "Registration successful!";
    QMessageBox::information(this, "Registration Success", "Registration successful! Welcome.");

    ui->UsernameField->clear();
    ui->EmailTextField->clear();
    ui->PasswordField->clear();

    on_Registration_complete();
}

void RegisterForm::on_Registration_complete()
{
    MainWindow *mainWindow = new MainWindow();
    this->hide();
    this->deleteLater();
    mainWindow->show();
}

void RegisterForm::on_CancelButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}
