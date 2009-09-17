#include "logfile.h"
#include "logfilefilter.h"

#include <QDateTime>

LogFile::LogFile(QFile *_file):File(_file)
{
    if (_file->exists())
    {
        if(_file->open(QIODevice::ReadOnly))
        {
            QTextStream stream(_file);
            QList<QString> lograwlist;

            while(!stream.atEnd())
            {
                lograwlist.append(stream.readLine());
            }

            LogItem *item;

            for(int i = 0;i<lograwlist.size();i++)
            {
                item = new LogItem(lograwlist.at(i));
                if(item->getTimestamp().isValid())
                {
                    LogItems.append(item);
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

