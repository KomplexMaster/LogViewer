#include "logfilemodel.h"
#include "logitem.h"

int LogFileModel::rowCount(const QModelIndex &parent) const
{
    return LogItems.count();
}

int LogFileModel::frowCount(const QModelIndex &parent) const
{
    return FilterItemMap.value(-1)->count();
}


QVariant LogFileModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= LogItems.size())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case Propertie::Type:
                return QVariant(LogItems.at(index.row())->getType());
            case Propertie::Timestamp:
                return QVariant(LogItems.at(index.row())->getTimestamp().toString("dd.MM.yyyy hh:mm:ss:zzz"));
            case Propertie::MessageID:
                return QVariant(LogItems.at(index.row())->getMessageID());
            case Propertie::SourceID:
                return QVariant(LogItems.at(index.row())->getSourceID());
            case Propertie::UNKOWND:
                return QVariant(LogItems.at(index.row())->getUNKOWND());
            case Propertie::Message:
                return QVariant(LogItems.at(index.row())->getMessage());

            default:
                return QVariant("false");
        }
    }
     
    else
        return QVariant();
}

QVariant LogFileModel::fdata(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= FilterItemMap.value(-1)->size())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case Propertie::Type:
                return QVariant(FilterItemMap.value(-1)->at(index.row())->getType());
            case Propertie::Timestamp:
                return QVariant(FilterItemMap.value(-1)->at(index.row())->getTimestamp().toString("dd.MM.yyyy hh:mm:ss:zzz"));
            case Propertie::MessageID:
                return QVariant(FilterItemMap.value(-1)->at(index.row())->getMessageID());
            case Propertie::SourceID:
                return QVariant(FilterItemMap.value(-1)->at(index.row())->getSourceID());
            case Propertie::UNKOWND:
                return QVariant(FilterItemMap.value(-1)->at(index.row())->getUNKOWND());
            case Propertie::Message:
                return QVariant(FilterItemMap.value(-1)->at(index.row())->getMessage());

            default:
                return QVariant("false");
        }
    }

    else
        return QVariant();
}


QVariant LogFileModel::headerData(int section, Qt::Orientation orientation,
                                     int role) const
{
   if (role != Qt::DisplayRole
      || orientation != Qt::Horizontal)
      return QVariant();
   switch (section) {
      case Propertie::Type:
         return tr("Type");
      case Propertie::Timestamp:
         return tr("Time");
      case Propertie::MessageID:
         return tr("MessageID");
      case Propertie::SourceID:
         return tr("SourceID");
      case Propertie::UNKOWND:
         return tr("UNKOWND");
      case Propertie::Message:
         return tr("Message");
     default:
         break;
   }
   return QVariant();
}

int LogFileModel::columnCount(const QModelIndex &parent) const
{
    return 6;
}

QList<LogFile*>* LogFileModel::getLogFileList(void)
{
    return LogFiles;
}

void LogFileModel::setLogFileList(QList<LogFile*>* _LogFiles)
{
    delete LogFiles;

    LogFiles = _LogFiles;

    emit fileListchange();
}

void LogFileModel::addLogFile(LogFile* _LogFile)
{
    LogFiles->append(_LogFile);
    emit fileListchange();
}

void LogFileModel::delLogFile(LogFile* _LogFile)
{
    LogFiles->removeAt(LogFiles->indexOf(_LogFile));
    emit fileListchange();
}

void LogFileModel::refreshItemList()
{
    LogItems.clear();

    qDebug() << "LogFileModel::Clear FilterItemMap";

    FilterItemMap.clear();

    qDebug() << "LogFileModel::fill FilterItemMap";

    foreach(LogFileFilter filter, LogFileFilters)
    {
        FilterItemMap.insert(filter.getUID(),new QList<LogItem*>());
    }

    FilterItemMap.insert(-1,new QList<LogItem*>());

    qDebug() << "FilterItemMap" << FilterItemMap.count();
    qDebug() << "LogFileFilters" << LogFileFilters.count();

    qDebug() << "LogFileModel::RefreshItemList";

    foreach(LogFile* file,*LogFiles)
    {
        foreach(LogItem* item, *file->getLogItemList())
        {
            bool match = false;
            foreach(LogFileFilter filter, LogFileFilters)
            {
                if(LogFile::filter(item,filter))
                {
                    FilterItemMap.value(filter.getUID())->append(item);
                    match = true;
                }
            }
            LogItems.append(item);
            if(match)FilterItemMap.value(-1)->append(item);
        }
        qDebug() << "LogFileModel::LogFile:" << file->getFile()->fileName() << " Items:" << file->getLogItemList()->count();
    }

    qDebug() << "LogFileModel::LogItems count:" << LogItems.count() << " LogFiles count:" << this->LogFiles->count();

    emit reset();
}

QList<LogFileFilter> LogFileModel::getFilters(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return QList<LogFileFilter>();
    }

    if (index.row() >= LogItems.size())
    {
        return QList<LogFileFilter>();
    }

    QList<LogFileFilter> matchedfilter;

    foreach(LogFileFilter filter, LogFileFilters)
    {
        if(FilterItemMap.value(filter.getUID())->indexOf(LogItems.at(index.row()))!=-1)
        {
            matchedfilter.append(filter);
        }
    }

    return matchedfilter;
}

QList<LogFileFilter> LogFileModel::getfFilters(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return QList<LogFileFilter>();
    }

    if (index.row() >= FilterItemMap.value(-1)->size())
    {
        return QList<LogFileFilter>();
    }

    QList<LogFileFilter> matchedfilter;

    foreach(LogFileFilter filter, LogFileFilters)
    {
        if(FilterItemMap.value(filter.getUID())->indexOf(FilterItemMap.value(-1)->at(index.row()))!=-1)
        {
            matchedfilter.append(filter);
        }
    }

    return matchedfilter;
}

void LogFileModel::addLogFileFilter(LogFileFilter _LogFileFilter)
{
    LogFileFilters.append(_LogFileFilter);

    qDebug() << "LogFileModel::addLogFileFilter:" << _LogFileFilter.color;
    qDebug() << "LogFileModel::addLogFileFilter: Uid:" << _LogFileFilter.getUID();
    qDebug() << "LogFileModel::addLogFileFilter: LogFileFilters count" << LogFileFilters.count();

    emit filterListchange();
}
