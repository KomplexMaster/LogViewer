#ifndef LOGITEMPARSERDIALOG_H
#define LOGITEMPARSERDIALOG_H

#include <QDialog>
#include "logfile.h"

namespace Ui {
    class LogItemParserDialog;
}

class LogItemParserDialog : public QDialog  //Dialog f�r Laden einer LogDatei
{
    Q_OBJECT
public:
    LogItemParserDialog(LogFile* logFile, QWidget *parent = 0);
    ~LogItemParserDialog();

protected:
    void changeEvent(QEvent *e);

    LogFile* logFile;                       //Pointer auf die zu ladendes LogFile

    QTimer* t;                              //Timer der die Pulse f�r refresh gibt
    QList<QProgressBar*> threadBars;        //Container mit den einzelnen ProgressBars f�r die Threads

private:
    Ui::LogItemParserDialog *ui;

public slots:

    void refresh(void);                     //SLOT aktuallisiert das Dialog und die ProgressBars
};

#endif // LOGITEMPARSERDIALOG_H
