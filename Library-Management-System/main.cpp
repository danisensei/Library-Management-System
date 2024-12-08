#include "mainmenu.h"
#include "mainwindow.h"
#include "registerform.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //mainmenu mainMenu;
    //mainMenu.show();

    MainWindow mainWindow;
    mainWindow.show();

    RegisterForm RegisterForm;
    RegisterForm.show();

    return app.exec();
}
