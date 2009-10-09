#ifndef LOGFILEMODEL_H
#define LOGFILEMODEL_H

#include <QAbstractListModel>
#include "logfilejar.h"

class LogFileModel : public QAbstractTableModel
{
    Q_OBJECT

protected:

    LogItemList*    LogItems;
    LogFileJar*     parent;

public:

    LogFileModel( LogFileJar *parent = 0);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index,
                  int role) const;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const;
    void sort( int column,
               Qt::SortOrder );

protected slots:

    void dataLoaded();
};

#endif // LOGFILEMODEL_H
