QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about_1.cpp \
    data_link.cpp \
    main.cpp \
    mainwindow.cpp \
    parameters.cpp \
    port.cpp \
    pram_connection.cpp \
    recieve_file_mode.cpp

HEADERS += \
    about_1.h \
    data_link.h \
    mainwindow.h \
    parameters.h \
    port.h \
    pram_connection.h \
    recieve_file_mode.h \
    main.cpp

FORMS += \
    Recieve.ui \
    Recieve_mode.ui \
    about_1.ui \
    mainwindow.ui \
    parameters.ui \
    pram_connection.ui \
    recieve_file_mode.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc
