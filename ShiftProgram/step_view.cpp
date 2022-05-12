#include "step_view.h"

Step_View::Step_View()
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    step_number = 1;
    QString message = "Шаг " + QString::number(step_number);
    setText(message);
}
