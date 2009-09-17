/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Tue 15. Sep 21:27:48 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      38,   11,   11,   11, 0x08,
      79,   73,   64,   11, 0x08,
     104,   99,   11,   11, 0x08,
     125,   11,   11,   11, 0x08,
     146,   11,   11,   11, 0x08,
     173,   11,   11,   11, 0x08,
     183,   11,   11,   11, 0x08,
     200,  194,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0on_actionOpen_triggered()\0"
    "on_actionExit_triggered()\0LogFile*\0"
    "_file\0loadLogFile(QFile*)\0_log\0"
    "addLogFile(LogFile*)\0refreshLogFileList()\0"
    "selectLogFile(QModelIndex)\0refresh()\0"
    "setCount()\0index\0leftclick(QModelIndex)\0"
    "setFilterColor()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

const QMetaObject *MainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionOpen_triggered(); break;
        case 1: on_actionExit_triggered(); break;
        case 2: { LogFile* _r = loadLogFile((*reinterpret_cast< QFile*(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< LogFile**>(_a[0]) = _r; }  break;
        case 3: addLogFile((*reinterpret_cast< LogFile*(*)>(_a[1]))); break;
        case 4: refreshLogFileList(); break;
        case 5: selectLogFile((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: refresh(); break;
        case 7: setCount(); break;
        case 8: leftclick((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: setFilterColor(); break;
        default: ;
        }
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
