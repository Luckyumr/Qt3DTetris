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

#ifndef SCENEMODIFIER_H
#define SCENEMODIFIER_H

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
#include <QStack>
#include <QTimer>

#include <entity.h>


class SceneModifier : public QObject
{
    Q_OBJECT

public:
    explicit SceneModifier(Qt3DCore::QEntity *rootEntity);
    ~SceneModifier();

    void wholeProcess();

    QTimer *time_clock = new QTimer(this);

    int LEFTBORDER = 5;
    int RIGHTBORDER = 14;
    int YPOS = 10;

public slots:
    void enableTorus(bool enabled);
    void enableCone(bool enabled);
    void enableCylinder(bool enabled);
    void enableCuboid(bool enabled);
    void enablePlane(bool enabled);
    void enableSphere(bool enabled);
    void enablemyshape(bool enabled);

    void change();
    void moveEntityLeft();
    void moveEntityRight();
    void moveEntityDown();
    void moveEntityDeep();
    void changeDirection();

protected:

private:
    void createfloor();   //生成地面
    void creategrid(float col);  //生成网格
    void createshap(entity *blocks);
    void saveCurrentEntity(entity *blocks);
    void processFlag(bool runFlag);

    bool changeEntityPos(float o0x,float o0z,float o0y,
                         float o1x,float o1z,float o1y,
                         float o2x,float o2z,float o2y,
                         float o3x,float o3z,float o3y);
    void tryRemoveEntity();

    Qt3DCore::QEntity *m_rootEntity;
    Qt3DExtras::QTorusMesh *m_torus;
    Qt3DCore::QEntity *m_coneEntity;
    Qt3DCore::QEntity *m_cylinderEntity;
    Qt3DCore::QEntity *m_torusEntity;
    Qt3DCore::QEntity *m_cuboidEntity;
    Qt3DCore::QEntity *m_planeEntity;
    Qt3DCore::QEntity *m_sphereEntity;
    Qt3DCore::QEntity *m_lifangEntity;

    entity::position *nowpos;

    float timenum = 10.0f;

    entity *rootEntity;
    Qt3DCore::QEntity *floorEntity;
    Qt3DCore::QEntity *gridEntity;

    int existPos[20][30][20];                //已有图形位置记录数组,分别为 X,Z,Y,(10,20,10)为新图形位置
    Qt3DCore::QEntity *totalGrid[20][30][20];  //已有图形记录数组,分别为 X,Z,Y,(10,20,10)为新图形位置
    entity::position currentEntityPos[4];    //当前控制图形位置
    int entityDirection;                     //当前图形方向 mode1 0,mode2 90,mode3 180,mode4 270
    int entityType;                          //当前图形种类

    int LockFlag =0;
    int startflag = 1;

private slots:

};


#endif // SCENEMODIFIER_H

