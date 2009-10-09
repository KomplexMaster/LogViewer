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
    logfileproxymodel.cpp \
    logitemparser.cpp \
    logitemparserdialog.cpp \
    logfileviewerfilterdockwidget.cpp \
    logfileviewerfiltereditordockwidget.cpp \
    logfileviewtindexbar.cpp \
    logfilejar.cpp
HEADERS += mainwindow.h \
    logfile.h \
    logfilemodel.h \
    logitem.h \
    logfilefilter.h \
    logdelegate.h \
    logfileviewwidget.h \
    logfileproxymodel.h \
    logitemparser.h \
    logitemparserdialog.h \
    logfileviewerfilterdockwidget.h \
    logfileviewerfiltereditordockwidget.h \
    logfileviewtindexbar.h \
    logfilejar.h
FORMS += mainwindow.ui \
    logfileviewwidget.ui \
    logitemparserdialog.ui \
    logfileviewerfilterdockwidget.ui \
    logfileviewerfiltereditordockwidget.ui
TRANSLATIONS = LogViewer_en.ts \
    LogViewer_de.ts
RESOURCES += res/res.qrc
