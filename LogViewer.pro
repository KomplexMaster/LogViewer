# -------------------------------------------------
# Project created by QtCreator 2009-07-25T12:34:53
# -------------------------------------------------
QT += network \
    script \
    webkit \
    xml
TARGET = LogViewer
TEMPLATE = app
SOURCES += mainwindow.cpp \
    logfile.cpp \
    logfilemodel.cpp \
    logitem.cpp \
    main.cpp \
    logfilefilter.cpp \
    logdelegate.cpp \
    logfileviewwidget.cpp \
    logfileviewwidgetindexbar.cpp \
    logfileproxymodel.cpp \
    logviewdockwidget.cpp \
    logitemparser.cpp
HEADERS += mainwindow.h \
    logfile.h \
    logfilemodel.h \
    logitem.h \
    logfilefilter.h \
    logdelegate.h \
    logfileviewwidget.h \
    logfileviewwidgetindexbar.h \
    logfileproxymodel.h \
    logviewdockwidget.h \
    logitemparser.h
FORMS += mainwindow.ui \
    logfileviewwidget.ui \
    logviewdockwidget.ui
TRANSLATIONS = LogViewer_en.ts \
    LogViewer_de.ts
RESOURCES += res/res.qrc
