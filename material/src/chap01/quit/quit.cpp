#include <QApplication>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QLabel *label = new QLabel();
    label->resize(QSize(500, 250));
    label->show();

    //QPushButton *button = new QPushButton("Quit");
    QPushButton *button = new QPushButton(label); //将label作为button的父窗口
    button->setText("quit");
    QObject::connect(button, SIGNAL(clicked()),
                     &app, SLOT(quit())); //连接信号槽
    button->show();

    return app.exec();
}
