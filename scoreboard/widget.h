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
    QPushButton *bGoal;
    QPushButton *bReset;
    QPushButton *bMinus;
    QPushButton *bGoal2;
    QHBoxLayout *h;
    QVBoxLayout *v, *v2;
    QLineEdit *text;
    QLineEdit *text2;

public slots:
    void stisk();
    void stisk2();
    void stiskReset();
    void cntPrint(QPushButton *b, int cnt);
    void stiskMinus();
};
#endif // WIDGET_H
