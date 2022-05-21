#ifndef GROUP_NAME_INPUT_H
#define GROUP_NAME_INPUT_H

#include <QFrame>
#include <QtWidgets>

class Group_Name_Input : public QDialog
{
    Q_OBJECT
public:
    Group_Name_Input(QWidget* ptr = nullptr);
    ~Group_Name_Input();

    bool getState();                    // возвращает флаг корректности ввода
    QString get_group_name();           // возвращает имя группы
private:
    bool activate_animation;            // запускаем анимацию, если ввод неверен более одного раза
    QPropertyAnimation* shrugged;       // наша анимация
    bool correct_input;                 // флаг корректности ввода, имя группы и указатель на поле ввода для извлечения текста из него
    QString group_name;
    QLineEdit* input;
    QLabel* warning_text;               // отображение подсказки об некорректности ввода

    void validation_check();            // проверка корректности ввода после щелчка мыши
};

#endif // GROUP_NAME_INPUT_H
