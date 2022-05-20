#include "lesson.h"

//---------------------------Lesson-------------------------------------------

Lesson_View::Lesson_View(Lesson les, QWidget *parent) : QFrame(parent), lesson(les)
{
    isActive = false;
    isUnchangable = false;
    step_number = 1;

    setAutoFillBackground(true);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
    setWindowFlags(Qt::SplashScreen);                                   // для того, чтобы виджет не имел стандарной рамки оккошка

    resize(1000, 80);
    //setMaximumSize(1000, 80);

    QFontMetrics metrics(QFont("Franklin Gothic Book", 30));
    int min_width = metrics.width(les.lesson_name + " " + "(" + les.teacher + ", " + les.audience + ")");
    setMinimumSize(1.2*min_width, 80);

    setStyleSheet("QFrame {border-radius: 7px; background-color: " + lesson_background_color() + ";}");
}

void Lesson_View::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    p.setFont(QFont("Franklin Gothic Book", 28));

    p.drawText(QRect(0,0,this->width() / 2, this->height()), Qt::AlignRight | Qt::AlignVCenter, lesson.lesson_name + " ");

    p.setFont(QFont("Trebuchet MS", 24));

    p.drawText(QRect(this->width() / 2,0,this->width() / 2, this->height()),Qt::AlignVCenter | Qt::AlignLeft,
                                                                            "(" + lesson.teacher + ", " + lesson.audience + ")");
}

QSize Lesson_View::sizeHint() const
{
    QFontMetrics m1(QFont("Franklin Gothic Book", 30));
    QFontMetrics m2(QFont("Trebuchet MS", 24));

    int text_width = m1.width(lesson.lesson_name + " ") + m2.width("(" + lesson.teacher + " " + lesson.audience + ")");

    return QSize(1.2*text_width, 80);
}

void Lesson_View::mousePressEvent(QMouseEvent *ev)
{
    switch (step_number) {
    case 1:
        if(!isUnchangable)
        {
            isUnchangable = 1;

            this->setStyleSheet("QFrame {border-width: 5px;border-color: indigo; border-style: solid; "
"                                       border-radius: 7px; background-color: " + lesson_background_color() + ";}");

            emit clicked(isUnchangable, lesson.day, lesson.number);
        }
        else {
            isUnchangable = 0;

            this->setStyleSheet("QFrame {border-width: 0px; border-radius: 7px; "
"                                       background-color: " + lesson_background_color() + ";}");

            emit clicked(isUnchangable, lesson.day, lesson.number);
        }

        break;
    case 2:
        if(!isActive)                                   // была неактивна
        {
            isActive = 1;

            this->setStyleSheet("QFrame {border-width: 3px;border-color: red; border-radius: 7px;"
"                                        background-color: " + lesson_background_color() + ";}");

            emit clicked(isActive, lesson.day, lesson.number);
        }
        else {                                          // была активна
            isActive = 0;

            this->setStyleSheet("QFrame {border-width: 0px; border-radius: 7px;"
"                                        background-color: " + lesson_background_color() + ";}");

            emit clicked(isActive, lesson.day, lesson.number);
        }

        break;
    default:
        break;
    }

}

QString Lesson_View::lesson_background_color() const
{
    if(lesson.lesson_type == "sem")
    {
        return "#99ccff";
    }
    if(lesson.lesson_type == "lab")
    {
        return "#ffff99";
    }
    if(lesson.lesson_type == "lec")
    {
        return "#ff9999";
    }
}



//---------------------------Time_of_the_Lesson-------------------------------------------

Time_of_the_Lesson::Time_of_the_Lesson(int day, int number,QWidget *parent) : QWidget(parent)
{
    this->day_of_the_week = day;
    this->number_of_lesson = number;

    setAutoFillBackground(true);
    setWindowFlags(Qt::SplashScreen);
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed));

    resize(280, 80);
    setMaximumSize(280, 80);
    setMinimumSize(280,80);

    QPalette pal = this->palette();
    pal.setBrush(this->backgroundRole(), QBrush(QColor(204, 205, 204)));

    setPalette(pal);
    setStyleSheet("QFrame {boder-radius: 5px;}");
}

QSize Time_of_the_Lesson::sizeHint() const
{
    QFontMetrics metrics(QFont("Lucida Console", 20));

    return QSize(1.2 * metrics.width("10:10 - 10:10"), 80);
}

QString Time_of_the_Lesson::get_time_bounds() const
{
    switch (number_of_lesson) {
    case 1:
        return QString("9:00-10:25");
    case 2:
        return QString("10:45-12:10");
    case 3:
        return QString("12:20-13:45");
    case 4:
        return QString("13:55-15:20");
    case 5:
        return QString("15:30-16:55");
    case 6:
        return QString("17:05-18:30");
    case 7:
        return QString("18:35-20:00");
    default:
        break;
    }
}

void Time_of_the_Lesson::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    QFont f = QFont("Lucida Console", 20);

    p.setFont(f);

    QRect widget_rect = QRect(0, 0, this->width(), this->height() + 5);

    p.drawText(widget_rect, Qt::AlignVCenter | Qt::AlignHCenter, get_time_bounds());
}

//---------------------------Week_Widget_View-------------------------------------------

Week_Widget_View::Week_Widget_View(short day_number, QWidget *parent) : QFrame(parent), day_number(day_number)
{
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QFile styles(":/styles/StyleSheets/Week_Widget_View.qss");
    styles.open(QFile::ReadOnly);
    QString style_string = styles.readAll();
    setStyleSheet(style_string);

    QFontMetrics metrics(QFont("Franklin Gothic Book", 24));
    int min_width = metrics.width("Воскресенье");
    setMinimumWidth(1.2*min_width);
}

QSize Week_Widget_View::sizeHint() const
{
    return size();
}

void Week_Widget_View::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    p.setFont(QFont("Franklin Gothic Book", 30));

    p.drawText(this->rect(),Qt::AlignCenter, get_day_name());
}

QString Week_Widget_View::get_day_name()
{
    switch (day_number) {
    case 1:
        return "Понедельник";
        break;
    case 2:
        return "Вторник";
        break;
    case 3:
        return "Среда";
        break;
    case 4:
        return "Четверг";
        break;
    case 5:
        return "Пятница";
        break;
    case 6:
        return "Суббота";
        break;
    case 7:
        return "Воскресенье";
        break;
    }
}
