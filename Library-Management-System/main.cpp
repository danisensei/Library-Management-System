#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    mainmenu mainMenu;
    mainMenu.show();
    return app.exec();
}
