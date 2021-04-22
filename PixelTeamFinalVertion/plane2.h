#ifndef PLANE2_H
#define PLANE2_H

#include <QWidget>
#include<QLabel>
#include<QList>
#include"bullet.h"
class Plane2 : public QLabel
{
    Q_OBJECT
public:
    explicit Plane2(QWidget *parent = nullptr);
    bool pzjc(int w1,int w2,int h1,int h2,int w3,int w4,int h3,int h4);
    static int die;
    int nowx2;
    int nowy2;
    int myplanex;
    int myplaney;
    int bulletx;
    int bullety;
    int id;
    int count;
    QList<Bullet*> *list;
    void setlist(QList<Bullet*> *);
    QTimer *timer;
    QTimer *pictimer;
    static void Die();
signals:
    void GameOver();
public slots:
    void AcceptMyplane(int x,int y);
};

#endif // PLANE2_H
