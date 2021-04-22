#ifndef PLANE1_H
#define PLANE1_H

#include <QWidget>
#include<QTimer>
#include<QLabel>
#include"bullet.h"
class Plane1 : public QLabel
{
    Q_OBJECT
public:
    explicit Plane1(int id,QWidget *parent = nullptr);
    bool pzjc(int w1,int w2,int h1,int h2,int w3,int w4,int h3,int h4);
    static int die;
    int nowx1;
    int nowy1;
    int myplanex;
    int myplaney;
    int bulletx;
    int bullety;
    int id;
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

#endif // PLANE1_H
