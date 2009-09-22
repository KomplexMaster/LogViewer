#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "logfile.h"
#include "logfilemodel.h"
#include "logfileviewwidget.h"
#include "LogItemParserDialog.h"

namespace Ui
{
    class MainWindowClass;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindowClass *ui;
    LogFile *test;
    LogFileModel *model;

    QList<LogFile*> LogFiles;

    QList<QFile> FileList;          //Lieste mit offenen Dateien

    LogItemParserDialog* lpd;

    LogFileViewWidgetIndexBar* bar;

private slots:
    void on_actionFilterEditor_toggled(bool );
    void on_actionOpen_triggered();
    void on_actionExit_triggered();

    LogFile* loadLogFile(QFile* _file);

    void addLogFile(LogFile* _log);

    void refreshLogFileList(void);

    void selectLogFile(QModelIndex);

    void refresh();

    void setCount();
    void leftclick(QModelIndex index);

    void setFilterColor();
};

#endif // MAINWINDOW_H
