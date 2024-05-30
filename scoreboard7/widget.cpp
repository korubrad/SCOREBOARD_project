// some parameters are changes here in this code, follow keyword CHANGE


#include "widget.h"

bool isRun = false;
int TimeTmp = 0;
int actualTime = 0;
int count = 0;
int count2 = 0;
int countPart = 1;
float TimeLimitInMinutes = 10; // CHANGE - in minutes
int TimeLimit = TimeLimitInMinutes * 60000;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    bGoal = new QPushButton();
    bGoal2 = new QPushButton();
    bReset = new QPushButton(QString("reset"), this);
    bReset2 = new QPushButton(QString("reset"), this);
    bMinus = new QPushButton(QString("minus"), this);
    bMinus2 = new QPushButton(QString("minus"), this);

    text = new QLineEdit("Home");
    text2 = new QLineEdit("Guest");

    h = new QHBoxLayout;
    v = new QVBoxLayout;
    v2 = new QVBoxLayout;
    v3 = new QVBoxLayout;
    timer = new QElapsedTimer;
    timerShort = new QTimer;
    button = new QPushButton;
    bPart = new QPushButton(QString("%1").arg(countPart++));
    bPartReset = new QPushButton(QString("Reset part"));
    bTimeReset = new QPushButton("Reset time");

    Widget::cntPrint(bGoal, count);
    Widget::cntPrint(bGoal2, count2);
    bReset->setStyleSheet("font: bold 14px; color: #9F005A; background-color: #AEAEAE; height: 30px; width: 150px;");
    bMinus->setStyleSheet("font: bold 14px; color: #C65A00; background-color: #AEAEAE; height: 30px; width: 150px;");
    bReset2->setStyleSheet("font: bold 14px; color: #9F005A; background-color: #AEAEAE; height: 30px; width: 150px;");
    bMinus2->setStyleSheet("font: bold 14px; color: #C65A00; background-color: #AEAEAE; height: 30px; width: 150px;");
    bPart->setStyleSheet("font: bold 14px; color: #AAFF00; background-color: #AEAEAE; height: 30px; width: 150px;");
    bPartReset->setStyleSheet("font: bold 14px; color: #AAFF00; background-color: #AEAEAE; height: 30px; width: 150px;");
    button->setStyleSheet("font: bold 20px; color: #000000; background-color: #FFFFFF; height: 30px; width: 150px;");
    bTimeReset->setStyleSheet("font: bold 10px; color: #000000; background-color: #FFFFFF; height: 10px; width: 150px;");

    v->addWidget(text);
    v->addWidget(bGoal);
    v->addWidget(bMinus);
    v->addWidget(bReset);

    h->addLayout(v);

    v2->addWidget(text2);
    v2->addWidget(bGoal2);
    v2->addWidget(bMinus2);
    v2->addWidget(bReset2);

    v3->addWidget(button);
    v3->addWidget(bTimeReset);
    v3->addWidget(bPart);
    v3->addWidget(bPartReset);

    h->addLayout(v3);
    h->addLayout(v2);
    setLayout(h);


    timerShort->setInterval(200);
    timerShort->start();

    timer->start();

    QObject::connect(
        timerShort,
        &QTimer::timeout,
        this,
        [=](){
            if(isRun)
                actualTime = timer->elapsed() + TimeTmp;
            else
                actualTime = TimeTmp;

            int TimeDif = TimeLimit - actualTime;

            if(TimeDif > 0)
            {
                qDebug() << TimeDif << "miliseconds";
                button->setText(QString("%1 : %2")
                                    .arg(TimeDif/60000)
                                    .arg((TimeDif/1000)%60));
            }
            else
            {
                qDebug() << "Konec casu";
                button->setText(QString("%1").arg("Konec casu"));
            }
        });

    QObject::connect(
        button,
        &QPushButton::clicked,
        this,
        [=](){
            if(isRun)
            {
                // prave bylo stopnuto
                TimeTmp = TimeTmp + timer->elapsed();
            }
            else
            {
                // prave bylo spusteno
                timer->restart();
                actualTime = timer->elapsed() + TimeTmp;
            }

            isRun = !isRun;
        });

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

    QObject::connect(
        bPart,
        & QPushButton::clicked,
        this,
        [=](){
            Widget::cntPrintPart(bPart, countPart++);
        }
        );

    QObject::connect(
        bPartReset,
        & QPushButton::clicked,
        this,
        [=](){
            countPart = 1;
            Widget::cntPrintPart(bPart, countPart++);
        });

    QObject::connect(
        bTimeReset,
        & QPushButton::clicked,
        this,
        [=](){

            TimeTmp = 0;
        });
}

void Widget::cntPrint(QPushButton *b, int c)
{
    b->setText(QString("goal %1").arg(c));
    b->setStyleSheet("font: bold 14px; color: #C60000; background-color: #AEAEAE; height: 30px; width: 150px;");
}

void Widget::cntPrintPart(QPushButton *b, int c)
{
    b->setText(QString("%1").arg(c));
    b->setStyleSheet("font: bold 14px; color: #BBFF00; background-color: #AEAEAE; height: 30px; width: 150px;");
}

Widget::~Widget()
{}


