#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QMap>
#include <QString>
#include <QVariantMap>

namespace Ui {
class mainmenu;
}

class mainmenu : public QWidget
{
    Q_OBJECT

public:
    explicit mainmenu(QWidget *parent = nullptr);
    ~mainmenu();

private slots:
    void on_adduserbutton_clicked();
    void on_deleteuserbutton_clicked();
    void on_edituserbutton_clicked();
    void on_viewusersbutton_clicked();
    void on_addbookbutton_clicked();
    void on_deletebookbutton_clicked();
    void on_editbookbutton_clicked();
    void on_searchbooksbutton_clicked();
    void on_issuebookbutton_clicked();
    void on_returnbookbutton_clicked();
    void on_logoutbutton_clicked();

private:
    Ui::mainmenu *ui;
    QMap<QString, QVariantMap> books;
};

#endif // MAINMENU_H
