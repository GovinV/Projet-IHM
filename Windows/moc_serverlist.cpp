/****************************************************************************
** Meta object code from reading C++ file 'serverlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uno/ui/interface/src/serverlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serverlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ServerList_t {
    QByteArrayData data[25];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ServerList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ServerList_t qt_meta_stringdata_ServerList = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ServerList"
QT_MOC_LITERAL(1, 11, 15), // "preItemAppended"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 16), // "postItemAppended"
QT_MOC_LITERAL(4, 45, 10), // "nameEdited"
QT_MOC_LITERAL(5, 56, 5), // "index"
QT_MOC_LITERAL(6, 62, 4), // "name"
QT_MOC_LITERAL(7, 67, 12), // "playerEdited"
QT_MOC_LITERAL(8, 80, 2), // "nb"
QT_MOC_LITERAL(9, 83, 9), // "maxEdited"
QT_MOC_LITERAL(10, 93, 14), // "preItemRemoved"
QT_MOC_LITERAL(11, 108, 15), // "postItemRemoved"
QT_MOC_LITERAL(12, 124, 10), // "appendItem"
QT_MOC_LITERAL(13, 135, 2), // "id"
QT_MOC_LITERAL(14, 138, 6), // "player"
QT_MOC_LITERAL(15, 145, 3), // "max"
QT_MOC_LITERAL(16, 149, 7), // "getItem"
QT_MOC_LITERAL(17, 157, 10), // "ServerItem"
QT_MOC_LITERAL(18, 168, 8), // "findItem"
QT_MOC_LITERAL(19, 177, 8), // "editName"
QT_MOC_LITERAL(20, 186, 10), // "editPlayer"
QT_MOC_LITERAL(21, 197, 7), // "editMax"
QT_MOC_LITERAL(22, 205, 7), // "isEmpty"
QT_MOC_LITERAL(23, 213, 11), // "removeItems"
QT_MOC_LITERAL(24, 225, 5) // "clear"

    },
    "ServerList\0preItemAppended\0\0"
    "postItemAppended\0nameEdited\0index\0"
    "name\0playerEdited\0nb\0maxEdited\0"
    "preItemRemoved\0postItemRemoved\0"
    "appendItem\0id\0player\0max\0getItem\0"
    "ServerItem\0findItem\0editName\0editPlayer\0"
    "editMax\0isEmpty\0removeItems\0clear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ServerList[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x06 /* Public */,
       3,    0,   95,    2, 0x06 /* Public */,
       4,    2,   96,    2, 0x06 /* Public */,
       7,    2,  101,    2, 0x06 /* Public */,
       9,    2,  106,    2, 0x06 /* Public */,
      10,    1,  111,    2, 0x06 /* Public */,
      11,    0,  114,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    4,  115,    2, 0x0a /* Public */,
      16,    1,  124,    2, 0x0a /* Public */,
      18,    1,  127,    2, 0x0a /* Public */,
      19,    2,  130,    2, 0x0a /* Public */,
      20,    2,  135,    2, 0x0a /* Public */,
      21,    2,  140,    2, 0x0a /* Public */,
      22,    0,  145,    2, 0x0a /* Public */,
      23,    1,  146,    2, 0x0a /* Public */,
      24,    0,  149,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    5,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    8,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::Int,    6,   13,   14,   15,
    0x80000000 | 17, QMetaType::Int,    5,
    QMetaType::Int, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   13,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   13,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,   13,    8,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,

       0        // eod
};

void ServerList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ServerList *_t = static_cast<ServerList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->preItemAppended(); break;
        case 1: _t->postItemAppended(); break;
        case 2: _t->nameEdited((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->playerEdited((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->maxEdited((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->preItemRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->postItemRemoved(); break;
        case 7: _t->appendItem((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 8: { ServerItem _r = _t->getItem((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< ServerItem*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->findItem((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->editName((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 11: _t->editPlayer((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 12: _t->editMax((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 13: { bool _r = _t->isEmpty();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->removeItems((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->clear(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ServerList::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerList::preItemAppended)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ServerList::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerList::postItemAppended)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ServerList::*_t)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerList::nameEdited)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (ServerList::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerList::playerEdited)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (ServerList::*_t)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerList::maxEdited)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (ServerList::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerList::preItemRemoved)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (ServerList::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ServerList::postItemRemoved)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ServerList::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ServerList.data,
      qt_meta_data_ServerList,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ServerList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ServerList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ServerList.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ServerList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ServerList::preItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ServerList::postItemAppended()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ServerList::nameEdited(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ServerList::playerEdited(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void ServerList::maxEdited(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void ServerList::preItemRemoved(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void ServerList::postItemRemoved()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
