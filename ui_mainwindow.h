/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Tue 15. Sep 21:26:59 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMdiArea>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QAction *actionSave;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QMdiArea *mdiArea;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;
    QToolBar *toolBar;
    QDockWidget *dockWidgetFilterEditor;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_7;
    QWidget *control;
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *labelDateTo;
    QLabel *labelDateFrom;
    QDateTimeEdit *dateTimeEditFrom;
    QDateTimeEdit *dateTimeEditTo;
    QGroupBox *groupBoxFilter;
    QGridLayout *gridLayout_5;
    QLabel *labelSeverity;
    QLabel *labelFacility;
    QLabel *labelSourceID;
    QLabel *labelMessageID;
    QComboBox *comboBoxSeverity;
    QComboBox *comboBoxFacility;
    QLineEdit *lineEditSourceID;
    QLineEdit *lineEditMessageID;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBoxSearch;
    QGridLayout *gridLayout_6;
    QLineEdit *lineEditSearch;
    QPushButton *pushButton;
    QDockWidget *dockWidgetFileList;
    QWidget *dockWidgetContents_2;
    QGridLayout *gridLayout_8;
    QListWidget *listWidget;
    QDockWidget *dockWidgetFilterList;
    QWidget *dockWidgetContents_3;
    QGridLayout *gridLayout_9;
    QListView *listView;
    QPushButton *pushButtonRefresh;

    void setupUi(QMainWindow *MainWindowClass)
    {
        if (MainWindowClass->objectName().isEmpty())
            MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
        MainWindowClass->resize(1129, 724);
        MainWindowClass->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        actionOpen = new QAction(MainWindowClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/open"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon);
        actionExit = new QAction(MainWindowClass);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/leave"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionSave = new QAction(MainWindowClass);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/filesave"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        centralWidget = new QWidget(MainWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setMargin(11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QString::fromUtf8("mdiArea"));

        gridLayout_4->addWidget(mdiArea, 0, 1, 1, 1);

        MainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1129, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        MainWindowClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindowClass->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindowClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setEnabled(true);
        MainWindowClass->addToolBar(Qt::TopToolBarArea, toolBar);
        dockWidgetFilterEditor = new QDockWidget(MainWindowClass);
        dockWidgetFilterEditor->setObjectName(QString::fromUtf8("dockWidgetFilterEditor"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout_7 = new QGridLayout(dockWidgetContents);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setMargin(11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        control = new QWidget(dockWidgetContents);
        control->setObjectName(QString::fromUtf8("control"));
        control->setMaximumSize(QSize(250, 16777215));
        control->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        gridLayout_3 = new QGridLayout(control);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setMargin(11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        groupBox = new QGroupBox(control);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(400, 16777215));
        groupBox->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        groupBox->setCheckable(false);
        groupBox->setChecked(false);
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        labelDateTo = new QLabel(groupBox);
        labelDateTo->setObjectName(QString::fromUtf8("labelDateTo"));
        labelDateTo->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_2->addWidget(labelDateTo, 2, 0, 1, 1);

        labelDateFrom = new QLabel(groupBox);
        labelDateFrom->setObjectName(QString::fromUtf8("labelDateFrom"));
        labelDateFrom->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_2->addWidget(labelDateFrom, 0, 0, 1, 1);

        dateTimeEditFrom = new QDateTimeEdit(groupBox);
        dateTimeEditFrom->setObjectName(QString::fromUtf8("dateTimeEditFrom"));
        dateTimeEditFrom->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateTimeEditFrom->setDate(QDate(2009, 1, 1));

        gridLayout_2->addWidget(dateTimeEditFrom, 1, 0, 1, 1);

        dateTimeEditTo = new QDateTimeEdit(groupBox);
        dateTimeEditTo->setObjectName(QString::fromUtf8("dateTimeEditTo"));
        dateTimeEditTo->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        dateTimeEditTo->setDate(QDate(2010, 1, 1));

        gridLayout_2->addWidget(dateTimeEditTo, 3, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 1, 0, 1, 1);

        groupBoxFilter = new QGroupBox(control);
        groupBoxFilter->setObjectName(QString::fromUtf8("groupBoxFilter"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBoxFilter->sizePolicy().hasHeightForWidth());
        groupBoxFilter->setSizePolicy(sizePolicy);
        groupBoxFilter->setMaximumSize(QSize(400, 16777215));
        groupBoxFilter->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        groupBoxFilter->setFlat(false);
        groupBoxFilter->setCheckable(false);
        groupBoxFilter->setChecked(false);
        gridLayout_5 = new QGridLayout(groupBoxFilter);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setMargin(11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        labelSeverity = new QLabel(groupBoxFilter);
        labelSeverity->setObjectName(QString::fromUtf8("labelSeverity"));
        labelSeverity->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_5->addWidget(labelSeverity, 0, 0, 1, 1);

        labelFacility = new QLabel(groupBoxFilter);
        labelFacility->setObjectName(QString::fromUtf8("labelFacility"));
        labelFacility->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_5->addWidget(labelFacility, 1, 0, 1, 1);

        labelSourceID = new QLabel(groupBoxFilter);
        labelSourceID->setObjectName(QString::fromUtf8("labelSourceID"));
        labelSourceID->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_5->addWidget(labelSourceID, 2, 0, 1, 1);

        labelMessageID = new QLabel(groupBoxFilter);
        labelMessageID->setObjectName(QString::fromUtf8("labelMessageID"));
        labelMessageID->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_5->addWidget(labelMessageID, 3, 0, 1, 1);

        comboBoxSeverity = new QComboBox(groupBoxFilter);
        comboBoxSeverity->setObjectName(QString::fromUtf8("comboBoxSeverity"));

        gridLayout_5->addWidget(comboBoxSeverity, 0, 1, 1, 1);

        comboBoxFacility = new QComboBox(groupBoxFilter);
        comboBoxFacility->setObjectName(QString::fromUtf8("comboBoxFacility"));
        comboBoxFacility->setEnabled(false);

        gridLayout_5->addWidget(comboBoxFacility, 1, 1, 1, 1);

        lineEditSourceID = new QLineEdit(groupBoxFilter);
        lineEditSourceID->setObjectName(QString::fromUtf8("lineEditSourceID"));

        gridLayout_5->addWidget(lineEditSourceID, 2, 1, 1, 1);

        lineEditMessageID = new QLineEdit(groupBoxFilter);
        lineEditMessageID->setObjectName(QString::fromUtf8("lineEditMessageID"));

        gridLayout_5->addWidget(lineEditMessageID, 3, 1, 1, 1);


        gridLayout_3->addWidget(groupBoxFilter, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 5, 0, 1, 1);

        groupBoxSearch = new QGroupBox(control);
        groupBoxSearch->setObjectName(QString::fromUtf8("groupBoxSearch"));
        gridLayout_6 = new QGridLayout(groupBoxSearch);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setMargin(11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        lineEditSearch = new QLineEdit(groupBoxSearch);
        lineEditSearch->setObjectName(QString::fromUtf8("lineEditSearch"));

        gridLayout_6->addWidget(lineEditSearch, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBoxSearch, 3, 0, 1, 1);

        pushButton = new QPushButton(control);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout_3->addWidget(pushButton, 0, 0, 1, 1);


        gridLayout_7->addWidget(control, 0, 0, 1, 1);

        dockWidgetFilterEditor->setWidget(dockWidgetContents);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetFilterEditor);
        dockWidgetFileList = new QDockWidget(MainWindowClass);
        dockWidgetFileList->setObjectName(QString::fromUtf8("dockWidgetFileList"));
        dockWidgetFileList->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        gridLayout_8 = new QGridLayout(dockWidgetContents_2);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setMargin(11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        listWidget = new QListWidget(dockWidgetContents_2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));
        listWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

        gridLayout_8->addWidget(listWidget, 0, 0, 1, 1);

        dockWidgetFileList->setWidget(dockWidgetContents_2);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetFileList);
        dockWidgetFilterList = new QDockWidget(MainWindowClass);
        dockWidgetFilterList->setObjectName(QString::fromUtf8("dockWidgetFilterList"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        gridLayout_9 = new QGridLayout(dockWidgetContents_3);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setMargin(11);
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        listView = new QListView(dockWidgetContents_3);
        listView->setObjectName(QString::fromUtf8("listView"));

        gridLayout_9->addWidget(listView, 0, 0, 1, 1);

        pushButtonRefresh = new QPushButton(dockWidgetContents_3);
        pushButtonRefresh->setObjectName(QString::fromUtf8("pushButtonRefresh"));
        pushButtonRefresh->setMaximumSize(QSize(400, 16777215));
        pushButtonRefresh->setLocale(QLocale(QLocale::English, QLocale::UnitedStates));

        gridLayout_9->addWidget(pushButtonRefresh, 1, 0, 1, 1);

        dockWidgetFilterList->setWidget(dockWidgetContents_3);
        MainWindowClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetFilterList);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);
        toolBar->addAction(actionOpen);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionExit);

        retranslateUi(MainWindowClass);
        QObject::connect(listWidget, SIGNAL(clicked(QModelIndex)), MainWindowClass, SLOT(selectLogFile(QModelIndex)));
        QObject::connect(pushButtonRefresh, SIGNAL(clicked()), MainWindowClass, SLOT(refresh()));
        QObject::connect(listWidget, SIGNAL(itemSelectionChanged()), MainWindowClass, SLOT(refresh()));
        QObject::connect(pushButton, SIGNAL(clicked()), MainWindowClass, SLOT(setFilterColor()));

        QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
        MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "LogViewer", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindowClass", "Open...", 0, QApplication::UnicodeUTF8));
        actionOpen->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindowClass", "Exit", 0, QApplication::UnicodeUTF8));
        actionExit->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+Q", 0, QApplication::UnicodeUTF8));
        actionSave->setText(QApplication::translate("MainWindowClass", "Save", 0, QApplication::UnicodeUTF8));
        actionSave->setShortcut(QApplication::translate("MainWindowClass", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindowClass", "File", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("MainWindowClass", "ToolBar", 0, QApplication::UnicodeUTF8));
        dockWidgetFilterEditor->setWindowTitle(QApplication::translate("MainWindowClass", "FilterEditor", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindowClass", "Date", 0, QApplication::UnicodeUTF8));
        labelDateTo->setText(QApplication::translate("MainWindowClass", "to", 0, QApplication::UnicodeUTF8));
        labelDateFrom->setText(QApplication::translate("MainWindowClass", "From", 0, QApplication::UnicodeUTF8));
        dateTimeEditFrom->setDisplayFormat(QApplication::translate("MainWindowClass", "dd.MM.yyyy HH:mm:ss:zzz", 0, QApplication::UnicodeUTF8));
        dateTimeEditTo->setDisplayFormat(QApplication::translate("MainWindowClass", "dd.MM.yyyy HH:mm:ss:zzz", 0, QApplication::UnicodeUTF8));
        groupBoxFilter->setTitle(QApplication::translate("MainWindowClass", "Filter", 0, QApplication::UnicodeUTF8));
        labelSeverity->setText(QApplication::translate("MainWindowClass", "Severity", 0, QApplication::UnicodeUTF8));
        labelFacility->setText(QApplication::translate("MainWindowClass", "Facility", 0, QApplication::UnicodeUTF8));
        labelSourceID->setText(QApplication::translate("MainWindowClass", "SourceID", 0, QApplication::UnicodeUTF8));
        labelMessageID->setText(QApplication::translate("MainWindowClass", "MessageID", 0, QApplication::UnicodeUTF8));
        comboBoxSeverity->clear();
        comboBoxSeverity->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "All", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Action", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Information", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Telegram", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Warning", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Recoverable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Error", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Fatal", 0, QApplication::UnicodeUTF8)
        );
        comboBoxFacility->clear();
        comboBoxFacility->insertItems(0, QStringList()
         << QApplication::translate("MainWindowClass", "Developer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Service", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("MainWindowClass", "Customer", 0, QApplication::UnicodeUTF8)
        );
        groupBoxSearch->setTitle(QApplication::translate("MainWindowClass", "Search", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWindowClass", "Color", 0, QApplication::UnicodeUTF8));
        dockWidgetFileList->setWindowTitle(QApplication::translate("MainWindowClass", "Files", 0, QApplication::UnicodeUTF8));
        dockWidgetFilterList->setWindowTitle(QApplication::translate("MainWindowClass", "Filters", 0, QApplication::UnicodeUTF8));
        pushButtonRefresh->setText(QApplication::translate("MainWindowClass", "Refresh", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
