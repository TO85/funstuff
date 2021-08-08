QT       *= core gui scxml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BottomWidget.cpp \
    IconFactory.cpp \
    PlayTttApplication.cpp \
    ScoreWidget.cpp \
    T3BoardWidget.cpp \
    main.cpp \
    MainWindow.cpp

HEADERS += \
    BottomWidget.h \
    IconFactory.h \
    MainWindow.h \
    PlayTttApplication.h \
    ScoreWidget.h \
    T3BoardWidget.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS += \
 PlayTTT.scxml
