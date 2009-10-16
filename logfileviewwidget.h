#ifndef LOGFILEVIEWWIDGET_H
#define LOGFILEVIEWWIDGET_H

#include <QtGui>
#include <QTreeView>
#include <QSplitter>
#include "logfileproxymodel.h"
#include "logfileviewtindexbar.h"
#include "logfilefiltermodel.h"

namespace Ui {
    class LogFileViewWidget;
}


class LogFileJar;

class LogFileViewWidget : public QWidget {
    Q_OBJECT
public:
    LogFileViewWidget(QWidget *parent = 0);
    ~LogFileViewWidget();

public slots:

    QString getStatusMessage();             //Liefert StatusMessage mit Anzahl der LogItems und so ..
    void loadLogFile(QString FileName);
    LogFileJar* getJar(void);

    LogFileFilterModel* getFilterModel(void);

    void moveToSelectedItem(QModelIndex);
    void isProgress(bool);

signals:

    void changeData();

protected:

    QStringList waitingChain;               //Container mit noch zu ladenen LogFiles
    LogFile* currentLoadingFile;            //Pointer auf ein LogFile das gerade geladen wird;

    QSettings       settings;               //Dient zum laden von Settings

    LogFileModel           *itemmodel;
    LogFileModel           *itemfilteredmodel;
    LogFileFilterModel     *filtermodel;

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
