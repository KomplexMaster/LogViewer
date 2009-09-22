#include "logfileviewerfiltereditordockwidget.h"
#include "ui_logfileviewerfiltereditordockwidget.h"

LogFileViewerFilterEditorDockWidget::LogFileViewerFilterEditorDockWidget(LogFileViewerFilterDockWidget *_parent) :
    QDockWidget(parent),parent(_parent),
    m_ui(new Ui::LogFileViewerFilterEditorDockWidget)
{
    m_ui->setupUi(this);

    connect(parent,SIGNAL(filterselect(LogFileFilter)),this,SLOT(loadFilter(LogFileFilter)));
}

LogFileViewerFilterEditorDockWidget::~LogFileViewerFilterEditorDockWidget()
{
    delete m_ui;
}

void LogFileViewerFilterEditorDockWidget::changeEvent(QEvent *e)
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

void LogFileViewerFilterEditorDockWidget::setColor()
{
}

void LogFileViewerFilterEditorDockWidget::loadFilter(LogFileFilter filter)
{
    m_ui->pushButton->setPalette(QPalette(filter.color));
    m_ui->dateTimeEditFrom->setDateTime(filter.from);
    m_ui->dateTimeEditTo->setDateTime(filter.to);
    m_ui->lineEditMessageID->setText(QString::number(filter.MessageID));
    m_ui->lineEditSourceID->setText(QString::number(filter.SourceID));
    m_ui->lineEditSearch->setText(filter.searchpattern);
}
