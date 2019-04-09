#include "entity.h"
#include <Qt3DCore>
#include <Qt3DExtras>
#include <QEntity>
#include <QDebug>
#include <qdebug.h>



entity::entity(Qt3DCore::QEntity *rootEntity) : m_rootEntity(rootEntity)
{
    qDebug("creat entity");

}

void entity::createT(position pos)
{
    /*
    1 2 3
      4

*/
    create(pos,
           -1.0f,0.0f,0.0f,
           0.0f,0.0f,0.0f,
           1.0f,0.0f,0.0f,
           0.0f,-1.0f,0.0f,
           0xFF7F50);
}

void entity::createO(position pos)
{
  /*
    3 4
    1 2

*/

    create(pos,
           -1.0f,-1.0f,0.0f,
           0.0f,-1.0f,0.0f,
           -1.0f,0.0f,0.0f,
           0.0f,0.0f,0.0f,
           0xC1FFC1);
}

void entity::createI(position pos)
{
 /*   4
      3
      2
      1
*/
    create(pos,
           0.0f,-1.0f,0.0f,
           0.0f,0.0f,0.0f,
           0.0f,1.0f,0.0f,
           0.0f,2.0f,0.0f,
           0xEE2C2C);
}
void entity::createL1(position pos)
{
    /*
     * 2 3 4
     * 1

   */

    create(pos,
           -1.0f,-1.0f,0.0f,
           -1.0f,0.0f,0.0f,
           0.0f,0.0f,0.0f,
           1.0f,0.0f,0.0f,
           0x00FFFF);
}

void entity::createL2(position pos)
{
    /*
     * 4 3 2
           1
   */
    create(pos,
           1.0f,-1.0f,0.0f,
           1.0f,0.0f,0.0f,
           0.0f,0.0f,0.0f,
           -1.0f,0.0f,0.0f,
           0xFFFF00);
}

void entity::createZ1(position pos)
{
    /*  4
        3 2
          1
   */
    create(pos,
           0.0f,-1.0f,0.0f,
           0.0f,0.0f,0.0f,
           -1.0f,0.0f,0.0f,
           -1.0f,1.0f,0.0f,
           0xFFE1FF);
}

void entity::createZ2(position pos)
{
    /*    4
        2 3
        1
   */
    create(pos,
           -1.0f,-1.0f,0.0f,
           -1.0f,0.0f,0.0f,
           0.0f,0.0f,0.0f,
           0.0f,1.0f,0.0f,
           0xE3E3E3);
}



float entity::create(position pos,
                      float o0x,float o0z,float o0y,
                      float o1x,float o1z,float o1y,
                      float o2x,float o2z,float o2y,
                      float o3x,float o3z,float o3y,
                      int color)
{
    qDebug("build new shape");
    float x= pos.x;
    float z= pos.z;
    float y= pos.y;
    //M_Shape data
    Qt3DExtras::QCuboidMesh *mysphereMesh0 = new Qt3DExtras::QCuboidMesh();      //渲染方式

    Qt3DExtras::QPhongMaterial *mysphereMaterial0 = new Qt3DExtras::QPhongMaterial();    //颜色
    mysphereMaterial0->setDiffuse(QColor(QRgb(color)));

    Qt3DCore::QTransform *mysphereTransform0 = new Qt3DCore::QTransform();       //位置
    mysphereTransform0->setScale(1.0f);
    mysphereTransform0->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform0->setTranslation(QVector3D(x+o0x,z+o0z, y+o0y));//(x,z,y)
    block[0] = new Qt3DCore::QEntity(m_rootEntity);
    block[0]->addComponent(mysphereMesh0);
    block[0]->addComponent(mysphereTransform0);
    block[0]->addComponent(mysphereMaterial0);
    block[0]->setEnabled(true);
    //qDebug("block0 ok");

    // Plane shape data
    Qt3DExtras::QCuboidMesh *mysphereMesh1 = new Qt3DExtras::QCuboidMesh();

    Qt3DExtras::QPhongMaterial *mysphereMaterial1 = new Qt3DExtras::QPhongMaterial();
    mysphereMaterial1->setDiffuse(QColor(QRgb(color)));

    Qt3DCore::QTransform *mysphereTransform1 = new Qt3DCore::QTransform();
    mysphereTransform1->setScale(1.0f);
    mysphereTransform1->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform1->setTranslation(QVector3D(x+o1x,z+o1z,y+o1y));//(x,z,y)
    block[1] = new Qt3DCore::QEntity(m_rootEntity);
    block[1]->addComponent(mysphereMesh1);
    block[1]->addComponent(mysphereTransform1);
    block[1]->addComponent(mysphereMaterial1);
    block[1]->setEnabled(true);
    //qDebug("block1 ok");

    // Plane shape data
    Qt3DExtras::QCuboidMesh *mysphereMesh3 = new Qt3DExtras::QCuboidMesh();

    Qt3DCore::QTransform *mysphereTransform3 = new Qt3DCore::QTransform();
    mysphereTransform3->setScale(1.0f);
    mysphereTransform3->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform3->setTranslation(QVector3D(x+o2x, z+o2z, y+o2y));

    Qt3DExtras::QPhongMaterial *mysphereMaterial3 = new Qt3DExtras::QPhongMaterial();
    mysphereMaterial3->setDiffuse(QColor(QRgb(color)));

    // Plane
    block[2] = new Qt3DCore::QEntity(m_rootEntity);
    block[2]->addComponent(mysphereMesh3);
    block[2]->addComponent(mysphereTransform3);
    block[2]->addComponent(mysphereMaterial3);
    block[2]->setEnabled(true);
    //qDebug("block2 ok");

    // Plane shape data
    Qt3DExtras::QCuboidMesh *mysphereMesh4 = new Qt3DExtras::QCuboidMesh();

    Qt3DCore::QTransform *mysphereTransform4 = new Qt3DCore::QTransform();
    mysphereTransform4->setScale(1.0f);
    mysphereTransform4->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform4->setTranslation(QVector3D(x+o3x, z+o3z, y+o3y));

    Qt3DExtras::QPhongMaterial *mysphereMaterial4 = new Qt3DExtras::QPhongMaterial();
    mysphereMaterial4->setDiffuse(QColor(QRgb(color)));

    // Plane
    block[3] = new Qt3DCore::QEntity(m_rootEntity);
    block[3]->addComponent(mysphereMesh4);
    block[3]->addComponent(mysphereTransform4);
    block[3]->addComponent(mysphereMaterial4);
    block[3]->setEnabled(true);
    //qDebug("block3 ok");

    return z-1.0f;
}

