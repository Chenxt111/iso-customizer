/****************************************************************************
** Meta object code from reading C++ file 'dchoicearchitecture.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../iso-customizer/dchoicearchitecture.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dchoicearchitecture.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DChoiceArchitecture_t {
    QByteArrayData data[7];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DChoiceArchitecture_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DChoiceArchitecture_t qt_meta_stringdata_DChoiceArchitecture = {
    {
QT_MOC_LITERAL(0, 0, 19), // "DChoiceArchitecture"
QT_MOC_LITERAL(1, 20, 13), // "nextBtnCliked"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 23), // "CheckIndexChangedSignal"
QT_MOC_LITERAL(4, 59, 11), // "QModelIndex"
QT_MOC_LITERAL(5, 71, 7), // "current"
QT_MOC_LITERAL(6, 79, 8) // "previous"

    },
    "DChoiceArchitecture\0nextBtnCliked\0\0"
    "CheckIndexChangedSignal\0QModelIndex\0"
    "current\0previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DChoiceArchitecture[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 4,    5,    6,

       0        // eod
};

void DChoiceArchitecture::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DChoiceArchitecture *_t = static_cast<DChoiceArchitecture *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nextBtnCliked(); break;
        case 1: _t->CheckIndexChangedSignal((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DChoiceArchitecture::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DChoiceArchitecture::nextBtnCliked)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DChoiceArchitecture::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DChoiceArchitecture.data,
      qt_meta_data_DChoiceArchitecture,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DChoiceArchitecture::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DChoiceArchitecture::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DChoiceArchitecture.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DChoiceArchitecture::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void DChoiceArchitecture::nextBtnCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_DListViewRest_t {
    QByteArrayData data[6];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DListViewRest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DListViewRest_t qt_meta_stringdata_DListViewRest = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DListViewRest"
QT_MOC_LITERAL(1, 14, 13), // "currentChange"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 11), // "QModelIndex"
QT_MOC_LITERAL(4, 41, 7), // "current"
QT_MOC_LITERAL(5, 49, 8) // "previous"

    },
    "DListViewRest\0currentChange\0\0QModelIndex\0"
    "current\0previous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DListViewRest[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,    4,    5,

       0        // eod
};

void DListViewRest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DListViewRest *_t = static_cast<DListViewRest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->currentChange((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DListViewRest::*)(const QModelIndex & , const QModelIndex & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DListViewRest::currentChange)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DListViewRest::staticMetaObject = {
    { &DListView::staticMetaObject, qt_meta_stringdata_DListViewRest.data,
      qt_meta_data_DListViewRest,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DListViewRest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DListViewRest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DListViewRest.stringdata0))
        return static_cast<void*>(this);
    return DListView::qt_metacast(_clname);
}

int DListViewRest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void DListViewRest::currentChange(const QModelIndex & _t1, const QModelIndex & _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
