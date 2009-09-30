#include "logfileviewwidget.h"
#include "ui_logfileviewwidget.h"
#include "logdelegate.h"
#include "logfile.h"




LogFileViewWidget::LogFileViewWidget(LogFileModel *_model, QWidget *parent):QWidget(parent),  model(_model),
    m_ui(new Ui::LogFileViewWidget)
{
    currentLoadingFile = 0;

    if(!model)model = new LogFileModel(this);   //Erstellt LogFileModel falls per default keines übergeben wurde
    proxymodel = new LogFileProxyModel(this);
    proxymodel->setSourceModel(model);

   // filterproxy = new QSortFilterProxyModel;
   // filterproxy->setDynamicSortFilter(true);
   // filterproxy->setSourceModel(model);

    //Erzeugt die Oberfläche

    top = new QTableView();         //erzeugt Views für ungefilterte (top) und gefilltere (botton) Ansicht
    botton = new QTableView();

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

    top->setModel(model);
    botton->setModel(proxymodel);

    top->setItemDelegate(new LogDelegate(this));
    botton->setItemDelegate(new LogDelegate(this));

    top->setSortingEnabled(true);

    loadColumnWidth();      //läd Breite der Zeilen für die Views

    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SIGNAL(changeData()));
    connect(model,SIGNAL(fileListchange()),indexbar,SLOT(recalScale()));
    connect(model,SIGNAL(filterListchange()),indexbar,SLOT(recalScale()));
    qDebug() << indexbar->metaObject()->className();
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

void LogFileViewWidget::addLogFile(LogFile* _LogFile)
{
    model->addLogFile(_LogFile);
    model->sortItems();
}

void LogFileViewWidget::delLogFile(LogFile* _LogFile)
{
    model->delLogFile(_LogFile);
}

LogFileModel* LogFileViewWidget::getLogFileModel()
{
    return model;
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

void LogFileViewWidget::loadLogFile(QString LogName)
{
    waitingChain.append(LogName);

    qDebug() << "LogFileViewWidget::loadLogFile->FileName:" << LogName;
    qDebug() << "LogFileViewWidget::loadLogFile->waitingChain size:" << waitingChain.size();

    if(currentLoadingFile==0)
    {
        qDebug() << "LogFileViewWidget::loadLogFile->First in waitingChain" << LogName;
        currentLoadingFile = new LogFile(new QFile(LogName));
        connect(currentLoadingFile,SIGNAL(readFinished()),this,SLOT(loadNextLogFile()));
    }
}

void LogFileViewWidget::loadNextLogFile(void)
{
    if((waitingChain.size()==0))
    {
        qDebug() << "LogFileViewWidget::loadNextLogFile->All Files loaded:";
        return;
    }

    qDebug() << "LogFileViewWidget::loadNextLogFile->Checke File:" << currentLoadingFile->getFile()->fileName();

    if(!currentLoadingFile->isLoaded())return;

    qDebug() << "LogFileViewWidget::loadNextLogFile->File:" << currentLoadingFile->getFile()->fileName() << "geladen.";

    if(waitingChain.contains(currentLoadingFile->getFile()->fileName()))
    {
        waitingChain.removeOne(currentLoadingFile->getFile()->fileName());

        qDebug() << "LogFileViewWidget::loadNextLogFile->waitingChain size:" << waitingChain.size();

        model->addLogFile(currentLoadingFile);
        model->sortItems();

        emit this->changeData();

        if(waitingChain.size()==0)
        {
            currentLoadingFile=0;
            return;
        }

        currentLoadingFile = new LogFile(new QFile(waitingChain.first()));
        connect(currentLoadingFile,SIGNAL(readFinished()),this,SLOT(loadNextLogFile()));
    }
}

QString LogFileViewWidget::getStatusMessage()
{
    return tr("LogFiles loaded:") + QString::number(model->getLogFileList()->size()) +
            tr("    LogItems in Model:") + QString::number(model->rowCount()) +
            tr("    LogItems with Filter match:") + QString::number(model->frowCount()) +
            tr("    LogFiles to load:") + QString::number(this->waitingChain.size());
}
