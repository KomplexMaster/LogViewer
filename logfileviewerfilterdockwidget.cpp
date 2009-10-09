#include "LogFileViewerFilterDockWidget.h"
#include "ui_LogFileViewerFilterDockWidget.h"

LogFileViewerFilterDockWidget::LogFileViewerFilterDockWidget(LogFileViewWidget *_parent) :
    QDockWidget(_parent),parent(_parent),
    ui(new Ui::LogFileViewerFilterDockWidget)
{
    ui->setupUi(this);

    model = new QStandardItemModel(0, 4, this);

    sourceView = ui->treeView;
    sourceView->setRootIsDecorated(false);
    sourceView->setAlternatingRowColors(true);
    sourceView->setModel(model);

    filterChange();

    connect(this->ui->pushButtonRefresh,SIGNAL(clicked()),this,SLOT(filterChange()));
    connect(this->ui->treeView,SIGNAL(clicked(QModelIndex)),this,SLOT(selectFilter(QModelIndex)));
}

LogFileViewerFilterDockWidget::~LogFileViewerFilterDockWidget()
{
    delete ui;
}

void LogFileViewerFilterDockWidget::changeEvent(QEvent *e)
{
    QDockWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LogFileViewerFilterDockWidget::filterChange()
{
    /*
    if(parent)
    {
        QList<LogFileFilter>* filterList = parent->getJar()->getFilters();

        model->removeRows(0,model->rowCount());

        qDebug() << "LogFileViewerFilterDockWidget::filterList:" << filterList->size();

        foreach(LogFileFilter filter,*filterList)
        {
            addFilter(&filter);

            qDebug() << "LogFileViewerFilterDockWidget::filterList:" << filter.getUID() << " date: " << filter.to.toString();
        }

        qDebug() << "LogFileViewerFilterDockWidget::model:" << model->rowCount();
    }
    else
    {
        model->removeRows(0,model->rowCount());
    }
    */
}

void LogFileViewerFilterDockWidget::addFilter(LogFileFilter* filter)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), filter->name);
    model->setData(model->index(0, 1), filter->Color);
    model->setData(model->index(0, 2), filter->getUID());
    model->setData(model->index(0, 3), false);
}

void LogFileViewerFilterDockWidget::selectFilter(QModelIndex index)
{
    /*
    if(parent)
    {
        int uid = model->index(index.row(),2).data().toInt();

        foreach(LogFileFilter filter,*parent->getLogFileModel()->getFilters())
        {
            if(filter.getUID() == uid)
            {
                this->filter = filter;
                emit filterselect(filter);
                return;
            }
        }
    }
    */
}



void LogFileViewerFilterDockWidget::storeFilter(LogFileFilter filter)
{
    qDebug() << "LogFileViewerFilterDockWidget::Store Filter:" << filter.getUID();

    //parent->getLogFileModel()->storeFilter(filter);

    //filterChange();
}

void LogFileViewerFilterDockWidget::addFilter()
{
    LogFileFilter newfilter;
    newfilter.name = "Filter Nr."+QString::number(newfilter.getUID());
    //parent->getLogFileModel()->addFilter(newfilter);
    //filterChange();
}

void LogFileViewerFilterDockWidget::delFilter()
{
    //parent->getLogFileModel()->delFilter(this->filter);
    //filterChange();
}

