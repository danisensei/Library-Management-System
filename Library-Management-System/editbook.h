#ifndef EDITBOOK_H
#define EDITBOOK_H

#include <QWidget>

namespace Ui {
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
private:
    Ui::editbook *ui;
};

#endif // EDITBOOK_H
