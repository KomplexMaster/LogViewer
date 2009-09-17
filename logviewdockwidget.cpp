#include "logviewdockwidget.h"
#include "ui_logviewdockwidget.h"

LogViewDockWidget::LogViewDockWidget(QWidget *parent) :
    QDockWidget(parent),
    logunfilteredmodle(0, 7, parent),
    m_ui(new Ui::LogViewDockWidget)
{
    m_ui->setupUi(this);


    // Beschrieftungen für die Model

    logfilteredmodle.setHeaderData(0, Qt::Horizontal, QObject::tr("Type"));
    logfilteredmodle.setHeaderData(1, Qt::Horizontal, QObject::tr("Time"));
    logfilteredmodle.setHeaderData(2, Qt::Horizontal, QObject::tr("MessageID"));
    logfilteredmodle.setHeaderData(3, Qt::Horizontal, QObject::tr("SourceID"));
    logfilteredmodle.setHeaderData(4, Qt::Horizontal, QObject::tr("UNKOWND"));
    logfilteredmodle.setHeaderData(5, Qt::Horizontal, QObject::tr("Message"));
    logfilteredmodle.setHeaderData(6, Qt::Horizontal, QObject::tr("File"));
    logfilteredmodle.setHeaderData(7, Qt::Horizontal, QObject::tr("Line"));

    logunfilteredmodle.setHeaderData(0, Qt::Horizontal, QObject::tr("Type"));
    logunfilteredmodle.setHeaderData(1, Qt::Horizontal, QObject::tr("Time"));
    logunfilteredmodle.setHeaderData(2, Qt::Horizontal, QObject::tr("MessageID"));
    logunfilteredmodle.setHeaderData(3, Qt::Horizontal, QObject::tr("SourceID"));
    logunfilteredmodle.setHeaderData(4, Qt::Horizontal, QObject::tr("UNKOWND"));
    logunfilteredmodle.setHeaderData(5, Qt::Horizontal, QObject::tr("Message"));
    logunfilteredmodle.setHeaderData(6, Qt::Horizontal, QObject::tr("File"));
    logunfilteredmodle.setHeaderData(7, Qt::Horizontal, QObject::tr("Line"));

    // Zuweisung der View zu den Models

    m_ui->filtered->setModel(&logfilteredmodle);
    m_ui->unfiltered->setModel(&logunfilteredmodle);

    m_ui->unfiltered->setRootIsDecorated(false);
    m_ui->unfiltered->setAlternatingRowColors(true);

    m_ui->filtered->setRootIsDecorated(false);
    m_ui->filtered->setAlternatingRowColors(true);
    m_ui->filtered->setSortingEnabled(true);

    //REMOVE!!!

    logfilteredmodle.setDynamicSortFilter(true);
    logfilteredmodle.setSourceModel(&logunfilteredmodle);

    qDebug() << "==> Start:" << QDateTime();

    LogFiles.append(LogFile(new QFile("D:\\Dokumente und Einstellungen\\Administrator.ROOZ-7A90DB47F2\\Eigene Dateien\\LogViewer\\release\\FlCompact.log")));

    qDebug() << "==> End:" << QDateTime();

    LogItem* logitem;

    foreach(logitem,*LogFiles.first().getLogItemList())
    {

        addLogLine(&logunfilteredmodle,logitem->getType(),logitem->getTimestamp(),logitem->getMessageID(),logitem->getSourceID(),logitem->getUNKOWND(),logitem->getMessage(),"filename",1);
    }
}

LogViewDockWidget::~LogViewDockWidget()
{
    delete m_ui;
}

void LogViewDockWidget::changeEvent(QEvent *e)
{
    QDockWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LogViewDockWidget::addLogLine(QAbstractItemModel *model, const QChar &type,
             const QDateTime &date, const int &messageid, const int &sourceid, const QString &unkownd, const QString &message, const QString &filename, const int &line)
{
    model->insertRow(0);
    model->setData(model->index(0, 0), type);
    model->setData(model->index(0, 1), date);
    model->setData(model->index(0, 2), messageid);
    model->setData(model->index(0, 3), sourceid);
    model->setData(model->index(0, 4), unkownd);
    model->setData(model->index(0, 5), message);
    model->setData(model->index(0, 6), filename);
    model->setData(model->index(0, 7), line);
}
