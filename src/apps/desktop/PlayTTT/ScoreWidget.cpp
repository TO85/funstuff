#include "ScoreWidget.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QSizePolicy>

#include "MainWindow.h"
#include "TttBoardWidget.h"

ScoreWidget::ScoreWidget(MainWindow *parent)
    : QWidget(parent)
    , mpMainWindow(parent)
    , mpMainGrid(new QGridLayout(this))
    , mpHomeName(new QLabel("Lancers", this))
    , mpVisitorName(new QLabel("Monsoons", this))
    , mpHomeTile(new QLabel(this))
    , mpVisitorTile(new QLabel(this))
    , mpHomeWins(new QLCDNumber(this))
    , mpVisitorWins(new QLCDNumber(this))
{
    setObjectName("ScoreWidget");
    qDebug() << Q_FUNC_INFO << objectName();
    mpMainGrid->setObjectName("MainGrid");
    mpHomeName->setObjectName("HomeName");
    mpVisitorName->setObjectName("VisitorName");
    mpHomeTile->setObjectName("HomeTile");
    mpVisitorTile->setObjectName("VisitorTile");
    mpHomeWins->setObjectName("HomeWins");
    mpVisitorWins->setObjectName("VisitorWins");
}

void ScoreWidget::setup()
{
    qDebug() << Q_FUNC_INFO << objectName();
    mpHomeWins->setDigitCount(3);
    mpHomeWins->setMinimumSize(60, 30);
    mpVisitorWins->setDigitCount(3);
    mpVisitorWins->setMinimumSize(60, 30);
    mpHomeTile->setMinimumSize(QSize(48,48));
    mpVisitorTile->setMinimumSize(QSize(48,48));
    mpHomeTile->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mpVisitorTile->setFrameStyle(QFrame::Panel | QFrame::Sunken);
    mainWindow()->board()->showAt(mpHomeTile, TttPixmaps::EmptyBase | TttPixmaps::Cross);
    mainWindow()->board()->showAt(mpVisitorTile, TttPixmaps::EmptyBase | TttPixmaps::Circle);
    update();

    Qt::Alignment tAlignment = Qt::AlignHCenter | Qt::AlignVCenter;
    mpMainGrid->setRowMinimumHeight(0, 15);
    mpMainGrid->setRowMinimumHeight(1, 60);
    mpMainGrid->setRowMinimumHeight(2, 30);
    mpMainGrid->setColumnMinimumWidth(0,  60);
    mpMainGrid->setColumnMinimumWidth(1,  60);
    mpMainGrid->setColumnMinimumWidth(2,  60);
    mpMainGrid->setSizeConstraint(QGridLayout::SetMinimumSize);
    mpMainGrid->addWidget(mpHomeName,       0, 0, tAlignment);
    mpMainGrid->addWidget(mpVisitorName,    0, 2, tAlignment);
    mpMainGrid->addWidget(mpHomeTile,       1, 0, tAlignment);
    mpMainGrid->addWidget(mpVisitorTile,    1, 2, tAlignment);
    mpMainGrid->addWidget(mpHomeWins,       2, 0, tAlignment);
    mpMainGrid->addWidget(mpVisitorWins,    2, 2, tAlignment);
    mpMainGrid->addWidget(mpCenterWidget,   0, 1, 3, 1, tAlignment);

    mpHomeWins->display(79);
    mpVisitorWins->display(19);
}

void ScoreWidget::clearCenterWidget()
{
    mpCenterWidget = nullptr;
    emit centerWidgetChanged();
}

void ScoreWidget::setCenterWidget(QWidget *pWidget)
{
    mpCenterWidget = nullptr;
    emit centerWidgetChanged();
}

QWidget *ScoreWidget::CenterWidget() const
{
    return mpCenterWidget;
}
