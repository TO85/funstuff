#include "BottomWidget.h"


BottomWidget::BottomWidget(QWidget *parent)
    : QLabel(parent)
{
    setObjectName("BottomWidget");
}

void BottomWidget::setup()
{
    setMinimumWidth(200);
    setMinimumHeight(40);
    setAlignment(Qt::AlignVCenter | Qt::AlignLeft);
    setText("Ready");
}

void BottomWidget::display(const QString &aString)
{
    setText(aString);
}
