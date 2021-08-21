#include "StartPlayState.h"

#include <QtDebug>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

#include "PlayTttApplication.h"

StartPlayState::StartPlayState(PlayTttApplication * pApplication)
    : mpApplication(pApplication)
{
    setObjectName("NextPlayState");
    qDebug() << Q_FUNC_INFO << mpApplication->applicationFilePath() << objectName();

}

void StartPlayState::setup()
{
    qDebug() << Q_FUNC_INFO;

}
