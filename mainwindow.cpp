#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logitem.h"
#include "logfilefilter.h"
#include "logviewdockwidget.h"
#include "logdelegate.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{
    ui->setupUi(this);

    model = new LogFileModel(this);

    LogFileViewWidget* log = new LogFileViewWidget(model, this);
    ui->mdiArea->addSubWindow(log);

    ui->mdiArea->addSubWindow(new LogViewDockWidget(this));

    log->maximumSize();
    connect(model,SIGNAL(dataChanged(QModelIndex,QModelIndex)),this,SLOT(setCount()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionOpen_triggered()
{
    //QColor color = QColorDialog::getColor(Qt::green, this);
    QStringList FileNames = QFileDialog::getOpenFileNames(this, tr("Open Log"), "", tr("Log File (*.log)"));

    foreach(QString FileName,FileNames)
    {
        this->addLogFile(loadLogFile(new QFile(FileName)));
    }

    LogFileViewWidget* w =  qobject_cast<LogFileViewWidget *>(ui->mdiArea->currentSubWindow()->widget());

    if(w)w->addLogFile(this->LogFiles.last());

    refreshLogFileList();
}

LogFile* MainWindow::loadLogFile(QFile* _file)
{
    return new LogFile(_file);
}

void MainWindow::addLogFile(LogFile* _log)
{
    LogFiles.append(_log);
}

void MainWindow::refreshLogFileList()
{
    ui->listWidget->clear();
}

void MainWindow::selectLogFile(QModelIndex i)
{
    QList<QListWidgetItem*> lwItems =  ui->listWidget->selectedItems();

    //QList<LogFile*>* selectedLogs = new QList<LogFile*>();

    /*foreach(QListWidgetItem* lwItem,lwItems)
    {
        foreach(LogFile* file,LogFiles)
        {
            if(file->getFileName() == lwItem->text())
            {
                selectedLogs->append(file);
            }
        }
    }

    model->setLogFileList(selectedLogs);
*/
    this->setCount();
}

void MainWindow::refresh()
{
    //LogFile* log = model->getLogFile();
    LogFileFilter ffilter;

    ffilter.from = ui->dateTimeEditFrom->dateTime();
    ffilter.to   = ui->dateTimeEditTo->dateTime();

    if(!ui->lineEditMessageID->text().isEmpty())
    {
        ffilter.MessageID = ui->lineEditMessageID->text().toInt();
    }else{
        ffilter.MessageID = -1;
    }

    if(!ui->lineEditSourceID->text().isEmpty())
    {
        ffilter.SourceID = ui->lineEditSourceID->text().toInt();
    }else{
        ffilter.SourceID = -1;
    }

    if(!ui->comboBoxSeverity->currentIndex()==0)
    {
        switch(ui->comboBoxSeverity->currentIndex()-1)
        {
            case Type::Action: ffilter.Type = 'A';break;
            case Type::Information: ffilter.Type = 'I';break;
            case Type::Telegram: ffilter.Type = 'T';break;
            case Type::Warning: ffilter.Type = 'W';break;
            case Type::Recoverable: ffilter.Type = 'R';break;
            case Type::Error: ffilter.Type = 'E';break;
            case Type::Fatal: ffilter.Type = 'F';break;
            default: ffilter.Type = '-';break;
        }
    }else{
        ffilter.Type = '-';
    }

    if(!ui->lineEditSearch->text().isEmpty())
    {
        ffilter.searchpattern = ui->lineEditSearch->text();
    }

    //log->setLogFileFilter(ffilter);
    //log->filter(log->getLogItemList(),log->getFilteredLogItemList(), log->getLogFileFilter());

    //model->setLogFile(log);

    this->selectLogFile(QModelIndex());

    this->setCount();
}

void MainWindow::setCount()
{
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(QString::number(model->rowCount()) + tr(" LogItems in the list"));
}

void MainWindow::leftclick(QModelIndex index)
{
    if(index.column()==1)
    {
        //ui->tableView->actions().at(0)->setEnabled(true);
    }
    else
    {
        //ui->tableView->actions().at(0)->setEnabled(false);
    }
}

void MainWindow::setFilterColor()
{
    ui->pushButton->setPalette(QPalette(QColorDialog::getColor(Qt::green, this)));
}
