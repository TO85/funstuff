#include "IconGrid.h"

#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidgetItem>

IconGrid::IconGrid(QWidget *parent)
    : QWidget(parent)
{
    mpMainLayout = new QVBoxLayout(parent);
    mpMainLabel = new QLabel(parent);
    mpMainLabel->setObjectName("IconGrid:MainLabel");
}

QSize IconGrid::overallSize() const
{
    QFrame tFrame;
    tFrame.setLineWidth(frameLineWidth());
    tFrame.setMidLineWidth(frameMidWidth());
    const int tFrameWidth = tFrame.lineWidth();

    QFrame tDivider;
    tDivider.setLineWidth(dividerLineWidth());
    tDivider.setMidLineWidth(dividerMidWidth());
    const int tDividerWidth = tDivider.lineWidth();

    const int nCellCols = gridSize().width();
    const int nCellRows = gridSize().height();
    const int tIconWidth = iconSize().width();
    const int tIconHeight = iconSize().height();

    const int tWidth    = 2 * tFrameWidth
                        + 2 * frameMargin()
                        + nCellCols * tIconWidth
                        + (nCellCols - 1) * dividerMargin()
                        + (nCellCols - 1) * tDividerWidth;
    const int tHeight   = 2 * tFrameWidth
                        + 2 * frameMargin()
                        + nCellRows * tIconHeight
                        + (nCellRows - 1) * dividerMargin()
                        + (nCellRows - 1) * tDividerWidth;
    return QSize(tWidth, tHeight);
}

void IconGrid::setup()
{
    mMainPixmap = QPixmap(overallSize());
    mMainPixmap.fill(mBackColor);
    mpMainLabel->setPixmap(mMainPixmap);
    mpMainLabel->setFixedSize(overallSize());
    if (mpMainLayout) delete mpMainLayout;
    mpMainLayout = new QVBoxLayout(mpMainLabel);
    setLayout(mpMainLayout);
}

QFrame *IconGrid::getMpFrame() const
{
    return mpFrame;
}

void IconGrid::setMpFrame(QFrame *newMpFrame)
{
    if (mpFrame == newMpFrame)
        return;
    mpFrame = newMpFrame;
    emit mpFrameChanged();
}

QFrame *IconGrid::getMpHDividerMemio() const
{
    return mpHDividerMemio;
}

void IconGrid::setMpHDividerMemio(QFrame *newMpHDividerMemio)
{
    if (mpHDividerMemio == newMpHDividerMemio)
        return;
    mpHDividerMemio = newMpHDividerMemio;
    emit mpHDividerMemioChanged();
}

QFrame *IconGrid::getMpVDividerMemio() const
{
    return mpVDividerMemio;
}

void IconGrid::setMpVDividerMemio(QFrame *newMpVDividerMemio)
{
    if (mpVDividerMemio == newMpVDividerMemio)
        return;
    mpVDividerMemio = newMpVDividerMemio;
    emit mpVDividerMemioChanged();
}

QVBoxLayout *IconGrid::getMainLayout() const
{
    return mpMainLayout;
}

QLabel *IconGrid::getMainLabel() const
{
    return mpMainLabel;
}

const QPixmap &IconGrid::mainPixmap() const
{
    return mMainPixmap;
}

void IconGrid::setMainPixmap(const QPixmap &newMainPixmap)
{
    if (mMainPixmap == newMainPixmap)
        return;
    mMainPixmap = newMainPixmap;
    emit mainPixmapChanged();
}

void IconGrid::resetMainPixmap()
{
    setMainPixmap(QPixmap());
}

const Matrix<QLabel *> &IconGrid::labelMatrix() const
{
    return mLabelMatrix;
}

const Matrix<QPixmap> &IconGrid::pixmapMatrix() const
{
    return mPixmapMatrix;
}

int IconGrid::dividerLineWidth() const
{
    return mDividerLineWidth;
}

void IconGrid::setDividerLineWidth(int newDividerLineWidth)
{
    if (mDividerLineWidth == newDividerLineWidth)
        return;
    mDividerLineWidth = newDividerLineWidth;
    emit dividerLineWidthChanged();
}

void IconGrid::resetDividerLineWidth()
{
    setDividerLineWidth(5);
}

int IconGrid::dividerMidWidth() const
{
    return mDividerMidWidth;
}

void IconGrid::setDividerMidWidth(int newDividerMidWidth)
{
    if (mDividerMidWidth == newDividerMidWidth)
        return;
    mDividerMidWidth = newDividerMidWidth;
    emit dividerMidWidthChanged();
}

void IconGrid::resetDividerMidWidth()
{
    setDividerMidWidth(0);
}

const QString &IconGrid::dividerStyleSheet() const
{
    return mDividerStyleSheet;
}

void IconGrid::setDividerStyleSheet(const QString &newDividerStyleSheet)
{
    if (mDividerStyleSheet == newDividerStyleSheet)
        return;
    mDividerStyleSheet = newDividerStyleSheet;
    emit dividerStyleSheetChanged();
}

void IconGrid::resetDividerStyleSheet()
{
    setDividerStyleSheet(QString());
}

int IconGrid::frameLineWidth() const
{
    return mFrameLineWidth;
}

void IconGrid::setFrameLineWidth(int newFrameLineWidth)
{
    if (mFrameLineWidth == newFrameLineWidth)
        return;
    mFrameLineWidth = newFrameLineWidth;
    emit frameLineWidthChanged();
}

void IconGrid::resetFrameLineWidth()
{
    setFrameLineWidth(0);
}

int IconGrid::frameMidWidth() const
{
    return mFrameMidWidth;
}

void IconGrid::setFrameMidWidth(int newFrameMidWidth)
{
    if (mFrameMidWidth == newFrameMidWidth)
        return;
    mFrameMidWidth = newFrameMidWidth;
    emit frameMidWidthChanged();
}

void IconGrid::resetFrameMidWidth()
{
    setFrameMidWidth(0);
}

const QString &IconGrid::frameStyleSheet() const
{
    return mFrameStyleSheet;
}

void IconGrid::setFrameStyleSheet(const QString &newFrameStyleSheet)
{
    if (mFrameStyleSheet == newFrameStyleSheet)
        return;
    mFrameStyleSheet = newFrameStyleSheet;
    emit frameStyleSheetChanged();
}

void IconGrid::resetFrameStyleSheet()
{
    setFrameStyleSheet(QString());
}

const QSize &IconGrid::gridSize() const
{
    return mGridSize;
}

void IconGrid::setGridSize(const QSize &newGridSize)
{
    if (mGridSize == newGridSize)
        return;
    mGridSize = newGridSize;
    emit gridSizeChanged();
}

void IconGrid::resetGridSize()
{
    setGridSize(QSize(3, 3));
}

const QSize &IconGrid::iconSize() const
{
    return mIconSize;
}

void IconGrid::setIconSize(const QSize &newIconSize)
{
    if (mIconSize == newIconSize)
        return;
    mIconSize = newIconSize;
    emit iconSizeChanged();
}

void IconGrid::resetIconSize()
{
    setIconSize(QSize(64, 64));
}

const QColor &IconGrid::cellColor() const
{
    return mCellColor;
}

void IconGrid::setCellColor(const QColor &newCellColor)
{
    if (mCellColor == newCellColor)
        return;
    mCellColor = newCellColor;
    emit cellColorChanged();
}

void IconGrid::resetCellColor()
{
    setCellColor(Qt::lightGray);
}

const QColor &IconGrid::backColor() const
{
    return mBackColor;
}

void IconGrid::setBackColor(const QColor &newBackColor)
{
    if (mBackColor == newBackColor)
        return;
    mBackColor = newBackColor;
    emit backColorChanged();
}

void IconGrid::resetBackColor()
{
    setBackColor(Qt::gray);
}

int IconGrid::dividerWidth() const
{
    return mDividerWidth;
}

int IconGrid::dividerMargin() const
{
    return mDividerMargin;
}

void IconGrid::setDividerMargin(int newDividerMargin)
{
    if (mDividerMargin == newDividerMargin)
        return;
    mDividerMargin = newDividerMargin;
    emit dividerMarginChanged();
}

void IconGrid::resetDividerMargin()
{
    setDividerMargin(1);
}

int IconGrid::frameWidth() const
{
    return mFrameWidth;
}

int IconGrid::frameMargin() const
{
    return mFrameMargin;
}

void IconGrid::setFrameMargin(int newFrameMargin)
{
    if (mFrameMargin == newFrameMargin)
        return;
    mFrameMargin = newFrameMargin;
    emit frameMarginChanged();
}

void IconGrid::resetFrameMargin()
{
    setFrameMargin(2);
}
