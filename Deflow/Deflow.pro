#-------------------------------------------------
#
# Project created by QtCreator 2019-02-12T10:52:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Deflow
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    topbarcontroller.cpp \
    canvas.cpp \
    foldertree.cpp \
    Blocks/baseblock.cpp \
    Blocks/printblock.cpp \
    StatusBar.cpp \
    openingdialog.cpp \
    graphspace.cpp \
    Blocks/addblock.cpp \
    linerenderer.cpp \
    Blocks/startblock.cpp \
    Connectors/connectorin.cpp \
    Connectors/connectorout.cpp \
    Connectors/connector.cpp \
    Connectors/connectorexecin.cpp \
    Connectors/connectorexecout.cpp \
    Blocks/stringblock.cpp \
    Blocks/acquireinputblock.cpp \
    Blocks/newvarblock.cpp \
    Blocks/varblock.cpp \
    Blocks/conditionalblock.cpp \
    FileManager.cpp \
    translator.cpp \
    Blocks/getgopropertysblock.cpp \
    Blocks/setgopropertysblock.cpp \
    Blocks/setvarblock.cpp \
    Blocks/subtractblock.cpp \
    Blocks/constantvarblock.cpp \
    Blocks/multiplicationblock.cpp \
    Blocks/divisionblock.cpp \
    Blocks/inputblock.cpp \
    autoupdatecombobox.cpp \
    Blocks/loopblock.cpp


HEADERS += \
        mainwindow.h \
    topbarcontroller.h \
    canvas.h \
    foldertree.h \
    Blocks/baseblock.h \
    Blocks/printblock.h \
    StatusBar.h \
    openingdialog.h \
    graphspace.h \
    blocks.h \
    Blocks/addblock.h \
    linerenderer.h \
    Blocks/startblock.h \
    Connectors/connectorin.h \
    Connectors/connectorout.h \
    Connectors/connector.h \
    Connectors/connectorexecin.h \
    Connectors/connectorexecout.h \
    Blocks/stringblock.h \
    Blocks/acquireinputblock.h \
    Blocks/newvarblock.h \
    Blocks/varblock.h \
    Blocks/conditionalblock.h \
    FileManager.h \
    translator.h \
    Blocks/getgopropertysblock.h \
    Blocks/setgopropertysblock.h \
    Blocks/setvarblock.h \
    Blocks/subtractblock.h \
    Blocks/constantvarblock.h \
    Blocks/multiplicationblock.h \
    Blocks/divisionblock.h \
    Blocks/inputblock.h \
    autoupdatecombobox.h \
    Blocks/loopblock.h

FORMS += \
        mainwindow.ui \
    foldertree.ui \
    Blocks/printblock.ui \
    Blocks/addblock.ui \
    canvas.ui \
    openingdialog.ui \
    graphspace.ui \
    linerenderer.ui \
    Blocks/startblock.ui \
    Connectors/connectorin.ui \
    Connectors/connectorout.ui \
    Connectors/connectorexecin.ui \
    Connectors/connectorexecout.ui \
    Blocks/stringblock.ui \
    Blocks/acquireinputblock.ui \
    Blocks/newvarblock.ui \
    Blocks/varblock.ui \
    Blocks/conditionalblock.ui \
    Blocks/getgopropertysblock.ui \
    Blocks/setgopropertysblock.ui \
    Blocks/setvarblock.ui \
    Blocks/subtractblock.ui \
    Blocks/constantvarblock.ui \
    Blocks/multiplicationblock.ui \
    Blocks/divisionblock.ui \
    Blocks/inputblock.ui \
    autoupdatecombobox.ui \
    Blocks/loopblock.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Arrow.png \
    Arrow-filled.png \
    Circle.png \
    Circle-filled.png

RESOURCES += \
    arrows.qrc

INCLUDEPATH += \
    $$PWD/Blocks \
    $$PWD/Connectors
