#pragma once

#include <QtCore/QStateMachine>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

class QScxmlStateMachine;

#include "IconFactory.h"

class PlayTttApplication : public QApplication
{
    Q_OBJECT
public:
    PlayTttApplication(int &argc, char **argv);
    QStateMachine *machine() { return mpStateMachine; }

private:
    QStateMachine *mpStateMachine=nullptr;

};
