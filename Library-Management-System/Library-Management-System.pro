QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adduser.cpp \
    deleteuser.cpp \
    editusers.cpp \
    linkedlist.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    registerform.cpp \
    viewusers.cpp

HEADERS += \
    adduser.h \
    deleteuser.h \
    editusers.h \
    linkedlist.h \
    mainmenu.h \
    mainwindow.h \
    registerform.h \
    viewusers.h

FORMS += \
    adduser.ui \
    deleteuser.ui \
    editusers.ui \
    mainmenu.ui \
    mainwindow.ui \
    registerform.ui \
    viewusers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
