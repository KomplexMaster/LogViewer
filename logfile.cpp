#include "logfile.h"
#include "logitem.h"
#include "logfilefilter.h"

#include <QDateTime>

LogFile::LogFile(QFile *_file):File(_file),threadCount(2)
{
    if (_file->exists())                                //Überprüft ob LogFile existiert
    {
        if(_file->open(QIODevice::ReadOnly))            //Überprüft ob LogFile geöffnet werden kann
        {
            QTextStream stream(_file);                  //Erstellt TextStream zum auslesen der Datei

            while(!stream.atEnd())                      //Schleife die, die Zeilen des LogFiles in das Array läd
            {
                lograwlist.append(stream.readLine());
            }

            for(int i(0);i>threadCount;i++)
            {

            }



            qDebug() << "START::" << QTime::currentTime();
            QTime dttmp(QTime::currentTime());

            QProgressDialog pd("test","cancel",0,lograwlist.size()/2);
            pd.show();
/*
            LogItemParser p1;
            LogItemParser p2;


            p1.startint = 0;
            p1.stopint = lograwlist.size()/2;
            p1.lograwlist = &lograwlist;

            p2.startint = p1.stopint;
            p2.stopint = lograwlist.size();
            p2.lograwlist = &lograwlist;
*/

            //t = new QTimer(this);
            //connect(t, SIGNAL(timeout()), this, SLOT(perform()));
            //t->start(0);


            /*p1.start(QThread::LowPriority);
            p2.start(QThread::LowPriority);

            while(p1.isRunning() || p2.isRunning())
            {
                p1.wait(1000);
                pd.show();
                qDebug() << "RUN::" << QTime::currentTime();
            };
*/

            //LogItems.append(p1._LogItems);
            //LogItems.append(p2._LogItems);

            qDebug() << "STOP::" << QTime::currentTime();

            qDebug() << "DIFF::" << dttmp.msecsTo(QTime::currentTime());
        }
    }
}

QList<LogItem*>* LogFile::getLogItemList(void)
{
    return &LogItems;
}

QFile* LogFile::getFile()
{
    return File;
}

LogFileFilter LogFile::getFilter(void)
{
    return this->LogFilter;
}

void LogFile::setFilter(LogFileFilter _filter)
{
    LogFilter = _filter;
}

void LogFile::filter(LogItemList* in, LogItemList* out, LogFileFilter filter)
{
    foreach(LogItem* item,*in)
    {
        if(LogFile::filter(item,filter))out->append(item);
    }
}

bool LogFile::filter(LogItem* item, LogFileFilter filter)
{
    if(filter.from.isValid())
    {
        if(item->getTimestamp() < filter.from)return false;
    }

    if(filter.to.isValid())
    {
        if(item->getTimestamp() > filter.to)return false;
    }


    if(filter.MessageID>=0)
    {
        if(item->getMessageID()!=filter.MessageID)return false;
    }

    if(filter.SourceID>=0)
    {
        if(item->getSourceID()!=filter.SourceID)return false;
    }


    if(filter.Type!='-')
    {
        if(item->getType()!=filter.Type)return false;
    }

    if(!filter.searchpattern.isEmpty())
    {
        if(!item->getMessage().contains(filter.searchpattern))return false;
    }

    return true;
}
