#include "logitemparser.h"

void LogItemParser::run(void)
{
    qDebug() << "LogItemParser::" << "Start at Pos:" << startPos << " to Pos:" << stopPos;

    for(i = startPos;i<stopPos;i++)      //Diese Schleife durchläuft das Array und erzeugt aus jeder Zeile ein LogItem
    {
        LogItem* item = new LogItem(lograwlist->at(i),i,this->parent);   //Dem Konstruktor von LogItem werden die aktuelle Zeile, die Zeilen Nummer und ein Pointer der Datei übergeben
        if(item->getTimestamp().isValid())      //Prüft ob der Zeitstempel richtig geparsst werden könnte
        {
            LogItems.append(item);              //Fügt das neue LogItem der LogItemListe hinzu
        }
    }

    qDebug() << "LogItemParser::" << "finished at Pos:" << i;

    emit finished();
}


LogItemParser::LogItemParser(int _startPos, int _stopPos, QList<QString>* _lograwlist, LogFile *_parent):startPos(_startPos), stopPos(_stopPos), lograwlist(_lograwlist), parent(_parent)
{
}

LogItemParser::~LogItemParser()
{
}

int LogItemParser::getStep(void)
{
    return i;
}

int LogItemParser::getframeWidth(void)
{
    return stopPos - startPos;
}

int LogItemParser::getstartPos(void)
{
    return startPos;
}

int LogItemParser::getstopPos(void)
{
    return stopPos;
}

QList<LogItem*>* LogItemParser::getLogItemList(void)
{
    return &LogItems;
}
