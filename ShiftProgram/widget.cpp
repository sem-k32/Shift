#include "widget.h"

Widget::Widget(QString group_number, QWidget *parent)
    : QWidget(parent)
{
    //задаю логику layouts
    QVBoxLayout* main_layer = new QVBoxLayout();

    QHBoxLayout* header_layout = new QHBoxLayout();                     // нетехнический слой
    Back_button* back_button = new Back_button();
    Program_name_widget* prog_name_widg = new Program_name_widget();
    header_layout->addWidget(back_button);
    header_layout->addWidget(prog_name_widg);

    QHBoxLayout* main_body = new QHBoxLayout();

    main_layer->addLayout(header_layout);
    main_layer->addLayout(main_body);

    QVBoxLayout* working_area = new QVBoxLayout();                      // нетехнический слой

    QVBoxLayout* general_shedule = new QVBoxLayout();

    for(int i = 0; i < 7; i++)
    {
        QHBoxLayout* day_of_the_week = new QHBoxLayout();

        QVBoxLayout* day_shedule = new QVBoxLayout();

        for (int j = 0; j < 7; ++j) {
            QHBoxLayout* time_and_subject_layout = new QHBoxLayout();


        }
    }

    main_body->addLayout(working_area);
    main_body->addLayout(general_shedule);


}

Widget::~Widget()
{
}

