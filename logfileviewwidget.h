#ifndef LOGFILEVIEWWIDGET_H
#define LOGFILEVIEWWIDGET_H

#include <QtGui>
#include <QTableView>
#include <QSplitter>
#include "logfileviewwidgetindexbar.h"
#include "logfilemodel.h"
#include "logfileproxymodel.h"

namespace Ui {
    class LogFileViewWidget;
}

class LogFileViewWidget : public QWidget {
    Q_OBJECT
public:
    LogFileViewWidget(LogFileModel *_model = 0, QWidget *parent = 0);
    ~LogFileViewWidget();

public slots:

    void addLogFile(LogFile* _LogFile);
    void delLogFile(LogFile* _LogFile);

    void jumpToLine();

signals:

    void changeLogFiles();

protected:

    LogFileModel           *model;
    LogFileProxyModel *proxymodel;

    LogFileViewWidgetIndexBar *indexbar;
    QTableView *top;
    QTableView *botton;
    QSplitter *split;
    QGridLayout *grid;

    void changeEvent(QEvent *e);

private:
    Ui::LogFileViewWidget *m_ui;
};

#endif // LOGFILEVIEWWIDGET_H
