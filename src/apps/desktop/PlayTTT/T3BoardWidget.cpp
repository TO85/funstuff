#include "T3BoardWidget.h"

#include <QtGui/QIcon>
#include <QtGui/QPainter>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

T3BoardWidget::T3BoardWidget(MainWindow *parent)
    : QWidget(parent)
    , mpMainWindow(parent)
    , mpMainLayout(new QGridLayout(this))
{
    setObjectName("T3BoardWidget");

}

void T3BoardWidget::clearBoard()
{
    const int nGrid = mLabelVector.count();
    for (int ix = 0; ix < nGrid; ++ix)
        setIconAt(ix, mainWindow()->factory()->pixmap("C"));
}

void T3BoardWidget::setIconAt(const int aIndex, const QIcon aIcon)
{
    setIconInLayout(layoutRow(aIndex), layoutCol(aIndex), aIcon);
}

void T3BoardWidget::setupLayout()
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


void T3BoardWidget::setIconAt(const int row, const int col, const QIcon aIcon)
{
    setIconAt(index(row, col), aIcon);
}

void T3BoardWidget::setIconInLayout(const int aLayoutRow, const int aLayoutCol, const QIcon aIcon)
{
    setPixmapAt(aLayoutRow, aLayoutCol, aIcon.pixmap(mIconSize));
}

void T3BoardWidget::setPixmapAt(QLabel *pLabel, const QPixmap aPixmap)
{
    pLabel->setPixmap(aPixmap);
}


void T3BoardWidget::setPixmapAt(const int aIndex, const QPixmap aPixmap)
{
    setPixmapAt(mLabelVector[aIndex], aPixmap);
}

void T3BoardWidget::setPixmapAt(const int aLayoutRow, const int aLayoutCol, const QPixmap aPixmap)
{
    setPixmapAt(indexFromLayout(aLayoutRow, aLayoutCol), aPixmap);
}

int T3BoardWidget::index(const int row, const int col) const
{
    return row * mGridSize.width() + col;
}

int T3BoardWidget::indexFromLayout(const int aLayoutRow, const int aLayoutCol) const
{
    return index(aLayoutRow / 2, aLayoutCol / 2);
}

int T3BoardWidget::gridEntries() const
{
    return mGridSize.width() * mGridSize.height();
}

int T3BoardWidget::row(const int aIndex) const
{
    return aIndex / mGridSize.width();
}

int T3BoardWidget::col(const int aIndex) const
{
    return aIndex % mGridSize.width();
}

int T3BoardWidget::layoutRow(const int aIndex) const
{
    return row(aIndex) * 2 + 1;
}

int T3BoardWidget::layoutCol(const int aIndex) const
{
    return col(aIndex) * 2 + 1;
}

