#include "logfilefilter.h"

bool operator==(LogFileFilter &lhs,const LogFileFilter &rhs)
{
    if(lhs.color!=rhs.color)return false;
    if(lhs.from!=rhs.from)return false;
    if(lhs.MessageID!=rhs.MessageID)return false;
    if(lhs.searchpattern!=rhs.searchpattern)return false;
    if(lhs.SourceID!=rhs.SourceID)return false;
    if(lhs.to!=rhs.to)return false;
    if(lhs.Type!=rhs.Type)return false;

    return true;
}

bool operator<(LogFileFilter lhs,const LogFileFilter rhs)
{
    if(lhs.uid==rhs.uid)return false;
    if(lhs.uid<rhs.uid)return true;
    return false;
}
bool operator>(LogFileFilter lhs,const LogFileFilter rhs)
{
    if(lhs.uid==rhs.uid)return false;
    if(lhs.uid>rhs.uid)return true;
    return false;
}
