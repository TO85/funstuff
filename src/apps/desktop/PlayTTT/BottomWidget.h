#pragma once

#include <QWidget>
#include <QtWidgets/QLabel>

class BottomWidget : public QLabel
{
    Q_OBJECT
public:
    explicit BottomWidget(QWidget *parent = nullptr);

public slots:
    void setup();
    void display(const QString &aString);

signals:

private:
    QLabel *mpMainLabel=nullptr;

};

