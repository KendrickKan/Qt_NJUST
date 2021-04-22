#ifndef MYPLANE_H
#define MYPLANE_H

#include <QObject>
#include <QWidget>
#include<QLabel>
#include"bullet.h"
class MyPlane : public QLabel
{
    Q_OBJECT
public:
    explicit MyPlane(QWidget *parent = nullptr);
    void init(int x,int y);//初始化飞机
    void Goto(int flag);
    void gameover();
    int fatherx;
    int fathery;
    int nowx;
    int nowy;
    QWidget * parent;
    QTimer *bullet;
    QList<Bullet*> *list;
signals:
    void Move(int x,int y);
public slots:
};

#endif // MYPLANE_H
