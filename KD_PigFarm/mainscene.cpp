#include "mainscene.h"
#include "ui_mainscene.h"
#include "kglobal.h"
#include "kpig.h"
#include <QPainter>
#include <QDesktopWidget>
#include <QPushButton>
#include <QLabel>
#include "allpigfarmscene.h"
#include <QMovie>
#include "aboutgamescene.h"
#include <QDebug>
#include <QFile>

MainScene::MainScene(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainScene)
{
    ui->setupUi(this);

    setFixedSize(600,950);//设置固定大小

    QDesktopWidget *desktop = QApplication::desktop();
    this->move((desktop->width()-this->width())/2,(desktop->height()-this->height())/2-40);//将窗口移至屏幕中间

    this->setWindowIcon(QIcon(":/Image/pigtouming.png"));//设置图标

    this->setWindowTitle("KD's PigFarm");//设置窗口名

    QPushButton * newgame = new QPushButton;//设置主页三个按钮
    QPushButton * openoldgame = new QPushButton;
    QPushButton * aboutgame = new QPushButton;
    newgame->setParent(this);
    openoldgame->setParent(this);
    aboutgame->setParent(this);

    newgame->setText("开始新游戏");
    newgame->setFixedSize(150,80);
    newgame->setStyleSheet("QPushButton{"
                                        "border:3px solid black;"
                                        "border-radius:5px;"
                                        "font-family:'华文新魏';"
                                        "font-size:28px"
                                        "}");
    newgame->move(50,550);

    openoldgame->setText("打开存档");
    openoldgame->setFixedSize(150,80);
    openoldgame->setStyleSheet("QPushButton{"
                                        "border:3px solid black;"
                                        "border-radius:5px;"
                                        "font-family:'华文新魏';"
                                        "font-size:28px"
                                        "}");
    openoldgame->move(225,550);


    aboutgame->setText("关于游戏");
    aboutgame->setFixedSize(150,80);
    aboutgame->setStyleSheet("QPushButton{"
                                        "border:3px solid black;"
                                        "border-radius:5px;"
                                        "font-family:'华文新魏';"
                                        "font-size:28px"
                                        "}");
    aboutgame->move(400,550);

    QLabel * klabel = new QLabel;
    klabel->setParent(this);
    QFont kfont_about_klabel;
    kfont_about_klabel.setFamily("Brush Script MT");//设置字体
    kfont_about_klabel.setPointSize(39);
    klabel->setFont(kfont_about_klabel);
    klabel->setText("Welcome to KD's PigFarm");//设置"Welcome to KD's PigFarm"标题
    klabel->move(10,-150);

//    bool neworopenfile=false ;//判断是新建还是打开原有的

//    allpigfarmscene * kallpigfarmscene1 = new allpigfarmscene(true);
//    allpigfarmscene * kallpigfarmscene2 = new allpigfarmscene(false);


    allpigfarmscene * kallpigfarmscene = new allpigfarmscene();
    connect(kallpigfarmscene,&allpigfarmscene::Backtomainscene,[=](){

        kallpigfarmscene->hide(); //将选择关卡场景 隐藏掉
        this->show(); //重新显示主场景

    });

    connect(newgame,&QPushButton::clicked,[=](){


        //清空出售记录
        QFile kPigFarmSellFile("kPigFarmSellFile.txt");

        QTextStream out(&kPigFarmSellFile);

        kPigFarmSellFile.open(QIODevice::WriteOnly | QIODevice::Text  );
        //kPigFarmSellFile.write();
            out<<"";
        kPigFarmSellFile.close();

        //清空购买记录
        QFile kPigFarmBuyFile("kPigFarmBuyFile.txt");

        QTextStream out2(&kPigFarmBuyFile);

        kPigFarmBuyFile.open(QIODevice::WriteOnly | QIODevice::Text  );
        //kPigFarmSellFile.write();
            out2<<"";
        kPigFarmBuyFile.close();



        for(int i=0;i<100;i++)
        {
            //for(int j=0;j<10;j++)
           // {
                onepighome * temp= new onepighome ;
                kallpigfarmscene->kpighome[i]=temp;
            //}
        }
        //kallpigfarmscene->clearpighouse();

        DateTime = 0;
        AllMoney = 0;
        DateTimer->start(1000);//日期计时器

        //allpigfarmscene * kallpigfarmscene = new allpigfarmscene();
        kallpigfarmscene->setGeometry(this->geometry());

        kallpigfarmscene->show();

       // qDebug()<<neworopenfile;
        qDebug()<<"choose new";

        this->hide();

//        connect(kallpigfarmscene,&allpigfarmscene::Backtomainscene,[=](){

//            kallpigfarmscene->hide(); //将选择关卡场景 隐藏掉
//            this->show(); //重新显示主场景

//        });//点击back 返回主场景

    });

    connect(openoldgame,&QPushButton::clicked,[=](){



        QFile kPigFarmFile("kPigFarmFile.txt");

        kPigFarmFile.open(QIODevice::ReadOnly | QIODevice::Text);

        QTextStream in(&kPigFarmFile);
        int templine=1;
        int templine2;
        int templine3;
        int tempkpighome=0;
        int temponepighomekpig;

        while( !in.atEnd()) //未到文件尾
        {
            QString line = in.readLine();
            if(templine==1)
                DateTime=line.toInt();
            else if(templine==2)
                AllMoney=line.toLongLong();
            else
            {
                templine2=templine-2;
                if(templine2%51==1)
                {
                    templine3=0;
                    tempkpighome=line.toInt();
                }
                else
                {
                    if(templine3%5==1)
                    {
                        temponepighomekpig=line.toInt();
                    }
                    else
                    {
                        if(templine3%5==2)
                            kallpigfarmscene->kpighome[tempkpighome]->onepighomekpig[temponepighomekpig]->weight=line.toDouble();
                        if(templine3%5==3)
                            kallpigfarmscene->kpighome[tempkpighome]->onepighomekpig[temponepighomekpig]->day=line.toInt();
                        if(templine3%5==4)
                            kallpigfarmscene->kpighome[tempkpighome]->onepighomekpig[temponepighomekpig]->pigtype=line.toInt();
                        if(templine3%5==0)
                            kallpigfarmscene->kpighome[tempkpighome]->onepighomekpig[temponepighomekpig]->ifinfected=line.toInt();
                    }
                }
            }
            templine++;
            templine3++;
        //    qDebug() << line.toInt();
        }
        kPigFarmFile.close();
        DateTimer->start(1000);

        for(int i=0;i<100;i++)
        {
            if(kallpigfarmscene->kpighome[i]->onepighomekpig[0]->pigtype==0)
                kallpigfarmscene->kpighome[i]->ifhaveblackpig=true;
            else
                kallpigfarmscene->kpighome[i]->ifhaveblackpig=false;
        }

        // qDebug()<<neworopenfile;
        qDebug()<<"choose open";

        kallpigfarmscene->setGeometry(this->geometry());
        kallpigfarmscene->show();
        this->hide();

//        connect(kallpigfarmscene,&allpigfarmscene::Backtomainscene,[=](){

//            kallpigfarmscene->hide(); //将选择关卡场景 隐藏掉
//            this->show(); //重新显示主场景

//        });//点击back 返回主场景


    });

    aboutgamescene * kaboutgamescene = new aboutgamescene;

    connect(aboutgame,&QPushButton::clicked,[=](){

        kaboutgamescene->show();


    });

}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter kpainter(this);
    QPixmap kpix;
    kpix.load(":/Image/timg.jpg");
    kpainter.drawPixmap(0,0,this->width(),this->height(),kpix);
    kpix.load(":/Image/tiantianyangzhutiantiankaixin.png");
    kpix = kpix.scaled(this->width(),kpix.height()*1.4);//图片缩放
    kpainter.drawPixmap(0,this->height()-kpix.height(),kpix.width(),kpix.height(),kpix);

}


MainScene::~MainScene()
{
    delete ui;
}
