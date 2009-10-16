#include "logfileviewwidget.h"
#include "ui_logfileviewwidget.h"
#include "logdelegate.h"
#include "logfile.h"
#include "logfileviewwidget.h"
#include "logfilejar.h"

LogFileViewWidget::LogFileViewWidget(QWidget *parent):QWidget(parent),
    m_ui(new Ui::LogFileViewWidget)
{
    currentLoadingFile = 0;

    top = new QTreeView();
    top->setRootIsDecorated(false);
    top->setAlternatingRowColors(true);
    top->setUniformRowHeights(true);
    top->setEditTriggers(QTreeView::DoubleClicked);

    botton = new QTreeView();
    botton->setRootIsDecorated(false);
    botton->setAlternatingRowColors(true);
    botton->setUniformRowHeights(true);


    this->setLayout(new QHBoxLayout(this));
    //indexbar = new LogFileViewWidgetIndexBar(this);
    //this->layout()->addWidget(indexbar);
    split = new QSplitter();
    this->layout()->addWidget(split);
    split->setOrientation(Qt::Vertical);

    split->addWidget(top);
    split->addWidget(botton);


    jar = new LogFileJar(this);


    itemmodel = new LogFileModel(jar);
    itemfilteredmodel = new LogFileModel(jar);
    itemfilteredmodel->setFiltered(true);
    filtermodel = new LogFileFilterModel(jar);

    top->setModel(itemmodel);
    top->setItemDelegate(new LogDelegate());

    botton->setModel(itemfilteredmodel);
    botton->setItemDelegate(new LogDelegate());

    connect(jar,SIGNAL(inProgress(bool)),this,SLOT(setDisabled(bool)));

    top->setSortingEnabled(true);
    botton->setSortingEnabled(true);
    connect(botton,SIGNAL(clicked(QModelIndex)),this,SLOT(moveToSelectedItem(QModelIndex)));
    connect(jar,SIGNAL(inProgress(bool)),this,SLOT(isProgress(bool)));
}

LogFileViewWidget::~LogFileViewWidget()
{
    saveColumnWidth();

    delete m_ui;
}

void LogFileViewWidget::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LogFileViewWidget::loadColumnWidth()
{
    if(top)
    {
        for(int i = 0;i<top->model()->columnCount();i++)
        {
            int width(settings.value("LogFileViewWidget/TopView/ColumnWidth/"+QString::number(i),"100").toInt());
            top->setColumnWidth(i,width);
        }
    }
    if(botton)
    {
        for(int i = 0;i<botton->model()->columnCount();i++)
        {
            int width(settings.value("LogFileViewWidget/BottonView/ColumnWidth/"+QString::number(i),"100").toInt());
            botton->setColumnWidth(i,width);
        }
    }
}

void LogFileViewWidget::saveColumnWidth()
{
    if(top)
    {
        for(int i = 0;i<top->model()->columnCount();i++)
        {
            settings.setValue("LogFileViewWidget/TopView/ColumnWidth/"+QString::number(i),QString::number(top->columnWidth(i)));
        }
    }
    if(botton)
    {
        for(int i = 0;i<botton->model()->columnCount();i++)
        {
            settings.setValue("LogFileViewWidget/BottonView/ColumnWidth/"+QString::number(i),QString::number(botton->columnWidth(i)));
        }
    }
}

QString LogFileViewWidget::getStatusMessage()
{
    return "bla";/*tr("LogFiles loaded:") + QString::number(model->getLogFileList()->size()); +
            tr("    LogItems in Model:") + QString::number(model->rowCount()) +
            tr("    LogItems with Filter match:") + QString::number(model->frowCount()) +
            tr("    LogFiles to load:") + QString::number(this->waitingChain.size());*/
}

LogFileJar* LogFileViewWidget::getJar()
{
    return jar;
}

void LogFileViewWidget::loadLogFile(QString FileName)
{
    jar->loadFile(FileName);
}

LogFileFilterModel* LogFileViewWidget::getFilterModel(void)
{
    return filtermodel;
}

void LogFileViewWidget::moveToSelectedItem(QModelIndex index)
{
    LogItem* filter = itemfilteredmodel->getLogItemOfIndex(index);
    top->setCurrentIndex(itemmodel->getIndexOfLogItem(filter));
}

void LogFileViewWidget::isProgress(bool b)
{
    qDebug() << b;
    this->setEnabled(!b);
}
