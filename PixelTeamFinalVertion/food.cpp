#include "food.h"
#include<QTime>
#include <QtGlobal>
Food::Food(int x,int y)
{
    this->x=x;
    this->y=y;
}
void Food::setsnake(Snake *temp)    //传入当前蛇身位置
{
    this->realsnake=temp;
}

void Food::NewFood()
{
    bool flag=1;
    while(flag){
        qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
        this->x=rand()%20;  //生成一个0和19之间的整数
        this->y=rand()%20;  //生成一个0和19之间的整数
        Snake *temp=realsnake;  //传入当前蛇各部分所在位置，通过下面的循环遍历
        while(temp!=nullptr){
            if(temp->x==this->x && temp->y ==this->y){  //若新生成的食物在蛇的“身体”上，退出重新生成
                flag=1;
                break;
            }
            else
                flag=0;
            temp=temp->next;
        }
    }
}
