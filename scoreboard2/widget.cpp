// under construction:
// stisk() a stisk2() nahradit lambda funkci

#include "widget.h"

int count = 0;
int count2 = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    bGoal = new QPushButton();
    bGoal2 = new QPushButton();
    bReset = new QPushButton(QString("reset"), this);
    bReset2 = new QPushButton(QString("reset"), this);
    bMinus = new QPushButton(QString("minus"), this);
    bMinus2 = new QPushButton(QString("minus"), this);

    h = new QHBoxLayout;
    v = new QVBoxLayout;
    v2 = new QVBoxLayout;

    text = new QLineEdit("Domaci");
    text2 = new QLineEdit("Hoste");

    Widget::cntPrint(bGoal, count);
    Widget::cntPrint(bGoal2, count2);
    bReset->setStyleSheet("font: bold 14px; color: #9F005A; background-color: #AEAEAE; height: 30px; width: 150px;");
    bMinus->setStyleSheet("font: bold 14px; color: #C65A00; background-color: #AEAEAE; height: 30px; width: 150px;");
    bReset2->setStyleSheet("font: bold 14px; color: #9F005A; background-color: #AEAEAE; height: 30px; width: 150px;");
    bMinus2->setStyleSheet("font: bold 14px; color: #C65A00; background-color: #AEAEAE; height: 30px; width: 150px;");

    v->addWidget(text);
    v->addWidget(bGoal);
    v->addWidget(bMinus);
    v->addWidget(bReset);

    h->addLayout(v);

    v2->addWidget(text2);
    v2->addWidget(bGoal2);
    v2->addWidget(bMinus2);
    v2->addWidget(bReset2);

    h->addLayout(v2);

    setLayout(h);

    QObject::connect(
        bGoal,
        & QPushButton::clicked,
        this,
        [=](){
            ++count;
            Widget::cntPrint(bGoal, count);
        }
    );

    QObject::connect(
        bGoal2,
        & QPushButton::clicked,
        this,
        [=](){
            ++count2;
            Widget::cntPrint(bGoal2, count2);
        }
        );

    QObject::connect(
        bReset,
        & QPushButton::clicked,
        this,
        [=](){
            count = 0;
            Widget::cntPrint(bGoal, count);
        }
        );

    QObject::connect(
        bMinus,
        & QPushButton::clicked,
        this,
        [=](){
            if (count > 0)
                --count;
            Widget::cntPrint(bGoal, count);
        }
        );

    QObject::connect(
        bReset2,
        & QPushButton::clicked,
        this,
        [=](){
            count2 = 0;
            Widget::cntPrint(bGoal2, count2);
        }
        );

    QObject::connect(
        bMinus2,
        & QPushButton::clicked,
        this,
        [=](){
            if (count2 > 0)
                --count2;
            Widget::cntPrint(bGoal2, count2);
        }
        );
}

void Widget::cntPrint(QPushButton *b, int c)
{
    b->setText(QString("goly %1").arg(c));
    b->setStyleSheet("font: bold 14px; color: #C60000; background-color: #AEAEAE; height: 30px; width: 150px;");
}


Widget::~Widget(){}
