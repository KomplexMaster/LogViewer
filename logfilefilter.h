#ifndef LOGFILEFILTER_H
#define LOGFILEFILTER_H

#include <QtCore>
#include <QColor>

static int LogFileFilterPop = 0;

class LogFileFilter
{

public:

    LogFileFilter(): Color(Qt::white), Type('-'), MessageID(-1), SourceID(-1),invert(false),uid(LogFileFilterPop)
    {
            LogFileFilterPop++;
    }

    QColor Color;

    QDateTime from;
    QDateTime to;
    QChar Type;
    int MessageID,SourceID;
    QString searchpattern;
    QString name;
    bool invert;


    int getUID(void){return uid;}

    friend QTextStream &operator<<(QTextStream &out,const LogFileFilter &rhs); //Function um ein LogFileFilter leicht durch qDebug auszugeben

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

QTextStream &operator<<(QTextStream &out,const LogFileFilter &rhs); //Function um ein LogFileFilter leicht durch qDebug auszugeben

#endif // LOGFILEFILTER_H
