#include "logfileviewwidget.h"
#include "ui_logfileviewwidget.h"

LogFileViewWidget::LogFileViewWidget(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::LogFileViewWidget)
{
    this->setLayout(new QGridLayout(this));
    split = new QSplitter();
    this->layout()->addWidget(split);
    split->setOrientation(Qt::Vertical);

    top = new QTableView(split);
    botton = new QTableView(split);

    this->setWindowTitle("test");
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
