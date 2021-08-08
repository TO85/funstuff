#pragma once

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

class QScxmlStateMachine;

#include "IconFactory.h"

class PlayTttApplication : public QApplication
{
    Q_OBJECT
public:
    PlayTttApplication(int &argc, char **argv);

private:
    QScxmlStateMachine *mpStateMachine=nullptr;

};
