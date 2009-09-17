#ifndef LOGDELEGATE_H
#define LOGDELEGATE_H

#include <QStyledItemDelegate>

#include "logfilemodel.h"
#include "logfileproxymodel.h"

class LogDelegate : public QStyledItemDelegate
{
protected:
    LogFileModel* model;

public:
    LogDelegate(QObject* parent);

    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
};

#endif // LOGDELEGATE_H
