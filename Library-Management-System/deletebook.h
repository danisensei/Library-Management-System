#ifndef DELETEBOOK_H
#define DELETEBOOK_H

#include <QWidget>
#include <QStandardItemModel>

namespace Ui
{
class deletebook;
}

class deletebook : public QWidget
{
    Q_OBJECT

public:
    explicit deletebook(QWidget *parent = nullptr);
    ~deletebook();

protected:
    void showEvent(QShowEvent *event) override;

private slots:
    void on_backbutton_clicked();
    void on_deletebutton_clicked();
    void loadBooksFromFile();

private:
    Ui::deletebook *ui;
    QStandardItemModel *model;
};

#endif // DELETEBOOK_H
