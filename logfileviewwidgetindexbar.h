#ifndef LOGFILEVIEWWIDGETINDEXBAR_H
#define LOGFILEVIEWWIDGETINDEXBAR_H

#include <QWidget>
#include <QTableView>
#include "logfilemodel.h"

class LogFileViewWidgetIndexBar : public QWidget
{
protected:
    QTableView* tView;
    void paintEvent(QPaintEvent* event);

    QPixmap* scale;

public:
    LogFileViewWidgetIndexBar(QTableView* _tView, QWidget *parent = 0);
    QSize minimumSize(void);
public slots:

    void recalScale(void);
};

#endif // LOGFILEVIEWWIDGETINDEXBAR_H
