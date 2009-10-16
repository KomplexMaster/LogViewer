#ifndef LOGFILEVIEWERFILTERDOCKWIDGET_H
#define LOGFILEVIEWERFILTERDOCKWIDGET_H

#include <QDockWidget>

#include "logfilefiltermodel.h"
#include "logfileviewwidget.h"

namespace Ui {
    class LogFileViewerFilterDockWidget;
}

class LogFileViewerFilterDockWidget : public QDockWidget {
    Q_OBJECT
public:
    LogFileViewerFilterDockWidget(LogFileViewWidget *parent);
    ~LogFileViewerFilterDockWidget();

public slots:

    void storeFilter(LogFileFilter filter);
    void addFilter();
    void delFilter();

private slots:

    void selectFilter(QModelIndex);

signals:

    void changeFilter(LogFileFilter filter);

protected:
    LogFileFilter filter;

    LogFileViewWidget *parent;
    LogFileFilterModel *model;

    QTreeView* sourceView;

    void changeEvent(QEvent *e);
    void addFilter(LogFileFilter* filter);

private:
    Ui::LogFileViewerFilterDockWidget *ui;
};

#endif // LOGFILEVIEWERFILTERDOCKWIDGET_H
