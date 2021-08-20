#include "NextPlayState.h"

#include <QtDebug>
#include <QtCore/QEvent>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>

#include "PlayTttApplication.h"

NextPlayState::NextPlayState(PlayTttApplication *pApplication)
    : mpApplication(pApplication)
    , mpTimer(new QTimer)
{
    setObjectName("NextPlayState");
    qDebug() << Q_FUNC_INFO << pApplication->applicationFilePath() << objectName();
    connect(mpTimer, &QTimer::timeout, this, &NextPlayState::timeout);
    mpTimer->setSingleShot(true);
}

NextPlayState::~NextPlayState()
{
    qDebug() << Q_FUNC_INFO;
    if (mpTimer) mpTimer->deleteLater();
}

bool NextPlayState::event(QEvent *e)
{
    qDebug() << Q_FUNC_INFO << e->type();
    bool accept = false;
    if (false)
        ;
    else if (QEvent::Type::KeyRelease == e->type())
    {
        QKeyEvent *pKeyEvent = (QKeyEvent *)(e);
        accept = handleKeyEvent(pKeyEvent);
    }
    else
        e->ignore();
    if (accept) e->accept();
    return accept;
}

void NextPlayState::onEntry(QEvent *event)
{
    qDebug() << Q_FUNC_INFO;
    mpTimer->start(mTimeoutMsec);
}

void NextPlayState::onExit(QEvent *event)
{
    qDebug() << Q_FUNC_INFO;
    mpTimer->stop();
}

bool NextPlayState::handleKeyEvent(QKeyEvent *pKeyEvent)
{
    qDebug() << Q_FUNC_INFO;
    bool accept = false;
    if (pKeyEvent)
    {
        switch (pKeyEvent->key())
        {
        case Qt::Key_Q:
            emit exit();
            break;

        default:
            ; // ignore key event
            break;
        }
    }
}

void NextPlayState::timeout()
{
    qDebug() << Q_FUNC_INFO;
    // Needo: Computer Decides
}
