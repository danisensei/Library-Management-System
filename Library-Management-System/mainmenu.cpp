#include "mainmenu.h"
#include "ui_mainmenu.h"

mainmenu::mainmenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainmenu)
{
    ui->setupUi(this);
}

mainmenu::~mainmenu()
{
    delete ui;
}

void mainmenu :: on_adduserbutton_clicked();
{

}

void mainmenu :: on_deleteuserbutton_clicked();
{

}

void mainmenu :: on_edituserbutton_clicked();
{

}

void mainmenu :: on_viewusersbutton_clicked();
{

}

void mainmenu :: on_addbookbutton_clicked();
{

}

void mainmenu :: on_deletebookbutton_clicked();
{

}

void mainmenu :: on_editbookbutton_clicked();
{

}

void mainmenu :: on_viewbooksbutton_clicked();
{

}

void mainmenu :: on_issuebookbutton_clicked();
{

}

void mainmenu :: on_returnbookbutton_clicked();
{

}
