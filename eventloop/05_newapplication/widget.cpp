#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "I am mainwindow Widget, I got a mouse event!";

    QWidget::mousePressEvent(event);
}

void Widget::on_pushButton_clicked()
{
    qDebug() << "I am push button , I got a mouse event!";
}
