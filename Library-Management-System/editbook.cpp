#include "editbook.h"
#include "ui_editbook.h"
#include "mainmenu.h"
#include "ui_mainmenu.h"
#include <QFile>



editbook::editbook(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::editbook)
    , model(nullptr)
{
    ui->setupUi(this);
    loadBooksFromFile();
}

editbook::~editbook()
{
    if (model) {
        delete model;
        model = nullptr;
    }
    delete ui;}

void editbook:: on_backbutton_clicked()
{
    mainmenu *backbutton= new mainmenu();
    backbutton->setAttribute(Qt::WA_DeleteOnClose);
    backbutton->show();
    this->hide();


}

void editbook::loadBooksFromFile()
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


    ui->booktable->setModel(model);
    ui->booktable->resizeColumnsToContents();
}
