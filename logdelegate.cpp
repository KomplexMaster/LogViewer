#include "logdelegate.h"
#include <QPainter>

LogDelegate::LogDelegate(LogFileModel* parent):QStyledItemDelegate(parent)
{
}

void LogDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    const LogFileModel* model =  qobject_cast<const LogFileModel*>(index.model());

    if(model)
    {
        QList<LogFileFilter> filters = model->getFilter(index);

        if(!filters.empty())
        {
            if(index.column()==0)
            {
                int filterWidth = (option.rect.width()/filters.size());

                QRect rect = option.rect;
                rect.setWidth(filterWidth);

                foreach(LogFileFilter currentFilter,filters)
                {
                    painter->fillRect(rect, QBrush(currentFilter.Color,Qt::SolidPattern));
                    rect.setX(rect.x()+filterWidth);
                    rect.setWidth(filterWidth);
                }
            }
            else
            {
                if(!filters.isEmpty())painter->fillRect(option.rect, QBrush(filters.last().Color,Qt::SolidPattern));
            }
        }
    }

    QStyledItemDelegate::paint(painter,option,index);
}
