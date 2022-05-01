#ifndef LESSON_H
#define LESSON_H

#include <QtWidgets>

class Lesson : public QFrame
{
    Q_OBJECT
public:
    explicit Lesson(QString teacher, QString lesson_name, QString lesson_type, QString audience, QWidget *parent = nullptr);

    QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent* ev) override;              // отображение строки

    void mousePressEvent(QMouseEvent* ev) override;         // по щелчку добавляем урок в список на замену (отправка сигнала)

private:
    QString teacher;                                        // параметры урока
    QString lesson_name;
    QString lesson_type;
    QString audience;

    bool isActive;                                          // флаг, отвечающий за то, выбран ли данный урок на замену или нет

    QColor lesson_background_color() const;                 // разный цвет в зависимости от типа урока

signals:
    void clicked(bool newState);
};

class Time_of_the_Lesson: public QWidget
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

#endif // LESSON_H
