#include "widget.h"
#include "header.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();

    QWidget w;
    QHBoxLayout* lay = new QHBoxLayout();
    Program_name_widget* pr_name = new Program_name_widget();
    Back_button* b_b = new Back_button();

    lay->addWidget(b_b);
    lay->addWidget(pr_name);
    w.setLayout(lay);

    w.show();

    return a.exec();
}
