#include "newapplication.h"
#include <QMouseEvent>
#include <QDebug>

bool NewApplication::notify(QObject *receiver, QEvent *event)
{
    if(event->type() == QMouseEvent::MouseButtonPress)
    {
        qDebug() << "sorry everybody I gonna filter all the mouse press event";
        return false;
    }
    else
        return QApplication::notify(receiver,event);
}
