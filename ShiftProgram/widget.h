#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets>
#include "header.h"
#include "lesson.h"
#include "step_view.h"
#include <set>
//#include библиотеки ядра

class MainWindow : public QFrame
{
    Q_OBJECT

public:
    MainWindow(QString group_number = "Б05-007",QWidget *parent = nullptr);
    ~MainWindow();

    // slots
    void manage_unchanching_list(int day, int num);                             // добавление/удаление урока в множестве неизменяемых
protected:

private:
    QString group_name;                                                         // группа студента

    std::set<std::pair<short, short>> unchanging_lessons;                       // множество неизменяемых предметов

signals:

};
#endif // WIDGET_H
