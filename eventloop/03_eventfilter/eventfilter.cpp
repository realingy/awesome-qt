#include "eventfilter.h"
#include "ui_eventfilter.h"
#include <QEvent>
#include <QKeyEvent>

EventFilter::EventFilter(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::EventFilter)
{
    ui->setupUi(this);

    ui->lineEdit_user->setText(QString("lee"));
    focusNextChild();
    ui->lineEdit_password->setText(QString("*******"));

    //监听控件
    ui->lineEdit_user->installEventFilter(this);
    ui->lineEdit_password->installEventFilter(this);
    ui->button_accept->installEventFilter(this);
    ui->button_cancel->installEventFilter(this);
}

EventFilter::~EventFilter()
{
    delete ui;
}

bool EventFilter::eventFilter(QObject *watched, QEvent *event)
{
    //定义事件处理动作
    if (watched == ui->lineEdit_user || watched == ui->lineEdit_password
        || watched == ui->button_accept || watched == ui->button_cancel)
    {
        if (event->type() == QEvent::KeyPress)
        {
            QKeyEvent *e = static_cast<QKeyEvent *>(event);
            if(e->key() == Qt::Key_Space)
            {
                focusNextChild();
                return true;
            }
        }
    }
    return QWidget::eventFilter(watched, event);
}
