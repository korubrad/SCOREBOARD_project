#include "intro.h"

Intro::Intro(QWidget *parent) : QWidget(parent)
{
    hINTRO = new QHBoxLayout;
    bINTRO = new QPushButton("Ahoj");

    hINTRO->addWidget(bINTRO);
    setLayout(hINTRO);
}

Intro::~Intro()
{}
