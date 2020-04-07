#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class QMouseEvent;
class QObject;

namespace Ui {
class Widget;
}

class Filter : public QObject
{
public:
    explicit Filter() {}
    ~Filter() {}

protected:
    bool eventFilter(QObject *obj, QEvent *event);
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    void mousePressEvent(QMouseEvent *event);

private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
