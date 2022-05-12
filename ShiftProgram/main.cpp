#include "lesson.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    QWidget w;

    QHBoxLayout* lay = new QHBoxLayout();
    Lesson* l = new Lesson("Efanov","Informatics","sem","322 ЛК");
    Time_of_the_Lesson* t = new Time_of_the_Lesson(1,1);

    lay->addWidget(t);
    lay->addWidget(l);
    //lay->addStretch(10000);
    QVBoxLayout* lay1 = new QVBoxLayout();
    Week_Widget_View* week = new Week_Widget_View(1);

    lay1->addWidget(week, 1000);
    lay1->addLayout(lay);
    lay1->addStretch(10000);

    w.setLayout(lay1);

    w.show();

    return a.exec();
}
