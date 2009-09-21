#include "logfileviewwidget.h"
#include "ui_logfileviewwidget.h"
#include "logdelegate.h"
#include "logfile.h"

LogFileViewWidget::LogFileViewWidget(LogFileModel *_model, QWidget *parent): model(_model), QWidget(parent),
    m_ui(new Ui::LogFileViewWidget)
{
    if(!model)model = new LogFileModel(this);

    LogFileFilter filter;           //REMOVE!!!!!!!!!!
    filter.SourceID = 240;          //REMOVE!!!!!!!!!!
    filter.color    = QColor(105,255,105,255);    //REMOVE!!!!!!!!!!
    model->addLogFileFilter(filter);//REMOVE!!!!!!!!!!
    LogFileFilter filter2;          //REMOVE!!!!!!!!!!
    filter2.SourceID = 17;           //REMOVE!!!!!!!!!!
    filter2.color    = QColor(255,105,105,255);      //REMOVE!!!!!!!!!!
    model->addLogFileFilter(filter2);//REMOVE!!!!!!!!!!
    //LogFileFilter filter3;          //REMOVE!!!!!!!!!!
    //filter3.SourceID = 243;          //REMOVE!!!!!!!!!!
    //filter3.color    = Qt::blue;      //REMOVE!!!!!!!!!!
    //model->addLogFileFilter(filter3);//REMOVE!!!!!!!!!!

    proxymodel = new LogFileProxyModel(this);
    proxymodel->setSourceModel(model);

    top = new QTableView();
    botton = new QTableView();

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

    this->setWindowTitle("test");

    top->setItemDelegate(new LogDelegate(this));
    botton->setItemDelegate(new LogDelegate(this));

    connect(this->botton,SIGNAL(clicked(QModelIndex)),this,SLOT(jumpToLine()));
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
}

void LogFileViewWidget::delLogFile(LogFile* _LogFile)
{
    model->delLogFile(_LogFile);
}

void LogFileViewWidget::jumpToLine()
{
    qDebug() << this->botton->selectionModel()->currentIndex().row();

    //QVariant data = proxymodel->data(this->botton->selectionModel()->currentIndex());

}
