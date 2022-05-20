#ifndef LESSON_H
#define LESSON_H

#include <QtWidgets>

class Lesson{                                               // класс для урока
public:
    Lesson(QString teacher, QString lesson_name, QString lesson_type, QString audience, int day, int num) : teacher(teacher), lesson_name(lesson_name),
        lesson_type(lesson_type), audience(audience), day(day), number(num)
    {}
    ~Lesson() = default;

    QString teacher;                                        // параметры урока
    QString lesson_name;
    QString lesson_type;
    QString audience;
    int day;                                                // день недели урока и номер пары
    int number;
};

class Lesson_View : public QFrame                           // виджет строки урока
{
    Q_OBJECT
public:
    explicit Lesson_View(Lesson les, QWidget *parent = nullptr);

    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent* ev) override;              // отображение строки

    void mousePressEvent(QMouseEvent* ev) override;         // по щелчку добавляем урок в список на замену/ в список неизменяемых
                                                            // (отправка сигнала)

private:
    Lesson lesson;                                          // урок, соответствующий отображению

    short step_number;                                      // номер шага; нужен для правильного поведения при клике

    bool isUnchangable;                                     // флаг, является ли данный урок неизменяемым для студента
    bool isActive;                                          // флаг, отвечающий за то, выбран ли данный урок на замену или нет

    QString lesson_background_color() const;                 // разный цвет в зависимости от типа урока

signals:
    void clicked(bool newState, int day, int num);
};

class Time_of_the_Lesson: public QWidget                    // виджет времени урока
{
    Q_OBJECT
public:
    explicit Time_of_the_Lesson(int day, int number,QWidget *parent = nullptr);

    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent* ev) override;          // отображение времени на видджете
private:
    int day_of_the_week;                                // параметры времени пары
    int number_of_lesson;

    QString get_time_bounds() const;                    // метод для удобства перевода между временем и индексами

signals:

};

class Week_Widget_View: public QFrame                    // виджет дня недели
{
    Q_OBJECT
public:
    explicit Week_Widget_View(short day_number,QWidget *parent = nullptr);

    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent* ev) override;          // отображение дня недели на виджете
private:
    short day_number;
    QString get_day_name();                             // по номеру дня текстовое название

signals:

};

#endif // LESSON_H
