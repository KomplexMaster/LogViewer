#ifndef LOGFILEPROXYMODEL_H
#define LOGFILEPROXYMODEL_H

#include <QSortFilterProxyModel>
#include "logfilemodel.h"

class LogFileProxyModel : public QSortFilterProxyModel
{
    //Q_OBJECT
public:
    LogFileProxyModel(QObject * parent = 0 ):QSortFilterProxyModel(parent){}

    QVariant data(const QModelIndex &index, int role) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
protected:
    bool lessThan(const QModelIndex &left,
                                          const QModelIndex &right) const;
};

#endif // LOGFILEPROXYMODEL_H
