QT       += core gui sql printsupport widgets serialport



QT       += core gui charts

QT += widgets



greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += console

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calendrier.cpp \
    connection.cpp \
    event.cpp \
    main.cpp \
    mainwindow.cpp \
    stat_combo.cpp


HEADERS += \
    calendrier.h \
    connection.h \
    event.h \
    mainwindow.h \
    stat_combo.h


FORMS += \
    calendrier.ui \
    mainwindow.ui \
    stat_combo.ui




# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
