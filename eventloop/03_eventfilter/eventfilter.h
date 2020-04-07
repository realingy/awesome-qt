#ifndef EVENTFILTER_H
#define EVENTFILTER_H

#include <QMainWindow>

namespace Ui {
class EventFilter;
}

class EventFilter : public QMainWindow
{
    Q_OBJECT

public:
    explicit EventFilter(QWidget *parent = 0);
    ~EventFilter();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private:
    Ui::EventFilter *ui;
};

#endif // EVENTFILTER_H
