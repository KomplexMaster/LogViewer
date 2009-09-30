#include "logitem.h"

LogItem::LogItem(const QString LogLine, int _LineNumber, LogFile* _LogFile):LineNumber(_LineNumber), File(_LogFile)
{
    QStringList elements = LogLine.split("|");  //Aufteilen in einzellne Element

    if(elements.count()>4)	//�berpr�ft ob die Anzhal der Elemente passt, bei einer leeren LogZeile ist es nur 1 Element
    {
        Type = elements.at(Propertie::Type).at(0); 	//Type feststellen

        QString tmptime(elements.at(Propertie::Timestamp));	//Speichert den Teil der Zeile f�r Zeit in tmptime

        int d(tmptime.left(2).toInt());
        int M(tmptime.mid(3,2).toInt());
        int y(tmptime.mid(6,4).toInt());
        int h(tmptime.mid(11,2).toInt());
        int m(tmptime.mid(14,2).toInt());
        int s(tmptime.mid(17,2).toInt());
        int ms(tmptime.mid(20,3).toInt());
        Timestamp = QDateTime(QDate(y,M,d),QTime(h,m,s,ms));

        MessageID = elements.at(Propertie::MessageID).toInt();

        SourceID = elements.at(Propertie::SourceID).toInt();

        UNKOWND = elements.at(Propertie::UNKOWND);

        Message = elements.at(Propertie::Message);
    }
}

QChar LogItem::getType(void) const
{
    return Type;
}

QDateTime LogItem::getTimestamp(void) const
{
    return Timestamp;
}

int LogItem::getMessageID() const
{
    return MessageID;
}

int LogItem::getSourceID() const
{
    return SourceID;
}

QString LogItem::getUNKOWND() const
{
    return UNKOWND;
}

QString LogItem::getMessage(void) const
{
    return Message;
}

LogFile* LogItem::getLogFile(void) const
{
    return File;
}

int LogItem::getLineNumber(void) const
{
    return LineNumber;
}

QTextStream &operator<<(QTextStream &out,const LogItem &rhs)
{
    out << "Type:" << rhs.getType() << " Timestamp:";
    out << rhs.Timestamp.toString();
    return out;
}

bool LogItem::operator<(const LogItem& rhs) const
{
    if(Timestamp==rhs.getTimestamp())
    {
        return (LineNumber<rhs.getLineNumber());
    }
    return (Timestamp<rhs.getTimestamp());
}

bool LogItem::operator>(const LogItem& rhs) const
{
    if(Timestamp==rhs.getTimestamp())
    {
        return (LineNumber>rhs.getLineNumber());
    }
    return (Timestamp>rhs.getTimestamp());
}

bool LogItem::operator==(const LogItem& rhs) const
{
    if(Timestamp==rhs.getTimestamp())
    {
        return (LineNumber==rhs.getLineNumber());
    }
    return false;
}

bool LogItemlessThan( const LogItem *lhs, const LogItem *rhs )
{
    //qDebug() << lhs->getTimestamp() << "<->" << rhs->getTimestamp();
    return *lhs<*rhs;
}

bool LogItemlessThanType( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getType() < rhs->getType();
}

//Functionen zum Sortieren
//lessThan

bool LogItem::LogItemlessThanType( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getType() < rhs->getType();
}

bool LogItem::LogItemlessThanMessageID( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getMessageID() < rhs->getMessageID();
}

bool LogItem::LogItemlessThanSourceID( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getSourceID() < rhs->getSourceID();
}

bool LogItem::LogItemlessThanTimestamp( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getTimestamp() < rhs->getTimestamp();
}

bool LogItem::LogItemlessThanLineNumber( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getLineNumber() < rhs->getLineNumber();
}

bool LogItem::LogItemlessThanMessage( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getMessage() < rhs->getMessage();
}

//greater

bool LogItem::LogItemgreaterThanType( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getType() > rhs->getType();
}

bool LogItem::LogItemgreaterThanMessageID( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getMessageID() > rhs->getMessageID();
}

bool LogItem::LogItemgreaterThanSourceID( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getSourceID() > rhs->getSourceID();
}

bool LogItem::LogItemgreaterThanTimestamp( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getTimestamp() > rhs->getTimestamp();
}

bool LogItem::LogItemgreaterThanLineNumber( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getLineNumber() > rhs->getLineNumber();
}

bool LogItem::LogItemgreaterThanMessage( const LogItem *lhs, const LogItem *rhs )
{
    return lhs->getMessage() > rhs->getMessage();
}
