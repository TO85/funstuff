#include "T3BoardWidget.h"

#include <QtGui/QIcon>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>

#include "IconFactory.h"

T3BoardWidget::T3BoardWidget(QWidget *parent)
    : QWidget(parent)
    , mpMainLayout(new QGridLayout(this))
{
    setObjectName("T3BoardWidget");

}

void T3BoardWidget::setup()
{
    const int nGrid = gridEntries();
    QPixmap blankPixmap = IconFactory::solidPixmap(Qt::gray, mIconSize);
    QPixmap vDividePixmap = IconFactory::solidPixmap(Qt::gray, QSize(3, mIconSize.height()));
    QPixmap hDividePixmap = IconFactory::solidPixmap(Qt::gray, QSize(mIconSize.width(),3));
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

void T3BoardWidget::setIconAt(const int aIndex, const QIcon aIcon)
{
    setIconInLayout(layoutRow(aIndex), layoutCol(aIndex), aIcon);
}

void T3BoardWidget::setPixmapAt(const int aIndex, const QPixmap aPixmap)
{

}

void T3BoardWidget::setPixmapAt(const int aLayoutRow, const int aLayoutCol, const QPixmap aPixmap)
{
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
