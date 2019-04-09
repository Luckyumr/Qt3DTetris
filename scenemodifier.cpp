/****************************************************************************
**
** Copyright (C) 2014 Klaralvdalens Datakonsult AB (KDAB).
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Qt3D module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "scenemodifier.h"

#include <QtCore/QDebug>
#include <QString>


SceneModifier::SceneModifier(Qt3DCore::QEntity *rootEntity)
    : m_rootEntity(rootEntity)
{
    // Torus shape data
    //! [0]
    m_torus = new Qt3DExtras::QTorusMesh();
    m_torus->setRadius(1.0f);
    m_torus->setMinorRadius(0.4f);
    m_torus->setRings(100);
    m_torus->setSlices(20);
    //! [0]

    // TorusMesh Transform
    //! [1]
    Qt3DCore::QTransform *torusTransform = new Qt3DCore::QTransform();
    torusTransform->setScale(2.0f);
    torusTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 1.0f, 0.0f), 25.0f));
    torusTransform->setTranslation(QVector3D(5.0f, 4.0f, 0.0f));
    //! [1]

    //! [2]
    Qt3DExtras::QPhongMaterial *torusMaterial = new Qt3DExtras::QPhongMaterial();
    torusMaterial->setDiffuse(QColor(QRgb(0xbeb32b)));
    //! [2]

    // Torus
    //! [3]
    m_torusEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_torusEntity->addComponent(m_torus);
    m_torusEntity->addComponent(torusMaterial);
    m_torusEntity->addComponent(torusTransform);
    //! [3]

    // Cone shape data
    Qt3DExtras::QConeMesh *cone = new Qt3DExtras::QConeMesh();
    cone->setTopRadius(0.5);
    cone->setBottomRadius(1);
    cone->setLength(3);
    cone->setRings(50);
    cone->setSlices(20);

    // ConeMesh Transform
    Qt3DCore::QTransform *coneTransform = new Qt3DCore::QTransform();
    coneTransform->setScale(1.5f);
    coneTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    coneTransform->setTranslation(QVector3D(0.0f, 4.0f, -1.5));

    Qt3DExtras::QPhongMaterial *coneMaterial = new Qt3DExtras::QPhongMaterial();
    coneMaterial->setDiffuse(QColor(QRgb(0x928327)));

    // Cone
    m_coneEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_coneEntity->addComponent(cone);
    m_coneEntity->addComponent(coneMaterial);
    m_coneEntity->addComponent(coneTransform);

    // Cylinder shape data
    Qt3DExtras::QCylinderMesh *cylinder = new Qt3DExtras::QCylinderMesh();
    cylinder->setRadius(1);
    cylinder->setLength(3);
    cylinder->setRings(10);
    cylinder->setSlices(20);

    // CylinderMesh Transform
    Qt3DCore::QTransform *cylinderTransform = new Qt3DCore::QTransform();
    cylinderTransform->setScale(1.5f);
    cylinderTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    cylinderTransform->setTranslation(QVector3D(-5.0f, 4.0f, -1.5));

    Qt3DExtras::QPhongMaterial *cylinderMaterial = new Qt3DExtras::QPhongMaterial();
    cylinderMaterial->setDiffuse(QColor(QRgb(0x928327)));

    // Cylinder
    m_cylinderEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_cylinderEntity->addComponent(cylinder);
    m_cylinderEntity->addComponent(cylinderMaterial);
    m_cylinderEntity->addComponent(cylinderTransform);

    // Cuboid shape data
    Qt3DExtras::QCuboidMesh *cuboid = new Qt3DExtras::QCuboidMesh();

    // CuboidMesh Transform
    Qt3DCore::QTransform *cuboidTransform = new Qt3DCore::QTransform();
    cuboidTransform->setScale(2.0f);
    cuboidTransform->setTranslation(QVector3D(5.0f, -4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial *cuboidMaterial = new Qt3DExtras::QPhongMaterial();
    cuboidMaterial->setDiffuse(QColor(QRgb(0x665423)));

    //Cuboid
    m_cuboidEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_cuboidEntity->addComponent(cuboid);
    m_cuboidEntity->addComponent(cuboidMaterial);
    m_cuboidEntity->addComponent(cuboidTransform);

    // Plane shape data
    Qt3DExtras::QPlaneMesh *planeMesh = new Qt3DExtras::QPlaneMesh();
    planeMesh->setWidth(2);
    planeMesh->setHeight(2);

    // Plane mesh transform
    Qt3DCore::QTransform *planeTransform = new Qt3DCore::QTransform();
    planeTransform->setScale(1.3f);
    planeTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    planeTransform->setTranslation(QVector3D(0.0f, -4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial *planeMaterial = new Qt3DExtras::QPhongMaterial();
    planeMaterial->setDiffuse(QColor(QRgb(0xa69929)));

    // Plane
    m_planeEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_planeEntity->addComponent(planeMesh);
    m_planeEntity->addComponent(planeMaterial);
    m_planeEntity->addComponent(planeTransform);

    // Sphere shape data
    Qt3DExtras::QSphereMesh *sphereMesh = new Qt3DExtras::QSphereMesh();
    sphereMesh->setRings(20);
    sphereMesh->setSlices(20);
    sphereMesh->setRadius(2);

    // Sphere mesh transform
    Qt3DCore::QTransform *sphereTransform = new Qt3DCore::QTransform();

    sphereTransform->setScale(1.3f);
    sphereTransform->setTranslation(QVector3D(-5.0f, -4.0f, 0.0f));

    Qt3DExtras::QPhongMaterial *sphereMaterial = new Qt3DExtras::QPhongMaterial();
    sphereMaterial->setDiffuse(QColor(QRgb(0xa69929)));

    // Sphere
    m_sphereEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_sphereEntity->addComponent(sphereMesh);
    m_sphereEntity->addComponent(sphereMaterial);
    m_sphereEntity->addComponent(sphereTransform);

    //M_Shape data
    Qt3DExtras::QCuboidMesh *mysphereMesh = new Qt3DExtras::QCuboidMesh();

    Qt3DCore::QTransform *mysphereTransform = new Qt3DCore::QTransform();
    mysphereTransform->setScale(2.0f);
    mysphereTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 45.0f));
    mysphereTransform->setTranslation(QVector3D(0.0f, 10.0f, -1.5));

    Qt3DExtras::QPhongMaterial *mysphereMaterial = new Qt3DExtras::QPhongMaterial();
    mysphereMaterial->setDiffuse(QColor(QRgb(0xFFAEB9)));

    //M_Sphere
    m_lifangEntity = new Qt3DCore::QEntity(m_rootEntity);
    m_lifangEntity->addComponent(mysphereMesh);
    m_lifangEntity->addComponent(mysphereTransform);
    m_lifangEntity->addComponent(mysphereMaterial);

}

SceneModifier::~SceneModifier()
{
}

//! [4]
void SceneModifier::enableTorus(bool enabled)
{
    m_torusEntity->setEnabled(enabled);
}
//! [4]

void SceneModifier::enablemyshape(bool enabled)
{
    m_lifangEntity->setEnabled(enabled);
}

void SceneModifier::enableCone(bool enabled)
{
    m_coneEntity->setEnabled(enabled);
}

void SceneModifier::enableCylinder(bool enabled)
{
    m_cylinderEntity->setEnabled(enabled);
}

void SceneModifier::enableCuboid(bool enabled)
{
    m_cuboidEntity->setEnabled(enabled);
}

void SceneModifier::enablePlane(bool enabled)
{
    m_planeEntity->setEnabled(enabled);
}

void SceneModifier::enableSphere(bool enabled)
{
    m_sphereEntity->setEnabled(enabled);
}

void SceneModifier::change()
{
    qDebug("change start");
    if(startflag == 1)
    {
        rootEntity = new entity(m_rootEntity);
        createshap(rootEntity);
        startflag = 0;
    }

    if(changeEntityPos(0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f))
    {
        qDebug("ok down");
        //可以下坠
    }
    else                               // 下坠时任何方块与其他相邻,创建下一个方块
    {
        qDebug("cant down");

        saveCurrentEntity(rootEntity);

        tryRemoveEntity();

        createshap(rootEntity);

    }
}


void SceneModifier::wholeProcess()
{
    //开始
    processFlag(true);
    createfloor();
    creategrid(LEFTBORDER-1.0f);
    creategrid(RIGHTBORDER);
    //开始后计时一秒一次下坠

}

void SceneModifier::processFlag(bool runFlag)
{
    if(runFlag == true)
    {
        //初始化位置与实体:
        for(int i=0; i < 20; i++)
            for(int j=0; j<30; j++)
                for(int k=0; k<20; k++)
                {
                    totalGrid[i][j][k] = NULL;
                    existPos[i][j][k] = 0;
                }
        qDebug()<<"Unset";

        QObject::connect(time_clock,SIGNAL(timeout()),this,SLOT(change()));
        time_clock->start(1000);
    }
    if(runFlag == false)
    {
        qDebug()<<"Prossce Stop";
        time_clock->stop();
    }
}


void SceneModifier::createfloor()   //生成地面
{
    //floor shape data
    Qt3DExtras::QPlaneMesh *floorMesh = new Qt3DExtras::QPlaneMesh();
    floorMesh->setWidth(20);
    floorMesh->setHeight(10);

    //floor mesh transform
    Qt3DCore::QTransform *planeTransform = new Qt3DCore::QTransform();
    planeTransform->setScale(1.3f);
    planeTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0.0f));
    planeTransform->setTranslation(QVector3D(10.0f, -0.5f, 10.0f));

    Qt3DExtras::QPhongMaterial *planeMaterial = new Qt3DExtras::QPhongMaterial();
    planeMaterial->setDiffuse(QColor(QRgb(0x00FF7F)));

    qDebug("floorcreat");
    floorEntity = new Qt3DCore::QEntity(m_rootEntity);
    floorEntity->addComponent(floorMesh);
    floorEntity->addComponent(planeMaterial);
    floorEntity->addComponent(planeTransform);
    floorEntity->setEnabled(true);
}


void SceneModifier::creategrid(float col)  //生成网格
{
    //floor shape data
    Qt3DExtras::QCylinderMesh *gridrMesh = new Qt3DExtras::QCylinderMesh();
    gridrMesh->setLength(20.0f);
    gridrMesh->setRadius(0.005f);

    //floor mesh transform
    Qt3DCore::QTransform *gridrTransform = new Qt3DCore::QTransform();
    gridrTransform->setScale(1.0f);
    gridrTransform->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(0.0f, 0.0f, 0.0f), 0.0f));
    gridrTransform->setTranslation(QVector3D(col+0.5, 10.0f, 10.0f));

    Qt3DExtras::QPhongMaterial *gridrMaterial = new Qt3DExtras::QPhongMaterial();
    gridrMaterial->setDiffuse(QColor(QRgb(0xFFFFFF)));

    qDebug("floorcreat");
    gridEntity = new Qt3DCore::QEntity(m_rootEntity);
    gridEntity->addComponent(gridrMesh);
    gridEntity->addComponent(gridrMaterial);
    gridEntity->addComponent(gridrTransform);
    gridEntity->setEnabled(true);
}

void SceneModifier::changeDirection()
{
    switch (entityType) {
    case 1:       //T
        switch (entityDirection) {
        case 1:             //0°
            if(changeEntityPos(1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,-1.0f,0.0f,-1.0f,1.0f,0.0f))    //可以转
            {
                entityDirection = 2;
            }
            break;
        case 2:             //90°
            if(changeEntityPos(1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,1.0f,0.0f,1.0f,1.0f,0.0f))    //可以转
            {
                entityDirection = 3;
            }
            break;
        case 3:             //180°
            if(changeEntityPos(-1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,1.0f,0.0f,1.0f,-1.0f,0.0f))    //可以转
            {
                entityDirection = 4;
            }
            break;
        case 4:             //270°
            if(changeEntityPos(-1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,-1.0f,0.0f,-1.0f,-1.0f,0.0f))    //可以转
            {
                entityDirection = 1;
            }
            break;
        default:
            qDebug() << "entityDirechtion Error";
            break;
        }
        break;

    case 2:       //O
            qDebug()<<"O no change";
        break;

    case 3:       //I
        switch (entityDirection) {
        case 1:             //0°
            if(changeEntityPos(-2.0f,2.0f,0.0f,-1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,-1.0f,0.0f))
            {
                entityDirection = 2;
            }
            break;
        case 2:             //180°
            if(changeEntityPos(2.0f,-2.0f,0.0f,1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,1.0f,0.0f))    //可以转
            {
                entityDirection = 1;
            }
            break;
        default:
            qDebug() << "entityDirechtion Error";
            break;
        }

        break;


    case 4:       //L1
        switch (entityDirection) {
        case 1:             //0°
            if(changeEntityPos(0.0f,2.0f,0.0f,1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,-1.0f,0.0f))    //可以转
            {
                entityDirection = 2;
            }
            break;
        case 2:             //90°
          if(changeEntityPos(2.0f,0.0f,0.0f,1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,1.0f,0.0f))   //可以转
            {
                entityDirection = 3;
            }
            break;
        case 3:             //180°
            if(changeEntityPos(0.0f,-2.0f,0.0f,-1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,1.0f,0.0f))    //可以转
            {
                entityDirection = 4;
            }
            break;
        case 4:             //270°
            if(changeEntityPos(-2.0f,0.0f,0.0f,-1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,-1.0f,0.0f))    //可以转
            {
                entityDirection = 1;
            }
            break;
        default:
            qDebug() << "entityDirechtion Error";
            break;
        }
        break;


    case 5:       //L2
        switch (entityDirection) {
        case 1:             //0°
            if(changeEntityPos(-2.0f,0.0f,0.0f,-1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,1.0f,0.0f))    //可以转
            {
                entityDirection = 2;
            }
            break;
        case 2:             //90°
          if(changeEntityPos(0.0f,2.0f,0.0f,-1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,-1.0f,0.0f))   //可以转
            {
                entityDirection = 3;
            }
            break;
        case 3:             //180°
            if(changeEntityPos(2.0f,0.0f,0.0f,1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,-1.0f,0.0f))    //可以转
            {
                entityDirection = 4;
            }
            break;
        case 4:             //270°
            if(changeEntityPos(0.0f,-2.0f,0.0f,1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,1.0f,0.0f))    //可以转
            {
                entityDirection = 1;
            }
            break;
        default:
            qDebug() << "entityDirechtion Error";
            break;
        }
        break;



    case 6:       //Z1
        switch (entityDirection) {
        case 1:             //0°
            if(changeEntityPos(-1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,1.0f,0.0f,2.0f,0.0f,0.0f))    //可以转
            {
                entityDirection = 2;
            }
            break;
        case 2:             //90°
            if(changeEntityPos(1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,-1.0f,0.0f,-2.0f,0.0f,0.0f))    //可以转
            {
                entityDirection = 1;
            }
            break;

        default:
            qDebug() << "entityDirechtion Error";
            break;
        }
        break;


    case 7:       //Z2
        switch (entityDirection) {
        case 1:             //0°
            if(changeEntityPos(0.0f,2.0f,0.0f,1.0f,1.0f,0.0f,0.0f,0.0f,0.0f,1.0f,-1.0f,0.0f))    //可以转
            {
                entityDirection = 2;
            }
            break;
        case 2:             //90°
            if(changeEntityPos(0.0f,-2.0f,0.0f,-1.0f,-1.0f,0.0f,0.0f,0.0f,0.0f,-1.0f,1.0f,0.0f))    //可以转
            {
                entityDirection = 1;
            }
            break;

        default:
            qDebug() << "entityDirechtion Error";
            break;
        }
        break;

    default:
        break;
    }

}

void SceneModifier::createshap(entity *blocks)
{
    if(LockFlag == 0)
    {

    //if创建时位置重叠,游戏结束
    qDebug("start createshap");
    float x = 10.0f;
    float z = 20.0f;
    float y = 10.0f;
    entity::position pos(x,z,y);

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int rand =qrand()%7;
    qDebug() << "rand =" << rand;

    switch (rand) {
    case 0:                   //T
        qDebug("creat T");
        if(existPos[int(x)][int(z)-1][int(y)]==1)
            processFlag(false);

        blocks->createT(pos);
        entityDirection = 1;
        entityType = 1;

        currentEntityPos[0].x = x-1.0f;
        currentEntityPos[0].z = z;
        currentEntityPos[0].y = y;

        currentEntityPos[1].x = x;
        currentEntityPos[1].z = z;
        currentEntityPos[1].y = y;

        currentEntityPos[2].x = x+1.0f;
        currentEntityPos[2].z = z;
        currentEntityPos[2].y = y;

        currentEntityPos[3].x = x;
        currentEntityPos[3].z = z-1.0f;
        currentEntityPos[3].y = y;

        break;
    case 1:                   //O
        qDebug("creat O");
        if(existPos[int(x)][int(z)-1][int(y)]==1 ||existPos[int(x)-1][int(z)-1][int(y)]==1 )
            processFlag(false);

        blocks->createO(pos);
        entityDirection = 1;
        entityType = 2;

        currentEntityPos[0].x = x-1.0f;
        currentEntityPos[0].z = z-1.0f;
        currentEntityPos[0].y = y;

        currentEntityPos[1].x = x;
        currentEntityPos[1].z = z-1.0f;
        currentEntityPos[1].y = y;

        currentEntityPos[2].x = x-1.0f;
        currentEntityPos[2].z = z;
        currentEntityPos[2].y = y;

        currentEntityPos[3].x = x;
        currentEntityPos[3].z = z;
        currentEntityPos[3].y = y;

        break;

    case 2:                   //I
        qDebug("creat I");
        if(existPos[int(x)][int(z)-1][int(y)]==1)
            processFlag(false);

        blocks->createI(pos);
        entityDirection = 1;
        entityType = 3;

        currentEntityPos[0].x = x;
        currentEntityPos[0].z = z-1.0f;
        currentEntityPos[0].y = y;

        currentEntityPos[1].x = x;
        currentEntityPos[1].z = z;
        currentEntityPos[1].y = y;

        currentEntityPos[2].x = x;
        currentEntityPos[2].z = z+1.0f;
        currentEntityPos[2].y = y;

        currentEntityPos[3].x = x;
        currentEntityPos[3].z = z+2.0f;
        currentEntityPos[3].y = y;

        break;
    case 3:                   //L1
        qDebug("creat L1");
        if(existPos[int(x)-1][int(z)-1][int(y)]==1)
            processFlag(false);

        blocks->createL1(pos);
        entityDirection = 1;
        entityType = 4;

        currentEntityPos[0].x = x-1.0f;
        currentEntityPos[0].z = z-1.0f;
        currentEntityPos[0].y = y;

        currentEntityPos[1].x = x-1.0f;
        currentEntityPos[1].z = z;
        currentEntityPos[1].y = y;

        currentEntityPos[2].x = x;
        currentEntityPos[2].z = z;
        currentEntityPos[2].y = y;

        currentEntityPos[3].x = x+1.0f;
        currentEntityPos[3].z = z;
        currentEntityPos[3].y = y;

        break;
    case 4:                   //L2
        qDebug("creat L2");
        if(existPos[int(x)+1][int(z)-1][int(y)]==1)
            processFlag(false);

        blocks->createL2(pos);
        entityDirection = 1;
        entityType = 5;

        currentEntityPos[0].x = x+1.0f;
        currentEntityPos[0].z = z-1.0f;
        currentEntityPos[0].y = y;

        currentEntityPos[1].x = x+1.0f;
        currentEntityPos[1].z = z;
        currentEntityPos[1].y = y;

        currentEntityPos[2].x = x;
        currentEntityPos[2].z = z;
        currentEntityPos[2].y = y;

        currentEntityPos[3].x = x-1.0f;
        currentEntityPos[3].z = z;
        currentEntityPos[3].y = y;

        break;
    case 5:                   //Z1
        qDebug("creat Z1");
        if(existPos[int(x)][int(z)-1][int(y)]==1)
            processFlag(false);

        blocks->createZ1(pos);
        entityDirection = 1;
        entityType = 6;

        currentEntityPos[0].x = x;
        currentEntityPos[0].z = z-1.0f;
        currentEntityPos[0].y = y;

        currentEntityPos[1].x = x;
        currentEntityPos[1].z = z;
        currentEntityPos[1].y = y;

        currentEntityPos[2].x = x-1.0f;
        currentEntityPos[2].z = z;
        currentEntityPos[2].y = y;

        currentEntityPos[3].x = x-1.0f;
        currentEntityPos[3].z = z+1.0f;
        currentEntityPos[3].y = y;

        break;
    case 6:                   //Z2
        qDebug("creat Z2");
        if(existPos[int(x)-1][int(z)-1][int(y)]==1)
            processFlag(false);

        blocks->createZ2(pos);
        entityDirection = 1;
        entityType = 7;

        currentEntityPos[0].x = x-1.0f;
        currentEntityPos[0].z = z-1.0f;
        currentEntityPos[0].y = y;

        currentEntityPos[1].x = x-1.0f;
        currentEntityPos[1].z = z;
        currentEntityPos[1].y = y;

        currentEntityPos[2].x = x;
        currentEntityPos[2].z = z;
        currentEntityPos[2].y = y;

        currentEntityPos[3].x = x;
        currentEntityPos[3].z = z+1.0f;
        currentEntityPos[3].y = y;

        break;

    default:
        break;
    }
    LockFlag = 1;

    }
}

void SceneModifier::saveCurrentEntity(entity *blocks){

    qDebug()<<"save shape";
        qDebug()<< "LockFlag == 1";
    int cx0 = int(currentEntityPos[0].x);
    int cz0 = int(currentEntityPos[0].z);
    int cy0 = int(currentEntityPos[0].y);

    int cx1 = int(currentEntityPos[1].x);
    int cz1 = int(currentEntityPos[1].z);
    int cy1 = int(currentEntityPos[1].y);

    int cx2 = int(currentEntityPos[2].x);
    int cz2 = int(currentEntityPos[2].z);
    int cy2 = int(currentEntityPos[2].y);

    int cx3 = int(currentEntityPos[3].x);
    int cz3 = int(currentEntityPos[3].z);
    int cy3 = int(currentEntityPos[3].y);

    totalGrid[cx0][cz0][cy0] = blocks->block[0];
    existPos[cx0][cz0][cy0] = 1;
    totalGrid[cx1][cz1][cy1] = blocks->block[1];
    existPos[cx1][cz1][cy1] = 1;
    totalGrid[cx2][cz2][cy2] = blocks->block[2];
    existPos[cx2][cz2][cy2] = 1;
    totalGrid[cx3][cz3][cy3] = blocks->block[3];
    existPos[cx3][cz3][cy3] = 1;

    LockFlag = 0;
}

void SceneModifier::moveEntityLeft()
{
    qDebug("move start");
    if(LockFlag == 0)
    {
        qDebug()<<"Lock cantmove";
        return;
    }
    //if 可以左移

    if(changeEntityPos(-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f))
    {
        qDebug("ok Left");
        //可以左移
    }
}


void SceneModifier::moveEntityRight()
{
    qDebug("Right move start");
    if(LockFlag == 0)
    {
        qDebug()<<"Lock cantmove";
        return;
    }
    //if 可以右移

    if(changeEntityPos(1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f,1.0f,0.0f,0.0f))
    {        qDebug("ok Right");
        //可以右移

    }
}

void SceneModifier::moveEntityDown()
{
    qDebug("Down move start");
    if(LockFlag == 0)
    {
        qDebug()<<"Lock cantmove";
        return;
    }
    //if 可以下移

    if(changeEntityPos(0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f))
    {
        qDebug("ok Down");
        //可以下移
    }
}

void SceneModifier::moveEntityDeep()
{
    qDebug("Deep move start");
    if(LockFlag == 0)
    {
        qDebug()<<"Lock cantmove";
        return;
    }

    while(changeEntityPos(0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f,0.0f,-1.0f,0.0f))
    {
        qDebug("next deep");
    }
    {
        qDebug("cant deep");
        LockFlag = 0;
    }

}


bool SceneModifier::changeEntityPos(float o0x,float o0z,float o0y,float o1x,float o1z,float o1y,
                                    float o2x,float o2z,float o2y,float o3x,float o3z,float o3y)
{
    qDebug() << "change jduge";
    qDebug() << (currentEntityPos[0].z+o0z>=0 && currentEntityPos[1].z+o1z>=0 && currentEntityPos[2].z+o2z>=0 && currentEntityPos[3].z+o3z>=0);             //最左边界之前
    qDebug() << (currentEntityPos[0].x+o0x>=LEFTBORDER && currentEntityPos[1].x+o1x>=LEFTBORDER && currentEntityPos[2].x+o2x>=LEFTBORDER && currentEntityPos[3].x+o3x>=LEFTBORDER);
    qDebug() << (currentEntityPos[0].x+o0x<=RIGHTBORDER && currentEntityPos[1].x+o1x<=RIGHTBORDER && currentEntityPos[2].x+o2x<=RIGHTBORDER && currentEntityPos[3].x+o3x<=RIGHTBORDER);
    qDebug() << (existPos[int(currentEntityPos[0].x+o0x)][int(currentEntityPos[0].z+o0z)][int(currentEntityPos[0].y+o0y)] == 0);  //block0下一格无
    qDebug() << (existPos[int(currentEntityPos[1].x+o1x)][int(currentEntityPos[1].z+o1z)][int(currentEntityPos[0].y+o0y)] == 0);  //block1下一格无
    qDebug() << (existPos[int(currentEntityPos[2].x+o2x)][int(currentEntityPos[2].z+o2z)][int(currentEntityPos[1].y+o1y)] == 0);  //block2下一格无
    qDebug() << (existPos[int(currentEntityPos[3].x+o3x)][int(currentEntityPos[3].z+o3z)][int(currentEntityPos[3].y+o3y)] == 0);  //block3下一格无
    qDebug() << "Finsh";

    if(currentEntityPos[0].z+o0z>=0 && currentEntityPos[1].z+o1z>=0 && currentEntityPos[2].z+o2z>=0 && currentEntityPos[3].z+o3z>=0             //最左边界之前
       && currentEntityPos[0].x+o0x>=LEFTBORDER && currentEntityPos[1].x+o1x>=LEFTBORDER && currentEntityPos[2].x+o2x>=LEFTBORDER && currentEntityPos[3].x+o3x>=LEFTBORDER
       && currentEntityPos[0].x+o0x<=RIGHTBORDER && currentEntityPos[1].x+o1x<=RIGHTBORDER && currentEntityPos[2].x+o2x<=RIGHTBORDER && currentEntityPos[3].x+o3x<=RIGHTBORDER
       && existPos[int(currentEntityPos[0].x+o0x)][int(currentEntityPos[0].z+o0z)][int(currentEntityPos[0].y+o0y)] == 0  //block0下一格无
       && existPos[int(currentEntityPos[1].x+o1x)][int(currentEntityPos[1].z+o1z)][int(currentEntityPos[0].y+o0y)] == 0  //block1下一格无
       && existPos[int(currentEntityPos[2].x+o2x)][int(currentEntityPos[2].z+o2z)][int(currentEntityPos[1].y+o1y)] == 0  //block2下一格无
       && existPos[int(currentEntityPos[3].x+o3x)][int(currentEntityPos[3].z+o3z)][int(currentEntityPos[3].y+o3y)] == 0  //block3下一格无
       )
    {

    currentEntityPos[0].x= currentEntityPos[0].x+o0x;
    currentEntityPos[0].z= currentEntityPos[0].z+o0z;
    currentEntityPos[0].y= currentEntityPos[0].y+o0y;

    currentEntityPos[1].x= currentEntityPos[1].x+o1x;
    currentEntityPos[1].z= currentEntityPos[1].z+o1z;
    currentEntityPos[1].y= currentEntityPos[1].y+o1y;

    currentEntityPos[2].x= currentEntityPos[2].x+o2x;
    currentEntityPos[2].z= currentEntityPos[2].z+o2z;
    currentEntityPos[2].y= currentEntityPos[2].y+o2y;

    currentEntityPos[3].x= currentEntityPos[3].x+o3x;
    currentEntityPos[3].z= currentEntityPos[3].z+o3z;
    currentEntityPos[3].y= currentEntityPos[3].y+o3y;


    Qt3DCore::QTransform *mysphereTransform0 = new Qt3DCore::QTransform();
//    mysphereTransform0->setScale(1.0f);
//    mysphereTransform0->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform0->setTranslation(QVector3D(currentEntityPos[0].x,currentEntityPos[0].z ,currentEntityPos[0].y ));
    rootEntity->block[0]->addComponent(mysphereTransform0);

    Qt3DCore::QTransform *mysphereTransform1 = new Qt3DCore::QTransform();
//    mysphereTransform1->setScale(1.0f);
//    mysphereTransform1->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform1->setTranslation(QVector3D(currentEntityPos[1].x,currentEntityPos[1].z ,currentEntityPos[1].y ));
    rootEntity->block[1]->addComponent(mysphereTransform1);

    Qt3DCore::QTransform *mysphereTransform2 = new Qt3DCore::QTransform();
//    mysphereTransform2->setScale(1.0f);
//    mysphereTransform2->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform2->setTranslation(QVector3D(currentEntityPos[2].x,currentEntityPos[2].z ,currentEntityPos[2].y ));
    rootEntity->block[2]->addComponent(mysphereTransform2);

    Qt3DCore::QTransform *mysphereTransform3 = new Qt3DCore::QTransform();
//    mysphereTransform3->setScale(1.0f);
//    mysphereTransform3->setRotation(QQuaternion::fromAxisAndAngle(QVector3D(1.0f, 0.0f, 0.0f), 0.0f));
    mysphereTransform3->setTranslation(QVector3D(currentEntityPos[3].x,currentEntityPos[3].z ,currentEntityPos[3].y ));
    rootEntity->block[3]->addComponent(mysphereTransform3);

    return true;
    }
    return false;
}

void SceneModifier::tryRemoveEntity()
{
    QStack<int> removeRow;
    for(int i=0 ; i <= 20 ; i++)
    {
        bool rowFull = true;
        for(int j =5 ; j <15 ;j++)
        {
            if(existPos[j][i][YPOS]==0)
            {
                rowFull = false;
            }
        }
        if(rowFull == true)
        {
            removeRow.push_back(i);
            qDebug() << i<< " row remove" ;
            for(int j = LEFTBORDER ; j <= RIGHTBORDER ;j++)
            {
                    totalGrid[j][i][YPOS]->setEnabled(false);
                    existPos[j][i][YPOS] = 0;
            }

        }
    }

    int removeRowCount[30];
    for(int i=0; i< 30 ; i++)
    {
        removeRowCount[i] =0;
    }
    while(!removeRow.empty())
    {
        int row = removeRow.top();
        removeRow.pop();
        for(int i=row+1; i < 30; i++)
            removeRowCount[i]++;
    }

    for(int i=1 ; i <= 20 ; i++)
    {
        for(int j = LEFTBORDER ; j <= RIGHTBORDER ;j++)
        {
            if(removeRowCount[i] != 0)
            {
                totalGrid[j][i-removeRowCount[i]][YPOS] = totalGrid[j][i][YPOS];
                if(totalGrid[j][i][YPOS] != NULL)
                {
                    qDebug() << "entity down";
                    Qt3DCore::QTransform *mySphereDown = new Qt3DCore::QTransform();
                    mySphereDown->setTranslation(QVector3D(j,i-removeRowCount[i] ,YPOS ));
                    totalGrid[j][i-removeRowCount[i]][YPOS]->addComponent(mySphereDown);
                }
                totalGrid[j][i][YPOS] = NULL;

                existPos[j][i-removeRowCount[i]][YPOS] = existPos[j][i][YPOS];
                existPos[j][i][YPOS] = 0;
            }
        }
    }
}

