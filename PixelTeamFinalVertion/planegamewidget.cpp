#include "planegamewidget.h"
#include<QPainter>
#include<QKeyEvent>
#include<QTimer>
#include "plane1.h"
#include"plane2.h"
#include"plane3.h"
#include<QMessageBox>
#include<QDebug>
planegamewidget::planegamewidget(QWidget *parent) : QWidget(parent)
{
    myplane=new MyPlane(this);
    this->setFixedSize(500,700);
    myplane->init(width(),height());
    plane1=new QTimer(this);
    connect(plane1,&QTimer::timeout,[=](){
       static int id=0;
       Plane1 *temp=new Plane1(id++,this);
       temp->setlist(myplane->list);//将自己的飞机所发出的子弹的链表传给plane1，用于判断是否能被击中
       connect(myplane,SIGNAL(Move(int,int)),temp,SLOT(AcceptMyplane(int,int)));//当自己的飞机的move信号发送，plane1接受新的自己的飞机的坐标
       connect(temp,&Plane1::GameOver,this,&planegamewidget::Gameover);//如果plane1被撞毁则整个游戏结束
       emit myplane->Move(myplane->nowx,myplane->nowy);//每次计时器响应都判断自己的飞机的位置并发出信号
       temp->show();
    });
    plane1->start(500);
    plane2=new QTimer(this);
    connect(plane2,&QTimer::timeout,[=](){
       static int id=0;
       Plane2 *temp=new Plane2(this);
       temp->setlist(myplane->list);
       connect(myplane,SIGNAL(Move(int,int)),temp,SLOT(AcceptMyplane(int,int)));
       connect(temp,&Plane2::GameOver,this,&planegamewidget::Gameover);
       emit myplane->Move(myplane->nowx,myplane->nowy);
       temp->show();
    });
    plane2->start(2000);
    plane3=new QTimer(this);
    connect(plane3,&QTimer::timeout,[=](){
       static int id=0;
       Plane3 *temp=new Plane3(this);
       temp->setlist(myplane->list);
       connect(myplane,SIGNAL(Move(int,int)),temp,SLOT(AcceptMyplane(int,int)));
       connect(temp,&Plane3::GameOver,this,&planegamewidget::Gameover);
       emit myplane->Move(myplane->nowx,myplane->nowy);
       temp->show();
    });
    plane3->start(2000);
    controlplane=1;
}
void planegamewidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    painter.drawPixmap(rect(),QPixmap(":/img/bk1.png"));
}
void planegamewidget::keyPressEvent(QKeyEvent *ev){//这里只控制移动 让子弹自动生成
    if(controlplane==1){
        if(ev->key()==Qt::Key_Left){
            myplane->Goto(1);
        }
        else if(ev->key()==Qt::Key_Right){
            myplane->Goto(2);
        }
        else if(ev->key()==Qt::Key_Up){
            myplane->Goto(3);
        }
        else if(ev->key()==Qt::Key_Down){
            myplane->Goto(4);
        }
    }
}
void planegamewidget::Gameover(){
    if(controlplane==1){
    Plane1::Die();
    Plane2::Die();
    Plane3::Die();
    controlplane=0;
    myplane->gameover();
    plane1->stop();
    plane2->stop();
    plane3->stop();
    QMessageBox::about(this,"you are lose!","点击重回开始界面");
    this->close();
    start->show();
    }
}
void planegamewidget::init(){
    Plane1::die=0;
    Plane2::die=0;
    Plane3::die=0;
}
void planegamewidget::setstart(QWidget *start){
    this->start=start;
}
