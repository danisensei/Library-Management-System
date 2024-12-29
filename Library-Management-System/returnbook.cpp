#include "returnbook.h"
#include "ui_returnbook.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItem>
#include <mainmenu.h>
#include<ui_mainmenu.h>

returnbook::returnbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::returnbook)
{
    ui->setupUi(this);
    availabilityModel = new QStandardItemModel(this);
    availabilityModel->setHorizontalHeaderLabels({"ISBN", "Availability", "Book Name", "Author"});
    ui->availabilityTable->setModel(availabilityModel);

    loadAvailability();

    connect(ui->returnButton, &QPushButton::clicked, this, &returnbook::on_returnButton_clicked);
}

returnbook::~returnbook()
{
    delete ui;
}

void returnbook::loadAvailability()
{
    QFile file("availability.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() == 4) {
                QList<QStandardItem*> row;
                row.append(new QStandardItem(parts[0]));  // ISBN
                row.append(new QStandardItem(parts[1]));  // Availability (User ID)
                row.append(new QStandardItem(parts[2]));  // Book Name
                row.append(new QStandardItem(parts[3]));  // Author
                availabilityModel->appendRow(row);
            }
        }
        file.close();
    }
}

void returnbook::on_returnButton_clicked()
{
    QString isbn = ui->ISBNfield->text();
    QString userId = ui->UserIDfield->text();

    if (isbn.isEmpty() || userId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please provide both ISBN and User ID.");
        return;
    }

    markAsReturned(isbn, userId);
}

void returnbook::markAsReturned(const QString &isbn, const QString &userId)
{
    bool found = false;
    QFile file("availability.txt");
    QStringList lines;

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() == 4 && parts[0] == isbn && parts[1] == userId) {
                found = true;
                continue;
            }
            lines.append(line);
        }
        file.close();
    }

    if (found) {
        saveUpdatedAvailability(lines);
        QMessageBox::information(this, "Return Success", "The book has been returned successfully.");
        updateAvailabilityTable();
    } else {
        QMessageBox::warning(this, "Return Error", "No matching book found for return.");
    }
}

void returnbook::saveUpdatedAvailability(const QStringList &lines)
{
    QFile file("availability.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (const QString &line : lines) {
            out << line << "\n";
        }
        file.close();
    }
}

void returnbook::updateAvailabilityTable()
{
    availabilityModel->clear();
    availabilityModel->setHorizontalHeaderLabels({"ISBN", "Availability", "Book Name", "Author"});
    loadAvailability();
}

void returnbook::on_backbutton_clicked()
{
    mainmenu *back = new mainmenu();
    back->show();
    this->hide();
}

