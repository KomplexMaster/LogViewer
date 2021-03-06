#include "LogFileViewerFilterDockWidget.h"
#include "ui_LogFileViewerFilterDockWidget.h"

LogFileViewerFilterDockWidget::LogFileViewerFilterDockWidget(LogFileViewWidget *_parent) :
    QDockWidget(_parent),parent(_parent),
    ui(new Ui::LogFileViewerFilterDockWidget)
{
    ui->setupUi(this);

    model = new QStandardItemModel(0, 4, this);

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Color"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Hash"));

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
    if(parent)
    {
        QList<LogFileFilter>* filterList = parent->getLogFileFilterList();

        model->removeRows(0,model->rowCount());

        qDebug() << "LogFileViewerFilterDockWidget::filterList:" << filterList->size();

        foreach(LogFileFilter filter,*filterList)
        {
            addFilter(&filter);
        }

        qDebug() << "LogFileViewerFilterDockWidget::model:" << model->rowCount();
    }
    else
    {
        model->removeRows(0,model->rowCount());
    }
}

void LogFileViewerFilterDockWidget::addFilter(LogFileFilter* filter)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), "Filter");
    model->setData(model->index(0, 1), filter->color);
    model->setData(model->index(0, 2), filter->getUID());
    model->setData(model->index(0, 3), false);
}

void LogFileViewerFilterDockWidget::selectFilter(QModelIndex index)
{
    if(parent)
    {
        int uid = model->index(index.row(),2).data().toInt();

        foreach(LogFileFilter filter,*parent->getLogFileFilterList())
        {
            if(filter.getUID() == uid)
            {
                emit filterselect(filter);
            }
        }
    }
}
