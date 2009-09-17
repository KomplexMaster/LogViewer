#ifndef LOGITEM_H
#define LOGITEM_H

#include <QtGui>


class LogItem;

typedef QList<LogItem*> LogItemList;

namespace Propertie
{
    enum Propertie {Type,Timestamp,MessageID,SourceID,UNKOWND,Message};
}
namespace Type
{
    enum Type {Action, Information, Telegram, Warning, Recoverable, Error, Fatal, All};
}

class LogItem

// LogItem ist eine Zeile eines LogFiles, alle Daten sind geparst

{

public:

    LogItem(const QString LogLine);		//Konstruktor wird eine Zeile der Logdatei übergeben und liefert ein LogItem

    QChar          getType(void) const;	//GetFunc für Type
    QDateTime getTimestamp(void) const;	//GetFunc für Timestamp
    int       getMessageID(void) const;	//GetFunc für MessageID
    int        getSourceID(void) const;	//GetFunc für SourceID
    QString     getUNKOWND(void) const;	//GetFunc für UNKOWN
    QString     getMessage(void) const;	//GetFunc für Message
	
    friend QTextStream &operator<<(QTextStream &out,const LogItem &rhs); //Function um ein LogItem leicht durch qDebug auszugeben

protected:

    int LogItemID;		//LogItem ID, ist eine uid
    QChar Type;			//Typ der LogZeile (Warning, Information, ...)
    QString Message; 	//Die Meldung der LogZeile
    QString UNKOWND;	//Was, wo ich nicht blicke wozu man des brauchen könnte, sinloses zeuch halt
    int SourceID;		//Source ID der Zeile
    int MessageID;		//Message ID der Zeile
    QDateTime Timestamp;//Zeitstempel in QDateTime Format
};

QTextStream &operator<<(QTextStream &out,const LogItem &rhs); //Function um ein LogItem leicht durch qDebug auszugeben

#endif // LOGITEM_H
