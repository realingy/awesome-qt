#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileInfo>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_pNetworkMan = new QNetworkAccessManager;
    //ui->progressBar->hide();
    ui->progressBar->setVisible(false);
}

void MainWindow::startRequest(QUrl url)
{
    m_pReply = m_pNetworkMan->get(QNetworkRequest(url));
    connect(m_pReply,SIGNAL(readyRead()),
                        this,SLOT(httpReadyRead()));

    connect(m_pReply,SIGNAL(downloadProgress(qint64,qint64)),
                        this,SLOT(updateDataReadProgress(qint64,qint64)));
    connect(m_pReply,SIGNAL(finished()),this,SLOT(httpFinished()));

}

void MainWindow::httpFinished()
{
    ui->progressBar->setVisible(false);
    m_pFile->flush();
    m_pFile->close();
    m_pReply->deleteLater();
    m_pReply = 0;
    delete m_pFile;
    m_pFile = 0;
}

void MainWindow::httpReadyRead()
{
    if(m_pFile)
        m_pFile->write(m_pReply->readAll());
}

void MainWindow::updateDataReadProgress(qint64 bytesRead,
                                        qint64 totalBytes)
{
    ui->progressBar->setMaximum(totalBytes);
    ui->progressBar->setValue(bytesRead);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    url = ui->lineEdit->text();
    QFileInfo info(url.path());
    QString fileName(info.fileName());

    if(fileName.isEmpty())
        fileName = "index.html";
    m_pFile = new QFile(fileName);
    if(m_pFile->open(QIODevice::WriteOnly))
    {
        qDebug()<<"file open error";
        delete m_pFile;
        m_pFile = 0;
        return;
    }
    startRequest(url);
    ui->progressBar->setValue(0);
    ui->progressBar->show();

}
