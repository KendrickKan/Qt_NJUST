#include"tetrismainwidget.h"
#include "tetrisgamewidget.h"
#include "ui_tetrismainwidget.h"  //???
#include<QKeyEvent>
#include<QTimer>
int TetrisMainWidget::running=false;
int TetrisMainWidget::score=0;
TetrisMainWidget::TetrisMainWidget(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TetrisMainWidget)
{
    ui->setupUi(this);
    this->resize(450,600);   //450*600的界面
    ui->next->hide();   //析构对象
    connect(ui->game,&TetrisGameWidget::GameOver,[=](){   //关闭GameWidget::GameOver槽函数
       ui->pushButton->setText("重新开始");
       ui->pushButton->setDisabled(false);        //按钮禁用关闭（开始游戏后又开始禁用）
       ui->label->setText(QString("最终得分为:%1").arg(score));  //下方lable显示信息
       score=0;                                   //内部时间重置
       TetrisGameWidget::gameOver=false;                //为游戏重新开始做准备，将游戏结束flag重新置错
       for(int i=0;i<10;i++){  //注意 这里的访问 严格按照x-y坐标系访问     清空游戏数据
           for(int j=0;j<20;j++){
           BlockControl::map[i][j]=0;
           BlockControl::colorMap[i][j]=0;
           }
       }
    });
    this->setWindowIcon(QIcon("://Tetris.ico"));   //设置界面图标
    this->setWindowTitle("Tetris");                 //设置界面标题
}

TetrisMainWidget::~TetrisMainWidget()
{
    delete ui;
}
void TetrisMainWidget:: keyPressEvent(QKeyEvent *e){      //图案点按移动
    if(running){
        if(e->key()==Qt::Key_Up||e->key()==Qt::Key_W){
            ui->game->con.move(1);
        }
        else if(e->key()==Qt::Key_Down||e->key()==Qt::Key_S){
            ui->game->con.move(2);
        }
        else if(e->key()==Qt::Key_Left||e->key()==Qt::Key_A){
            ui->game->con.move(3);
        }
        else if(e->key()==Qt::Key_Right||e->key()==Qt::Key_D){
            ui->game->con.move(4);
        }
        update();
        ui->label_2->setText(QString("当前分数:%1").arg(score));
    }
    if(e->key()==Qt::Key_Space){                     //点按空格暂停
        if(ui->game->timer){
            if(running){
                running=false;
                ui->game->timer->stop();
                update();
            }
            else{                                 //再次点按就重新开始ui->game->timer为基准
                running=true;
                ui->game->timer->start(1000);
            }
        }
    }
}

void TetrisMainWidget::on_pushButton_clicked()   //主界面私有的槽函数：点按qpushbutton按钮后在整个游戏过程中触发
{
    running=true;
    ui->game->timer = new QTimer(this);
    ui->game->timer->start(1000);  //1s触发的定时器
    update(); //更少的闪烁   从不会产生循环
    ui->game->con.newBlock();
    ui->game->anotherCon.newBlock();  //创建新的砖块
    ui->game->con.rePaint();
    connect(ui->game->timer,&QTimer::timeout,[=](){
        ui->game->con.move(2);      //2对应的是向下移动
        update();
    });
    ui->next->show();                          //展示整个界面
    ui->pushButton->setDisabled(true);           //只要程序在运行中就要将pushbutton改名+无效化
    ui->label->setText("游戏进行中");
}
void TetrisMainWidget::closeEvent(QCloseEvent *event){
    emit this->Backtomainscene();
}
