#include "LogItemParserDialog.h"
#include "ui_LogItemParserDialog.h"

LogItemParserDialog::LogItemParserDialog(LogFile* _logFile, QWidget *parent) :
    QDialog(parent), logFile(_logFile),
    ui(new Ui::LogItemParserDialog)
{
    ui->setupUi(this);

    foreach(LogItemParser* parser,*logFile->getParserThread())
    {
        QProgressBar* pb = new QProgressBar(ui->Threads);
        ui->Threads->layout()->addWidget(pb);
        threadBars.append(pb);
    }

    t = new QTimer(this);
    connect(t, SIGNAL(timeout()), this, SLOT(refresh()));
    t->start(100);

    ui->FileName->setText(logFile->getFile()->fileName());
    ui->Lines->setText(QString::number(logFile->getLines()));

    ui->ButtonCancel->setEnabled(false);
}

LogItemParserDialog::~LogItemParserDialog()
{
    delete ui;
}

void LogItemParserDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void LogItemParserDialog::refresh(void)
{
    int linesfinished = 0;

    for(int i = 0;i<logFile->getParserThread()->size();i++)
    {
        int start = logFile->getParserThread()->at(i)->getstartPos();
        int width = logFile->getParserThread()->at(i)->getframeWidth();
        int pos   = logFile->getParserThread()->at(i)->getStep() - start;

        threadBars.at(i)->setMaximum(width);
        threadBars.at(i)->setValue(pos);

        linesfinished+=pos;
    }

    double sec = (double)logFile->getStartTime().msecsTo(QTime::currentTime());

    ui->lps->setText(QString::number((double)linesfinished/(sec),'g',5)+"k");

    if(logFile->getParserThread()->size()==0)this->close();
}
