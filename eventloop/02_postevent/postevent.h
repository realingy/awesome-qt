#ifndef POSTEVENT_H
#define POSTEVENT_H

#include <QWidget>

class QEvent;

class PostEvent : public QWidget
{
    Q_OBJECT

public:
    PostEvent(QWidget *parent = 0);
    ~PostEvent();

protected:
    //void customEvent(QEvent *event);
    bool event(QEvent *e);

private:
    void delay(int msec);

};

#endif // POSTEVENT_H
