#include "searchbooks.h"
#include "ui_searchbooks.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

searchbooks::searchbooks(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchbooks)
{
    ui->setupUi(this);

    loadBooksFromFile("addedbooks.txt");

    model = new QStandardItemModel(this);
    model->setHorizontalHeaderLabels({"ISBN", "Name", "Author", "Genre"});
    ui->tableView->setModel(model);
    ui->tableView->resizeColumnsToContents();

    populateTable();

    connect(ui->searchButton, &QPushButton::clicked, this, &searchbooks::on_searchButton_clicked);
}

searchbooks::~searchbooks()
{
    delete ui;
}

void searchbooks::on_backbutton_clicked()
{
    mainmenu *backwidget = new mainmenu();
    backwidget->setAttribute(Qt::WA_DeleteOnClose);
    backwidget->show();
    this->hide();
}

void searchbooks::on_searchButton_clicked()
{
    QString searchTerm = ui->searchLineEdit->text().trimmed();

    if (searchTerm.isEmpty()) {
        QMessageBox::warning(this, "Search Error", "Please enter a search term.");
        return;
    }

    model->removeRows(0, model->rowCount());
    QString lowerSearchTerm = searchTerm.toLower();

    bool found = false;
    for (auto it = booksMap.constBegin(); it != booksMap.constEnd(); ++it) {
        if (it.key().toLower().contains(lowerSearchTerm) || it.value().at(0).toLower().contains(lowerSearchTerm)) {
            QList<QStandardItem *> row;
            row.append(new QStandardItem(it.key()));   // ISBN
            row.append(new QStandardItem(it.value().at(0))); // Name
            row.append(new QStandardItem(it.value().at(1))); // Author
            row.append(new QStandardItem(it.value().at(2))); // Genre
            model->appendRow(row);
            found = true;
        }
    }

    if (!found) {
        QMessageBox::information(this, "No Results", "No books found matching the search term.");
    }
}

void searchbooks::loadBooksFromFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Error", "Unable to open books file.");
        return;
    }

    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split("|");

        if (fields.size() == 4) {
            QString isbn = fields.at(0).trimmed();
            QString name = fields.at(1).trimmed();
            QString author = fields.at(2).trimmed();
            QString genre = fields.at(3).trimmed();

            booksMap.insert(isbn, {name, author, genre});
        }
    }
    file.close();
}

void searchbooks::populateTable()
{
    for (auto it = booksMap.constBegin(); it != booksMap.constEnd(); ++it) {
        QList<QStandardItem *> row;
        row.append(new QStandardItem(it.key()));   // ISBN
        row.append(new QStandardItem(it.value().at(0))); // Name
        row.append(new QStandardItem(it.value().at(1))); // Author
        row.append(new QStandardItem(it.value().at(2))); // Genre
        model->appendRow(row);

        ui->tableView->resizeColumnsToContents();
    }
}
