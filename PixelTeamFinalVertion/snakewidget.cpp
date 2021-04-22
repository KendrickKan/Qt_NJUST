#include "snakewidget.h"
#include"snake.h"
#include<QPainter>
#include<QDebug>
#include<QTimer>
#include<QMessageBox>

SnakeWidget::SnakeWidget(QWidget *parent)
    : QWidget(parent)
{
    snake1 = new Snake(5,0);
    Snake *temp1 = snake1;
    for(int i=0;i<=4;i++){
        Snake *temp= new Snake(4-i,0);
        temp1->next=temp;
        temp1=temp;
        snake1->tailx=temp->x;
        snake1->taily=temp->y;
    }
    food.setsnake(snake1);
    time=new QTimer(this);
    int ret=QMessageBox::question(this,"welcome to snake!","begin game?");
    if(ret==QMessageBox::Yes){
        time->start(500);
        connect(time,&QTimer::timeout,[=](){
            if(snake1->flag==1)
                snake1->Up();
            else if(snake1->flag==2)
                snake1->Down();
            else if(snake1->flag==3)
                snake1->Left();
            else if(snake1->flag==4)
                snake1->Right();
            update();
            if(snake1->EatItself()){
                time->stop();
                int ret=QMessageBox::question(this,"you are lose!","try again?");
                if(ret==QMessageBox::Yes){
                    Snake *temp=snake1;
                    while(temp!=nullptr)
                    {
                        temp=temp->next;
                        delete snake1;
                        snake1=temp;
                    }
                    snake1 = new Snake(5,0);
                    Snake *temp1 = snake1;
                    for(int i=0;i<=4;i++){
                        Snake *temp= new Snake(4-i,0);
                        temp1->next=temp;
                        temp1=temp;
                        snake1->tailx=temp->x;
                        snake1->taily=temp->y;
                    }
                    food.setsnake(snake1);
                    this->start();
                }
                else{
                    this->close();
                }
            }
            if(EatFood()){
                snake1->Addsnake();
                food.NewFood();
            }
        });
    }
}
void SnakeWidget::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);
    QPainter p(this);
    p.setViewport(0,0,width(),height());
    p.fillRect(0,0,width(),height(),Qt::black);
    p.setWindow(0,0,200,200);
   // p.setBrush(Qt::white);
    for(int i=0;i<20;i++){
        for(int j=0;j<20;j++){
            p.setBrush(Qt::white);
            p.drawRect(i*10,j*10,10,10);
            //p.drawrect(i,j,10,10);
        }
    p.setBrush(Qt::red);
    p.drawRect(food.x*10,food.y*10,10,10);
    p.setBrush(Qt::yellow);
    Snake *temp=snake1;
    while(temp!=nullptr){
        p.drawRect(temp->x*10,temp->y*10,10,10);
        temp=temp->next;
    }
    }
}
void SnakeWidget::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key()==Qt::Key_Up)
    {
        snake1->Up();
    }
    else if(ev->key()==Qt::Key_Down)
    {
        snake1->Down();
    }
    else if(ev->key()==Qt::Key_Left)
    {
        snake1->Left();
    }
    else if(ev->key()==Qt::Key_Right)
    {
        snake1->Right();
    }
    if(EatFood()){
        snake1->Addsnake();
        food.NewFood();
    }
    update();
    if(snake1->EatItself()){
        this->stop();
        int ret=QMessageBox::question(this,"you are lose!","try again?");
        if(ret==QMessageBox::Yes){
            Snake *temp=snake1;
            while(temp!=nullptr)
            {
                temp=temp->next;
                delete snake1;
                snake1=temp;
            }
            snake1 = new Snake(5,0);
            Snake *temp1 = snake1;
            for(int i=0;i<=4;i++){
                Snake *temp= new Snake(4-i,0);
                temp1->next=temp;
                temp1=temp;
                snake1->tailx=temp->x;
                snake1->taily=temp->y;
            }
            food.setsnake(snake1);
            this->start();
        }
        else{
            this->close();
        }
    }
    return QWidget::keyPressEvent(ev);
}
bool SnakeWidget::EatFood(){
    if(snake1->x == food.x && snake1->y == food.y)
        return true;
    else
        return false;
}
void SnakeWidget::start(){
    time->start(300);
}
void SnakeWidget::stop(){
    time->stop();
}
SnakeWidget::~SnakeWidget()
{

}
void SnakeWidget::closeEvent(QCloseEvent *event)
{
    emit this->Backtomainscene();
}
