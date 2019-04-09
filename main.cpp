
#include <main.h>

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

#include <QGuiApplication>

#include <Qt3DRender/qcamera.h>
#include <Qt3DCore/qentity.h>
#include <Qt3DRender/qcameralens.h>

#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtGui/QScreen>

#include <Qt3DInput/QInputAspect>

#include <Qt3DExtras/qtorusmesh.h>
#include <Qt3DRender/qmesh.h>
#include <Qt3DRender/qtechnique.h>
#include <Qt3DRender/qmaterial.h>
#include <Qt3DRender/qeffect.h>
#include <Qt3DRender/qtexture.h>
#include <Qt3DRender/qrenderpass.h>
#include <Qt3DRender/qsceneloader.h>
#include <Qt3DRender/qpointlight.h>

#include <Qt3DCore/qtransform.h>
#include <Qt3DCore/qaspectengine.h>

#include <Qt3DRender/qrenderaspect.h>
#include <Qt3DExtras/qforwardrenderer.h>

#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/qfirstpersoncameracontroller.h>
#include <QPushButton>

#include <QDateTime>
#include <QTimer>
#include <entity.h>
#include <mywidget.h>
#include <QKeyEvent>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    view->defaultFrameGraph()->setClearColor(QColor(QRgb(0x4d4d4f)));
    QWidget *container = QWidget::createWindowContainer(view);
    QSize screenSize = view->screen()->size();
    container->setMinimumSize(QSize(200, 100));
    container->setMaximumSize(screenSize);
    // Root entity
    Qt3DCore::QEntity *rootEntity1 = new Qt3DCore::QEntity();

    // Scenemodifier
    SceneModifier *modifier1 = new SceneModifier(rootEntity1);

//    QWidget *widget = new QWidget;
    MyWidget *widget = new MyWidget;
    QHBoxLayout *hLayout = new QHBoxLayout(widget);
    QVBoxLayout *vLayout = new QVBoxLayout();
    vLayout->setAlignment(Qt::AlignTop);
    hLayout->addWidget(container, 1);
    hLayout->addLayout(vLayout);

    widget->setWindowTitle(QStringLiteral("Basic shapes"));
    widget->setFocusPolicy(Qt::StrongFocus);

    Qt3DInput::QInputAspect *input = new Qt3DInput::QInputAspect;
    view->registerAspect(input);


    // Camera
    Qt3DRender::QCamera *cameraEntity = view->camera();

    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f); //视觉域,分辨率,近,远可视范围
    cameraEntity->setPosition(QVector3D(10.0f, 10.0f, 40.0f));
    cameraEntity->setUpVector(QVector3D(0, 1, 0));
    cameraEntity->setViewCenter(QVector3D(10, 10, 10));

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity1);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform(lightEntity);
    lightTransform->setTranslation(cameraEntity->position());
    lightEntity->addComponent(lightTransform);

    // For camera controls
    Qt3DExtras::QFirstPersonCameraController *camController = new Qt3DExtras::QFirstPersonCameraController(rootEntity1);
    camController->setCamera(cameraEntity);

    // Set root object of the scene
    view->setRootEntity(rootEntity1);

    // Create control widgets
    QCommandLinkButton *info = new QCommandLinkButton();
    info->setText(QStringLiteral("Qt3D ready-made meshes"));
    info->setDescription(QString::fromLatin1("Qt3D provides several ready-made meshes, like torus, cylinder, cone, "
                                             "cube, plane and sphere."));
    info->setIconSize(QSize(0,0));

    QCheckBox *torusCB = new QCheckBox(widget);
    torusCB->setChecked(true);
    torusCB->setText(QStringLiteral("Torus"));

    QCheckBox *coneCB = new QCheckBox(widget);
    coneCB->setChecked(true);
    coneCB->setText(QStringLiteral("Cone"));

    QCheckBox *cylinderCB = new QCheckBox(widget);
    cylinderCB->setChecked(true);
    cylinderCB->setText(QStringLiteral("Cylinder"));

    QCheckBox *cuboidCB = new QCheckBox(widget);
    cuboidCB->setChecked(true);
    cuboidCB->setText(QStringLiteral("Cuboid"));

    QCheckBox *planeCB = new QCheckBox(widget);
    planeCB->setChecked(true);
    planeCB->setText(QStringLiteral("Plane"));

    QCheckBox *sphereCB = new QCheckBox(widget);
    sphereCB->setChecked(true);
    sphereCB->setText(QStringLiteral("Sphere"));

    QCheckBox *nianiaCB = new QCheckBox(widget);
    nianiaCB->setChecked(true);
    nianiaCB->setText(QStringLiteral("niashape"));

    QPushButton *leftbutton =new QPushButton(widget);
    leftbutton->setGeometry(QRect(0,50,100,25));
    leftbutton->setText("<-");

    QPushButton *rightbutton =new QPushButton(widget);
    rightbutton->setGeometry(QRect(50,50,100,25));
    rightbutton->setText("->");

    QPushButton *downbutton =new QPushButton(widget);
    downbutton->setGeometry(QRect(50,50,100,25));
    downbutton->setText("V");

    QPushButton *deepbutton =new QPushButton(widget);
    deepbutton->setGeometry(QRect(50,50,100,25));
    deepbutton->setText("W");

    QPushButton *rotate =new QPushButton(widget);
    rotate->setGeometry(QRect(50,50,100,25));
    rotate->setText("G");

    QHBoxLayout *h1Layout = new QHBoxLayout();
    h1Layout->setAlignment(Qt::AlignCenter);

    QHBoxLayout *h2Layout = new QHBoxLayout();
    h2Layout->setAlignment(Qt::AlignCenter);


//    vLayout->addWidget(info);
//    vLayout->addWidget(torusCB);
//    vLayout->addWidget(coneCB);
//    vLayout->addWidget(cylinderCB);
//    vLayout->addWidget(cuboidCB);
//    vLayout->addWidget(planeCB);
//    vLayout->addWidget(sphereCB);
//    vLayout->addWidget(nianiaCB);
    vLayout->addLayout(h1Layout);
    vLayout->addLayout(h2Layout);

    h1Layout->addWidget(leftbutton);
    h1Layout->addWidget(rightbutton);

    h2Layout->addWidget(deepbutton);
    h2Layout->addWidget(downbutton);

    vLayout->addWidget(rotate);




    QObject::connect(torusCB, &QCheckBox::stateChanged,
                     modifier1, &SceneModifier::enableTorus);
    QObject::connect(coneCB, &QCheckBox::stateChanged,
                     modifier1, &SceneModifier::enableCone);
    QObject::connect(cylinderCB, &QCheckBox::stateChanged,
                     modifier1, &SceneModifier::enableCylinder);
    QObject::connect(cuboidCB, &QCheckBox::stateChanged,
                     modifier1, &SceneModifier::enableCuboid);
    QObject::connect(planeCB, &QCheckBox::stateChanged,
                     modifier1, &SceneModifier::enablePlane);
    QObject::connect(sphereCB, &QCheckBox::stateChanged,
                     modifier1, &SceneModifier::enableSphere);
    QObject::connect(nianiaCB, &QCheckBox::stateChanged,
                     modifier1, &SceneModifier::enablemyshape);

    QObject::connect(leftbutton, &QPushButton::clicked,
                     modifier1, &SceneModifier::moveEntityLeft);
    QObject::connect(rightbutton, &QPushButton::clicked,
                     modifier1, &SceneModifier::moveEntityRight);
    QObject::connect(downbutton, &QPushButton::clicked,
                     modifier1, &SceneModifier::moveEntityDown);
    QObject::connect(deepbutton, &QPushButton::clicked,
                     modifier1, &SceneModifier::moveEntityDeep);
    QObject::connect(rotate, &QPushButton::clicked,
                     modifier1, &SceneModifier::changeDirection);


    QObject::connect(widget, &MyWidget::clickedLeft,
                     modifier1, &SceneModifier::moveEntityLeft);
    QObject::connect(widget, &MyWidget::clickedRight,
                     modifier1, &SceneModifier::moveEntityRight);
    QObject::connect(widget, &MyWidget::clickedDown,
                     modifier1, &SceneModifier::moveEntityDown);
    QObject::connect(widget, &MyWidget::clickedDeep,
                     modifier1, &SceneModifier::moveEntityDeep);
    QObject::connect(widget, &MyWidget::clickedShift,
                     modifier1, &SceneModifier::changeDirection);


    torusCB->setChecked(false);
    coneCB->setChecked(false);
    cylinderCB->setChecked(false);
    cuboidCB->setChecked(false);
    planeCB->setChecked(false);
    sphereCB->setChecked(false);
    nianiaCB->setChecked(false);

//    torusCB->setChecked(true);
//    coneCB->setChecked(true);
//    cylinderCB->setChecked(true);
//    cuboidCB->setChecked(true);
//    planeCB->setChecked(true);
//    sphereCB->setChecked(true);
//    nianiaCB->setChecked(true);

    qDebug("start process");

    modifier1->wholeProcess();
    // Show window
    widget->show();
    widget->resize(1200, 800);


    return app.exec();
}
