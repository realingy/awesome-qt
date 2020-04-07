#ifndef SENDEVENT_H
#define SENDEVENT_H

#include <QWidget>

namespace Ui {
class SendEvent;
}

class SendEvent : public QWidget
{
    Q_OBJECT

public:
    explicit SendEvent(QWidget *parent = 0);
    ~SendEvent();

private slots:
    void on_pb_bs_clicked();

    void on_pb_del_clicked();

private:
    Ui::SendEvent *ui;
};

#endif // SENDEVENT_H
