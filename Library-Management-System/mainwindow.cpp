#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "registerform.h"
#include "mainmenu.h"
#include <QFontDatabase>
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadCustomFont();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadCustomFont()
{
    int fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/VT323-Regular.ttf");
    if (fontId == -1) {
        qDebug() << "Failed to load font!";
    } else {
        QStringList fontFamilies = QFontDatabase::applicationFontFamilies(fontId);
        qDebug() << "Loaded font families:" << fontFamilies;

        QFont customFont(fontFamilies.at(0), 16);
        QApplication::setFont(customFont);
    }
}

void MainWindow::on_RegisterButton_clicked()
{
    qDebug() << "RegisterButton clicked!";
    RegisterForm *registerForm = new RegisterForm();
    registerForm->setAttribute(Qt::WA_DeleteOnClose);
    registerForm->show();
    this->hide();
}

void MainWindow::on_LoginButton_clicked()
{
    qDebug() << "LoginButton clicked!";

    QString enteredUsername = ui->Username->text();
    QString enteredPassword = ui->Password->text();

    QFile file("users.txt");
    if (!file.exists()) {
        qDebug() << "Users file not found!";
        return;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open users file!";
        return;
    }

    QList<QPair<QString, QString>> users;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 3)
        {
            QString username = parts[0];
            QString password = parts[2];
            users.append(qMakePair(username, password));
        }
    }
    file.close();


    bool loginSuccess = false;
    for (const auto& user : users)
    {
        if (user.first == enteredUsername && user.second == enteredPassword)
        {
            loginSuccess = true;
            break;
        }
    }

    if (loginSuccess)
    {
        qDebug() << "Login successful!";
        on_Login_Success();
    } else

    {
        qDebug() << "Invalid credentials!";
    }
}

void MainWindow::on_Login_Success()
{
    mainmenu *newMainMenu = new mainmenu();
    this->hide();
    this->close();
    newMainMenu->show();
}
