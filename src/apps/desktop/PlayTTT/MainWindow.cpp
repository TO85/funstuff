#include "MainWindow.h"

#include <QtCore/QTimer>
#include <QtGui/QBrush>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "ScoreWidget.h"
#include "TttBoardWidget.h"
#include "BottomWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << Q_FUNC_INFO;
    setObjectName("MainWindow:PlayTttApplication");
}

MainWindow::~MainWindow()
{
}

/* ------------------------- public slots ------------------------ */

void MainWindow::construct()
{
    qDebug() << Q_FUNC_INFO;
    mpMainWidget = new  QWidget(this);
    mpMainLayout = new  QGridLayout(mpMainWidget);
    mpScoreWidget = new  ScoreWidget(this);
    mpTttBoardWidget = new  TttBoardWidget(this);
    mpBottomWidget = new  BottomWidget(mpMainWidget);
    emit constructed();
}

void MainWindow::setup()
{
    qDebug() << Q_FUNC_INFO;
    QTimer::singleShot(cmShortShotMsec, this, &MainWindow::setupIcons);
}

void MainWindow::displayMessage(const QString &aString)
{
    qDebug() << Q_FUNC_INFO;
    mpBottomWidget->display(aString);
}

/* ------------------------ private slots ------------------------ */

void MainWindow::setupIcons()

{
    qDebug() << Q_FUNC_INFO;
    mpTttBoardWidget->setupPixmaps();
    QTimer::singleShot(cmShortShotMsec, this, &MainWindow::setupWidgets);
}

void MainWindow::setupWidgets()
{
    qDebug() << Q_FUNC_INFO;
    mpScoreWidget->setup();
    mpTttBoardWidget->setupLayout();
    mpBottomWidget->setup();
    QTimer::singleShot(cmShortShotMsec, this, &MainWindow::setupLayout);
}

void MainWindow::setupLayout()
{
    qDebug() << Q_FUNC_INFO;
    mpMainLayout->setColumnMinimumWidth(0, 300);
    mpMainLayout->addWidget(mpScoreWidget, 0, 0);
    mpMainLayout->setRowMinimumHeight(0, 60);
    mpMainLayout->addWidget(mpTttBoardWidget, 1, 0, Qt::AlignHCenter | Qt::AlignVCenter);
    mpMainLayout->setRowMinimumHeight(1, 200);
    mpMainLayout->addWidget(mpBottomWidget, 2, 0);
    mpMainLayout->setRowMinimumHeight(2,  40);
    mpMainWidget->setMinimumHeight(360);
    mpMainWidget->setMinimumWidth(300);
    mpMainWidget->setLayout(mpMainLayout);
    QTimer::singleShot(cmShortShotMsec, this, &MainWindow::setupToolbar);
}

void MainWindow::setupToolbar()
{
    qDebug() << Q_FUNC_INFO;
    QToolBar * tToolBar = addToolBar("Main");
    QTimer::singleShot(cmShortShotMsec, this, &MainWindow::setupFinish);
}

void MainWindow::setupFinish()
{
    qDebug() << Q_FUNC_INFO;
    setCentralWidget(mpMainWidget);
    emit setupComplete();
}

