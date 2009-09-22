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

public slots:
    void setColor();
    void loadFilter(LogFileFilter filter);

protected:
    void changeEvent(QEvent *e);
    LogFileViewerFilterDockWidget* parent;

private:
    Ui::LogFileViewerFilterEditorDockWidget *m_ui;
};

#endif // LOGFILEVIEWERFILTEREDITORDOCKWIDGET_H
