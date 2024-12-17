#include "addbook.h"
#include "ui_addbook.h"
#include <QMessageBox>

addbook::addbook(QMap<QString, QVariantMap>* books, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::addbook)
    , books(books)
{
    ui->setupUi(this);

    // Connect the add button to the onAddBook slot
    connect(ui->addbutton, &QPushButton::clicked, this, &addbook::onAddBook);

    // Connect the back button to the onBack slot
    connect(ui->backbutton, &QPushButton::clicked, this, &addbook::onBack);
}

addbook::~addbook()
{
    delete ui;
}

void addbook::onAddBook()
{
    // Retrieve data from UI fields
    QString name = ui->nameline->text().trimmed();
    QString author = ui->authorline->text().trimmed();
    QString isbn = ui->idline->text().trimmed();
    QString genre = ui->comboBox->currentText();

    // Check if fields are filled
    if (name.isEmpty() || author.isEmpty() || isbn.isEmpty()) {
        QMessageBox::warning(this, "Input Error", "All fields except genre must be filled!");
        return;
    }

    // Check if the book with the same ISBN already exists
    if (books->contains(isbn)) {
        QMessageBox::warning(this, "Duplicate Entry", "A book with this ISBN already exists!");
        return;
    }

    // Create a QVariantMap for the book
    QVariantMap bookDetails;
    bookDetails["name"] = name;
    bookDetails["author"] = author;
    bookDetails["genre"] = genre;

    // Add the book to the QMap
    books->insert(isbn, bookDetails);

    QMessageBox::information(this, "Success", "Book added successfully!");

    // Clear the input fields
    ui->nameline->clear();
    ui->authorline->clear();
    ui->idline->clear();
    ui->comboBox->setCurrentIndex(0);
}

void addbook::onBack()
{
    this->close(); // Close the current window
}
