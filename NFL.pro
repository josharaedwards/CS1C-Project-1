QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adminpanel.cpp \
    contactsheet.cpp \
    dialog.cpp \
    football.cpp \
    helppanel.cpp \
    init.cpp \
    main.cpp \
    mainwindow.cpp \
    sort.cpp

HEADERS += \
    adminpanel.h \
    contactsheet.h \
    dialog.h \
    football.h \
    helppanel.h \
    init.h \
    mainwindow.h \
    sort.h

FORMS += \
    adminpanel.ui \
    contactsheet.ui \
    dialog.ui \
    helppanel.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
