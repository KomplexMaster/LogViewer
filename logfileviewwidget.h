#ifndef LOGFILEVIEWWIDGET_H
#define LOGFILEVIEWWIDGET_H

#include <QtGui>
#include <QTreeView>
#include <QSplitter>
#include "logfileproxymodel.h"
#include "logfileviewtindexbar.h"

namespace Ui {
    class LogFileViewWidget;
}


class LogFileJar;

class LogFileViewWidget : public QWidget {
    Q_OBJECT
public:
    LogFileViewWidget(QWidget *parent = 0);
    ~LogFileViewWidget();

    LogFileJar* getJar();

public slots:

    //LogFileModel* getLogFileModel();        //gibt LogFileModel zurück
    //void loadNextLogFile();                 //stösst nächstes zu ladende LogFile an
    QString getStatusMessage();             //Liefert StatusMessage mit Anzahl der LogItems und so ..
    void loadLogFile(QString FileName);

signals:

    void changeData();

protected:

    QStringList waitingChain;               //Container mit noch zu ladenen LogFiles
    LogFile* currentLoadingFile;            //Pointer auf ein LogFile das gerade geladen wird;

    QSettings       settings;               //Dient zum laden von Settings

    LogFileModel           *model;
    //LogFileProxyModel *proxymodel;
    //QSortFilterProxyModel *filterproxy;

    void loadColumnWidth();                 //läd Zeilenbreite aus der in der Regestry
    void saveColumnWidth();                 //speichert Zeilenbreite in der Regestry

    LogFileViewtIndexBar *bar;

    QTreeView  *top;
    QTreeView  *botton;

    QSplitter *split;
    QGridLayout *grid;

    void changeEvent(QEvent *e);

    LogFileJar* jar;
private:
    Ui::LogFileViewWidget *m_ui;
};

#endif // LOGFILEVIEWWIDGET_H
