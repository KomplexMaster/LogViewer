/****************************************************************************
** Meta object code from reading C++ file 'logfilemodel.h'
**
** Created: Mon 3. Aug 10:34:44 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../logfilemodel.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'logfilemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LogFileModel[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // signals: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x05,
      31,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      50,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_LogFileModel[] = {
    "LogFileModel\0\0fileListchange()\0"
    "filterListchange()\0refreshItemList()\0"
};

const QMetaObject LogFileModel::staticMetaObject = {
    { &QAbstractTableModel::staticMetaObject, qt_meta_stringdata_LogFileModel,
      qt_meta_data_LogFileModel, 0 }
};

const QMetaObject *LogFileModel::metaObject() const
{
    return &staticMetaObject;
}

void *LogFileModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LogFileModel))
        return static_cast<void*>(const_cast< LogFileModel*>(this));
    return QAbstractTableModel::qt_metacast(_clname);
}

int LogFileModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractTableModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: fileListchange(); break;
        case 1: filterListchange(); break;
        case 2: refreshItemList(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void LogFileModel::fileListchange()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void LogFileModel::filterListchange()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
