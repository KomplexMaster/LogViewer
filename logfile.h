#ifndef LOGFILE_H
#define LOGFILE_H

#include <QTGUI>
#include "logfilefilter.h"
#include "logitemparser.h"

class LogItem;

typedef QList<LogItem*> LogItemList;

class LogFile : public QObject       // LogFile ist ein Container f�r LogItems einer .log
{

    Q_OBJECT

protected:
    LogItemList     LogItems;           //enh�lt alle LogItems dieses LogFiles
    QFile*          File;               //enh�lt Name des LogFiles
    LogFileFilter   LogFilter;          //Filter dieses LogFiles
    QTime           startime;           //TimeStamp der zu beginn des Paresvorgangs gesetzt wird, wird zum berechen der Geschwindigkeit benutzt lps (Zeilen pro Sekunde)

    QList<LogItemParser*> ParserThread; //Container mit Pointer f�r einzelne Threads
    QList<QString> lograwlist;          //Alle Zeilen des LogFiles werden in dem Array lograwlist zwischengespeicher

    int             threadCount;        //Anzahl der Thread die zum Pasern gestaret werden
    int             lineCount;          //Z�hler der angibt wie viel Zeilen das LogFile besitzt

    QSettings       settings;

public:

    LogFile(QFile *_file);
    virtual ~LogFile();

    bool isLoaded();                         //liefert true zur�ck falls alle Threads Fertig sind;

    LogItemList*    getLogItemList(void);   //Liefert Liste alle LogItem zur�ck
    int             getLinesCount(void);    //Anzahl der Zeilen des LogFiles
    QTime           getStartTime(void);     //Liefert startime
    QFile*          getFile(void);          //Liefer das File zur�ck
    QList<LogItemParser*>* getParserThread(void);

    LogFileFilter getFilter(void);
    void setFilter(LogFileFilter _filter);

    static void filter(LogItemList* in, LogItemList* out, LogFileFilter filter);
    static bool filter(LogItem* in, LogFileFilter filter);
    static bool FilterCheck(LogItem* in, LogFileFilter filter);

    int count();

public slots:

    void threadFinished(void);          //Threads stossen diesen Slot nach ihrer Beendigung an, dabei wird �berpr�fft ob noch weitere Threads am laufen sind,
                                        //und gegebenenfalls das readFinishd Signal ausgel�st

signals:

    void readFinished(void);            //Signal wird nach beendigung aller Parsevorg�nge ausgel�st, Bei diesen Signal ist das LogFile komplet geladen
};

#endif // LOGFILE_H
