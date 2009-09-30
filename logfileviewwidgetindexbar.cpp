#include "logfileviewwidgetindexbar.h"
#include "logfileviewwidget.h"
#include <QPainter>
#include <qDebug>
#include <QScrollBar>

LogFileViewWidgetIndexBar::LogFileViewWidgetIndexBar(LogFileViewWidget *parent):QWidget(parent)
{
    setMinimumWidth(20);
    setMaximumWidth(20);

    recalScale();
}

QSize LogFileViewWidgetIndexBar::minimumSize(void)
{
    QSize wsize = QWidget::minimumSize();
    wsize.setWidth(wsize.width()+10);

    return QWidget::minimumSize();
}

void LogFileViewWidgetIndexBar::paintEvent(QPaintEvent *event)
{
        QWidget::paintEvent(event);
        QPainter p(this);

        //if(size()!=scale->size())recalScale();

        p.drawPixmap(0,0,*scale);
}

void LogFileViewWidgetIndexBar::recalScale()
{
    /*
    delete scale;
    scale = new QPixmap(this->size());

    QPainter p(scale);

    p.fillRect(QRectF(QPointF(0,0),size()),QBrush(Qt::white,Qt::SolidPattern));

    if(parent->getLogFileModel())
    {
        int raw = parent->getLogFileModel()->rowCount();
        double factor = raw / (double)size().height();

        LogFileModel*        model =  qobject_cast<LogFileModel *>(parent->getLogFileModel());

        if(model)
        {
            for(int i = 0;i<size().height();i++)
            {
                for(int j = (double)i*factor; j<=(double)(i+1)*factor; j++)
                {

                    QList<LogFileFilter> filters = model->getFiltersFromIndex(model->index(j,0));

                    if(!filters.isEmpty())
                    {
                        if(filters.first().Color.isValid())
                        {
                            p.setPen(filters.first().Color);
                            p.drawLine(0,i,size().width(),i);
                            break;
                        }
                    }
                }
            }
            update();
        }
    }*/
}
