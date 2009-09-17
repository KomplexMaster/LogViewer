#ifndef LOGVIEWDOCKWIDGET_H
#define LOGVIEWDOCKWIDGET_H

#include <QtGui/QDockWidget>
#include <QtGui>

#include "logfile.h"

namespace Ui {
    class LogViewDockWidget;
}

class LogViewDockWidget : public QDockWidget {
    Q_OBJECT
public:
    LogViewDockWidget(QWidget *parent = 0);
    ~LogViewDockWidget();

    void addLogLine(QAbstractItemModel *model, const QChar &type,
             const QDateTime &date, const int &messageid, const int &sourceid, const QString &unkownd, const QString &message, const QString &filename, const int &line);

protected:
    void changeEvent(QEvent *e);

    QList<LogFile>  LogFiles;

    QStandardItemModel filemodle;   //Modle für Dateien
    QStandardItemModel logunfilteredmodle;    //Modle für Logs
    QSortFilterProxyModel logfilteredmodle;    //Modle für gefilterte Logs

private:
    Ui::LogViewDockWidget *m_ui;
};

#endif // LOGVIEWDOCKWIDGET_H
