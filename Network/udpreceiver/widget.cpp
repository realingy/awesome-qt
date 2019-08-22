#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    m_pReceiver = new QUdpSocket(this);
    m_pReceiver->bind(45454,QUdpSocket::ShareAddress);
    connect(m_pReceiver,SIGNAL(readyRead()),
                this,SLOT(progressPendingDatagram()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::progressPendingDatagram()
{
    while(m_pReceiver->hasPendingDatagrams())
    {
        QByteArray datagram;
        datagram.resize(m_pReceiver->pendingDatagramSize());
        m_pReceiver->readDatagram(datagram.data(),datagram.size());
        ui->label->setText(datagram);
    }
}
