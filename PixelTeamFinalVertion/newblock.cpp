#include "newblock.h"
#include<QPen>
#include<QPainter>
#include"tetrisgamewidget.h"
#include<QColor>
#include "tetrismainwidget.h"
NewBlock::NewBlock(QWidget *parent) : QWidget(parent)
{

}
//{0, 0}, {1, 0}, {0, 1}, {1, 1}
void NewBlock::paintEvent (QPaintEvent *e){
    //这个窗口 有大小
    Q_UNUSED(e);
    QPainter p(this);
    p.setViewport(this->rect());
    p.setWindow(0,0,80,80);
    QPen pen;
    pen.setWidth(0);
    pen.setColor("blue");
    p.setPen(pen);
    p.drawRect(10,10,60,60);
    TetrisGameWidget::anotherCon.block[TetrisGameWidget::anotherCon.type][TetrisGameWidget::anotherCon.process];
        for(int i=0;i<4;i++){
            int width=TetrisGameWidget::anotherCon.block[TetrisGameWidget::anotherCon.type][TetrisGameWidget::anotherCon.process][i].x();
            int height=TetrisGameWidget::anotherCon.block[TetrisGameWidget::anotherCon.type][TetrisGameWidget::anotherCon.process][i].y();
            p.fillRect(25+width*10,25+height*10,10,10,TetrisGameWidget::color[TetrisGameWidget::anotherCon.color]);
            pen.setWidth(0);
            pen.setColor("white");
            p.setPen(pen);
            p.drawRect(25+width*10,25+height*10,10,10);
        }
}
