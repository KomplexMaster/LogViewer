#ifndef LOGITEM_H
#define LOGITEM_H

#include <QtGui>


class LogItem;
class LogFile;

namespace Propertie
{
    enum Propertie {Type,Timestamp,MessageID,SourceID,UNKOWND,Message,LineNumber,LogFile};
}
namespace Type
{
    enum Type {Action, Information, Telegram, Warning, Recoverable, Error, Fatal, All};
}

class LogItem       // LogItem ist eine Zeile eines LogFiles, alle Daten sind geparst
{

public:

    LogItem(const QString LogLine,int LineNumber, LogFile* _LogFile);		//Konstruktor wird eine Zeile der Logdatei �bergeben und liefert ein LogItem

    QChar          getType(void) const;	//GetFunc f�r Type
    QDateTime getTimestamp(void) const;	//GetFunc f�r Timestamp
    int       getMessageID(void) const;	//GetFunc f�r MessageID
    int        getSourceID(void) const;	//GetFunc f�r SourceID
    QString     getUNKOWND(void) const;	//GetFunc f�r UNKOWN
    QString     getMessage(void) const;	//GetFunc f�r Message
    int      getLineNumber(void) const; //GetFunc f�r LineNumber
    LogFile*    getLogFile(void) const; //GetFunc f�r LogFile

    friend QTextStream &operator<<(QTextStream &out,const LogItem &rhs); //Function um ein LogItem leicht durch qDebug auszugeben
    //friend QTextStream &operator<<(QTextStream &out,const LogItem* rhs); //Function um ein LogItem leicht durch qDebug auszugeben

    bool operator<(const LogItem& rhs) const;
    bool operator>(const LogItem& rhs) const;
    bool operator==(const LogItem& rhs) const;
    static bool lessThan( const LogItem &lhs, const LogItem &rhs ){ return lhs<rhs;};
    static bool lessThan( const LogItem *lhs, const LogItem *rhs ){ return *lhs<*rhs;};

    static bool LogItemlessThanType( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemlessThanMessageID( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemlessThanSourceID( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemlessThanTimestamp( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemlessThanLineNumber( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemlessThanMessage( const LogItem *lhs, const LogItem *rhs );

    static bool LogItemgreaterThanType( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemgreaterThanMessageID( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemgreaterThanSourceID( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemgreaterThanTimestamp( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemgreaterThanLineNumber( const LogItem *lhs, const LogItem *rhs );
    static bool LogItemgreaterThanMessage( const LogItem *lhs, const LogItem *rhs );

protected:

    int LogItemID;		//LogItem ID, ist eine uid
    QChar Type;			//Typ der LogZeile (Warning, Information, ...)
    QString Message;            //Die Meldung der LogZeile
    QString UNKOWND;            //Was, wo ich nicht blicke wozu man des brauchen k�nnte, sinloses zeuch halt
    int SourceID;		//Source ID der Zeile
    int MessageID;		//Message ID der Zeile
    QDateTime Timestamp;        //Zeitstempel in QDateTime Format


    int LineNumber;             //Zeile des LogFiles
    LogFile *File;              //Pointer auf die Date aus der die Zeile ausgelesen wurde.
};

QTextStream &operator<<(QTextStream &out,const LogItem &rhs); //Function um ein LogItem leicht durch qDebug auszugeben

bool LogItemlessThan( const LogItem *lhs, const LogItem *rhs );

#endif // LOGITEM_H
