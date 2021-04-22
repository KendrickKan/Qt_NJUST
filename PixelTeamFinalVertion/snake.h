#ifndef SNAKE_H
#define SNAKE_H
#include<QKeyEvent>
#include<QLabel>
class Snake
{
public:
    int x,y;            //蛇身坐标
    int flag;           //四个运动方向 1上2下3左4右
    int tailx,taily;    //蛇尾坐标
    Snake *next;        //指针连接

    Snake(int x,int y);
    void Up();
    void Down();
    void Left();
    void Right();
    bool EatItself();   //判断是否咬到自己
    void Addsnake();    //尾部添加节点
    bool judge(int x,int y);
    void Update();
};

#endif // SNAKE_H
