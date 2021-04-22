#include "plane1.h"
#include<QTimer>
#include<QTime>
#include<QLabel>
#include<QDebug>
#include<QPixmap>
#include<QMovie>
int Plane1::die=0;
Plane1::Plane1(int id,QWidget *parent) : QLabel(parent)
{
    QTime t;
    t=QTime::currentTime();
    qsrand(t.msec()+t.second()*1000);
    resize(34,24);
    this->setPixmap(QPixmap(":/img/plane.png"));
    timer=new QTimer(this);
    nowy1=0;
    nowx1=qrand()%450;
    this->move(nowx1,nowy1);
    connect(timer,&QTimer::timeout,[=](){
        if(pzjc(nowy1,nowy1+24,nowx1,nowx1+34,myplaney,myplaney+80,myplanex,myplanex+66)){
            //这里是检测游戏飞机是否碰撞 如果碰撞 停止所有计时器
            die=900;
            timer->stop();
            emit GameOver();
        }
        else{
            for(int i=0;i<list->length();i++){
                if(pzjc(nowy1,nowy1+24,nowx1,nowx1+34,list->at(i)->bullety,list->at(i)->bullety+13,list->at(i)->bulletx,list->at(i)->bulletx+13)){
                    list->at(i)->timer->stop();
                    delete list->at(i);
                    list->removeAt(i);
                    this->timer->stop();
                    QMovie *movie = new QMovie(":/img/planeboom.gif");
                    this->setMovie(movie);
                    movie->start();
                    pictimer=new QTimer(this);
                    pictimer->start(200);
                    connect(pictimer,&QTimer::timeout,[=](){
                        this->hide();
                        pictimer->stop();
                    });
                }
            }
            this->move(nowx1,nowy1+=(6+die));
            if(nowy1>700){
                timer->stop();
                delete this;
            }
        }
        }
    );
    timer->start(40);
}
void Plane1::AcceptMyplane(int x,int y){//接受当前自己的飞机的坐标
    this->myplanex=x;
    this->myplaney=y;
}
bool Plane1::pzjc(int w1,int w2,int h1,int h2,int w3,int w4,int h3,int h4)
{
    if(w1>=w4 || w2<=w3 || h2<=h3 || h4<=h1){
        return false;
    }
    else{
        return true;
    }
}
void Plane1::setlist(QList<Bullet*> *list){
    this->list=list;
}
void Plane1::Die(){
    die=900;
}
