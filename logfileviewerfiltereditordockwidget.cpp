#include "logfileviewerfiltereditordockwidget.h"
#include "ui_logfileviewerfiltereditordockwidget.h"

LogFileViewerFilterEditorDockWidget::LogFileViewerFilterEditorDockWidget(LogFileViewerFilterDockWidget *_parent) :
    QDockWidget(parent),parent(_parent),
    m_ui(new Ui::LogFileViewerFilterEditorDockWidget)
{
    m_ui->setupUi(this);

    //connect(parent,SIGNAL(filterselect(LogFileFilter)),this,SLOT(setFilter(LogFileFilter)));
    connect(this->m_ui->pushButtonSave,SIGNAL(clicked()),this,SLOT(storeFilter()));
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
    qDebug() << "LogFileViewerFilterEditorDockWidget::getColor";

    QColor newColor = QColorDialog::getColor(Qt::green,parent);

    qDebug() << "LogFileViewerFilterEditorDockWidget::new Color:";

    if(newColor.isValid())filter.Color = newColor;

    setFilter(filter);
}

void LogFileViewerFilterEditorDockWidget::setSearchPattern()
{
    filter.searchpattern = m_ui->lineEditSearch->text();
    setFilter(filter);
}

void LogFileViewerFilterEditorDockWidget::setMessageID()
{
    filter.MessageID = m_ui->lineEditMessageID->text().toInt();
    setFilter(filter);
}

void LogFileViewerFilterEditorDockWidget::setSourceID()
{
    filter.SourceID = m_ui->lineEditSourceID->text().toInt();
    setFilter(filter);
}

LogFileFilter LogFileViewerFilterEditorDockWidget::getLogFileFilter()
{
    return filter;
}

void LogFileViewerFilterEditorDockWidget::setFilter(LogFileFilter _filter)
{
    filter = _filter;

    m_ui->pushButton->setPalette(QPalette(filter.Color));
    m_ui->dateTimeEditFrom->setDateTime(filter.from);
    m_ui->dateTimeEditTo->setDateTime(filter.to);
    m_ui->lineEditMessageID->setText(QString::number(filter.MessageID));
    m_ui->lineEditSourceID->setText(QString::number(filter.SourceID));
    m_ui->lineEditSearch->setText(filter.searchpattern);
    m_ui->checkBoxInvert->setChecked(filter.invert);
}

void LogFileViewerFilterEditorDockWidget::setFrom(QDateTime _from)
{
    filter.from = _from;
}

void LogFileViewerFilterEditorDockWidget::setTo(QDateTime _to)
{
    filter.to = _to;
}

void LogFileViewerFilterEditorDockWidget::storeFilter()
{
    filter.searchpattern    = m_ui->lineEditSearch->text();
    filter.MessageID        = m_ui->lineEditMessageID->text().toInt();
    filter.SourceID         = m_ui->lineEditSourceID->text().toInt();
    filter.from             = m_ui->dateTimeEditFrom->dateTime();
    filter.to               = m_ui->dateTimeEditTo->dateTime();
    filter.invert           = m_ui->checkBoxInvert->isChecked();

    parent->storeFilter(filter);
}
