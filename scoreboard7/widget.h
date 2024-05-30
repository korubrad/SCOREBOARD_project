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

    QPushButton *bGoal, *bGoal2;
    QPushButton *bReset, *bReset2;
    QPushButton *bMinus, *bMinus2;
    QPushButton *bPart, *bPartReset;
    QPushButton *bTimeReset;
    QVBoxLayout *v, *v2, *v3;
    QLineEdit *text, *text2;

public slots:
    void cntPrint(QPushButton *b, int cnt);
    void cntPrintPart(QPushButton *b, int cnt);
};
#endif // WIDGET_H
