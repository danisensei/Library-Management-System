#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>
#include <QDebug>

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
}

void MainWindow::on_LoginButton_clicked()
{
    qDebug() << "LoginButton clicked!";
}
