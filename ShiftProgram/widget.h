#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include "header.h"
#include "lesson.h"
#include "step_view.h"
//#include библиотеки ядра

class MainWindow : public QFrame
{
    Q_OBJECT

public:
    MainWindow(QString group_number = "B05-007",QWidget *parent = nullptr);
    ~MainWindow();
protected:

private:

signals:

};
#endif // WIDGET_H
