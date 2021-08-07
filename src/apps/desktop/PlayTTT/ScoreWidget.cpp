#include "ScoreWidget.h"

#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QSizePolicy>


ScoreWidget::ScoreWidget(QWidget *parent)
    : QWidget(parent)
    , mpMainGrid(new QGridLayout(this))
    , mpHomeName(new QLabel("Lancers", this))
    , mpVisitorName(new QLabel("Monsoons", this))
    , mpHomeTile(new QLabel(this))
    , mpVisitorTile(new QLabel(this))
    , mpHomeWins(new QLCDNumber(this))
    , mpVisitorWins(new QLCDNumber(this))
{
    setObjectName("ScoreWidget");
}

void ScoreWidget::setup()
{
    mpHomeWins->setDigitCount(3);
    mpHomeWins->setMinimumSize(60, 30);
    mpVisitorWins->setDigitCount(3);
    mpVisitorWins->setMinimumSize(60, 30);
    mpHomeTile=nullptr; // TODO
    mpVisitorTile=nullptr;

    Qt::Alignment tAlignment = Qt::AlignHCenter | Qt::AlignVCenter;
    QLabel *pHomeLabel = new QLabel("Home", this);
    QLabel *pVisitorLabel = new QLabel("Visitor", this);
    mpMainGrid->setRowMinimumHeight(0, 15);
    mpMainGrid->setRowMinimumHeight(1, 15);
    mpMainGrid->setRowMinimumHeight(2, 30);
    mpMainGrid->setColumnMinimumWidth(0,  60);
    mpMainGrid->setColumnMinimumWidth(1,  60);
    mpMainGrid->setColumnMinimumWidth(2,  60);
    mpMainGrid->setColumnMinimumWidth(3,  60);
    mpMainGrid->setColumnMinimumWidth(4,  60);
    mpMainGrid->setSizeConstraint(QGridLayout::SetMinimumSize);
    mpMainGrid->addWidget(pHomeLabel,       0, 0, tAlignment);
    mpMainGrid->addWidget(pVisitorLabel,    0, 4, tAlignment);
    mpMainGrid->addWidget(mpHomeName,       1, 0, tAlignment);
    mpMainGrid->addWidget(mpVisitorName,    1, 4, tAlignment);
    mpMainGrid->addWidget(mpHomeWins,       2, 0, tAlignment);
    mpMainGrid->addWidget(mpVisitorWins,    2, 4, tAlignment);

    mpHomeWins->display(79);
    mpVisitorWins->display(19);
}
