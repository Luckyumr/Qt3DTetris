android|ios|tvos|winrt {
    warning( "This example is not supported for android, ios, tvos, or winrt." )
}

QT += 3dcore 3drender 3dinput 3dextras
QT += widgets

TARGET = QT3DTetris

target.path = ../$$TARGET
INSTALLS += target

SOURCES += main.cpp \
    scenemodifier.cpp \
    entity.cpp \
    mywidget.cpp

HEADERS += \
    scenemodifier.h \
    entity.h \
    mywidget.h


