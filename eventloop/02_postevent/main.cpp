#include "postevent.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PostEvent w;
    w.show();

    return a.exec();
}
