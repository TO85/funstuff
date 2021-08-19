#include "TttBoardWidget.h"

#include <QtGui/QIcon>
#include <QtGui/QPainter>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "MainWindow.h"

TttBoardWidget::TttBoardWidget(MainWindow *parent)
    : QWidget(parent)
    , mpMainLayout(new QGridLayout(this))
{
    setObjectName("T3BoardWidget");

}

void TttBoardWidget::clearBoard()
{
    const int nGrid = mLabelVector.count();
//  NEEDO  for (int ix = 0; ix < nGrid; ++ix)
  //      setIconAt(ix, mainWindow()->factory()->pixmap("C"));
}

void TttBoardWidget::setIconAt(const int aIndex, const QIcon aIcon)
{
    setIconInLayout(layoutRow(aIndex), layoutCol(aIndex), aIcon);
}

void TttBoardWidget::setupPixmaps()
{
    mPixmaps.setup();
}

void TttBoardWidget::setupLayout()
{
    const int nGrid = gridEntries();
    QPixmap blankPixmap(mIconSize); blankPixmap.fill(Qt::gray);
    QPixmap vDividePixmap(QSize(3, mIconSize.height())); blankPixmap.fill(Qt::black);
    QPixmap hDividePixmap(QSize(mIconSize.width(),3)); blankPixmap.fill(Qt::black);
    QLabel vDivideLabel(this); vDivideLabel.setPixmap(vDividePixmap);
    QLabel hDivideLabel(this); hDivideLabel.setPixmap(hDividePixmap);

    mLabelVector.resize(nGrid);
    for (int ix = 0; ix < nGrid; ++ix)
    {
        mLabelVector[ix] = new QLabel(this);
        mLabelVector[ix]->setPixmap(blankPixmap);
        const int lrow = layoutRow(ix);
        const int lcol = layoutCol(ix);
        mpMainLayout->addWidget(mLabelVector[ix], lrow, lcol);
        if (lrow > 0) mpMainLayout->addWidget(&hDivideLabel, lrow-1, lcol);
        if (lcol > 0) mpMainLayout->addWidget(&hDivideLabel, lrow, lcol-1);
    }
    setLayout(mpMainLayout);
}

void TttBoardWidget::showAt(const int aIndex, const TttPixmaps::Keys &aKeyStack)
{
    qDebug() << Q_FUNC_INFO << aIndex << aKeyStack;

}

void TttBoardWidget::showAt(QLabel *pLabel, const int aPixmapKeyStack)
{
    qDebug() << Q_FUNC_INFO << pLabel->size() << aPixmapKeyStack;
    pLabel->setPixmap(mPixmaps.pixmap(aPixmapKeyStack));
}


void TttBoardWidget::setIconAt(const int row, const int col, const QIcon aIcon)
{
    setIconAt(index(row, col), aIcon);
}

void TttBoardWidget::setIconInLayout(const int aLayoutRow, const int aLayoutCol, const QIcon aIcon)
{
    setPixmapAt(aLayoutRow, aLayoutCol, aIcon.pixmap(mIconSize));
}

void TttBoardWidget::setPixmapAt(QLabel *pLabel, const QPixmap aPixmap)
{
    pLabel->setPixmap(aPixmap);
}


void TttBoardWidget::setPixmapAt(const int aIndex, const QPixmap aPixmap)
{
    setPixmapAt(mLabelVector[aIndex], aPixmap);
}

void TttBoardWidget::setPixmapAt(const int aLayoutRow, const int aLayoutCol, const QPixmap aPixmap)
{
    setPixmapAt(indexFromLayout(aLayoutRow, aLayoutCol), aPixmap);
}

int TttBoardWidget::index(const int row, const int col) const
{
    return (mGridSize.height() - row - 1) * mGridSize.width() + col;
}

int TttBoardWidget::indexFromLayout(const int aLayoutRow, const int aLayoutCol) const
{
    return index(mGridSize.height() - aLayoutRow / 2 - 1, aLayoutCol / 2);
}


int TttBoardWidget::gridEntries() const
{
    return mGridSize.width() * mGridSize.height();
}

int TttBoardWidget::row(const int aIndex) const
{
    return aIndex / mGridSize.width();
}

int TttBoardWidget::col(const int aIndex) const
{
    return aIndex % mGridSize.width();
}

int TttBoardWidget::layoutRow(const int aIndex) const
{
    return mGridSize.height() - row(aIndex) - 1 * 2 + 1;
}

int TttBoardWidget::layoutCol(const int aIndex) const
{
    return col(aIndex) * 2 + 1;
}

