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
{

public:

    LogItem(const QString LogLine);

    QChar          getType(void) const;
    QDateTime getTimestamp(void) const;
    int       getMessageID(void) const;
    int        getSourceID(void) const;
    QString     getUNKOWND(void) const;
    QString     getMessage(void) const;

    friend QTextStream &operator<<(QTextStream &out,const LogItem &rhs);

protected:

    int LogItemID;

    QChar Type;

    QString Message;
    QString UNKOWND;

    int SourceID;
    int MessageID;

    QDateTime Timestamp;
};

QTextStream &operator<<(QTextStream &out,const LogItem &rhs);

#endif // LOGITEM_H
