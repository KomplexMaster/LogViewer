#ifndef LOGFILEVIEWERFILTEREDITORDOCKWIDGET_H
#define LOGFILEVIEWERFILTEREDITORDOCKWIDGET_H

#include <QtGui/QDockWidget>

#include "logfileviewerfilterdockwidget.h"

namespace Ui {
    class LogFileViewerFilterEditorDockWidget;
}

class LogFileViewerFilterEditorDockWidget : public QDockWidget {
    Q_OBJECT
public:
    LogFileViewerFilterEditorDockWidget(LogFileViewerFilterDockWidget *parent = 0);
    ~LogFileViewerFilterEditorDockWidget();

    LogFileFilter getLogFileFilter(void);


public slots:
    void setColor();
    void setFilter(LogFileFilter _filter);
    void setFrom(QDateTime _from);
    void setTo(QDateTime _to);

    void setSearchPattern();
    void setMessageID();
    void setSourceID();

    void storeFilter();

protected:
    void changeEvent(QEvent *e);
    LogFileViewerFilterDockWidget* parent;
    LogFileFilter filter;

private:
    Ui::LogFileViewerFilterEditorDockWidget *m_ui;
};

#endif // LOGFILEVIEWERFILTEREDITORDOCKWIDGET_H
