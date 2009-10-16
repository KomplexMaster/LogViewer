#ifndef LOGDELEGATE_H
#define LOGDELEGATE_H

#include <QStyledItemDelegate>

#include "logfilemodel.h"
#include "logfileproxymodel.h"

class LogDelegate : public QStyledItemDelegate
{
protected:

public:
    LogDelegate(LogFileModel* parent = 0);

    void paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
};

#endif // LOGDELEGATE_H
