#ifndef LOGFILEMODEL_H
#define LOGFILEMODEL_H

#include <QAbstractListModel>

#include "logfile.h"

class LogFileModel : public QAbstractTableModel
{
    Q_OBJECT

protected:
    QList<LogFile*>                         *LogFiles;


    LogItemList                        FilterLogItems;
    LogItemList                              LogItems;

    QList<LogFileFilter>               LogFileFilters;          //Liste mit allen Filtern die angewand werden

public:

    //***Filter
    QList<LogFileFilter>* getFilters();             //Liefert Liste mit allen Filtern zurück
    void addFilter(LogFileFilter _LogFileFilter);   //Fügt einen Filter in die Liste Hinzu und Löst das Signal "filterListchange()" aus
    void delFilter(LogFileFilter _LogFileFilter);
    void storeFilter(LogFileFilter filter);         //Function dient zum Speichern von Bestehenden und Neuen Filtern

    LogFileModel( QObject *parent = 0)
        : QAbstractTableModel(parent), LogFiles(new QList<LogFile*>())
    {
        connect(this,SIGNAL(fileListchange()),this,SLOT(refreshItemList()));
        connect(this,SIGNAL(filterListchange()),this,SLOT(refreshItemList()));
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int frowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QList<LogFileFilter> getFiltersFromIndex(const QModelIndex &index = QModelIndex()) const;
    QList<LogFileFilter> getfFiltersFromIndex(const QModelIndex &index = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant fdata(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    QList<LogFile*>* getLogFileList(void);
    void             setLogFileList(QList<LogFile*>* _LogFiles);
    void             addLogFile(LogFile* _LogFile);
    void             delLogFile(LogFile* _LogFile);

    void setLogFile(LogFile *_logfile);

    LogFile* getLogFile(void);

    void sortItems(void);

    void sort( int column, Qt::SortOrder );

public slots:

    void refreshItemList();

signals:

    void   fileListchange();
    void filterListchange();
};

#endif // LOGFILEMODEL_H
