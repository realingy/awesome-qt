#include "widget.h"
#include "ui_widget.h"
#include <QByteArray>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    m_pSender = new QUdpSocket(this);

}

Widget::~Widget()
{
    delete ui;
}

//start broadcast
void Widget::on_pushButton_clicked()
{
    QByteArray datagram = "hello world!";
    m_pSender->writeDatagram(datagram.data(),datagram.size(),
                             QHostAddress::Broadcast,45454);

}
