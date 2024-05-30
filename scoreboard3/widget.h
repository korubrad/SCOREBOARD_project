#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QElapsedTimer>
#include <QDebug>
#include <QPushButton>
#include <QTimer>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QElapsedTimer *t;
    QPushButton *b, *bStop;
    QHBoxLayout *h;
    QTimer *timerPrint;
};
#endif // WIDGET_H
