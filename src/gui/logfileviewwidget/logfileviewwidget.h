#ifndef LOGFILEVIEWWIDGET_H
#define LOGFILEVIEWWIDGET_H

#include <QtGui>
#include <QTableView>
#include <QSplitter>

namespace Ui {
    class LogFileViewWidget;
}

class LogFileViewWidget : public QWidget {
    Q_OBJECT
public:
    LogFileViewWidget(QWidget *parent = 0);
    ~LogFileViewWidget();

protected:

    QTableView *top;
    QTableView *botton;
    QSplitter *split;
    QGridLayout *grid;

    void changeEvent(QEvent *e);

private:
    Ui::LogFileViewWidget *m_ui;
};

#endif // LOGFILEVIEWWIDGET_H
