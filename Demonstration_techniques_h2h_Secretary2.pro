QT       += core gui sql quickwidgets websockets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addcompetition.cpp \
    database.cpp \
    eventscrollbar.cpp \
    itemsporsmanonmat.cpp \
    itemsportsmen.cpp \
    main.cpp \
    mainlistsportsmen.cpp \
    mainwindow.cpp \
    udpserver.cpp

HEADERS += \
    addcompetition.h \
    database.h \
    eventscrollbar.h \
    itemsporsmanonmat.h \
    itemsportsmen.h \
    main.h \
    mainlistsportsmen.h \
    mainwindow.h \
    udpserver.h

FORMS += \
    addcompetition.ui \
    mainlistsportsmen.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Server.qml \
    grid.qml
