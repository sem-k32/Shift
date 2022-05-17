#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow* main_window = new MainWindow();

    QScrollArea main_window_view;
    main_window_view.setMinimumWidth(1400);
    main_window_view.setMinimumHeight(400);
    main_window_view.setWidgetResizable(true);
    main_window_view.setWidget(main_window);

    main_window_view.show();

    return a.exec();
}
