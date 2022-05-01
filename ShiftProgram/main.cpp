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

    w.setLayout(lay);

    w.show();

    return a.exec();
}
