#ifndef NEWMOUSEEVENT_H
#define NEWMOUSEEVENT_H

#include <QEvent>
#include <QString>

class NewMouseEvent : public QEvent
{
public:
    explicit NewMouseEvent() :  QEvent(MouseTenClick) {}
    const static Type MouseTenClick = static_cast<Type>(QEvent::User+0x10); //一种新的事件类型
};

#endif // NEWMOUSEEVENT_H
