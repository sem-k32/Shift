#ifndef STEP_VIEW_H
#define STEP_VIEW_H

#include <QtWidgets>

class Step_View : public QLabel
{
    Q_OBJECT
public:
    Step_View();
protected:

private:
    short step_number;                  // номер текущего шага

public slots:

};

#endif // STEP_VIEW_H
