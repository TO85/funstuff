##! @file PlayTTT.poo {repo funstuff}/src/apps/desktop/PlayTTT

QT       *= core gui
greaterThan(QT_MAJOR_VERSION, 4): QT *= widgets

CONFIG += c++11

#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS -= -lGL
INCLUDEPATH *= ../../../libs

SOURCES += \
    ActionManager.cpp \
    BottomWidget.cpp \
    IconFactory.cpp \
    IconGrid.cpp \
    NextPlayState.cpp \
    PlayTttApplication.cpp \
    Random.cpp \
    RandomExec.cpp \
    ScoreWidget.cpp \
    StartPlayState.cpp \
    TttBoardWidget.cpp \
    TttMachine.cpp \
    TttPixmaps.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    ActionManager.h \
    BottomWidget.h \
    IconFactory.h \
    IconGrid.h \
    MainWindow.h \
    NextPlayState.h \
    PlayTttApplication.h \
    Random.h \
    RandomExec.h \
    RandomInterface.h \
    ScoreWidget.h \
    StartPlayState.h \
    TttBoardWidget.h \
    TttMachine.h \
    TttPixmaps.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS += \
 PlayTTT.scxml
