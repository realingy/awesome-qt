#include "postevent.h"
#include <QEvent>
#include <QDebug>
#include <QApplication>
#include <QTime>

int count = 0;
QEvent::Type NewType;

/*!
 * 使用postEvent异步分发事件
 * 连续分发10个事件，在事件处理函数中逐个处理
 */
PostEvent::PostEvent(QWidget *parent)
    : QWidget(parent)
{
    int i = 1;
    while(i <= 10)
    {
        //postEvent传递的事件必须是通过new创建的
        qDebug() << "分发第" << i << "个事件";
        QApplication::postEvent(this, new QEvent(NewType));
        i++;
    }
}

PostEvent::~PostEvent()
{

}

/*
void PostEvent::customEvent(QEvent *event)
{
    //使用延时模拟处理过程
    if(event->type() == NewType)
    {
        qDebug() << "现在时间:" <<
                    QTime::currentTime().toString("hh::mm:ss.zzz");
        qDebug() << "第" << ++count << "次收到了事件！处理事件需要一点时间！";
        delay(1000*2);
    }

    QWidget::customEvent(event);
}
*/

bool PostEvent::event(QEvent *e)
{
    //使用延时模拟处理过程
    if(e->type() == NewType)
    {
        qDebug() << "现在时间:" <<
                    QTime::currentTime().toString("hh::mm:ss.zzz");
        qDebug() << "第" << ++count << "次收到了事件！处理事件需要一点时间！";
        delay(1000*2);
    }

    return QWidget::event(e);
}

void PostEvent::delay(int msec)
{
    QTime start = QTime::currentTime();

    QTime end;
    do{
        end = QTime::currentTime();
    } while(start.msecsTo(end) <= msec);
}
