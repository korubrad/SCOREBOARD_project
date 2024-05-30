#include "widget.h"
#include "intro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Intro INTRO;
    Widget w;
    INTRO.show();
    w.show();
    return a.exec();
}
