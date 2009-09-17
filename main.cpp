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

    QPixmap pixmap(":/img/splash");

    qDebug() << test;

    test++;

    QSplashScreen splash(pixmap);

    MainWindow w;

    w.show();
    //splash.show();

    splash.showMessage("Loaded modules"+QString::number(test));

    return a.exec();
}
