#include"blockcontrol.h"
//#include<QRandomGenerator>
#include<bits/stdc++.h>
#include"tetrisgamewidget.h"
#include<QTimer>
#include"tetrismainwidget.h"
QVector<QVector<QVector<QPoint>>> BlockControl::block=   //2*4*4的三维vector
{ //方块类型现在整理好了
  {
      {{0, 0}, {1, 0}, {1, 1}, {1, 2}},  // *
      {{2, 0}, {0, 1}, {1, 1}, {2, 1}},  // *
      {{1, 0}, {1, 1}, {1, 2}, {2, 2}},  // ** L类型方块
      {{0, 1}, {1, 1}, {2, 1}, {0, 2}}
  },//这个是L
  {
      {{1, 0}, {1, 1}, {1, 2}, {1, 3}}, // *
      {{0, 1}, {1, 1}, {2, 1}, {3, 1}}, // *
      {{1, 0}, {1, 1}, {1, 2}, {1, 3}}, // *
      {{0, 1}, {1, 1}, {2, 1}, {3, 1}}  // *  直方块
  },//这个是直线
  {
      {{1, 0}, {2, 0}, {1, 1}, {1, 2}}, //  *
      {{0, 1}, {1, 1}, {2, 1}, {2, 2}}, //  *
      {{1, 0}, {1, 1}, {0, 2}, {1, 2}}, // **  反L
      {{0, 0}, {0, 1}, {1, 1}, {2, 1}}
  },//这个是反L
  {
      {{0, 0}, {1, 0}, {2, 0}, {1, 1}},
      {{0, 0}, {0, 1}, {0, 2}, {1, 1}}, //  *
      {{0, 2}, {1, 2}, {2, 2}, {1, 1}},//  ***  就这个类似三角形的方块
      {{2, 0}, {2, 1}, {2, 2}, {1, 1}}
  },//这个是 土
  {
      {{0, 0}, {1, 0}, {0, 1}, {1, 1}},
      {{0, 0}, {1, 0}, {0, 1}, {1, 1}}, // **
      {{0, 0}, {1, 0}, {0, 1}, {1, 1}}, // **  正方形方块
      {{0, 0}, {1, 0}, {0, 1}, {1, 1}}
  },//这个是田
  {
      {{1, 1}, {2, 1}, {2, 0}, {1, 2}},
      {{1, 1}, {0, 1}, {1, 2}, {2, 2}},  //   *
      {{1, 1}, {2, 1}, {2, 0}, {1, 2}}, //   **
      {{1, 1}, {0, 1}, {1, 2}, {2, 2}}  //   *   旋转是Z的方块
  },//这个是Z
  {
      {{0, 0}, {0, 1}, {1, 1}, {1, 2}},//   *
      {{0, 1}, {1, 1}, {1, 0}, {2, 0}},//   **
      {{0, 0}, {0, 1}, {1, 1}, {1, 2}},//    * 旋转式反Z的方块
      {{0, 1}, {1, 1}, {1, 0}, {2, 0}}
  },//这个是反Z
};
QVector<QVector<int>> BlockControl::map;
QVector<QVector<int>> BlockControl::colorMap;
#include<QDebug>
BlockControl::BlockControl()
{
}
void BlockControl::newBlock(){
    srand( (unsigned)time( NULL ) );//随机数种子
        x=3;
        y=0;//默认都是在 这个地方进行生成砖块
        int j;
        while(1){
            j=rand()%7;
             if(j!=7)break;
        }
        type=j;     //0~6的随机数随机给定新方块的形状
        while(1){
             j=rand()%4;
             if(j!=4)break;
        }
        process=j;
//        type=QRandomGenerator::global()->bounded(0,7); //Qt5新随机数方法 返回[0,7)
//        process=QRandomGenerator::global()->bounded(0,4);
        qDebug()<<type<<process;
        while(1){
            j=rand()%8;
             if(j!=8)break;
        }
        color=j;                    //gamewidget中确定方块颜色共8种用rgb表示法确定
//        color=QRandomGenerator::global()->bounded(0,8);
}
bool BlockControl::indexCheck(int moveX,int moveY,int newProcess){
    // moveX 代表x坐标位移大小 moveY代表y坐标大小 newProcess代表用户想要进行砖块转换
    for(int i=0;i<4;i++){ //i<4 因为每种砖块都是由4个构成
        int tempx=this->x+block[this->type][newProcess][i].x()+moveX;
        int tempy=this->y+block[this->type][newProcess][i].y()+moveY;
        //条件说明 x超过边界 y超过边界 想要移动的地方已经具有砖块 都返回false 不允许当前移动操作
        if(tempx<0||tempx>9||tempy<0||tempy>19||map[tempx][tempy])  //这些位置非空都要返回false
            return false;
    }
    return true;
}
void BlockControl::move(int type){
    bool stopFlag=false; //标志是否停止
    gc();//移除刚才的痕迹 进行下一步绘制
    if(type==1){                     //1代表想上 即方块进行变化
        int newProcess=(this->process+1)%4;
        if(indexCheck(0,0,newProcess)){       //下标检查
            this->process=newProcess;
        }
    }
    else if(type==2){                //2代表向下移动  //这里比较特殊 这里需要判断方块是否落地
        stopFlag=indexCheck(0,1,this->process);  // 如果落地 新建状况 并且检测是否有行可以消除
        if(stopFlag){
            y++;
        }
        else{
            rePaint(); //回溯一次 下面的paint准备绘制新方块
            clearRow(); //有方块落地 检测是否可以消行
            *this=TetrisGameWidget::anotherCon; //不太记得默认拷贝好不好使了 我就自己重载了一个 可以的话 不需要这个的
        }
    }
    else if(type==3){ //3代表向左移动
        if(indexCheck(-1,0,this->process)){
            x--;
        }
    }
    else if(type==4){//4代表向右移动
        if(indexCheck(1,0,this->process)){
            x++;
        }
    }
    rePaint(); //如果说没有发生任何移动 重绘回来 起重画和回溯作用 也需要检测是否死亡  //移动/变换之后也要进行重绘
}
void BlockControl::gc(){ //垃圾回收 即发生移动过后 清除上一步的痕迹 方便下一次的移动
    for(int i=0;i<4;i++){
        map[this->x+block[this->type][this->process][i].x()][this->y+block[this->type][this->process][i].y()]=0;
    }
}
void BlockControl::rePaint(){
    for(int i=0;i<4;i++){
        int tempx=this->x+block[this->type][this->process][i].x();
        int tempy=this->y+block[this->type][this->process][i].y();
        if(map[tempx][tempy]){//新砖块刷新 可地图已经有了内容 即死亡
            TetrisGameWidget::timer->stop();   //计时器停止
            TetrisGameWidget::gameOver=true;  //gameover的flag为真
            TetrisMainWidget::running=false;  //running的flag为假
        }
        else{
            colorMap[tempx][tempy]=this->color;
            map[tempx][tempy]=1;
        }
    }
}
void BlockControl::clearRow(){           //消除行检测   ??
    int i,j;
    for(j=0;j<map[0].size();j++){ //因为是按x y格式进行标记的 所以删除方式比较特殊
        int flag1=true;
        for(i=0;i<map.size();i++){
            if(map[i][j]==0)
                flag1=false;
        }
        if(flag1){
            for(int k=0;k<map.size();k++){
                map[k].remove(j);
                map[k].insert(0,0); //插入到最前！！达到自动更新坐标
            }
            TetrisMainWidget::score+=100;   //完成一次消行加100分
        }
    }
}
void BlockControl::operator=(BlockControl &another){   //对control类之间进行运算符重载，判等
   this->x=another.x;
    this->y=another.y;
   this->type=another.type;
    this->process=another.process;
    this->color=another.color;
    another.newBlock();
}
