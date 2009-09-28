#include "logfile.h"
#include "logitem.h"
#include "logfilefilter.h"

#include <QDateTime>

LogFile::LogFile(QFile *_file):File(_file)
{
    threadCount = settings.value("LogFile/threadCount").toInt();

    if(threadCount<1)
    {
        settings.setValue("LogFile/threadCount","1");
        threadCount = 1;
    }

    if (_file->exists())                                //Überprüft ob LogFile existiert
    {
        if(_file->open(QIODevice::ReadOnly))            //Überprüft ob LogFile geöffnet werden kann
        {
            QTextStream stream(_file);                  //Erstellt TextStream zum auslesen der Datei

            while(!stream.atEnd())                      //Schleife die, die Zeilen des LogFiles in das Array läd
            {
                lograwlist.append(stream.readLine());
            }

            lineCount = lograwlist.size();              //setzt lineCount auf Anzahl der RohZeilen (Zeilen die nicht gelesen werden können, werden ignoriert)

            qDebug() << "LogFile::" << "LogRawList:" << lograwlist.size();

            //Erzeugen der Threads

            int startPos,stopPos;
            int frameSize(lograwlist.size()/threadCount);   //Berechnet die Grösse der Frames nach (Zeilen Anzahl) / (Anzahl der Threads)

            for(int i = 0;i<threadCount;i++)                //Diese Schleife erzeugt die Threads und Speichert sie in der Liste ParserThread
            {
                startPos = i*frameSize;                     //Berechnet die StartPosition im LogRawList Array für den Thread

                if(i==threadCount)                          //Wenn der Letzte Thread gestartet wird, ist die StopPosition automatisch das ende des LogRawList Arrays
                {
                    stopPos = lograwlist.size();
                }
                else                                        //StopPosition wird nach Start + FrameGrösse berechnet
                {
                    stopPos = startPos+frameSize;
                }


                LogItemParser* parser = new LogItemParser(startPos, stopPos, &lograwlist, this);    //Erzeugt den Thread
                connect(parser,SIGNAL(finished()),this,SLOT(threadFinished()));                     //Wenn der Thread beendet ist löst er den Slot threadFinished aus
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

    while(ParserThread.size()!=0)ParserThread.clear();

    lograwlist.clear();

    qDebug() << "LogFile::readFinished" << startime.msecsTo(QTime::currentTime()) << "msec";

    qDebug() << "LogFile::LogItemList:" << LogItems.size();

    qDebug() << "LogFile::ParserThread:" << ParserThread.size();

    qDebug() << (LogItems.at(0) < LogItems.at(1));
    qDebug() << (LogItems.at(1) < LogItems.at(2));
    qDebug() << (LogItems.at(2) < LogItems.at(3));
    qDebug() << (LogItems.at(3) < LogItems.at(4));
    qDebug() << (LogItems.at(4) < LogItems.at(5));

    emit this->readFinished();
}

QList<LogItemParser*>* LogFile::getParserThread(void)
{
   return &ParserThread;
}

int LogFile::getLinesCount()
{
    return lineCount;
}

QTime LogFile::getStartTime()
{

    return startime;
}

LogFile::~LogFile()
{
    foreach(LogItemParser* parser, ParserThread)
    {
        delete parser;
    }
}
