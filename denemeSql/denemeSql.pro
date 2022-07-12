QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    informationdialog.cpp \
    lineeditpopupform.cpp \
    main.cpp \
    mainwindow.cpp \
    secdialog.cpp \
    servisdialog.cpp

HEADERS += \
    informationdialog.h \
    lineeditpopupform.h \
    mainwindow.h \
    secdialog.h \
    servisdialog.h

FORMS += \
    informationdialog.ui \
    lineeditpopupform.ui \
    mainwindow.ui \
    secdialog.ui \
    servisdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Desktop/lib/ -llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Desktop/lib/ -llibmysqld
else:unix: LIBS += -L$$PWD/../../Desktop/lib/ -llibmysql

INCLUDEPATH += $$PWD/../../Desktop
DEPENDPATH += $$PWD/../../Desktop

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../Desktop/ -llibmysql
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../Desktop/ -llibmysqld

INCLUDEPATH += $$PWD/../../Desktop
DEPENDPATH += $$PWD/../../Desktop