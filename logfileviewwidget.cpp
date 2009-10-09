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

    //Erstellt LogFileModel falls per default keines übergeben wurde
    //proxymodel = new LogFileProxyModel(this);
    //proxymodel->setSourceModel(model);

   // filterproxy = new QSortFilterProxyModel;
   // filterproxy->setDynamicSortFilter(true);
   // filterproxy->setSourceModel(model);

    //Erzeugt die Oberfläche

    //top = new QTableView();         //erzeugt Views für ungefilterte (top) und gefilltere (botton) Ansicht

    top = new QTreeView();
    top->setRootIsDecorated(false);
    top->setAlternatingRowColors(true);
    top->setUniformRowHeights(true);

    botton = new QTreeView();
    botton->setRootIsDecorated(false);
    botton->setAlternatingRowColors(true);
    botton->setUniformRowHeights(true);

 //   proxyView = new QTreeView;
 //   proxyView->setRootIsDecorated(false);
 //   proxyView->setAlternatingRowColors(true);
 //   proxyView->setModel(proxymodel);
 //   proxyView->setSortingEnabled(true);


    this->setLayout(new QHBoxLayout(this));
    //indexbar = new LogFileViewWidgetIndexBar(this);
    //this->layout()->addWidget(indexbar);
    split = new QSplitter();
    this->layout()->addWidget(split);
    split->setOrientation(Qt::Vertical);

    split->addWidget(top);
    split->addWidget(botton);

    //top->setModel(model);
    //botton->setModel(proxymodel);

    //top->setItemDelegate(new LogDelegate(this));
    //botton->setItemDelegate(new LogDelegate(this));

    top->setSortingEnabled(true);

    //loadColumnWidth();      //läd Breite der Zeilen für die Views
    //connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SIGNAL(changeData()));

    jar = new LogFileJar(this);
    model = new LogFileModel(jar);

    top->setModel(model);
    botton->setModel(model);
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
