#include "widget.h"

MainWindow::MainWindow(QString group_number, QWidget *parent)
    : QFrame(parent)
{
    setAutoFillBackground(true);
    setWindowFlags(Qt::SplashScreen);

    //задаю логику layouts
    QVBoxLayout* main_layer = new QVBoxLayout();

    QHBoxLayout* header_layout = new QHBoxLayout();                     // нетехнический слой
    Back_button* back_button = new Back_button();
    Program_name_widget* prog_name_widg = new Program_name_widget();
    header_layout->addWidget(back_button);
    header_layout->addWidget(prog_name_widg);

    QHBoxLayout* main_body = new QHBoxLayout();

    main_layer->addLayout(header_layout);
    main_layer->addSpacing(10);
    main_layer->addLayout(main_body);
    main_layer->addStretch(1000);

    QVBoxLayout* working_area = new QVBoxLayout();                      // нетехнический слой

    Step_View* step_widget = new Step_View();                           // создаём виджета показа шага, пояснительную надпись и кнопку
    step_widget->setStyleSheet("QLabel{font-family: 'Sylfaen'; font-size: 30px;}");
                                                                        // "далее"
    QLabel* hint_first_step = new QLabel();
    hint_first_step->setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding));
    hint_first_step->setMinimumWidth(280);
    hint_first_step->setMaximumWidth(350);
    hint_first_step->setMaximumHeight(100);
    hint_first_step->setStyleSheet("QLabel{font-family: 'Sylfaen'; font-size: 24px;}");
    hint_first_step->setWordWrap(true);
    hint_first_step->setAlignment(Qt::AlignCenter);
    hint_first_step->setText("Щёлкни по тем предметам, которые ты не хочешь менять");

    QPushButton* next_step_button = new QPushButton();
    next_step_button->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    next_step_button->setStyleSheet("QPushButton{font-family: 'Franklin Gothic Medium'; font-size: 24px;}");
    next_step_button->setText("Далее");

    working_area->addWidget(step_widget);
    working_area->addWidget(hint_first_step);
    working_area->addWidget(next_step_button, 0, Qt::AlignCenter);
    working_area->addStretch(1000);

    QVBoxLayout* general_shedule = new QVBoxLayout();

    for(int i = 0; i < 7; i++)                                                  // заполняем данными виджеты уроков
    {
        Week_Widget_View* current_week = new Week_Widget_View(i+1);

        general_shedule->addWidget(current_week);

        for (int j = 0; j < 7; ++j) {
            QHBoxLayout* time_and_subject_layout = new QHBoxLayout();

            // заполнение данными через функцию ядра (пока нет)
            Lesson_View* cur_lesson;

            if(j % 3 == 0)
            {
                cur_lesson = new Lesson_View(Lesson("Teacher", "Lesson name", "sem", "321", i+1, j+1));
            }
            else if(j % 3 == 1)
            {
                cur_lesson = new Lesson_View(Lesson("Teacher", "Lab name", "lab", "132", i+1, j+1));
            }
            else {
                cur_lesson = new Lesson_View(Lesson("Teacher", "Lecture name", "lec", "213", i+1, j+1));
            }

            Time_of_the_Lesson* cur_lesson_time = new Time_of_the_Lesson(i+1, j+1);

            // соединение сигналов для MainWindow
            QObject::connect(cur_lesson, &Lesson_View::clicked_unchangable, this, &MainWindow::manage_unchanching_list);

            time_and_subject_layout->addWidget(cur_lesson_time);
            time_and_subject_layout->addWidget(cur_lesson);

            general_shedule->addLayout(time_and_subject_layout);
        }
    }

    main_body->addLayout(working_area);
    main_body->addLayout(general_shedule);

    setLayout(main_layer);
}

MainWindow::~MainWindow()
{
}

void MainWindow::manage_unchanching_list(int day, int num)
{
    if(unchanging_lessons.count(std::make_pair(day, num)))
    {
        unchanging_lessons.erase(std::make_pair(day, num));
    }
    else {
        unchanging_lessons.insert(std::make_pair(day, num));
    }
}

