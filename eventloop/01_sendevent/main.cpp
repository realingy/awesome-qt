#include "sendevent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SendEvent w;
    w.show();

    return a.exec();
}
