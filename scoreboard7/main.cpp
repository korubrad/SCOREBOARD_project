#include "widget.h"
#include "intro.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Intro INTRO;
    Widget w;
    w.show();
    INTRO.show();
    return a.exec();
}
