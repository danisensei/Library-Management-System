#ifndef ISSUEBOOK_H
#define ISSUEBOOK_H

#include <QWidget>

namespace Ui {
class issuebook;
}

class issuebook : public QWidget
{
    Q_OBJECT

public:
    explicit issuebook(QWidget *parent = nullptr);
    ~issuebook();

private slots:
    void on_backbutton_clicked();

private:
    Ui::issuebook *ui;
};

#endif // ISSUEBOOK_H
