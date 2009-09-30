#ifndef LOGFILE_H
#define LOGFILE_H

#include <QTGUI>
#include "logfilefilter.h"
#include "logitemparser.h"

class LogItem;

typedef QList<LogItem*> LogItemList;

class LogFile : public QObject       // LogFile ist ein Container für LogItems einer .log
{

    Q_OBJECT

protected:
    LogItemList     LogItems;           //enhält alle LogItems dieses LogFiles
    QFile*          File;               //enhält Name des LogFiles
    LogFileFilter   LogFilter;          //Filter dieses LogFiles
    QTime           startime;           //TimeStamp der zu beginn des Paresvorgangs gesetzt wird, wird zum berechen der Geschwindigkeit benutzt lps (Zeilen pro Sekunde)

    QList<LogItemParser*> ParserThread; //Container mit Pointer für einzelne Threads
    QList<QString> lograwlist;          //Alle Zeilen des LogFiles werden in dem Array lograwlist zwischengespeicher

    int             threadCount;        //Anzahl der Thread die zum Pasern gestaret werden
    int             lineCount;          //Zähler der angibt wie viel Zeilen das LogFile besitzt

    QSettings       settings;

public:

    LogFile(QFile *_file);
    virtual ~LogFile();

    bool isLoaded();                         //liefert true zurück falls alle Threads Fertig sind;

    LogItemList*    getLogItemList(void);   //Liefert Liste alle LogItem zurück
    int             getLinesCount(void);    //Anzahl der Zeilen des LogFiles
    QTime           getStartTime(void);     //Liefert startime
    QFile*          getFile(void);          //Liefer das File zurück
    QList<LogItemParser*>* getParserThread(void);

    LogFileFilter getFilter(void);
    void setFilter(LogFileFilter _filter);

    static void filter(LogItemList* in, LogItemList* out, LogFileFilter filter);
    static bool filter(LogItem* in, LogFileFilter filter);
    static bool FilterCheck(LogItem* in, LogFileFilter filter);

    int count();

public slots:

    void threadFinished(void);          //Threads stossen diesen Slot nach ihrer Beendigung an, dabei wird überprüfft ob noch weitere Threads am laufen sind,
                                        //und gegebenenfalls das readFinishd Signal ausgelöst

signals:

    void readFinished(void);            //Signal wird nach beendigung aller Parsevorgänge ausgelöst, Bei diesen Signal ist das LogFile komplet geladen
};

#endif // LOGFILE_H
