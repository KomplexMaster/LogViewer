/****************************************************************************
** Meta object code from reading C++ file 'logfileviewwidget.h'
**
** Created: Sun 6. Sep 20:25:14 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../logfileviewwidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logfileviewwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogFileViewWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      45,   36,   18,   18, 0x0a,
      66,   36,   18,   18, 0x0a,
      87,   18,   18,   18, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LogFileViewWidget[] = {
    "LogFileViewWidget\0\0changeLogFiles()\0"
    "_LogFile\0addLogFile(LogFile*)\0"
    "delLogFile(LogFile*)\0jumpToLine()\0"
};

const QMetaObject LogFileViewWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LogFileViewWidget,
      qt_meta_data_LogFileViewWidget, 0 }
};

const QMetaObject *LogFileViewWidget::metaObject() const
{
    return &staticMetaObject;
}

void *LogFileViewWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogFileViewWidget))
        return static_cast<void*>(const_cast< LogFileViewWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int LogFileViewWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: changeLogFiles(); break;
        case 1: addLogFile((*reinterpret_cast< LogFile*(*)>(_a[1]))); break;
        case 2: delLogFile((*reinterpret_cast< LogFile*(*)>(_a[1]))); break;
        case 3: jumpToLine(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void LogFileViewWidget::changeLogFiles()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
