/****************************************************************************
** Meta object code from reading C++ file 'dmidterminstallation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../iso-customizer/dmidterminstallation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dmidterminstallation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DMidTermInstallation_t {
    QByteArrayData data[10];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DMidTermInstallation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DMidTermInstallation_t qt_meta_stringdata_DMidTermInstallation = {
    {
QT_MOC_LITERAL(0, 0, 20), // "DMidTermInstallation"
QT_MOC_LITERAL(1, 21, 13), // "iconBtnCliked"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 5), // "locat"
QT_MOC_LITERAL(4, 42, 13), // "nextBtnCliked"
QT_MOC_LITERAL(5, 56, 17), // "LinkbuttonClicked"
QT_MOC_LITERAL(6, 74, 18), // "ClearbuttonClicked"
QT_MOC_LITERAL(7, 93, 9), // "itemFoucs"
QT_MOC_LITERAL(8, 103, 12), // "QMouseEvent*"
QT_MOC_LITERAL(9, 116, 1) // "e"

    },
    "DMidTermInstallation\0iconBtnCliked\0\0"
    "locat\0nextBtnCliked\0LinkbuttonClicked\0"
    "ClearbuttonClicked\0itemFoucs\0QMouseEvent*\0"
    "e"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DMidTermInstallation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void DMidTermInstallation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DMidTermInstallation *_t = static_cast<DMidTermInstallation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->iconBtnCliked((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->nextBtnCliked(); break;
        case 2: _t->LinkbuttonClicked(); break;
        case 3: _t->ClearbuttonClicked(); break;
        case 4: _t->itemFoucs((*reinterpret_cast< QMouseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DMidTermInstallation::*)(const QPoint & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMidTermInstallation::iconBtnCliked)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DMidTermInstallation::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DMidTermInstallation::nextBtnCliked)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DMidTermInstallation::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DMidTermInstallation.data,
      qt_meta_data_DMidTermInstallation,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *DMidTermInstallation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DMidTermInstallation::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DMidTermInstallation.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int DMidTermInstallation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void DMidTermInstallation::iconBtnCliked(const QPoint & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DMidTermInstallation::nextBtnCliked()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
