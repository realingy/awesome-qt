#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QHostInfo>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString localHostName = QHostInfo::localHostName();
    ui->label->setText(localHostName);

    QHostInfo info = QHostInfo::fromName(localHostName);
    qDebug()<<"IP address:"<<info.addresses();
}

Widget::~Widget()
{
    delete ui;
}
