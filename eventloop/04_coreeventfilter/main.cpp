#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //试试去掉以下两行代码
    Filter filter;
    a.installEventFilter(&filter); //给QCoreApplication安装了一个事件过滤器，过滤掉所有的鼠标点击事件，所以不再发布某些事件，窗口不再接收到相应的事件

    Widget w;
    w.show();

    return a.exec();
}
