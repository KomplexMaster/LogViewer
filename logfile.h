#ifndef LOGFILE_H
#define LOGFILE_H

#include <QTGUI>
#include "logfilefilter.h"
#include "logitemparser.h"

class LogItem;

typedef QList<LogItem*> LogItemList;

class LogFile : public QObject
{

    Q_OBJECT

protected:
    LogItemList     LogItems;           //enhält alle LogItems dieses LogFiles
    QFile*          File;               //enhält Name des LogFiles
    LogFileFilter   LogFilter;          //Filter dieses LogFiles

    QList<LogItemParser*> ParserThread; //Container mit Pointer für einzelne Threads

    int threadCount;                    //Anzahl der Thread die zum Pasern gestaret werden

    QList<QString> lograwlist;                  //Alle Zeilen des LogFiles werden in dem Array lograwlist zwischengespeichert
public:

    LogFile(QFile *_file);
    //virtual ~LogFile();

    LogItemList* getLogItemList(void);
    
    QFile* getFile(void);

    LogFileFilter getFilter(void);
    void setFilter(LogFileFilter _filter);

    static void filter(LogItemList* in, LogItemList* out, LogFileFilter filter);
    static bool filter(LogItem* in, LogFileFilter filter);

    int count();

signals:

    void readFinished(void);
};

#endif // LOGFILE_H
