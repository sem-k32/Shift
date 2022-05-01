#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include "header.h"
#include "lesson.h"
//#include библиотеки ядра

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QString group_number = "B05-007",QWidget *parent = nullptr);
    ~Widget();
};
#endif // WIDGET_H
