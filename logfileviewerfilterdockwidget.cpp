#include "LogFileViewerFilterDockWidget.h"
#include "ui_LogFileViewerFilterDockWidget.h"
#include "logfilefilterdelegate.h"

LogFileViewerFilterDockWidget::LogFileViewerFilterDockWidget(LogFileViewWidget *_parent) :
    QDockWidget(_parent),parent(_parent),
    ui(new Ui::LogFileViewerFilterDockWidget)
{
    ui->setupUi(this);

    model = parent->getFilterModel();

    sourceView = ui->treeView;
    sourceView->setRootIsDecorated(false);
    sourceView->setAlternatingRowColors(true);
    sourceView->setModel(model);
    //sourceView->setItemDelegate(new LogFileFilterDelegate(this));

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

void LogFileViewerFilterDockWidget::addFilter(LogFileFilter* filter)
{
}

void LogFileViewerFilterDockWidget::selectFilter(QModelIndex index)
{
    emit changeFilter(model->getFilterOfIndex(index));
}


void LogFileViewerFilterDockWidget::storeFilter(LogFileFilter filter)
{
    if(!sourceView->currentIndex().isValid())return;

    parent->getJar()->replaceFilter(sourceView->currentIndex().row(),filter);
}

void LogFileViewerFilterDockWidget::addFilter()
{
    LogFileFilter newfilter;
    newfilter.name = "Filter Nr.:"+QString::number(newfilter.getUID());
    parent->getJar()->appendFilter(newfilter);
}

void LogFileViewerFilterDockWidget::delFilter()
{
    if(!sourceView->currentIndex().isValid())return;

    parent->getJar()->removeFilter(sourceView->currentIndex().row());
    qDebug() << sourceView->currentIndex().row();
}

