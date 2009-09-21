#include <QtGui/QApplication>
#include "mainwindow.h"
#include "logfile.h"
#include "logfilemodel.h"
#include "logitem.h"

#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication::setOrganizationName("Kramer-NET");
    QCoreApplication::setOrganizationDomain("Kramer-NET.de");
    QCoreApplication::setApplicationName("LogViewer");

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
