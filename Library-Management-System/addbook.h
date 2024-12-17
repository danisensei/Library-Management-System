#ifndef ADDBOOK_H
#define ADDBOOK_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QVariantMap>

namespace Ui {
class addbook;
}

class addbook : public QWidget
{
    Q_OBJECT

public:
    explicit addbook(QMap<QString, QVariantMap>* books, QWidget *parent = nullptr);
    ~addbook();

private slots:
    void onAddBook();
    void onBack();

private:
    Ui::addbook *ui;
    QMap<QString, QVariantMap>* books;

    void loadBooksFromFile();
    void saveBookToFile(const QString& isbn, const QVariantMap& bookDetails);
};

#endif // ADDBOOK_H
