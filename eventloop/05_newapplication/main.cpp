#include "widget.h"
#include "newapplication.h"

//运行结果：点击界面的任意位置，事件都被qApp过滤。
int main(int argc, char *argv[])
{
    NewApplication a(argc, argv);

    Widget w;
    w.show();

    return a.exec();
}
