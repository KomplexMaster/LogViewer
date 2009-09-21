#include "logfileviewwidgetindexbar.h"
#include <QPainter>
#include <qDebug>
#include <QScrollBar>

LogFileViewWidgetIndexBar::LogFileViewWidgetIndexBar(QTableView* _tView, QWidget *parent):QWidget(parent), tView(_tView)
{
    setMinimumWidth(20);
    setMaximumWidth(20);
    setBaseSize(20,20);

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

        if(size()!=scale->size())recalScale();

        p.drawPixmap(0,0,*scale);
}

void LogFileViewWidgetIndexBar::recalScale()
{
    delete scale;
    scale = new QPixmap(this->size());

    QPainter p(scale);

    p.fillRect(QRectF(QPointF(0,0),size()),QBrush(Qt::white,Qt::SolidPattern));

    if(tView->model())
    {
        int raw = tView->model()->rowCount();
        double factor = raw / (double)size().height();

        LogFileModel*        model =  qobject_cast<LogFileModel *>(tView->model());

        if(model)
        {
            for(int i = 0;i<size().height();i++)
            {
                for(int j = (double)i*factor; j<=(double)(i+1)*factor; j++)
                {

                    QList<LogFileFilter> filters = model->getFilters(model->index(j,0));

                    if(!filters.isEmpty())
                    {
                        if(filters.first().color.isValid())
                        {
                            p.setPen(filters.first().color);
                            p.drawLine(0,i,size().width(),i);
                            break;
                        }
                    }
                }
            }
        }
    }
    else
    {

    }

}
