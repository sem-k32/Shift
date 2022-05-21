#include "group_name_input.h"

Group_Name_Input::Group_Name_Input(QWidget* ptr): QDialog(ptr)
{
    correct_input = false;
    activate_animation = false;
    group_name = "";

    setWindowTitle("Начало работы");
    setFixedSize(350, 190);

    QLabel* hint_text = new QLabel("Введите название группы:");
    hint_text->setStyleSheet("QLabel{font-size: 25px;}");

    warning_text = new QLabel("Некорректный ввод");
    warning_text->setStyleSheet("QLabel{font-size: 15px; font-style: italic; color: red;}");
    warning_text->setHidden(true);

    shrugged = new QPropertyAnimation(warning_text, "pos", this);

    input = new QLineEdit("Б05-007");
    input->setStyleSheet("QLineEdit{font-size: 15px; width: 180px; height: 25px; margin-top: 5px; margin-bottom: 5px;}");

    QPushButton* next_button = new QPushButton("Далее");
    next_button->setStyleSheet("QPushButton {font-size: 20px; width: 100px; height: 30px;}");

    QObject::connect(next_button, &QPushButton::clicked, this, &Group_Name_Input::validation_check);    // соединяем сигнал клика

    QVBoxLayout* lay = new QVBoxLayout();
    lay->addWidget(hint_text, 0, Qt::AlignCenter);
    lay->addWidget(warning_text, 0, Qt::AlignCenter);
    lay->addWidget(input, 0, Qt::AlignCenter);
    lay->addWidget(next_button, 0, Qt::AlignCenter);
    setLayout(lay);
}

Group_Name_Input::~Group_Name_Input()
{
}

bool Group_Name_Input::getState()
{
    return correct_input;
}

QString Group_Name_Input::get_group_name()
{
    return group_name;
}

void Group_Name_Input::validation_check()
{
    QString input_string = input->text();
    QRegExp validation("[БМ][0-9]{2}-[0-9]{3}");
    if(validation.exactMatch(input_string))
    {
        group_name = input_string;
        correct_input = true;

        accept();
    }
    else {
        if(!activate_animation)
        {
            warning_text->setHidden(false);
            activate_animation = true;
        }
        else {
            QPoint cur_pos = warning_text->pos();                                               // задаём параметры анимации
            shrugged->setStartValue(cur_pos);
            shrugged->setKeyValueAt(0.33, QPoint(cur_pos.x() + 10, cur_pos.y()));
            shrugged->setKeyValueAt(0.66, QPoint(cur_pos.x() - 10, cur_pos.y()));
            shrugged->setEndValue(cur_pos);
            shrugged->setDuration(1000);
            shrugged->setLoopCount(1);
            shrugged->setEasingCurve(QEasingCurve::OutExpo);
            shrugged->start();
        }
    }
}
