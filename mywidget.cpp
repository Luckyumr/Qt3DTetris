#include "mywidget.h"

MyWidget::MyWidget(QWidget *parent) : QWidget(parent)
{
}



void MyWidget::keyPressEvent(QKeyEvent *event)
{
    qDebug() << "buttom press";
    switch (event->key()) {
    case Qt::Key_Left:
        qDebug() << "Left buttom press";
        emit clickedLeft();
        break;
    case Qt::Key_Right:
        qDebug() << "Right buttom press";
        emit clickedRight();
        break;
    case Qt::Key_Down:
        qDebug() << "Down buttom press";
        emit clickedDown();
        break;
    case Qt::Key_Shift:
        qDebug() << "Shift buttom press";
        emit clickedShift();
        break;
    case Qt::Key_Space:
        qDebug() << "Space buttom press";
        emit clickedDeep();
        break;
    default:
        break;
    }
}
