#include "logfile.h"
#include "logitem.h"
#include "logfilefilter.h"

#include <QDateTime>

LogFile::LogFile(QFile *_file):File(_file),threadCount(4)
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

            lineCount = lograwlist.size();

            qDebug() << "LogFile::" << "LogRawList:" << lograwlist.size();

            //Erzeugen der Threads

            int startPos,stopPos;
            int frameSize(lograwlist.size()/threadCount);

            for(int i = 0;i<threadCount;i++)
            {
                startPos = i*frameSize;

                if(i==threadCount)
                {
                    stopPos = lograwlist.size();
                }
                else
                {
                    stopPos = startPos+frameSize;
                }


                LogItemParser* parser = new LogItemParser(startPos, stopPos, &lograwlist, this);
                connect(parser,SIGNAL(finished()),this,SLOT(threadFinished()));
                ParserThread.append(parser);
            }

            qDebug() << "LogFile::" << ParserThread.size() << " Thread erzeugt";

            //Starte Thraeds

            foreach(LogItemParser* parser,ParserThread)
            {
                parser->start();
            }

            qDebug() << "START::" << QTime::currentTime();

            startime = QTime::currentTime();
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

void LogFile::threadFinished(void)
{
    qDebug() << "LogFile::" << "Thread finished";

    foreach(LogItemParser* parser,ParserThread)
    {
        if(parser->isRunning())return;
    }    

    qDebug() << "LogFile::" << "all Thread are finished";

    qDebug() << "LogFile::Append LogItemLits to MainList" << QTime::currentTime();

    foreach(LogItemParser* parser,ParserThread)
    {
        this->LogItems.append(*parser->getLogItemList());
    }

    ParserThread.clear();
    lograwlist.clear();

    qDebug() << "LogFile::readFinished" << startime.msecsTo(QTime::currentTime()) << "msec";

    qDebug() << "LogFile::LogItemList:" << LogItems.size();

    emit this->readFinished();
}

QList<LogItemParser*>* LogFile::getParserThread(void)
{
   return &ParserThread;
}

int LogFile::getLines()
{
    return lineCount;
}

QTime LogFile::getStartTime()
{

    return startime;
}
