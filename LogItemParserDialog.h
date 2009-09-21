#ifndef LOGITEMPARSERDIALOG_H
#define LOGITEMPARSERDIALOG_H

#include <QDialog>
#include "logfile.h"

namespace Ui {
    class LogItemParserDialog;
}

class LogItemParserDialog : public QDialog {
    Q_OBJECT
public:
    LogItemParserDialog(LogFile* logFile, QWidget *parent = 0);
    ~LogItemParserDialog();

protected:
    void changeEvent(QEvent *e);

    LogFile* logFile;

    QTimer* t;
    QList<QProgressBar*> threadBars;

private:
    Ui::LogItemParserDialog *ui;

public slots:

    void refresh(void);
};

#endif // LOGITEMPARSERDIALOG_H
