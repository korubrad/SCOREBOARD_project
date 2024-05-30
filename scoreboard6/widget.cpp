#include "widget.h"

bool isRun = true;
int TimeTmp = 0;
int actualTime = 0;
int TimeLimit = 120000; // ms, nutno nastavit rucne

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    h = new QHBoxLayout;
    timer = new QElapsedTimer;
    timerShort = new QTimer;
    button = new QPushButton;
    //timeButton = new QPushButton();
    //spinBox = new QSpinBox;

    h->addWidget(button);
    //h->addWidget(spinBox);
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
                qDebug() << TimeDif;
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
}

Widget::~Widget()
{}
