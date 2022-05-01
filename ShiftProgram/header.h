#ifndef HEADER_H
#define HEADER_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>
#include <QPainter>

class Back_button : public QWidget
{
    Q_OBJECT
public:
    explicit Back_button(QWidget *parent = nullptr);

    virtual QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent* ev) override;
private:
    int current_stage;

signals:

};

class Program_name_widget : public QWidget
{
    Q_OBJECT
public:
    explicit Program_name_widget(QWidget *parent = nullptr);

    virtual QSize sizeHint() const override;
protected:
    void paintEvent(QPaintEvent *event) override;

};


#endif // HEADER_H
