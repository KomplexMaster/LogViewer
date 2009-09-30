#include "LogItemParserDialog.h"
#include "ui_LogItemParserDialog.h"

LogItemParserDialog::LogItemParserDialog(LogFile* _logFile, QWidget *parent) :
    QDialog(parent), logFile(_logFile),
    ui(new Ui::LogItemParserDialog)
{
    ui->setupUi(this);

    foreach(LogItemParser* parser,*logFile->getParserThread())      //Schleife erstellt ProgressBars für ParserThreads
    {
        QProgressBar* pb = new QProgressBar(ui->Threads);
        pb->setValue(parser->getStep());
        pb->setMaximum(parser->getframeWidth());
        ui->Threads->layout()->addWidget(pb);
        threadBars.append(pb);
    }

    t = new QTimer(this);                                           //Erstellt Timer der im 100ms Takt das dialog refresht
    connect(t, SIGNAL(timeout()), this, SLOT(refresh()));
    t->start(100);

    ui->FileName->setText(logFile->getFile()->fileName());          //Setzt DateiName
    ui->Lines->setText(QString::number(logFile->getLinesCount()));  //Setzt Lines

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
    if(logFile->getParserThread()->size()==0)                                   //Prüft ober Threads noch Aktiv sind und Schließt den Dialog bei Vollendung der Threads
    {
        close();
        t->stop();
    }
    else
    {
        int linesfinished = 0;                                                  //Variable für Abgearbeitete Zeilen

        for(int i = 0;i<logFile->getParserThread()->size();i++)                 //Geht alle ParserThreads durch
        {
            int start = logFile->getParserThread()->at(i)->getstartPos();       //Aktualisiert die ProgressBars
            int width = logFile->getParserThread()->at(i)->getframeWidth();
            int pos   = logFile->getParserThread()->at(i)->getStep() - start;

            threadBars.at(i)->setMaximum(width);
            threadBars.at(i)->setValue(pos);

            linesfinished+=pos;                                                 //Addiert die einzelnen abgearbeiteten Zeilen der Threads zusammen
        }

        double sec = (double)logFile->getStartTime().msecsTo(QTime::currentTime()); //setzt die vergangene Sekunden

        ui->lps->setText(QString::number((double)linesfinished/(sec),'g',5)+"k");   //berechnet die Gechschwindigkeit anhand von AbgearbeitetenZeilen / vergangene Sekunden

        logFile->threadFinished();
    }
}
