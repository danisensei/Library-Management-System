#include "issuebook.h"
#include "ui_issuebook.h"
#include "mainmenu.h"
#include <QStandardItem>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

issuebook::issuebook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::issuebook)
{
    ui->setupUi(this);

    bookModel = new QStandardItemModel(this);
    bookModel->setHorizontalHeaderLabels({"ISBN", "Book Name", "Availability"});
    ui->bookTable->setModel(bookModel);

    userModel = new QStandardItemModel(this);
    userModel->setHorizontalHeaderLabels({"Name", "User ID"});
    ui->UserTable->setModel(userModel);

    loadBooks();
    loadUsers();

    connect(ui->issueButton, &QPushButton::clicked, this, &issuebook::on_issueButton_clicked);
}

issuebook::~issuebook()
{
    delete ui;
}

void issuebook::on_backbutton_clicked()
{
    mainmenu *backwidget = new mainmenu();
    backwidget->show();
    this->close();
}

void issuebook::loadBooks()
{
    QFile file("addedbooks.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("|");

            QList<QStandardItem*> row;

            if (parts.size() == 4) {
                // Format: ISBN|Book Name|Author|Genre
                row.append(new QStandardItem(parts[0])); // ISBN
                row.append(new QStandardItem(parts[1])); // Book Name
                row.append(new QStandardItem("Available")); // Default availability
            } else if (parts.size() == 3) {

                // Format: ISBN|Book Name|User ID
                row.append(new QStandardItem(parts[0])); // ISBN
                row.append(new QStandardItem(parts[1])); // Book Name
                row.append(new QStandardItem(parts[2])); // Availability/User ID
            }

            if (!row.isEmpty())
                bookModel->appendRow(row);
        }
        file.close();
    }
}



void issuebook::loadUsers()
{
    QFile file("addedusers.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() >= 3) {
                QList<QStandardItem*> row;
                row.append(new QStandardItem(parts[0]));
                row.append(new QStandardItem(parts[2].trimmed()));
                userModel->appendRow(row);
            }
        }
        file.close();
    }
}

void issuebook::on_issueButton_clicked()
{
    QString isbn = ui->ISBNfield->text();
    QString userId = ui->UserIDfield->text();

    if (isbn.isEmpty() || userId.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "Please provide both ISBN and User ID.");
        return;
    }


    issueQueue.push(qMakePair(isbn, userId));
    processIssueRequest();
}

void issuebook::processIssueRequest()
{
    if (issueQueue.empty()) {
        QMessageBox::information(this, "Queue Empty", "No book issue requests in the queue.");
        return;
    }


    QPair<QString, QString> issueRequest = issueQueue.front();
    QString isbn = issueRequest.first;
    QString userId = issueRequest.second;
    QString bookName;

    bool found = false;
    for (int row = 0; row < bookModel->rowCount(); ++row) {
        if (bookModel->item(row, 0)->text() == isbn) {
            bookName = bookModel->item(row, 1)->text();
            bookModel->item(row, 2)->setText(userId); // Update availability to User ID
            found = true;
            break;
        }
    }


    if (!found) {
        QMessageBox::warning(this, "Book Not Found", "No book found with the given ISBN.");
    } else {
        issueQueue.pop();

        storeIssuedBookDetails(isbn, userId, bookName);

        updateBookAvailability(isbn, userId);
    }
}

void issuebook::storeIssuedBookDetails(const QString &isbn, const QString &userId, const QString &bookName)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    QFile file("issuedbooks.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << userId << "," << isbn << "," << bookName << "," << currentDateTime << "," << "Issued" << "\n";
        file.close();
    }
}

void issuebook::updateBookAvailability(const QString &isbn, const QString &userId)
{
    QFile file("addedbooks.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "Failed to open addedbooks.txt.");
        return;
    }

    QTextStream in(&file);
    QString content;
    bool updated = false;

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split("|");

        if (parts.size() >= 2 && parts[0] == isbn) {
            content += parts[0] + "|" + parts[1] + "|" + userId + "\n";
            updated = true;
        } else {
            content += line + "\n";
        }
    }

    if (updated) {
        file.resize(0);
        QTextStream out(&file);
        out << content;
    }

    file.close();
}

