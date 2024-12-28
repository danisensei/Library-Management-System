QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbook.cpp \
    adduser.cpp \
    deletebook.cpp \
    deleteuser.cpp \
    editbook.cpp \
    editusers.cpp \
    issuebook.cpp \
    linkedlist.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    registerform.cpp \
    searchbooks.cpp \
    viewusers.cpp

HEADERS += \
    addbook.h \
    adduser.h \
    deletebook.h \
    deleteuser.h \
    editbook.h \
    editusers.h \
    issuebook.h \
    linkedlist.h \
    mainmenu.h \
    mainwindow.h \
    registerform.h \
    searchbooks.h \
    viewusers.h

FORMS += \
    addbook.ui \
    adduser.ui \
    deletebook.ui \
    deleteuser.ui \
    editbook.ui \
    editusers.ui \
    issuebook.ui \
    mainmenu.ui \
    mainwindow.ui \
    registerform.ui \
    searchbooks.ui \
    viewusers.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
