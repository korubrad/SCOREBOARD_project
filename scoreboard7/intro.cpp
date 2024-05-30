#include "intro.h"

Intro::Intro(QWidget *parent) : QWidget(parent)
{
    hINTRO = new QHBoxLayout;
    message = new QTextEdit("Tohle je tutoriál, jak ovládat tento scoreboard\n\n"
                            "Levý a pravý sloupec je určený k zaznamenávání gólů.\n"
                            "K ovládání tu jsou tři tlačítka:\n"
                            "a) goal (kde je přímo aktuální skóre) - přičítá góly\n"
                            "b) minus - odečítá góly\n"
                            "c) reset - nastaví počet gólů na 0.\n\n"
                            "Prostřední sloupec je určený ke spouštění časomíry,\n"
                            "která jde i zastavovat a opět spouštět. Pod ní je\n"
                            "vidět, kolikátá část zápasu se právě odehrává.\n"
                            "Ovládání tu je jednoduché:\n"
                            "a) Kliknutím na časomíru ji spustíme / zastavíme\n"
                            "b) Reset time zresetuje kompletně časomíru\n"
                            "c) Kliknutím na tlačítko, kde je pouze číslo,\n"
                            "změníme jeho hodnotu (tj. část zápasu)\n"
                            "d) Reset part zresetuje part na 1.\n\n"
                            "Počet minut časomíry je nutně pevně nastavit přímo v kódu :(.\n"
                            "Home / Guest jde přejmenovat interaktivně přímo v ovládacím okně.\n"
                            "Tresty hráčů zde nejsou možné :(.\n");



    hINTRO->addWidget(message);
    setLayout(hINTRO);
}

Intro::~Intro()
{}
