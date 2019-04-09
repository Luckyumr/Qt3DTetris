#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>
#include <scenemodifier.h>
#include <QPushButton>
#include <QKeyEvent>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = Q_NULLPTR);

protected:
  //Key event
  void keyPressEvent(QKeyEvent * e);
signals:
  void clickedLeft();
  void clickedRight();
  void clickedDown();
  void clickedShift();
  void clickedDeep();

public slots:

private:
};

#endif // MYWIDGET_H
