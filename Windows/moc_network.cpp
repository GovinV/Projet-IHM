/****************************************************************************
** Meta object code from reading C++ file 'network.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uno/ui/interface/src/network.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'network.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Network_t {
    QByteArrayData data[34];
    char stringdata0[329];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Network_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Network_t qt_meta_stringdata_Network = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Network"
QT_MOC_LITERAL(1, 8, 8), // "loadRoom"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 4), // "mess"
QT_MOC_LITERAL(4, 23, 2), // "id"
QT_MOC_LITERAL(5, 26, 6), // "player"
QT_MOC_LITERAL(6, 33, 9), // "maxPlayer"
QT_MOC_LITERAL(7, 43, 16), // "changeMyRoomName"
QT_MOC_LITERAL(8, 60, 8), // "new_name"
QT_MOC_LITERAL(9, 69, 12), // "serverStatut"
QT_MOC_LITERAL(10, 82, 6), // "online"
QT_MOC_LITERAL(11, 89, 17), // "serverlistChanged"
QT_MOC_LITERAL(12, 107, 8), // "tmpReady"
QT_MOC_LITERAL(13, 116, 9), // "hostLeave"
QT_MOC_LITERAL(14, 126, 17), // "playerlistChanged"
QT_MOC_LITERAL(15, 144, 14), // "serverRoomNull"
QT_MOC_LITERAL(16, 159, 4), // "none"
QT_MOC_LITERAL(17, 164, 17), // "receiveFromServer"
QT_MOC_LITERAL(18, 182, 9), // "startGame"
QT_MOC_LITERAL(19, 192, 14), // "changeNickname"
QT_MOC_LITERAL(20, 207, 6), // "pseudo"
QT_MOC_LITERAL(21, 214, 14), // "changeRoomName"
QT_MOC_LITERAL(22, 229, 4), // "name"
QT_MOC_LITERAL(23, 234, 15), // "changeMaxPlayer"
QT_MOC_LITERAL(24, 250, 1), // "n"
QT_MOC_LITERAL(25, 252, 8), // "roomList"
QT_MOC_LITERAL(26, 261, 8), // "setReady"
QT_MOC_LITERAL(27, 270, 5), // "ready"
QT_MOC_LITERAL(28, 276, 10), // "createRoom"
QT_MOC_LITERAL(29, 287, 9), // "room_name"
QT_MOC_LITERAL(30, 297, 8), // "joinRoom"
QT_MOC_LITERAL(31, 306, 7), // "room_id"
QT_MOC_LITERAL(32, 314, 9), // "leaveRoom"
QT_MOC_LITERAL(33, 324, 4) // "quit"

    },
    "Network\0loadRoom\0\0mess\0id\0player\0"
    "maxPlayer\0changeMyRoomName\0new_name\0"
    "serverStatut\0online\0serverlistChanged\0"
    "tmpReady\0hostLeave\0playerlistChanged\0"
    "serverRoomNull\0none\0receiveFromServer\0"
    "startGame\0changeNickname\0pseudo\0"
    "changeRoomName\0name\0changeMaxPlayer\0"
    "n\0roomList\0setReady\0ready\0createRoom\0"
    "room_name\0joinRoom\0room_id\0leaveRoom\0"
    "quit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Network[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  109,    2, 0x06 /* Public */,
       7,    1,  118,    2, 0x06 /* Public */,
       9,    1,  121,    2, 0x06 /* Public */,
      11,    0,  124,    2, 0x06 /* Public */,
      12,    0,  125,    2, 0x06 /* Public */,
      13,    0,  126,    2, 0x06 /* Public */,
      14,    0,  127,    2, 0x06 /* Public */,
      15,    1,  128,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    1,  131,    2, 0x0a /* Public */,
      18,    0,  134,    2, 0x0a /* Public */,
      19,    1,  135,    2, 0x0a /* Public */,
      21,    1,  138,    2, 0x0a /* Public */,
      23,    1,  141,    2, 0x0a /* Public */,
      25,    0,  144,    2, 0x0a /* Public */,
      26,    1,  145,    2, 0x0a /* Public */,
      28,    1,  148,    2, 0x0a /* Public */,
      30,    1,  151,    2, 0x0a /* Public */,
      32,    0,  154,    2, 0x0a /* Public */,
      33,    0,  155,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Bool,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   16,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   20,
    QMetaType::Void, QMetaType::QString,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::QString,   29,
    QMetaType::Void, QMetaType::QString,   31,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Network::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Network *_t = static_cast<Network *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loadRoom((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->changeMyRoomName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->serverStatut((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->serverlistChanged(); break;
        case 4: _t->tmpReady(); break;
        case 5: _t->hostLeave(); break;
        case 6: _t->playerlistChanged(); break;
        case 7: _t->serverRoomNull((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->receiveFromServer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->startGame(); break;
        case 10: _t->changeNickname((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->changeRoomName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->changeMaxPlayer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->roomList(); break;
        case 14: _t->setReady((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 15: _t->createRoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->joinRoom((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->leaveRoom(); break;
        case 18: _t->quit(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Network::*_t)(QString , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::loadRoom)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Network::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::changeMyRoomName)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Network::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::serverStatut)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Network::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::serverlistChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Network::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::tmpReady)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Network::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::hostLeave)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Network::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::playerlistChanged)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Network::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Network::serverRoomNull)) {
                *result = 7;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Network::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Network.data,
      qt_meta_data_Network,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Network::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Network::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Network.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Network::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Network::loadRoom(QString _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Network::changeMyRoomName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Network::serverStatut(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Network::serverlistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Network::tmpReady()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Network::hostLeave()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Network::playerlistChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Network::serverRoomNull(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
