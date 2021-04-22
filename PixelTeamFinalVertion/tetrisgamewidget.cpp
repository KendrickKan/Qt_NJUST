#include"tetrisgamewidget.h"
#include<QPainter>
#include<QPen>
#include<QKeyEvent>
#include<QTimer>
#include<tetrismainwidget.h>
BlockControl  TetrisGameWidget::con;
BlockControl  TetrisGameWidget::anotherCon;       //有命名为con，anothercon的control实例化对象
QTimer* TetrisGameWidget::timer;              //定时器 用于每隔1s触发一次游戏界面更新
bool TetrisGameWidget::gameOver=false;       //游戏终止触发flag
QVector<QColor> TetrisGameWidget::color={       //方块颜色
    QColor::fromRgb(85,170,255),QColor::fromRgb(255,125,33),
    QColor::fromRgb(33,178,74),QColor::fromRgb(189,121,82),
    QColor::fromRgb(140,0,16),QColor::fromRgb(57,73,206),
    QColor::fromRgb(255,203,8),QColor::fromRgb(181,231,24)
};
TetrisGameWidget::TetrisGameWidget(QWidget *parent) : QWidget(parent)
{
    this->resize(350,700);//设置推荐尺寸  因为使用了viewport 不用过于担心窗口问题
    for(int i=0;i<10;i++){  //注意 这里的访问 严格按照x-y坐标系访问    //对地图信息和颜色地图进行压栈
        BlockControl::map.push_back(QVector<int>(20,0));
    }
    for(int i=0;i<10;i++){  //注意 这里的访问 严格按照x-y坐标系访问
        BlockControl::colorMap.push_back(QVector<int>(20,0));
    }
    //con.rePaint();
}
void TetrisGameWidget::paintEvent (QPaintEvent *)
{
    QPainter p(this);
    p.setViewport(this->rect());
    p.setWindow(-1,-1,101,201);  //限制绘画范围
    QPen pen;
    pen.setWidth(0);
    pen.setColor("black");      //用黑线进行绘画
    p.setPen(pen);
    p.drawRect(-1,-1,100,200);
    for(int i=0;i<BlockControl::map.size();i++){ //根据1的标志 来绘画砖块
        for(int j=0;j<BlockControl::map[i].size();j++){
            if(BlockControl::map[i][j]){
                p.fillRect(i*10,j*10,9,9,color[BlockControl::colorMap[i][j]]);
            }
        }
    }
    pen.setWidth(0);
    pen.setColor("white");
    p.setPen(pen);
    //这里一定要先填充砖块 再划线 不然砖块画出来会非常难看
    //画线
    for(int i=1;i<20;i++){
        p.drawLine(0,i*10,99,i*10);
    }
    for(int i=1;i<10;i++){
        p.drawLine(i*10,1,i*10,198);
    }
    if(gameOver){                   //gameover的flag为真的时候paintevent直接无效化了
        delete timer;
        timer=nullptr;
        emit GameOver();
    }
}

//void GameWidget::keyPressEvent(QKeyEvent *e){
//    if(e->key()==Qt::Key_Up){
//        con.move(1);
//    }
//    else if(e->key()==Qt::Key_Down){
//        con.move(2);
//    }
//    else if(e->key()==Qt::Key_Left){
//        con.move(3);
//    }
//    else if(e->key()==Qt::Key_Right){
//        con.move(4);
//    }
//    update();
//}

