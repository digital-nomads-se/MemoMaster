#include "headers/mainwindow.h"
#include "headers/notemainwindow.h"
#include "headers/todomainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
