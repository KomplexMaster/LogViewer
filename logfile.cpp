#include "logfile.h"
#include "logitem.h"
#include "logfilefilter.h"

#include <QDateTime>

LogFile::LogFile(QFile *_file):File(_file)
{
    if (_file->exists())                                //Überprüft ob LogFile existiert
    {
        if(_file->open(QIODevice::ReadOnly))            //Überprüft ob LogFile geöffnet werden kann
        {
            QTextStream stream(_file);                  //Erstellt TextStream zum auslesen der Datei
            QList<QString> lograwlist;                  //Alle Zeilen des LogFiles werden in dem Array lograwlist zwischengespeichert

            while(!stream.atEnd())                      //Schleife die, die Zeilen des LogFiles in das Array läd
            {
                lograwlist.append(stream.readLine());
            }

            LogItem *item;                              //*item dient hals Hilfvariable

            for(int i = 0;i<lograwlist.size();i++)      //Diese Schleife durchläuft das Array und erzeugt aus jeder Zeile ein LogItem
            {
                item = new LogItem(lograwlist.at(i),i,this);   //Dem Konstruktor von LogItem werden die aktuelle Zeile, die Zeilen Nummer und ein Pointer der Datei übergeben
                if(item->getTimestamp().isValid())      //Prüft ob der Zeitstempel richtig geparsst werden könnte
                {
                    LogItems.append(item);              //Fügt das neue LogItem der LogItemListe hinzu
                }
            }
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

