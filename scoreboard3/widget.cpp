#include "widget.h"
#define INTERVAL 1000

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    h = new QHBoxLayout();

    b = new QPushButton();
    bStop = new QPushButton();

    t = new QElapsedTimer();

    timerPrint = new QTimer();
    timerPrint->setInterval(INTERVAL);
    timerPrint->start();

    t->start();


    bStop->setText("Stop / Start");

    h->addWidget(b);
    h->addWidget(bStop);
    setLayout(h);

    QObject::connect(
        timerPrint,
        &QTimer::timeout,
        this,
        [=](){
            int time = t->elapsed();
            b->setText(QString("%1 : %2")
                           .arg(time/60000)
                           .arg((time/1000)%60));
        }
        );

    timerPrint->

    QObject::connect(
        b,
        & QPushButton::clicked,
        this,
        [=](){
            qDebug() << t->elapsed() << " " << (t->elapsed()) / 1000 << "seconds";
        });

    QObject::connect(
        bStop,
        & QPushButton::clicked,
        this,
        [=](){
            t->restart();
        });

}

Widget::~Widget() {}



