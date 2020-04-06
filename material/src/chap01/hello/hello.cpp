#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv); //QApplication类用于管理应用程序的所有资源，需要传入main入口函数的两个命令行参数。
    QLabel *label = new QLabel("Hello Qt!"); //QLabel窗口部件（widget），作为主程序的窗口。

    label->resize(QSize(500, 250));
    label->show(); //部件创建的时候，默认是隐藏的，通过成员函数才可以手动的将其显示出来。

    return app.exec(); //将应用程序的控制权交还给Qt，此时就开始了Qt的事件循环。这是一种的等待模式，程序会等待用户的动作，
    // 例如鼠标和按键动作，用户的动作会被Qt转换成事件（event）。

    // Qlabel对象在程序结束的时候没有手动的进行资源回收，造成内存泄漏，但是这种小的泄露一般都在可忍受范围内
    delete label;
}
