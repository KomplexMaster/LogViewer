#ifndef LOGFILEVIEWERFILTERDOCKWIDGET_H
#define LOGFILEVIEWERFILTERDOCKWIDGET_H

#include <QDockWidget>

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

    void filterChange(void);

private slots:

    void selectFilter(QModelIndex);

signals:

    void filterselect(LogFileFilter filter);

protected:
    LogFileViewWidget *parent;
    QStandardItemModel *model;

    QTreeView* sourceView;

    void changeEvent(QEvent *e);
    void addFilter(LogFileFilter* filter);

private:
    Ui::LogFileViewerFilterDockWidget *ui;
};

#endif // LOGFILEVIEWERFILTERDOCKWIDGET_H
