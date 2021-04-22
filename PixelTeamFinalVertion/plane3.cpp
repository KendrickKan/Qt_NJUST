#include "plane3.h"
#include<QTimer>
#include<QTime>
#include<QLabel>
#include<QDebug>
#include<QPixmap>
#include<QMovie>
int Plane3::die=0;
Plane3::Plane3(QWidget *parent) : QLabel(parent)
{
    count=0;
    QTime t;
    t=QTime::currentTime();
    qsrand(t.msec()+t.second()*389);
    resize(110,170);
    this->setPixmap(QPixmap(":/img/bigplane.png"));
    timer=new QTimer(this);
    nowy2=0;
    nowx2=qrand()%450;
    this->move(nowx2,nowy2);
    connect(timer,&QTimer::timeout,[=](){
        if(pzjc(nowy2,nowy2+170,nowx2,nowx2+110,myplaney,myplaney+80,myplanex,myplanex+66)){
            //这里是检测游戏飞机是否碰撞 如果碰撞 停止所有计时器
            die=900;
            timer->stop();
            emit GameOver();
        }
        else{
            for(int i=0;i<list->length();i++){
                if(pzjc(nowy2,nowy2+170,nowx2,nowx2+110,list->at(i)->bullety,list->at(i)->bullety+13,list->at(i)->bulletx,list->at(i)->bulletx+13)){
                    list->at(i)->timer->stop();
                    delete list->at(i);
                    list->removeAt(i);
                    count++;
                    if(count==10){
                     this->timer->stop();
                    QMovie *movie = new QMovie(":/img/bigplaneboom.gif");
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
    timer->start(70);
}
void Plane3::AcceptMyplane(int x,int y){
    this->myplanex=x;
    this->myplaney=y;
}
bool Plane3::pzjc(int w1,int w2,int h1,int h2,int w3,int w4,int h3,int h4)
{
    if(w1>=w4 || w2<=w3 || h2<=h3 || h4<=h1){
        return false;
    }
    else{
        return true;
    }
}
void Plane3::setlist(QList<Bullet*> *list){
    this->list=list;
}
void Plane3::Die(){
    die=900;
}
