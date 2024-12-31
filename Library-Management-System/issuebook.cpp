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
    bookModel->setHorizontalHeaderLabels({"ISBN", "Book Name", "Author"});
    ui->bookTable->setModel(bookModel);

    userModel = new QStandardItemModel(this);
    userModel->setHorizontalHeaderLabels({"Name", "User ID"});
    ui->UserTable->setModel(userModel);

    availabilityModel = new QStandardItemModel(this);
    availabilityModel->setHorizontalHeaderLabels({"ISBN", "Issued To", "Book Name", "Author"});
    ui->AvailabilityTable->setModel(availabilityModel);

    loadBooks();
    loadUsers();
    loadAvailability();

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
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split("|");

            QList<QStandardItem*> row;

            if (parts.size() >= 4)
            {
                // Format: ISBN|Book Name|Author|Genre
                row.append(new QStandardItem(parts[0])); // ISBN
                row.append(new QStandardItem(parts[1])); // Book Name
                row.append(new QStandardItem(parts[2])); // Author
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
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split(",");
            if (parts.size() >= 3)
            {
                QList<QStandardItem*> row;
                row.append(new QStandardItem(parts[0]));
                row.append(new QStandardItem(parts[2].trimmed()));
                userModel->appendRow(row);
            }
        }
        file.close();
    }
}

void issuebook::loadAvailability()
{
    QFile file("availability.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() == 4)
            { // expect ISBN, Availability/ Issued to (User ID) , Book Name, Author
                QList<QStandardItem*> row;
                row.append(new QStandardItem(parts[0])); // ISBN
                row.append(new QStandardItem(parts[1])); // Availability/Issued to (User ID)
                row.append(new QStandardItem(parts[2])); // Book Name
                row.append(new QStandardItem(parts[3])); // Author
                availabilityModel->appendRow(row);
            }
        }
        file.close();
    }
}

void issuebook::on_issueButton_clicked()
{
    QString isbn = ui->ISBNfield->text();
    QString userId = ui->UserIDfield->text();

    if (isbn.isEmpty() || userId.isEmpty())
    {
        QMessageBox::warning(this, "Input Error", "Please provide both ISBN and User ID.");
        return;
    }

    issueQueue.push(qMakePair(isbn, userId));
    processIssueRequest();
}

void issuebook::processIssueRequest()
{
    if (issueQueue.empty())
    {
        QMessageBox::information(this, "Queue Empty", "No book issue requests in the queue.");
        return;
    }

    QPair<QString, QString> issueRequest = issueQueue.front();
    QString isbn = issueRequest.first;
    QString userId = issueRequest.second;
    QString bookName;
    QString userName;

    bool bookFound = false;
    bool userFound = false;

    // Find the book in the model
    for (int row = 0; row < bookModel->rowCount(); ++row)
    {
        if (bookModel->item(row, 0)->text() == isbn)
        {
            bookName = bookModel->item(row, 1)->text();
            bookFound = true;
            break;
        }
    }

    // Find the user in the model
    for (int row = 0; row < userModel->rowCount(); ++row)
    {
        if (userModel->item(row, 1)->text() == userId)
        {
            userName = userModel->item(row, 0)->text();
            userFound = true;
            break;
        }
    }

    if (!bookFound) {
        QMessageBox::warning(this, "Book Not Found", "No book found with the given ISBN.");
    }
    else if (!userFound)
    {
        QMessageBox::warning(this, "User Not Found", "No user found with the given User ID.");
    }
    else
    {
        issueQueue.pop();

        storeIssuedBookDetails(isbn, userId, bookName);
        updateBookAvailability(isbn, userId);

        QMessageBox::information(
            this,
            "Success",
            QString("'%1' with ISBN '%2' issued to %3 (User ID: %4).")
                .arg(bookName)
                .arg(isbn)
                .arg(userName)
                .arg(userId)
            );
    }
}

void issuebook::storeIssuedBookDetails(const QString &isbn, const QString &userId, const QString &bookName)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd HH:mm:ss");

    QFile file("issuedbooks.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << userId << "," << isbn << "," << bookName << "," << currentDateTime << "," << "Issued" << "\n";
        file.close();
    }
}

void issuebook::updateBookAvailability(const QString &isbn, const QString &userId)
{
    storeAvailability(isbn, userId);
    updateAvailabilityTable(isbn, userId);
}

void issuebook::updateAvailabilityTable(const QString &isbn, const QString &userId)
{
    // Check if the ISBN already exists in the availability table and update it
    for (int row = 0; row < availabilityModel->rowCount(); ++row)
    {
        if (availabilityModel->item(row, 0)->text() == isbn)
        {
            availabilityModel->item(row, 1)->setText(userId);
            return;
        }
    }

    QList<QStandardItem*> row;
    row.append(new QStandardItem(isbn));
    row.append(new QStandardItem(userId));
    availabilityModel->appendRow(row);
}

void issuebook::storeAvailability(const QString &isbn, const QString &userId)
{
    QString bookName;
    QString author;

    // Find the book details using the ISBN
    for (int row = 0; row < bookModel->rowCount(); ++row)
    {
        if (bookModel->item(row, 0)->text() == isbn)
        {
            bookName = bookModel->item(row, 1)->text();  // Book Name
            author = bookModel->item(row, 2)->text();    // Author
            break;
        }
    }

    QFile file("availability.txt");
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << isbn << "|" << userId << "|" << bookName << "|" << author << "\n";
        file.close();
    }
    else
    {
        QMessageBox::warning(this, "File Error", "Failed to open availability.txt.");
    }
}
