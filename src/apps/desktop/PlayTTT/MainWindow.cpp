#include "MainWindow.h"

#include <QtGui/QBrush>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "ScoreWidget.h"
#include "T3BoardWidget.h"
#include "BottomWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , mpMainWidget(new QWidget(this))
    , mpMainLayout(new QGridLayout(mpMainWidget))
    , mpScoreWidget(new ScoreWidget(this))
    , mpT3BoardWidget(new T3BoardWidget(this))
    , mpBottomWidget(new BottomWidget(mpMainWidget))
{
}

MainWindow::~MainWindow()
{
}

void MainWindow::displayMessage(const QString &aString)
{
    mpBottomWidget->display(aString);
}

void MainWindow::showAt(const int aIndex, const QString &aKey)
{
    const QIcon tIcon = factory()->icon(aKey);
    mpT3BoardWidget->setIconAt(aIndex, tIcon);
}

void MainWindow::showAt(QLabel *pLabel, const QString &aKey)
{
    const QIcon tIcon = factory()->icon(aKey);
    pLabel->setPixmap(tIcon.pixmap(mIconSize));
}


void MainWindow::setup()
{
    mpScoreWidget->setup();
    mpT3BoardWidget->setupLayout();
    mpBottomWidget->setup();
    setupIcons();
    mpMainLayout->setColumnMinimumWidth(0, 200);
    mpMainLayout->addWidget(mpScoreWidget, 0, 0);
    mpMainLayout->setRowMinimumHeight(0, 60);
    mpMainLayout->addWidget(mpT3BoardWidget, 1, 0, Qt::AlignHCenter | Qt::AlignVCenter);
    mpMainLayout->setRowMinimumHeight(1, 200);
    mpMainLayout->addWidget(mpBottomWidget, 2, 0);
    mpMainLayout->setRowMinimumHeight(2,  40);
    mpMainWidget->setMinimumHeight(360);
    mpMainWidget->setMinimumWidth(200);
    mpMainWidget->setLayout(mpMainLayout);
    setCentralWidget(mpMainWidget);
}

void MainWindow::setupIcons()
{
    const QSize tSize = mIconSize;
    const QColor tHColor = Qt::red;
    const QColor tVColor = Qt::blue;

    factory()->create("Empty", IconFactory::Empty, QColor(), tSize);
    factory()->create("Home", IconFactory::Ex, tHColor, tSize);
    factory()->create("Visitor", IconFactory::Oh, tVColor, tSize);
}

