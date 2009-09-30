#ifndef LOGFILEVIEWWIDGET_H
#define LOGFILEVIEWWIDGET_H

#include <QtGui>
#include <QTableView>
#include <QSplitter>
#include "logfilemodel.h"
#include "logfileproxymodel.h"

namespace Ui {
    class LogFileViewWidget;
}


class LogFileViewWidget : public QWidget {
    Q_OBJECT
public:
    LogFileViewWidget(LogFileModel *_model = 0, QWidget *parent = 0);
    ~LogFileViewWidget();

public slots:

    void addLogFile(LogFile* _LogFile);     //Dient zum laden einer Weiteren Datei in den View
    void delLogFile(LogFile* _LogFile);     //Löscht ein File aus dem View
    void loadLogFile(QString LogName);      //Function dien zum laden von LogFile mit hilfe eine Chain
    LogFileModel* getLogFileModel();        //gibt LogFileModel zurück
    void loadNextLogFile();                 //stösst nächstes zu ladende LogFile an
    QString getStatusMessage();             //Liefert StatusMessage mit Anzahl der LogItems und so ..

signals:

    void changeData();

protected:

    QStringList waitingChain;               //Container mit noch zu ladenen LogFiles
    LogFile* currentLoadingFile;            //Pointer auf ein LogFile das gerade geladen wird;

    QSettings       settings;               //Dient zum laden von Settings

    LogFileModel           *model;
    LogFileProxyModel *proxymodel;
    QSortFilterProxyModel *filterproxy;

    void loadColumnWidth();                 //läd Zeilenbreite aus der in der Regestry
    void saveColumnWidth();                 //speichert Zeilenbreite in der Regestry

    QTableView *top;
    QTableView *botton;
    QTreeView  *proxyView;

    QSplitter *split;

    QGridLayout *grid;

    void changeEvent(QEvent *e);

private:
    Ui::LogFileViewWidget *m_ui;
};

#endif // LOGFILEVIEWWIDGET_H
