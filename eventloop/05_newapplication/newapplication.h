#ifndef NEWAPPLICATION_H
#define NEWAPPLICATION_H

#include <QApplication>

class NewApplication : public QApplication
{
public:
    NewApplication(int argc, char **argv) : QApplication(argc,argv) {}

    virtual bool notify(QObject *, QEvent *);

};

#endif // NEWAPPLICATION_H
