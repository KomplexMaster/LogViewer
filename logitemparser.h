#ifndef LOGITEMPARSER_H
#define LOGITEMPARSER_H

#include <QThread>
#include <QTGUI>

#include <logitem.h>

class LogFile;

/*

    LogItemParser ist ein Thread der dazu dient die Zeilen einer LogDatei zu Parsen.
    Dazu werden die einzelnen Zeilen in den Speicher gelesen und dem LogItemParser
    übergeben, mit einer Star- und einer StopPosition. Zwischen diesen Positionen
    arbeiten der Parser die LogZeilen ab und Speichern die LogItems intern in einer
    LogItemList ab.

*/

class LogItemParser : public QThread
{
    Q_OBJECT

    public:

        LogItemParser(int _startPos, int _stopPos, LogFile *parent);
        ~LogItemParser();

        // Getter Setter

        int getframeWidth(void);        //gibt die grösse der des zu prasenden Bereichs an
        int getstartPos(void);          //startPos
        int getstopPos(void);           //stopPos
        int getStep(void);              //mom pos der zu parsenden Zeile

    protected:

        int startPos;                   //start des zu parsenden Bereichs
        int stopPos;                    //ende des zu parsenden Bereichs
        int i;                          //dient als LoopVariable

        LogFile* parent;                //Pointer auf das LogFile das den Thread gestartet hat (wird zum erzeugen der LogItems benötigt)

        QList<QString> *lograwlist;     //Pointer zu den zu parsenden LogZeilen
        LogItemList LogItems;           //Container mit den geparsden LogItems

        void run(void);

    signals:

        void finished();                //wird nach bedendigung des Pasevorgangs ausgelöst (wer hättes es gedacht?)
};

#endif // LOGITEMPARSER_H
