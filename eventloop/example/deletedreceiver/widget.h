#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void slotSendEvent();
    void deleteLabel();

private:
    Ui::Widget *ui;

    QLabel *m_label;

};

#endif // WIDGET_H
