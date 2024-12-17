#include "addbook.h"
#include "ui_addbook.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <mainmenu.h>
#include <ui_mainmenu.h>

addbook::addbook(QMap<QString, QVariantMap>* books, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addbook)
    , books(books)
{
    ui->setupUi(this);

    loadBooksFromFile();

    connect(ui->addbutton, &QPushButton::clicked, this, &addbook::onAddBook);
    connect(ui->backbutton, &QPushButton::clicked, this, &addbook::onBack);
}

addbook::~addbook()
{
    delete ui;
}

void addbook::loadBooksFromFile()
{
    QFile file("addedbooks.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split("|");
            if (parts.size() == 4) {
                QString isbn = parts[0];
                QVariantMap bookDetails;
                bookDetails["name"] = parts[1];
                bookDetails["author"] = parts[2];
                bookDetails["genre"] = parts[3];
                books->insert(isbn, bookDetails);
            }
        }
        file.close();
    }
}

void addbook::saveBookToFile(const QString& isbn, const QVariantMap& bookDetails)
{
    QFile file("addedbooks.txt");
    if (file.open(QIODevice::Append | QIODevice::Text)) {
        QTextStream out(&file);
        out << isbn << "|" << bookDetails["name"].toString() << "|"
            << bookDetails["author"].toString() << "|"
            << bookDetails["genre"].toString() << "\n";
        file.close();
    }
}

void addbook::onAddBook()
{
    QString name = ui->booknamefield->text().trimmed();
    QString author = ui->authorfield->text().trimmed();
    QString isbn = ui->ISBNfield->text().trimmed();
    QString genre = ui->genrecombobox->currentText();


    if (name.isEmpty() || author.isEmpty() || isbn.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields except genre must be filled!");
        return;
    }

    if (books->contains(isbn)) {
        QMessageBox::warning(this, "Duplicate Entry", "A book with this ISBN already exists!");
        return;
    }

    QVariantMap bookDetails;
    bookDetails["name"] = name;
    bookDetails["author"] = author;
    bookDetails["genre"] = genre;

    books->insert(isbn, bookDetails);

    saveBookToFile(isbn, bookDetails);

    QMessageBox::information(this, "Success", "Book added successfully!");

    ui->booknamefield->clear();
    ui->authorfield->clear();
    ui->ISBNfield->clear();
    ui->genrecombobox->setCurrentIndex(0);
}

void addbook::onBack()
{
    qDebug() <<"back button clicked";
    mainmenu *backwidget= new mainmenu();
    backwidget->setAttribute(Qt::WA_DeleteOnClose);
    backwidget->show();
    this->hide();
}
