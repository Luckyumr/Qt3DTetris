#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>

#include <QtCore>
#include <Qt3DCore>
#include <Qt3DExtras>
#include <QEntity>
#include <QtCore/QObject>

#include <Qt3DCore/qentity.h>
#include <Qt3DCore/qtransform.h>

#include <Qt3DExtras/QTorusMesh>
#include <Qt3DExtras/QConeMesh>
#include <Qt3DExtras/QCylinderMesh>
#include <Qt3DExtras/QCuboidMesh>
#include <Qt3DExtras/QPlaneMesh>
#include <Qt3DExtras/QSphereMesh>
#include <Qt3DExtras/QPhongMaterial>


class entity : public QObject
{
    Q_OBJECT
public:
    explicit entity(Qt3DCore::QEntity *rootEntity);

    struct position
    {
        float x;
        float z;
        float y;

        position(float x=0,float z=0,float y=0) {
            this->x = x;
            this->z = z;
            this->y = y;
        }
    };

    Qt3DCore::QEntity *block[4];
    position currentPos[4];


    position test1;

    void createT(position pos);
    void createO(position pos);
    void createI(position pos);
    void createL1(position pos);
    void createL2(position pos);
    void createZ1(position pos);
    void createZ2(position pos);

    float create(position pos,
                  float o0x,float o0z,float o0y,
                  float o1x,float o1z,float o1y,
                  float o2x,float o2z,float o2y,
                  float o3x,float o3z,float o3y,
                  int color);


    Qt3DCore::QEntity *test;

private:
    Qt3DCore::QEntity *m_rootEntity;

signals:

public slots:
};

#endif // ENTITY_H
