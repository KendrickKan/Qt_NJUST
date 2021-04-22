#include "planemainwidget.h"
#include "planegamewidget.h"
#include<QPushButton>
#include<QPainter>
planemainwidget::planemainwidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *button=new QPushButton(this);
    button->setText("开始游戏");
    button->setStyleSheet("background:#C3C8C9;color:gray");
    resize(500,700);
    button->move(width()*0.40,height()*0.7);
    connect(button,&QPushButton::clicked,[=](){
        sonwidget=new planegamewidget();
        sonwidget->resize(500,700);
        sonwidget->init();
        sonwidget->setstart(this);
        sonwidget->show();
        this->hide();
    });

}
void planemainwidget::paintEvent(QPaintEvent *ev){
    QPainter paint(this);
    //paint.drawPixmap(0,0,500,700,QPixmap(":/img/bk1.png"));
    paint.drawPixmap(rect(),QPixmap(":/img/start.JPG"));
}
planemainwidget::~planemainwidget()
{

}
void planemainwidget::closeEvent(QCloseEvent *event)
{
    emit this->Backtomainscene();
}
