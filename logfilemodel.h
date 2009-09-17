#ifndef LOGFILEMODEL_H
#define LOGFILEMODEL_H

#include <QAbstractListModel>

#include "logfile.h"

class LogFileModel : public QAbstractTableModel
{
    Q_OBJECT

protected:
    QList<LogFile*>                         *LogFiles;
    QList<LogFileFilter>               LogFileFilters;

    QMap<int, QList<LogItem*>*>  FilterItemMap;
    LogItemList                              LogItems;


public:
    LogFileModel( QObject *parent = 0)
        : QAbstractTableModel(parent), LogFiles(new QList<LogFile*>())
    {
        connect(this,SIGNAL(fileListchange()),this,SLOT(refreshItemList()));
        connect(this,SIGNAL(filterListchange()),this,SLOT(refreshItemList()));
    }

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int frowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    QList<LogFileFilter> getFilters(const QModelIndex &index = QModelIndex()) const;
    QList<LogFileFilter> getfFilters(const QModelIndex &index = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role) const;
    QVariant fdata(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;

    QList<LogFile*>* getLogFileList(void);
    void             setLogFileList(QList<LogFile*>* _LogFiles);
    void             addLogFile(LogFile* _LogFile);
    void             delLogFile(LogFile* _LogFile);

    //QList<LogFileFilter> getLogFileFilters(void);
    //void                 setLogFileFilters(QList<LogFileFilter> _LogFileFilters);
    void                 addLogFileFilter(LogFileFilter _LogFileFilter);
    //void                 delLogFileFilter(LogFileFilter _LogFileFilter);

    void setLogFile(LogFile *_logfile);

    LogFile* getLogFile(void);

public slots:

    void refreshItemList();

signals:

    void   fileListchange();
    void filterListchange();
};

#endif // LOGFILEMODEL_H
