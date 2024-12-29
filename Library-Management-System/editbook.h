#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui
{
class editbook;
}

class editbook : public QWidget
{
    Q_OBJECT

public:
    explicit editbook(QWidget *parent = nullptr);
    ~editbook();

private slots:
    void on_backbutton_clicked();
    void loadBooksFromFile();
    void savetofile();
    void on_savebutton_clicked();

private:
    Ui::editbook *ui;
    QStandardItemModel *model;
};

#endif // EDITBOOK_H
