#include "NextPlayState.h"

#include <QtCore/QEvent>
#include <QtCore/QTimer>
#include <QtGui/QKeyEvent>

#include "PlayTttApplication.h"

NextPlayState::NextPlayState(PlayTttApplication *pApplication)
    : mpApplication(pApplication)
    , mpTimer(new QTimer)
{
    setObjectName("NextPlayState");
    connect(mpTimer, &QTimer::timeout, this, &NextPlayState::timeout);
    mpTimer->setSingleShot(true);
}

NextPlayState::~NextPlayState()
{
    if (mpTimer) mpTimer->deleteLater();
}

bool NextPlayState::event(QEvent *e)
{
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
    mpTimer->start(mTimeoutMsec);
}

void NextPlayState::onExit(QEvent *event)
{
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
    // Needo: Computer Decides
}
