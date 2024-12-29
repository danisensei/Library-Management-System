#ifndef SEARCHBOOKS_H
#define SEARCHBOOKS_H

#include <QWidget>
#include <QMap>
#include <QStandardItemModel>
#include <QStringList>

namespace Ui
{
class searchbooks;
}

class searchbooks : public QWidget
{
    Q_OBJECT

public:
    explicit searchbooks(QWidget *parent = nullptr);
    ~searchbooks();

private slots:
    void on_backbutton_clicked();
    void on_searchButton_clicked();

private:
    Ui::searchbooks *ui;
    QMap<QString, QStringList> booksMap;
    QStandardItemModel *model;

    void loadBooksFromFile(const QString &fileName);
    void populateTable();
};

#endif // SEARCHBOOKS_H
