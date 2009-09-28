#include "logdelegate.h"
#include <QPainter>

LogDelegate::LogDelegate(QObject* parent):QStyledItemDelegate(parent)
{
}

void LogDelegate::paint ( QPainter * painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const
{
    LogFileModel *model = (LogFileModel*)(index.model());

    if(model)
    {
        //Filter ohne Farbe werden nicht gezeichenet

        QList<LogFileFilter> filters ;

        if(QString(index.model()->metaObject()->className())=="QSortFilterProxyModel")
        {
            model = (LogFileModel*)((LogFileProxyModel*)index.model())->sourceModel();
            filters = model->getfFiltersFromIndex(index);
        }
        else
        {
            filters = model->getFiltersFromIndex(index);
        }

        //qDebug() << model->metaObject()->className();

        int ColorCount=0;   //anzahl der Filter mit Frabe

        foreach(LogFileFilter filter,filters)
        {
            if(filter.color.isValid())ColorCount++;
        }

        if(!filters.empty())
        {
            painter->fillRect(option.rect, QBrush(filters.first().color,Qt::SolidPattern));
        }

        /*
        if(ColorCount!=0)
        {
            double factor = (double)option.rect.height()/ColorCount;

            qDebug() << factor;
            qDebug() << ColorCount;

            int FilterNum = 0;

            foreach(LogFileFilter filter,filters)
            {
                if(filter.color.isValid())
                {
                    QRect rect(0,FilterNum*factor,option.rect.width(),(FilterNum+1)*factor);

                    qDebug() << rect;

                    painter->fillRect(rect, QBrush(filter.color,Qt::SolidPattern));

                    qDebug() << "paint";

                    FilterNum++;
                }
            }
        }*/
    }

    QStyledItemDelegate::paint(painter,option,index);
}
