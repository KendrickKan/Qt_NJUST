#include "plane2.h"
#include<QTimer>
#include<QTime>
#include<QLabel>
#include<QDebug>
#include<QPixmap>
#include<QMovie>
int Plane2::die=0;
Plane2::Plane2(QWidget *parent) : QLabel(parent)
{
    count=0;
    QTime t;
    t=QTime::currentTime();
    qsrand(t.msec()+t.second()*890);
    resize(46,60);
    this->setPixmap(QPixmap(":/img/midplane.png"));
    timer=new QTimer(this);
    nowy2=0;
    nowx2=qrand()%450;
    this->move(nowx2,nowy2);
    connect(timer,&QTimer::timeout,[=](){
        if(pzjc(nowy2,nowy2+60,nowx2,nowx2+46,myplaney,myplaney+80,myplanex,myplanex+66)){
            //这里是检测游戏飞机是否碰撞 如果碰撞 停止所有计时器
            die=900;
            timer->stop();
            emit GameOver();
        }
        else{
            for(int i=0;i<list->length();i++){
                if(pzjc(nowy2,nowy2+60,nowx2,nowx2+46,list->at(i)->bullety,list->at(i)->bullety+13,list->at(i)->bulletx,list->at(i)->bulletx+13)){
                    list->at(i)->timer->stop();
                    delete list->at(i);
                    list->removeAt(i);
                    count++;
                    if(count==5){
                    this->timer->stop();
                    QMovie *movie = new QMovie(":/img/midplaneboom.gif");
                    this->setMovie(movie);
                    movie->start();
                    pictimer=new QTimer(this);
                    pictimer->start(300);
                    connect(pictimer,&QTimer::timeout,[=](){
                        this->hide();
                        pictimer->stop();
                         });
                    }
                }
                    }
            this->move(nowx2,nowy2+=(6+die));
            if(nowy2>700){
                timer->stop();
                delete this;
            }
           }

    });
    timer->start(20);
}
void Plane2::AcceptMyplane(int x,int y){
    this->myplanex=x;
    this->myplaney=y;
}
bool Plane2::pzjc(int w1,int w2,int h1,int h2,int w3,int w4,int h3,int h4)
{
    if(w1>=w4 || w2<=w3 || h2<=h3 || h4<=h1){
        return false;
    }
    else{
        return true;
    }
}
void Plane2::setlist(QList<Bullet*> *list){
    this->list=list;
}
void Plane2::Die(){
    die=900;
}
