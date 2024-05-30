#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>
#include <QElapsedTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QDebug>
#include <QLineEdit>
#include <QSpinBox>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QHBoxLayout *h;
    QPushButton *button, *timeButton;
    QElapsedTimer *timer;
    QTimer *timerShort;
    //QSpinBox *spinBox;
};
#endif // WIDGET_H
