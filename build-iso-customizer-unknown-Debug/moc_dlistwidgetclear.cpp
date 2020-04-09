/****************************************************************************
** Meta object code from reading C++ file 'dlistwidgetclear.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../iso-customizer/dlistwidgetclear.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dlistwidgetclear.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DListWidgetClear_t {
    QByteArrayData data[8];
    char stringdata0[79];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DListWidgetClear_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DListWidgetClear_t qt_meta_stringdata_DListWidgetClear = {
    {
QT_MOC_LITERAL(0, 0, 16), // "DListWidgetClear"
QT_MOC_LITERAL(1, 17, 10), // "indexfoucs"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 12), // "QMouseEvent*"
QT_MOC_LITERAL(4, 42, 1), // "e"
QT_MOC_LITERAL(5, 44, 11), // "creatWidget"
QT_MOC_LITERAL(6, 56, 16), // "clearButtnCliked"
QT_MOC_LITERAL(7, 73, 5) // "locat"

    },
    "DListWidgetClear\0indexfoucs\0\0QMouseEvent*\0"
    "e\0creatWidget\0clearButtnCliked\0locat"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DListWidgetClear[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    0,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   33,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    7,

       0        // eod
};

void DListWidgetClear::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DListWidgetClear *_t = static_cast<DListWidgetClear *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->indexfoucs((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        case 1: _t->creatWidget(); break;
        case 2: _t->clearButtnCliked((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DListWidgetClear::*)(QMouseEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DListWidgetClear::indexfoucs)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DListWidgetClear::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DListWidgetClear::creatWidget)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DListWidgetClear::staticMetaObject = {
    { &DListWidget::staticMetaObject, qt_meta_stringdata_DListWidgetClear.data,
      qt_meta_data_DListWidgetClear,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DListWidgetClear::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DListWidgetClear::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DListWidgetClear.stringdata0))
        return static_cast<void*>(this);
    return DListWidget::qt_metacast(_clname);
}

int DListWidgetClear::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = DListWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DListWidgetClear::indexfoucs(QMouseEvent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DListWidgetClear::creatWidget()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
