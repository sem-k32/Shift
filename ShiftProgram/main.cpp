#include "group_name_input.h"
#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Group_Name_Input* group_input = new Group_Name_Input();

    if(group_input->exec() == QDialog::Accepted)
    {
        group_input->hide();
    }
    else {
        a.exit(-1);
    }

    QString group_name = group_input->get_group_name();
    delete group_input;

    MainWindow* main_window = new MainWindow(group_name);

    QScrollArea main_window_view;
    main_window_view.setMinimumWidth(1400);
    main_window_view.setMinimumHeight(400);
    main_window_view.resize(1400, 800);
    main_window_view.setWidgetResizable(true);
    main_window_view.setWidget(main_window);

    main_window_view.show();

    return a.exec();
}
