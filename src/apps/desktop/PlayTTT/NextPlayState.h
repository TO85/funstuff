#pragma once

#include <QState>
#include <QObject>

#include <QtDebug>
class QKeyEvent;
class QTimer;

class PlayTttApplication;

class NextPlayState : public QState
{
    Q_OBJECT
public:
    NextPlayState(PlayTttApplication * pApplication);
    ~NextPlayState();
    PlayTttApplication *application() { return mpApplication; }

public:
    void setTimoutMsec(const quint64 aMsec) { mTimeoutMsec = aMsec; }

signals:
    void homePlays(const QChar &aChar);
    void visitorPlays(const QChar &aChar);
    void exit();

protected:
    virtual bool event(QEvent *e) override;
    virtual void onEntry(QEvent *event) override;
    virtual void onExit(QEvent *event) override;

private slots:
    bool handleKeyEvent(QKeyEvent *pKeyEvent);
    void timeout();

private:
    PlayTttApplication *mpApplication=nullptr;
    QTimer *mpTimer=nullptr;
    quint64 mTimeoutMsec=500;
};
