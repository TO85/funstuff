#pragma once

#include <QState>
#include <QObject>

class QPushButton;
class QVBoxLayout;
class QWidget;

class MainWindow;

class StartPlayState : public QState
{
    Q_OBJECT
public:
    StartPlayState(MainWindow *pMainWindow);
    ~StartPlayState() {;}
    MainWindow *mainWindow() { return mpMainWindow; }

public slots:
    void setup();

//    virtual bool event(QEvent *e) override;
    virtual void onEntry(QEvent *event) override;
    virtual void onExit(QEvent *event) override;


private:
    MainWindow *mpMainWindow=nullptr;
    QWidget *mpMainWidget=nullptr;
};

