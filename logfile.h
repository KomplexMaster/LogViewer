#ifndef LOGFILE_H
#define LOGFILE_H

#include <QTGUI>
#include "logitem.h"
#include "logfilefilter.h"

class LogFile
{
protected:
    LogItemList     LogItems;           //enhält alle LogItems dieses LogFiles
    QFile*          File;               //enhält Name des LogFiles
    LogFileFilter   LogFilter;          //Filter dieses LogFiles

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
};

#endif // LOGFILE_H
