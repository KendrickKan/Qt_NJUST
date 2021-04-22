#ifndef BLOCKCONTROL_H
#define BLOCKCONTROL_H

#include<QVector>
#include<QPoint>
class BlockControl
{
public:
    BlockControl();
    int x; //当前处于的x坐标
    int y; //当前处于的y坐标
    int type; //方块的类型
    int process;//方块类型变成了那种了
    int color; //颜色类型
    static QVector<QVector<int>> map; //map类  地图信息
    static QVector<QVector<QVector<QPoint>>> block; //留存砖块形状 配合control类生成方块
    static QVector<QVector<int>> colorMap;  //颜色地图
    void newBlock();//生成新的砖块
    bool indexCheck(int moveX,int moveY,int newProcess); //砖块发生移动的时候 检查下标
    void move(int type);  //点按上下左右移动或者翻转 包含了indexcheck
    void gc();//垃圾回收 即发生移动过后 清楚上一步的痕迹
    void rePaint();//重绘
    void clearRow();//消行
    void operator=(BlockControl&);
    void gameOver();
};

#endif // BLOCKCONTROL_H
