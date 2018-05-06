/****************************************************************************
** Meta object code from reading C++ file 'playerlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uno/ui/interface/src/playerlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playerlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_PlayerList_t {
    QByteArrayData data[19];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PlayerList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PlayerList_t qt_meta_stringdata_PlayerList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "PlayerList"
QT_MOC_LITERAL(1, 11, 15), // "preItemAppended"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "postItemAppended"
QT_MOC_LITERAL(4, 45, 11), // "readyEdited"
QT_MOC_LITERAL(5, 57, 5), // "index"
QT_MOC_LITERAL(6, 63, 5), // "ready"
QT_MOC_LITERAL(7, 69, 11), // "dataChanged"
QT_MOC_LITERAL(8, 81, 14), // "preItemRemoved"
QT_MOC_LITERAL(9, 96, 15), // "postItemRemoved"
QT_MOC_LITERAL(10, 112, 10), // "appendItem"
QT_MOC_LITERAL(11, 123, 2), // "id"
QT_MOC_LITERAL(12, 126, 4), // "name"
QT_MOC_LITERAL(13, 131, 7), // "getItem"
QT_MOC_LITERAL(14, 139, 10), // "PlayerItem"
QT_MOC_LITERAL(15, 150, 8), // "findItem"
QT_MOC_LITERAL(16, 159, 9), // "editReady"
QT_MOC_LITERAL(17, 169, 11), // "removeItems"
QT_MOC_LITERAL(18, 181, 5) // "clear"

    },
    "PlayerList\0preItemAppended\0\0"
    "postItemAppended\0readyEdited\0index\0"
    "ready\0dataChanged\0preItemRemoved\0"
    "postItemRemoved\0appendItem\0id\0name\0"
    "getItem\0PlayerItem\0findItem\0editReady\0"
    "removeItems\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PlayerList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x06 /* Public */,
       3,    0,   75,    2, 0x06 /* Public */,
       4,    2,   76,    2, 0x06 /* Public */,
       7,    0,   81,    2, 0x06 /* Public */,
       8,    1,   82,    2, 0x06 /* Public */,
       9,    0,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    2,   86,    2, 0x0a /* Public */,
      13,    1,   91,    2, 0x0a /* Public */,
      15,    1,   94,    2, 0x0a /* Public */,
      16,    2,   97,    2, 0x0a /* Public */,
      17,    1,  102,    2, 0x0a /* Public */,
      18,    0,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Bool,    5,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   11,   12,
    0x80000000 | 14, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::QString,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   11,    6,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void PlayerList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PlayerList *_t = static_cast<PlayerList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->readyEdited((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 3: _t->dataChanged(); break;
        case 4: _t->preItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->postItemRemoved(); break;
        case 6: _t->appendItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: { PlayerItem _r = _t->getItem((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< PlayerItem*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->findItem((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->editReady((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 10: _t->removeItems((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (PlayerList::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerList::preItemAppended)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (PlayerList::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerList::postItemAppended)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (PlayerList::*_t)(int , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerList::readyEdited)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (PlayerList::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerList::dataChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (PlayerList::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerList::preItemRemoved)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (PlayerList::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&PlayerList::postItemRemoved)) {
                *result = 5;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject PlayerList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_PlayerList.data,
      qt_meta_data_PlayerList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *PlayerList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PlayerList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_PlayerList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int PlayerList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void PlayerList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void PlayerList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void PlayerList::readyEdited(int _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void PlayerList::dataChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void PlayerList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void PlayerList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
