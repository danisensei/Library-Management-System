#ifndef RETURNBOOK_H
#define RETURNBOOK_H

#include <QWidget>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStandardItemModel>

namespace Ui {
class returnbook;
}

class returnbook : public QWidget
{
    Q_OBJECT

public:
    explicit returnbook(QWidget *parent = nullptr);
    ~returnbook();

private slots:
    void on_returnButton_clicked();

    void on_backbutton_clicked();

private:
    Ui::returnbook *ui;
    QStandardItemModel *availabilityModel;

    void loadAvailability();
    void updateAvailabilityTable();
    void markAsReturned(const QString &isbn, const QString &userId);
    void saveUpdatedAvailability(const QStringList &lines);
};

#endif // RETURNBOOK_H
