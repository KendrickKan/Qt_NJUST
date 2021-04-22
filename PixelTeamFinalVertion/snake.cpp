#include "snake.h"
#include<QDebug>
Snake::Snake(int x,int y)
{
    this->x=x;
    this->y=y;
    tailx=x;
    taily=y;
    flag=4;
    next=nullptr;
}
void Snake::Up()
{
    if(flag==2)
        return;
    Update();
    this->y--;
    if(this->y<0)
        this->y+=20;
    flag=1;
}
void Snake::Down()
{
    if(flag==1)
        return;
    Update();
    this->y++;
    if(this->y>=20)
        this->y-=20;
    flag=2;
}
void Snake::Left()
{
    if(flag==4)
        return;
    Update();
    this->x--;
    if(this->x<0)
        this->x+=20;
    flag=3;
}
void Snake::Right()
{

    if(flag==3)
        return;
    Update();
    this->x++;
    if(this->x>=20)
        this->x-=20;
    flag=4;
}

void Snake::Update()
{
    Snake *temp1=this;
    while(temp1->next!=nullptr)
        temp1=temp1->next;
    this->tailx=temp1->x;
    this->taily=temp1->y;
    temp1=this->next;
    int tempx,tempy;
    while(temp1!=nullptr){
        if(temp1==this->next){
            tempx=temp1->x;
            tempy=temp1->y;
            temp1->x=this->x;
            temp1->y=this->y;
        }
        else{
            int k,b;
            k=tempx,b=tempy;
            tempx=temp1->x;
            tempy=temp1->y;
            temp1->x=k;
            temp1->y=b;
        }
        temp1=temp1->next;
    }
    //继续走 现在的任务就是每个下一个节点 接上上一个节点

}
bool Snake::EatItself()
{
    Snake *temp=this->next;
    while(temp!=nullptr)
    {
        if(this->x==temp->x && this->y==temp->y)
            return true;
        temp=temp->next;
    }
    return false;
}
void Snake::Addsnake(){
    Snake *temp=this;
    while(temp->next!=nullptr)
        temp=temp->next;
    temp->next=new Snake(this->tailx,this->taily);
}
