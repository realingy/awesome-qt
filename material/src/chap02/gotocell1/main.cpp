#include <QApplication>
#include <QDialog>

#include "ui_gotocelldialog.h"

#include <iostream>

int i = 12;

int main(int argc, char *argv[])
{
#if 0
    int i = i;
    std::cout << "i = " << i << std::endl;
    return 0;
#endif

#if 1
    QApplication app(argc, argv);

    Ui::GoToCellDialog ui;
    QDialog *dialog = new QDialog;
    ui.setupUi(dialog);
    dialog->show();

    return app.exec();
#endif

}
