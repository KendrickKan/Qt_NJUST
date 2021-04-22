#ifndef FOOD_H
#define FOOD_H

//食物
#include"snake.h"

class Food
{
public:
    int x,y;
    Snake *realsnake; //蛇

    Food(int x=8,int y=12);
    void NewFood(); //生成下一个食物
    void setsnake(Snake *temp); //传入当前的蛇
};

#endif // FOOD_H
