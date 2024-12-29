#ifndef ISSUEBOOK_H
#define ISSUEBOOK_H

#include <QWidget>
#include <QStandardItemModel>
#include <QFile>
#include <QTextStream>
#include <queue>
#include <QString>
#include <QPair>
#include <QDateTime>

namespace Ui
{
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
    void on_issueButton_clicked();

private:
    Ui::issuebook *ui;
    QStandardItemModel *bookModel;
    QStandardItemModel *userModel;
    QStandardItemModel *availabilityModel;
    std::queue<QPair<QString, QString>> issueQueue;

    void loadBooks();
    void loadUsers();
    void loadAvailability();

    void processIssueRequest();
    void storeIssuedBookDetails(const QString &isbn, const QString &userId, const QString &bookName);
    void updateBookAvailability(const QString &isbn, const QString &userId);
    void updateAvailabilityTable(const QString &isbn, const QString &availability);
    void storeAvailability(const QString &isbn, const QString &availability);
};

#endif // ISSUEBOOK_H
