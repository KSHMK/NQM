#include "mainwindow.h"
#include <QApplication>
#include <unistd.h>

int main(int argc, char *argv[])
{
    setuid(0);
    setgid(0);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
