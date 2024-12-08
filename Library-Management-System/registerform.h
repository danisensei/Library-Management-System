#ifndef REGISTERFORM_H
#define REGISTERFORM_H

#include <QWidget>

namespace Ui {
class RegisterForm;
}

class RegisterForm : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterForm(QWidget *parent = nullptr);
    ~RegisterForm();

private slots:
    void on_RegisterButton_clicked();
    void on_CancelButton_clicked();


private:
    Ui::RegisterForm *ui;
};



#endif // REGISTERFORM_H
