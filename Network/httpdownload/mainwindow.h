#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QFile>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void startRequest(QUrl url); //apply a link

private slots:
    void httpFinished();
    void httpReadyRead();
    void updateDataReadProgress(qint64,qint64);

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager	*	m_pNetworkMan;
    QNetworkReply			*	m_pReply;
    QUrl						url;
    QFile					*	m_pFile;


};

#endif // MAINWINDOW_H
