// Tato verze je ve stadiu, kdy mame v levem sloupci
// text-line, citacu golu, minus, reset
// v pravem sloupci je text-line, citac golu
// bez moznosti odcitani ci resetu, ale funguje
// nezavisle na leve casti
// tuto verzi archivuje z toho duvodu, ze nevim jak
// elegantne skrz QObject::connect predat do jeho
// argumentu argument pro funkce, na kterou ma &
// (nejde zkompilovat ani spustit)


#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    // Widget w(0, 640, 480);
    //QObject::connect(&b1, & QPushButton::clicked, [&](){
    //    b1.setText("ahoj");
    //    b2.setStyleSheet("background-color: red");
    //    box.exec();
    //});

    w.show();
    return a.exec();
}
