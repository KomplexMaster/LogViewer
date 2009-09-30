#ifndef LOGFILEVIEWWIDGETINDEXBAR_H
#define LOGFILEVIEWWIDGETINDEXBAR_H

#include <QWidget>
#include "logfileviewwidget.h"

class LogFileViewWidget;

class LogFileViewWidgetIndexBar : public QWidget
{
    Q_OBJECT

protected:

    LogFileViewWidget* parent;

    void paintEvent(QPaintEvent* event);

    QPixmap* scale;

public:
    LogFileViewWidgetIndexBar(LogFileViewWidget *parent);

    QSize minimumSize(void);

public slots:

    void recalScale(void);
};

#endif // LOGFILEVIEWWIDGETINDEXBAR_H
