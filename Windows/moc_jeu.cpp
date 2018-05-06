/****************************************************************************
** Meta object code from reading C++ file 'jeu.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../uno/ui/game/src/jeu.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'jeu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Jeu_t {
    QByteArrayData data[21];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Jeu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Jeu_t qt_meta_stringdata_Jeu = {
    {
QT_MOC_LITERAL(0, 0, 3), // "Jeu"
QT_MOC_LITERAL(1, 4, 13), // "curCardChange"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "index"
QT_MOC_LITERAL(4, 25, 2), // "cl"
QT_MOC_LITERAL(5, 28, 5), // "value"
QT_MOC_LITERAL(6, 34, 6), // "myTurn"
QT_MOC_LITERAL(7, 41, 11), // "changeColor"
QT_MOC_LITERAL(8, 53, 10), // "playCardOk"
QT_MOC_LITERAL(9, 64, 11), // "selectColor"
QT_MOC_LITERAL(10, 76, 9), // "waitForIA"
QT_MOC_LITERAL(11, 86, 7), // "gameEnd"
QT_MOC_LITERAL(12, 94, 2), // "me"
QT_MOC_LITERAL(13, 97, 10), // "nextStepIA"
QT_MOC_LITERAL(14, 108, 5), // "start"
QT_MOC_LITERAL(15, 114, 12), // "unoBtPressed"
QT_MOC_LITERAL(16, 127, 18), // "contreUnoBtPressed"
QT_MOC_LITERAL(17, 146, 17), // "playCardBtPressed"
QT_MOC_LITERAL(18, 164, 1), // "i"
QT_MOC_LITERAL(19, 166, 15), // "playChangeColor"
QT_MOC_LITERAL(20, 182, 17) // "drawCardBtPressed"

    },
    "Jeu\0curCardChange\0\0index\0cl\0value\0"
    "myTurn\0changeColor\0playCardOk\0selectColor\0"
    "waitForIA\0gameEnd\0me\0nextStepIA\0start\0"
    "unoBtPressed\0contreUnoBtPressed\0"
    "playCardBtPressed\0i\0playChangeColor\0"
    "drawCardBtPressed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Jeu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   84,    2, 0x06 /* Public */,
       6,    0,   91,    2, 0x06 /* Public */,
       7,    1,   92,    2, 0x06 /* Public */,
       8,    0,   95,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    0,   97,    2, 0x06 /* Public */,
      11,    1,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    1,  105,    2, 0x0a /* Public */,
      19,    1,  108,    2, 0x0a /* Public */,
      20,    0,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString, QMetaType::Int,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void Jeu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Jeu *_t = static_cast<Jeu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->curCardChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->myTurn(); break;
        case 2: _t->changeColor((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->playCardOk(); break;
        case 4: _t->selectColor(); break;
        case 5: _t->waitForIA(); break;
        case 6: _t->gameEnd((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->nextStepIA(); break;
        case 8: _t->start(); break;
        case 9: _t->unoBtPressed(); break;
        case 10: _t->contreUnoBtPressed(); break;
        case 11: _t->playCardBtPressed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->playChangeColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->drawCardBtPressed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Jeu::*_t)(int , QString , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Jeu::curCardChange)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Jeu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Jeu::myTurn)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Jeu::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Jeu::changeColor)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Jeu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Jeu::playCardOk)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Jeu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Jeu::selectColor)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Jeu::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Jeu::waitForIA)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Jeu::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Jeu::gameEnd)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Jeu::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Jeu.data,
      qt_meta_data_Jeu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Jeu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Jeu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Jeu.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Jeu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Jeu::curCardChange(int _t1, QString _t2, int _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Jeu::myTurn()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Jeu::changeColor(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Jeu::playCardOk()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Jeu::selectColor()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Jeu::waitForIA()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Jeu::gameEnd(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
