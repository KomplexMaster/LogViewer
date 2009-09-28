#include "logfileviewwidget.h"
#include "ui_logfileviewwidget.h"
#include "logdelegate.h"
#include "logfile.h"




LogFileViewWidget::LogFileViewWidget(LogFileModel *_model, QWidget *parent):QWidget(parent),  model(_model),
    m_ui(new Ui::LogFileViewWidget)
{
    if(!model)model = new LogFileModel(this);   //Erstellt LogFileModel falls per default keines übergeben wurde
    proxymodel = new LogFileProxyModel(this);
    proxymodel->setSourceModel(model);

   // filterproxy = new QSortFilterProxyModel;
   // filterproxy->setDynamicSortFilter(true);
   // filterproxy->setSourceModel(model);


    LogFileFilter filter;           //REMOVE!!!!!!!!!!
    filter.SourceID = 240;          //REMOVE!!!!!!!!!!
    filter.color    = QColor(105,255,105,255);    //REMOVE!!!!!!!!!!
    model->addFilter(filter);//REMOVE!!!!!!!!!!
    LogFileFilter filter2;          //REMOVE!!!!!!!!!!
    filter2.SourceID = 17;           //REMOVE!!!!!!!!!!
    filter2.color    = QColor(255,105,105,255);      //REMOVE!!!!!!!!!!
    model->addFilter(filter2);//REMOVE!!!!!!!!!!
   /* LogFileFilter filter3;          //REMOVE!!!!!!!!!!
    filter3.SourceID = 243;          //REMOVE!!!!!!!!!!
    filter3.color    = Qt::blue;      //REMOVE!!!!!!!!!!
    model->addLogFileFilter(filter3);//REMOVE!!!!!!!!!!
*/
    //Erzeugt die Oberfläche

    top = new QTableView();         //erzeugt Views für ungefilterte (top) und gefilltere (botton) Ansicht
    botton = new QTableView();

 //   proxyView = new QTreeView;
 //   proxyView->setRootIsDecorated(false);
 //   proxyView->setAlternatingRowColors(true);
 //   proxyView->setModel(proxymodel);
 //   proxyView->setSortingEnabled(true);



    this->setLayout(new QHBoxLayout(this));
    indexbar = new LogFileViewWidgetIndexBar(top,this);
    this->layout()->addWidget(indexbar);
    split = new QSplitter();
    this->layout()->addWidget(split);
    split->setOrientation(Qt::Vertical);

    split->addWidget(top);
    split->addWidget(botton);

    top->setModel(model);
    botton->setModel(proxymodel);

    top->setItemDelegate(new LogDelegate(this));
    botton->setItemDelegate(new LogDelegate(this));
}

LogFileViewWidget::~LogFileViewWidget()
{
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
