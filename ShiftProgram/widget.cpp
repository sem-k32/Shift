#include "widget.h"

MainWindow::MainWindow(QString group_number, QWidget *parent)
    : QFrame(parent)
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

    Step_View* step_widget = new Step_View();                           // создаём виджета показа шага, пояснительную надпись и кнопку
                                                                        //                                                       "далее"
    QLabel* hint_first_step = new QLabel();
    hint_first_step->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred));
    hint_first_step->setMinimumWidth(280);
    hint_first_step->setMaximumWidth(350);
    hint_first_step->setText("Щёлкни по тем предметам, которые ты хочешь изменить");

    QPushButton* next_step_button = new QPushButton();
    next_step_button->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    next_step_button->setText("Далее");

    working_area->addWidget(step_widget);
    working_area->addWidget(hint_first_step);
    working_area->addWidget(next_step_button);

    QVBoxLayout* general_shedule = new QVBoxLayout();

    for(int i = 0; i < 7; i++)                                                  // заполняем данными виджеты уроков
    {
        Week_Widget_View* current_week = new Week_Widget_View(i+1);

        general_shedule->addWidget(current_week);

        for (int j = 0; j < 7; ++j) {
            QHBoxLayout* time_and_subject_layout = new QHBoxLayout();

            // заполнение данными через функцию ядра
            Lesson* cur_lesson = new Lesson();
            Time_of_the_Lesson* cur_lesson_time = new Time_of_the_Lesson(i+1, j+1);

            // заполнение данными через функцию ядра

            time_and_subject_layout->addWidget(cur_lesson);
            time_and_subject_layout->addWidget(cur_lesson_time);

            general_shedule->addLayout(time_and_subject_layout);
        }
    }

    main_body->addLayout(working_area);
    main_body->addLayout(general_shedule);


}

MainWindow::~MainWindow()
{
}

