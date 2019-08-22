#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QTextCodec>
#include <QString>
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_pNetMan = new QNetworkAccessManager;
    connect(m_pNetMan,SIGNAL(finished(QNetworkReply*)),
                    this,SLOT(replyFinished(QNetworkReply*)));
    m_pNetMan->get(QNetworkRequest(QUrl("http://www.baidu.com")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QTextCodec *codec = QTextCodec::codecForName("utf8");
    QString all = codec->toUnicode(reply->readAll());
    ui->textBrowser->setText(all);
    reply->deleteLater();
}

