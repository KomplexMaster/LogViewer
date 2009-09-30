#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logitem.h"
#include "logfilefilter.h"
#include "logviewdockwidget.h"
#include "logfileviewerfilterdockwidget.h"
#include "logfileviewerfiltereditordockwidget.h"
#include "logdelegate.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass)
{   
    ui->setupUi(this);

    model = new LogFileModel(this);

    LogFileViewWidget* log = new LogFileViewWidget(model, this);
    ui->mdiArea->addSubWindow(log);

    ui->mdiArea->setActiveSubWindow(ui->mdiArea->subWindowList().first());
    ui->mdiArea->activeSubWindow()->showMaximized();

    log->maximumSize();
    connect(log->getLogFileModel(),SIGNAL(filterListchange()),this,SLOT(refresh()));
    connect(log,SIGNAL(changeData()),this,SLOT(refresh()));

    LogFileViewerFilterDockWidget* fw = new LogFileViewerFilterDockWidget(log);
    this->addDockWidget(Qt::LeftDockWidgetArea,fw);
    LogFileViewerFilterEditorDockWidget* few = new LogFileViewerFilterEditorDockWidget(fw);
    this->addDockWidget(Qt::LeftDockWidgetArea,few);
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
    QStringList FileNames = QFileDialog::getOpenFileNames(this, tr("Open Log"), "", tr("Log File (*.log)"));

    LogFileViewWidget* w =  qobject_cast<LogFileViewWidget *>(ui->mdiArea->currentSubWindow()->widget());

    foreach(QString FileName,FileNames)
    {
        w->loadLogFile(FileName);
    }

    refreshLogFileList();
}

LogFile* MainWindow::loadLogFile(QFile* _file)
{
    LogFile* logFile = new LogFile(_file);
    lpd = new LogItemParserDialog(logFile,this);
    lpd->show();

    connect(logFile,SIGNAL(readFinished()),this,SLOT(refreshLogFileList()));

    return logFile;
}

void MainWindow::addLogFile(LogFile* _log)
{
    LogFiles.append(_log);
}

void MainWindow::refreshLogFileList()
{
    //ui->listWidget->clear();
}

void MainWindow::selectLogFile(QModelIndex i)
{
    //QList<QListWidgetItem*> lwItems =  ui->listWidget->selectedItems();

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
    qDebug() << "MainWindow::refresh()";
    LogFileViewWidget* w =  qobject_cast<LogFileViewWidget *>(ui->mdiArea->currentSubWindow()->widget());
    ui->statusBar->clearMessage();
    ui->statusBar->showMessage(w->getStatusMessage());
}

void MainWindow::setCount()
{

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
    //ui->pushButton->setPalette(QPalette(QColorDialog::getColor(Qt::green, this)));
}

void MainWindow::on_actionFilterEditor_toggled(bool select)
{
    //ui->dockWidgetFilterEditor->show();
}
