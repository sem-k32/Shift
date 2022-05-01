#include "lesson.h"

//---------------------------Lesson-------------------------------------------

Lesson::Lesson(QString teacher, QString lesson_name, QString lesson_type,
               QString audience, QWidget *parent) : QFrame(parent), teacher(teacher), lesson_name(lesson_name),
                                                    lesson_type(lesson_type), audience(audience)
{
    isActive = 0;

    setWindowFlags(Qt::SplashScreen);                                   // для того, чтобы виджет не имел стандарной рамки оккошка

    setMaximumSize(1000, 50);

    QPalette pal;
    pal.setBrush(QPalette::Window,QBrush(lesson_background_color()));

    setPalette(pal);
}

void Lesson::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    QFontMetrics m1(QFont("Franklin Gothic Book", 30));
    QFontMetrics m2(QFont("Trebuchet MS", 24));                                 // берём длину и ширину  итоговой строки

    int text_height = m1.height();
    int text_width = m1.width(lesson_name + " ") + m2.width("(" + teacher + " " + audience + ")");

    p.setFont(QFont("Franklin Gothic Book", 30));

    int x_draw_lesson_name = this->width() / 2 - text_width / 2;
    int y_draw_lesson_name = this->height() / 2 + text_height / 2;

    p.drawText(x_draw_lesson_name, y_draw_lesson_name, lesson_name + " ");

    p.setFont(QFont("Trebuchet MS", 24));

    int x_draw_add_info = x_draw_lesson_name + m1.width(lesson_name + " ");
    int y_draw_add_info = y_draw_lesson_name;

    p.drawText(x_draw_add_info, y_draw_add_info, "(" + teacher + " " + audience + ")");
}

QSize Lesson::sizeHint() const
{
    QFontMetrics m1(QFont("Franklin Gothic Book", 30));
    QFontMetrics m2(QFont("Trebuchet MS", 24));

    int text_height = m1.height();
    int text_width = m1.width(lesson_name + " ") + m2.width("(" + teacher + " " + audience + ")");

    return QSize(text_width, text_height);
}

QSizePolicy Lesson::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
}

void Lesson::mousePressEvent(QMouseEvent *ev)
{
    if(!isActive)                                   // была неактивна
    {
        isActive = 1;

        this->setStyleSheet("QWidget {border-width: 3px;border-color: red}");

        emit clicked(isActive);
    }
    else {                                          // была активна
        isActive = 0;

        this->setStyleSheet("QWidget {border-width: 0px;}");

        emit clicked(isActive);
    }
}

QColor Lesson::lesson_background_color() const
{
    if(lesson_type == "sem")
    {
        return QColor("#99ccff");
    }
    if(lesson_type == "lab")
    {
        return QColor("#ffff99");
    }
    if(lesson_type == "lec")
    {
        return QColor("#ff9999");
    }
}



//---------------------------Time_of_the_Lesson-------------------------------------------

Time_of_the_Lesson::Time_of_the_Lesson(int day, int number,QWidget *parent) : QWidget(parent)
{
    this->day_of_the_week = day;
    this->number_of_lesson = number;

    setWindowFlags(Qt::SplashScreen);

    setMaximumSize(150, 55);

    QPalette pal;
    pal.setBrush(QPalette::Base, QBrush(QColor(204, 205, 204)));

    setPalette(pal);
}

QSizePolicy Time_of_the_Lesson::sizePolicy() const
{
    return QSizePolicy(QSizePolicy::Preferred,QSizePolicy::Preferred);
}

QSize Time_of_the_Lesson::sizeHint() const
{
    QFontMetrics metrics(QFont("Lucida Console", 18));

    return QSize(1.2 * metrics.width("10:10 - 10:10"),1.2 * metrics.height());
}

QString Time_of_the_Lesson::get_time_bounds() const
{
    switch (number_of_lesson) {
    case 0:
        return QString("9:00 - 10:25");
    case 1:
        return QString("10:45 - 12:10");
    case 2:
        return QString("12:20 - 13:45");
    case 3:
        return QString("13:55 - 15:20");
    case 4:
        return QString("15:30 - 16:55");
    case 5:
        return QString("17:05 - 18:30");
    case 6:
        return QString("18:35 - 20:00");
    default:
        break;
    }
}

void Time_of_the_Lesson::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    QFont f = QFont("Lucida Console", 18);

    p.setFont(f);

    QRect widget_rect = this->rect();

    p.drawText(widget_rect, Qt::AlignCenter, get_time_bounds());
}
