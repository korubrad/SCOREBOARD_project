#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLayout>
#include <QLabel>
#include <QLineEdit>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    //Widget(QWidget *parent = nullptr, int sirka = 640, int vyska = 480);
    ~Widget();
    QPushButton *bGoal, *bGoal2;
    QPushButton *bReset, *bReset2;
    QPushButton *bMinus, *bMinus2;
    QHBoxLayout *h;
    QVBoxLayout *v, *v2;
    QLineEdit *text, *text2;

public slots:
    void cntPrint(QPushButton *b, int cnt);
};
#endif // WIDGET_H
