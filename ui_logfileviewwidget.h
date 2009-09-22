/********************************************************************************
** Form generated from reading ui file 'logfileviewwidget.ui'
**
** Created: Tue 22. Sep 09:27:44 2009
**      by: Qt User Interface Compiler version 4.5.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_LOGFILEVIEWWIDGET_H
#define UI_LOGFILEVIEWWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogFileViewWidget
{
public:
    QGridLayout *gridLayout;
    QTreeView *unfilteredView;
    QTreeView *filteredView;

    void setupUi(QWidget *LogFileViewWidget)
    {
        if (LogFileViewWidget->objectName().isEmpty())
            LogFileViewWidget->setObjectName(QString::fromUtf8("LogFileViewWidget"));
        LogFileViewWidget->resize(617, 440);
        gridLayout = new QGridLayout(LogFileViewWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        unfilteredView = new QTreeView(LogFileViewWidget);
        unfilteredView->setObjectName(QString::fromUtf8("unfilteredView"));

        gridLayout->addWidget(unfilteredView, 0, 0, 1, 1);

        filteredView = new QTreeView(LogFileViewWidget);
        filteredView->setObjectName(QString::fromUtf8("filteredView"));

        gridLayout->addWidget(filteredView, 1, 0, 1, 1);


        retranslateUi(LogFileViewWidget);

        QMetaObject::connectSlotsByName(LogFileViewWidget);
    } // setupUi

    void retranslateUi(QWidget *LogFileViewWidget)
    {
        LogFileViewWidget->setWindowTitle(QApplication::translate("LogFileViewWidget", "Form", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(LogFileViewWidget);
    } // retranslateUi

};

namespace Ui {
    class LogFileViewWidget: public Ui_LogFileViewWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGFILEVIEWWIDGET_H
