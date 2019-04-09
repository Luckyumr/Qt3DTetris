/****************************************************************************
** Meta object code from reading C++ file 'scenemodifier.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../scenemodifier.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'scenemodifier.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SceneModifier_t {
    QByteArrayData data[16];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SceneModifier_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SceneModifier_t qt_meta_stringdata_SceneModifier = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SceneModifier"
QT_MOC_LITERAL(1, 14, 11), // "enableTorus"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "enabled"
QT_MOC_LITERAL(4, 35, 10), // "enableCone"
QT_MOC_LITERAL(5, 46, 14), // "enableCylinder"
QT_MOC_LITERAL(6, 61, 12), // "enableCuboid"
QT_MOC_LITERAL(7, 74, 11), // "enablePlane"
QT_MOC_LITERAL(8, 86, 12), // "enableSphere"
QT_MOC_LITERAL(9, 99, 13), // "enablemyshape"
QT_MOC_LITERAL(10, 113, 6), // "change"
QT_MOC_LITERAL(11, 120, 14), // "moveEntityLeft"
QT_MOC_LITERAL(12, 135, 15), // "moveEntityRight"
QT_MOC_LITERAL(13, 151, 14), // "moveEntityDown"
QT_MOC_LITERAL(14, 166, 14), // "moveEntityDeep"
QT_MOC_LITERAL(15, 181, 15) // "changeDirection"

    },
    "SceneModifier\0enableTorus\0\0enabled\0"
    "enableCone\0enableCylinder\0enableCuboid\0"
    "enablePlane\0enableSphere\0enablemyshape\0"
    "change\0moveEntityLeft\0moveEntityRight\0"
    "moveEntityDown\0moveEntityDeep\0"
    "changeDirection"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SceneModifier[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    1,   82,    2, 0x0a /* Public */,
       5,    1,   85,    2, 0x0a /* Public */,
       6,    1,   88,    2, 0x0a /* Public */,
       7,    1,   91,    2, 0x0a /* Public */,
       8,    1,   94,    2, 0x0a /* Public */,
       9,    1,   97,    2, 0x0a /* Public */,
      10,    0,  100,    2, 0x0a /* Public */,
      11,    0,  101,    2, 0x0a /* Public */,
      12,    0,  102,    2, 0x0a /* Public */,
      13,    0,  103,    2, 0x0a /* Public */,
      14,    0,  104,    2, 0x0a /* Public */,
      15,    0,  105,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SceneModifier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SceneModifier *_t = static_cast<SceneModifier *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enableTorus((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->enableCone((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->enableCylinder((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->enableCuboid((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->enablePlane((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->enableSphere((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->enablemyshape((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->change(); break;
        case 8: _t->moveEntityLeft(); break;
        case 9: _t->moveEntityRight(); break;
        case 10: _t->moveEntityDown(); break;
        case 11: _t->moveEntityDeep(); break;
        case 12: _t->changeDirection(); break;
        default: ;
        }
    }
}

const QMetaObject SceneModifier::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SceneModifier.data,
      qt_meta_data_SceneModifier,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SceneModifier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SceneModifier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SceneModifier.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int SceneModifier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
