#ifndef INTRO_H
#define INTRO_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QSpinBox>

class Intro : public QWidget
{
    Q_OBJECT

public:
    Intro(QWidget *parent = nullptr);
    ~Intro();
    QHBoxLayout *hINTRO;
    QVBoxLayout *vINTRO;
    QPushButton *bINTRO;
    QSpinBox *spinINTRO;
};

#endif // INTRO_H
