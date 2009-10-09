#include "logfileproxymodel.h"

QVariant LogFileProxyModel::data(const QModelIndex &index, int role) const
{
    //if((LogFileModel*)this->sourceModel())
    //{
    //    return ((LogFileModel*)this->sourceModel())->fdata(index,role);
    //}
    return QVariant();
}

int LogFileProxyModel::rowCount(const QModelIndex &index) const
{
    //if((LogFileModel*)this->sourceModel())
    //{
    //    return ((LogFileModel*)this->sourceModel())->frowCount(index);
    //}
    return 0;
}

bool LogFileProxyModel::lessThan(const QModelIndex &left, const QModelIndex &right) const
{
    return true;
}
