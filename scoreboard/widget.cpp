#include "widget.h"

int count = 0;
int count2 = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    bGoal = new QPushButton();
    bGoal2 = new QPushButton();
    bReset = new QPushButton(QString("reset"), this);
    bMinus = new QPushButton(QString("minus"), this);

    h = new QHBoxLayout;
    v = new QVBoxLayout;
    v2 = new QVBoxLayout;

    text = new QLineEdit("Domaci");
    text2 = new QLineEdit("Hoste");

    Widget::cntPrint(bGoal, count);
    Widget::cntPrint(bGoal2, count2);
    bReset->setStyleSheet("font: bold 14px; color: #9F005A; background-color: #AEAEAE; height: 30px; width: 150px;");
    bMinus->setStyleSheet("font: bold 14px; color: #C65A00; background-color: #AEAEAE; height: 30px; width: 150px;");

    //b1->setStyleSheet("background-color: green; height: 30px; width: 150px;");

    //h->addWidget(b1);
    //h->addWidget(bReset);
    //this->setLayout(h);
    v->addWidget(text);
    v->addWidget(bGoal);
    v->addWidget(bMinus);
    v->addWidget(bReset);

    h->addLayout(v);

    v2->addWidget(text2);
    v2->addWidget(bGoal2);

    h->addLayout(v2);

    //h->addWidget(bGoal2);

    //this->setLayout(h);
    setLayout(h);

    QObject::connect(
        bGoal,
        & QPushButton::clicked,
        this,
        &Widget::stisk);

    QObject::connect(
        bGoal2,
        & QPushButton::clicked,
        this,
        &Widget::stisk2);

    QObject::connect(
        bReset,
        & QPushButton::clicked,
        this,
        &Widget::stiskReset);

    QObject::connect(
        bMinus,
        & QPushButton::clicked,
        this,
        &Widget::stiskMinus);
}

void Widget::stisk()
{
    ++count;
    Widget::cntPrint(bGoal, count);
}

void Widget::stisk2()
{
    ++count2;
    Widget::cntPrint(bGoal2, count2);
}

void Widget::stiskReset()
{
    count = 0;
    Widget::cntPrint(bGoal, count);
}

void Widget::cntPrint(QPushButton *b, int c)
{
    b->setText(QString("goly %1").arg(c));
    b->setStyleSheet("font: bold 14px; color: #C60000; background-color: #AEAEAE; height: 30px; width: 150px;");
}

void Widget::stiskMinus()
{
    if (count > 0)
        --count;
    Widget::cntPrint(bGoal, count);
}

Widget::~Widget(){}
