#include "logfilemodel.h"
#include "logitem.h"

int LogFileModel::rowCount(const QModelIndex &parent) const
{
    return LogItems->count();
}

QVariant LogFileModel::data(const QModelIndex &index, int role) const
{
    //qDebug() << "index.column()" << index.column() << "index.row()" << index.row();
    if (!index.isValid())
        return QVariant();

    if (index.row() >= LogItems->size())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        LogItem* item = LogItems->at(index.row());

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

void LogFileModel::sort( int column, Qt::SortOrder order )
{
    emit reset();
}

LogFileModel::LogFileModel( LogFileJar *_parent) : QAbstractTableModel(parent), parent(_parent)
{
    setHeaderData(0, Qt::Horizontal, QObject::tr("Name"));
    setHeaderData(1, Qt::Horizontal, QObject::tr("Color"));
    setHeaderData(2, Qt::Horizontal, QObject::tr("ID"));
    setHeaderData(3, Qt::Horizontal, QObject::tr("Hash"));

    LogItems = _parent->getLogItemList();

    connect(_parent,SIGNAL(changeData()),this,SLOT(dataLoaded()));
}

void LogFileModel::dataLoaded()
{
    reset();
}
