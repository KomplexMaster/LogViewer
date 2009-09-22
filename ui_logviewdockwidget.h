/********************************************************************************
** Form generated from reading ui file 'logviewdockwidget.ui'
**
** Created: Tue 22. Sep 09:27:44 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGVIEWDOCKWIDGET_H
#define UI_LOGVIEWDOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogViewDockWidget
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QTreeView *filtered;
    QTreeView *unfiltered;

    void setupUi(QDockWidget *LogViewDockWidget)
    {
        if (LogViewDockWidget->objectName().isEmpty())
            LogViewDockWidget->setObjectName(QString::fromUtf8("LogViewDockWidget"));
        LogViewDockWidget->resize(1024, 768);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        filtered = new QTreeView(dockWidgetContents);
        filtered->setObjectName(QString::fromUtf8("filtered"));

        gridLayout->addWidget(filtered, 1, 0, 1, 1);

        unfiltered = new QTreeView(dockWidgetContents);
        unfiltered->setObjectName(QString::fromUtf8("unfiltered"));

        gridLayout->addWidget(unfiltered, 0, 0, 1, 1);

        LogViewDockWidget->setWidget(dockWidgetContents);

        retranslateUi(LogViewDockWidget);

        QMetaObject::connectSlotsByName(LogViewDockWidget);
    } // setupUi

    void retranslateUi(QDockWidget *LogViewDockWidget)
    {
        LogViewDockWidget->setWindowTitle(QApplication::translate("LogViewDockWidget", "DockWidget", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LogViewDockWidget);
    } // retranslateUi

};

namespace Ui {
    class LogViewDockWidget: public Ui_LogViewDockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGVIEWDOCKWIDGET_H
