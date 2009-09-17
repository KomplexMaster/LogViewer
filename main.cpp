#include <QtGui/QApplication>
#include "mainwindow.h"
#include "logfile.h"
#include "logfilemodel.h"
#include "logitem.h"

#include <iostream>

static int test = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
