#ifndef LOGFILEFILTER_H
#define LOGFILEFILTER_H

#include <QtCore>
#include <QColor>

static int LogFileFilterPop = 0;

class LogFileFilter
{

public:

    LogFileFilter(): Type('-'), MessageID(-1), SourceID(-1),uid(LogFileFilterPop)
    {
            LogFileFilterPop++;
    }

    QColor color;

    QDateTime from;
    QDateTime to;
    QChar Type;
    int MessageID,SourceID;
    QString searchpattern;

    int getUID(void){return uid;}

private:

    int uid;

    friend bool operator==(LogFileFilter &lhs,const LogFileFilter &rhs);
    friend bool operator<(LogFileFilter lhs,LogFileFilter rhs);
    friend bool operator>(LogFileFilter lhs,LogFileFilter rhs);
};

/*
inline bool operator==(QChar c1, QChar c2) { return c1.unicode() == c2.unicode(); }
inline bool operator!=(QChar c1, QChar c2) { return c1.unicode() != c2.unicode(); }
inline bool operator<=(QChar c1, QChar c2) { return c1.unicode() <= c2.unicode(); }
inline bool operator>=(QChar c1, QChar c2) { return c1.unicode() >= c2.unicode(); }
*/
bool operator<(LogFileFilter lhs, LogFileFilter rhs);
bool operator>(LogFileFilter lhs, LogFileFilter rhs);

bool operator==(LogFileFilter &lhs,const LogFileFilter &rhs);

#endif // LOGFILEFILTER_H
