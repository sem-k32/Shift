#include "header.h"

//------------------------------------Back_button-----------------------------------

Back_button::Back_button(QWidget* parent): QWidget(parent)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
    resize(70, 50);

    setWindowFlags(Qt::SplashScreen);
    setCursor(QCursor(Qt::PointingHandCursor));
    this->setAutoFillBackground(true);
}

QSize Back_button::sizeHint() const
{
    return QSize(70,50);
}

void Back_button::paintEvent(QPaintEvent *ev)
{
    QPainter p(this);

    QPixmap background_image = QPixmap(":/img/images/back-icon.png");
    background_image = background_image.scaled(70,50);

    p.drawPixmap(0,0,background_image);
}

//------------------------------------Program_name_widget-----------------------------------

Program_name_widget::Program_name_widget(QWidget* parent): QWidget(parent)
{
    setSizePolicy(QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed));
    setWindowFlags(Qt::SplashScreen);
}

QSize Program_name_widget::sizeHint() const
{
    return QSize(this->width(), 65);
}

void Program_name_widget::paintEvent(QPaintEvent* ev)
{
    QPainter p(this);

    QFont f = QFont("SWMono", 48);

    p.setFont(f);

    QRect widget_rect = this->rect();

    p.drawText(widget_rect, Qt::AlignCenter, "SHIFT");
}
