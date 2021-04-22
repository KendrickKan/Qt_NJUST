#include "myplane.h"
#include<QMovie>
#include<QLabel>
#include<QTimer>
#include"bullet.h"
#include<QList>
#include<QDebug>
MyPlane::MyPlane(QWidget *parent) : QLabel(parent)
{
    list=new QList<Bullet*>;//自己的飞机新建一个子弹list
    QMovie *movie = new QMovie(":/img/myplane.gif");
    this->setMovie(movie);
    movie->start();
  //  this->setPixmap(QPixmap(":/img/myplane.gif"));
    resize(66,80);
    this->parent=parent;
}
void MyPlane::init(int x,int y){
    nowx=x*0.5-30;
    nowy=y*0.8;//设置初始位置，最开始传进来的x，y是屏幕的宽度，长度;
    this->move(nowx,nowy);
    fatherx=x,fathery=y;
    //emit where(this->nowx,this->nowy);
    //这里就要开启定时器 发起子弹
    bullet = new QTimer(this);
    connect(bullet,&QTimer::timeout,[=](){
         Bullet* temp=new Bullet(nowx,nowy,parent);
         temp->setlist(list);//将我的飞机的子弹list传回子弹对象上，用于判断是否移开屏幕，方便消除
         list->push_back(temp);//将子弹存入list
    });
    bullet->start(100);
}
void MyPlane::Goto(int flag){//控制飞机移动
    if(flag==1){
        if(nowx>0)
            this->move(nowx-=20,nowy);
     }
    else if(flag==2){
        if(nowx<(fatherx-70))
            this->move(nowx+=20,nowy);
    }
    else if(flag==3){
        if(nowy>5)
            this->move(nowx,nowy-=20);
    }
    else{
        if(nowy<(fathery-80))
            this->move(nowx,nowy+=20);
    }
    emit move(nowx,nowy);
}
void MyPlane::gameover(){
    QMovie *movie = new QMovie(":/img/myboom.gif");
    this->setMovie(movie);
    movie->start();
    this->bullet->stop();
    for(int i=0;i<list->length();i++)
        list->removeLast();//游戏结束，remove所有剩余子弹
}
