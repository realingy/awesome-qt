#include "sendevent.h"
#include "ui_sendevent.h"
#include <QKeyEvent>

SendEvent::SendEvent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SendEvent)
{
    ui->setupUi(this);
}

SendEvent::~SendEvent()
{
    delete ui;
}

void SendEvent::on_pb_bs_clicked()
{
    int  key = Qt::Key_Backspace; //

    QKeyEvent EventPress(QEvent::KeyPress, key, Qt::NoModifier);
    QApplication::sendEvent(ui->textEdit, &EventPress);

    QKeyEvent EventRelease(QEvent::KeyRelease, key, Qt::NoModifier);
    QApplication::sendEvent(ui->textEdit, &EventRelease);
}

void SendEvent::on_pb_del_clicked()
{
    int  key = Qt::Key_Delete; //

    QKeyEvent EventPress(QEvent::KeyPress, key, Qt::NoModifier);
    QApplication::sendEvent(ui->textEdit, &EventPress);

    QKeyEvent EventRelease(QEvent::KeyRelease, key, Qt::NoModifier);
    QApplication::sendEvent(ui->textEdit, &EventRelease);
}
