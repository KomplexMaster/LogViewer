#include "logfilemodel.h"
#include "logitem.h"

int LogFileModel::rowCount(const QModelIndex &parent) const
{
    return LogItems.count();
}

int LogFileModel::frowCount(const QModelIndex &parent) const
{
    return FilterLogItem.count();
}


QVariant LogFileModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (index.row() >= LogItems.size())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        LogItem* item = LogItems.at(index.row());

        switch (index.column())
        {
            case Propertie::Type:
                return QVariant(item->getType());
            case Propertie::Timestamp:
                return QVariant(item->getTimestamp().toString("dd.MM.yyyy hh:mm:ss:zzz"));
            case Propertie::MessageID:
                return QVariant(item->getMessageID());
            case Propertie::SourceID:
                return QVariant(item->getSourceID());
            case Propertie::UNKOWND:
                return QVariant(item->getUNKOWND());
            case Propertie::Message:
                return QVariant(item->getMessage());
            case Propertie::LineNumber:
                return QVariant(item->getLineNumber());
            case Propertie::LogFile:
                return QVariant(item->getLogFile()->getFile()->fileName());
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

    if (index.row() >= FilterLogItem.size())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        switch (index.column())
        {
            case Propertie::Type:
                return QVariant(FilterLogItem.at(index.row())->getType());
            case Propertie::Timestamp:
                return QVariant(FilterLogItem.at(index.row())->getTimestamp().toString("dd.MM.yyyy hh:mm:ss:zzz"));
            case Propertie::MessageID:
                return QVariant(FilterLogItem.at(index.row())->getMessageID());
            case Propertie::SourceID:
                return QVariant(FilterLogItem.at(index.row())->getSourceID());
            case Propertie::UNKOWND:
                return QVariant(FilterLogItem.at(index.row())->getUNKOWND());
            case Propertie::Message:
                return QVariant(FilterLogItem.at(index.row())->getMessage());

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
      case Propertie::LineNumber:
         return tr("Line");
      case Propertie::LogFile:
         return tr("LogFile");
     default:
         break;
   }
   return QVariant();
}

int LogFileModel::columnCount(const QModelIndex &parent) const
{
    return 8;
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

    connect(_LogFile,SIGNAL(readFinished()),this,SLOT(refreshItemList()));
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

    FilterLogItem.clear();

    qDebug() << "LogFileModel::fill FilterItemMap";

    qDebug() << "LogFileFilters" << LogFileFilters.count();

    qDebug() << "LogFileModel::RefreshItemList";

    foreach(LogFile* file,*LogFiles)                    // geht alle LogFiles durch
    {
        foreach(LogItem* item, *file->getLogItemList()) // geht jedes LogItem des LogFiles durch
        {
            bool match = false;
            foreach(LogFileFilter filter, LogFileFilters)
            {
                if(LogFile::filter(item,filter))
                {
                    FilterLogItem.append(item);
                    match = true;
                    break;
                }
            }
            LogItems.append(item);
            if(match)FilterLogItem.append(item);
        }
        qDebug() << "LogFileModel::LogFile:" << file->getFile()->fileName() << " Items:" << file->getLogItemList()->count();
    }

    qDebug() << "LogFileModel::LogItems count:" << LogItems.count() << " LogFiles count:" << this->LogFiles->count();

    emit reset();
}

QList<LogFileFilter> LogFileModel::getFiltersFromIndex(const QModelIndex &index) const
{
    if (!index.isValid())               //Überprüft auf gültichkeit des index
    {
        return QList<LogFileFilter>();  //Wenn ungültig wird eine leere Liste zurück gegeben
    }

    if (index.row() >= LogItems.size()) //Überprüft ob index ausserhalb der daten Liegt;
    {
        return QList<LogFileFilter>();  //Wenn ja, wird wieder eine leere Liste zurück gegeben
    }

    QList<LogFileFilter> matchedfilter; //Liste Mit allen Filtern auf der das LogItem passt

    foreach(LogFileFilter filter, LogFileFilters)
    {
        if(LogFile::filter(LogItems.at(index.row()),filter))
        {
            matchedfilter.append(filter);
        }
    }

    return matchedfilter;
}

QList<LogFileFilter> LogFileModel::getfFiltersFromIndex(const QModelIndex &index) const
{
    if (!index.isValid())
    {
        return QList<LogFileFilter>();
    }

    if (index.row() >= FilterLogItem.size())
    {
        return QList<LogFileFilter>();
    }

    QList<LogFileFilter> matchedfilter; //Liste Mit allen Filtern auf der das LogItem passt

    foreach(LogFileFilter filter, LogFileFilters)
    {
        if(LogFile::filter(FilterLogItem.at(index.row()),filter))
        {
            matchedfilter.append(filter);
        }
    }

    return matchedfilter;
}

void LogFileModel::addFilter(LogFileFilter _LogFileFilter)
{
    LogFileFilters.append(_LogFileFilter);

    qDebug() << "LogFileModel::addFilter:" << _LogFileFilter.color;
    qDebug() << "LogFileModel::addFilter: Uid:" << _LogFileFilter.getUID();
    qDebug() << "LogFileModel::addFilter: LogFileFilters count" << LogFileFilters.count();

    emit filterListchange();
}

void LogFileModel::sortItems(void)
{

}

QList<LogFileFilter>* LogFileModel::getFilters()
{
    return &LogFileFilters;
}

void LogFileModel::storeFilter(LogFileFilter filter)
{
    qDebug() << "LogFileModel::storeFilter: LogFileFilters count" << LogFileFilters.count();

    foreach(LogFileFilter currentFilter, LogFileFilters)
    {
        if(currentFilter.getUID()==filter.getUID())
        {
            LogFileFilters.replace(LogFileFilters.indexOf(currentFilter),filter);

            emit filterListchange();
            refreshItemList();

            qDebug() << "LogFileModel::storeFilter: Filter change";

            return;
        }
    }

    qDebug() << "LogFileModel::storeFilter: Filter added";

    LogFileFilters.append(filter);
    emit filterListchange();
    refreshItemList();
}
