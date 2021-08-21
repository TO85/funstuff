#pragma once

#include <QWidget>

class QGridLayout;
class QLabel;
class QLCDNumber;

class MainWindow;

class ScoreWidget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(QWidget * mpCenterWidget READ CenterWidget WRITE setCenterWidget
               NOTIFY centerWidgetChanged RESET clearCenterWidget);

public:
    explicit ScoreWidget(MainWindow *parent = nullptr);
    MainWindow * mainWindow() { return mpMainWindow; }
    QWidget *CenterWidget() const;

public slots:
    void setup();
    void clearCenterWidget();
    void setCenterWidget(QWidget * pWidget);


signals:
    void centerWidgetChanged();

private:
    MainWindow *mpMainWindow=nullptr;
    QGridLayout *mpMainGrid=nullptr;
    QWidget * mpCenterWidget=nullptr;
    QLabel *mpHomeName=nullptr;
    QLabel *mpVisitorName=nullptr;
    QLabel *mpHomeTile=nullptr;
    QLabel *mpVisitorTile=nullptr;

    QLCDNumber *mpHomeWins=nullptr;
    QLCDNumber *mpVisitorWins=nullptr;
};

