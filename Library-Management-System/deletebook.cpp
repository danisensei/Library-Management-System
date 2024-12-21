#include "deletebook.h"
#include "ui_deletebook.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItemModel>


QStandardItemModel *model;

deletebook::deletebook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletebook)
    , model(nullptr)
{
    ui->setupUi(this);
    loadBooksFromFile();
}


deletebook::~deletebook()
{
    if (model) {
        delete model;
        model = nullptr;
    }
    delete ui;
}


void deletebook::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    loadBooksFromFile();
}



void deletebook::on_backbutton_clicked()
{
    qDebug() << "Back button clicked";
    mainmenu *backwidget = new mainmenu();
    backwidget->setAttribute(Qt::WA_DeleteOnClose);
    backwidget->show();
    this->close();
}

void deletebook::on_deletebutton_clicked()
{
    QString isbnToDelete = ui->isbnbox->text().trimmed();

    if (isbnToDelete.isEmpty()) {
        QMessageBox::warning(this, "Error", "Please enter an ISBN to delete.");
        return;
    }

    QFile file("addedbooks.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Failed to open the file for reading.");
        return;
    }


    QTextStream in(&file);
    QStringList allLines;
    bool found = false;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");
        if (parts.size() == 4 && parts[0] == isbnToDelete) {
            found = true;
        } else {
            allLines.append(line);
        }
    }
    file.close();

    if (!found) {
        QMessageBox::information(this, "Not Found", "No book found with the given ISBN.");
        return;
    }


    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        QMessageBox::critical(this, "Error", "Failed to open the file for writing.");
        return;
    }

    QTextStream out(&file);
    for (const QString &line : allLines) {
        out << line << "\n";
    }
    file.close();

    QMessageBox::information(this, "Success", "Book deleted successfully!");


    loadBooksFromFile();
}

void deletebook::loadBooksFromFile()
{

    if (model) {
        delete model;
        model = nullptr;
    }


    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"ISBN", "Name", "Author", "Genre"});

    QFile file("addedbooks.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() == 4) {
                QList<QStandardItem *> items;
                for (const QString &part : parts) {
                    items.append(new QStandardItem(part));
                }
                model->appendRow(items);
            }
        }
        file.close();
    }


    ui->Booktable->setModel(model);
    ui->Booktable->resizeColumnsToContents();
}

