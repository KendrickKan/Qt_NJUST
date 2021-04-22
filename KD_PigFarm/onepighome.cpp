#include "onepighome.h"
#include "kglobal.h"
#include <QPainter>
#include <QIcon>
#include <QPushButton>
#include <QLabel>
#include <QTimer>
#include <QDebug>
#include <QFile>
onepighome::onepighome()
{
    this->kpighomepix.load(":/Image/pighome.png");

    this->ifinfected=false;//初始化猪圈没有感染的猪
    blackpignum=whitepignum=colorfulpignum=0;

    setFixedSize(600,950);//设置固定大小

    setWindowIcon(QIcon(":/Image/pigtouming.png"));//设置图标

    setWindowTitle("KD's PigFarm");//设置窗口名


    //返回按钮
    QPushButton * backBtn = new QPushButton;
    backBtn->setStyleSheet("QPushButton{border:0px;}");
    QPixmap backpix;
    backpix.load(":/Image/BackButton.png");
    backBtn->setIcon(backpix);
    backBtn->setIconSize(QSize(backpix.width(),backpix.height()));
    backBtn->setFixedSize(backpix.width(),backpix.height());
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width() , this->height() - backBtn->height());

    //点击返回
    connect(backBtn,&QPushButton::clicked,[=](){
        //告诉主场景 我返回了，主场景监听返回按钮
        emit this->Backtoallpigfarmscene();

    });







    QPushButton * pausebutton = new QPushButton;//////////暂停按钮
    pausebutton->setStyleSheet("QPushButton{border:0px;}");
    QPixmap pausepix;
    pausepix.load(":/Image/PauseButton.JPG");
    pausebutton->setIcon(pausepix);
    pausebutton->setIconSize(QSize(backpix.width(),backpix.height()));
    pausebutton->setFixedSize(backpix.width(),backpix.height());
    pausebutton->setParent(this);
    pausebutton->move(this->width() - pausebutton->width()-80 , this->height() - pausebutton->height());

    connect(pausebutton,&QPushButton::clicked,[=](){

        DateTimer->stop();

    });

    QPushButton * beginbutton = new QPushButton;///////////开始按钮
    beginbutton->setStyleSheet("QPushButton{border:0px;}");
    QPixmap beginpix;
    beginpix.load(":/Image/beginbutton.JPG");
    beginbutton->setIcon(beginpix);
    beginbutton->setIconSize(QSize(backpix.width(),backpix.height()));
    beginbutton->setFixedSize(backpix.width(),backpix.height());
    beginbutton->setParent(this);
    beginbutton->move(this->width() - beginbutton->width()-160 , this->height() - beginbutton->height());

    connect(beginbutton,&QPushButton::clicked,[=](){

        DateTimer->start(1000);

    });



    printDate();
    printMoney();
    QPixmap tempsizepix;
    tempsizepix.load(":/Image/blackpig.png");


    for(int i=0;i<10;i++)
    {
        if(i==0)
        {
            onepighomekpig[i]=onepighome::BuyAPig(0);//买猪
            if(onepighomekpig[i]->pigtype==0)
                ifhaveblackpig=true;
            else
                ifhaveblackpig=false;
        }
        else
        {
            if(onepighomekpig[0]->pigtype==0)
            {
                onepighomekpig[i]=onepighome::BuyAPig(1);
            }
            else
            {
                onepighomekpig[i]=onepighome::BuyAPig(2);
            }
        }
        if(onepighomekpig[i]->pigtype==0)
            blackpignum++;
        else if(onepighomekpig[i]->pigtype==1)
            whitepignum++;
        else if(onepighomekpig[i]->pigtype==2)
            colorfulpignum++;


        QPixmap kpigbuttonpix=onepighomekpig[i]->kpigpix;
        onepighomekpigpushbutton[i]=new QPushButton;
        onepighomekpigpushbutton[i]->setFixedSize( kpigbuttonpix.width()/8,kpigbuttonpix.height()/8);
//        qDebug()<<kpigbuttonpix.width()/8<<" "<<kpigbuttonpix.height()/8;
        onepighomekpigpushbutton[i]->setStyleSheet("QPushButton{border:0px;}");
        onepighomekpigpushbutton[i]->setIcon(kpigbuttonpix);
        onepighomekpigpushbutton[i]->setParent(this);
        onepighomekpigpushbutton[i]->setIconSize(QSize(kpigbuttonpix.width()/8,kpigbuttonpix.height()/8));
        onepighomekpigpushbutton[i]->move(i % 5 * 110 + 49,i / 5 * 160 + 400);

        connect(onepighomekpigpushbutton[i],&QPushButton::clicked,[=](){
            qDebug()<<i;
        });


        QLabel * onepighomePixLabel = new QLabel;//猪pix Label
        onepighomePixLabel->setParent(this);
        onepighomePixLabel->setFixedSize(62,63);
        onepighomePixLabel->move(i % 5 * 110 + 49,i / 5 * 160 + 400);
        onepighomePixLabel->setPixmap(onepighomekpig[i]->kpigpix);
        onepighomePixLabel->setScaledContents(true);
        //设置让鼠标进行穿透   51号属性
        onepighomePixLabel->setAttribute(Qt::WA_TransparentForMouseEvents);
        connect(DateTimer,&QTimer::timeout,[=](){

            onepighomePixLabel->setPixmap(onepighomekpig[i]->kpigpix);
        });


        //////////////////////////显示猪的编号
        QFont kfont_about_onepighomeonepiglabel;//每个图标下面设置编号
        kfont_about_onepighomeonepiglabel.setFamily("Brush Script MT");//设置字体
        kfont_about_onepighomeonepiglabel.setPointSize(17);
        QLabel * onepighomeonepiglabel = new QLabel;
        onepighomeonepiglabel->setParent(this);
        //onepighomeonepiglabel->setFixedSize(kpigbuttonpix.width()/8,kpigbuttonpix.height()/8);
        onepighomeonepiglabel->setFont(kfont_about_onepighomeonepiglabel);
        onepighomeonepiglabel->setText(QString::number(i));
        onepighomeonepiglabel->move(i % 5 * 110 + 70,i / 5 * 160 + 455);

        //////////////////////////显示猪的种类
        QFont kfont_about_onepighomeonepigTypeandWeightandDay;//每个图标下面设置类型
        kfont_about_onepighomeonepigTypeandWeightandDay.setFamily("华文新魏");//设置字体
        kfont_about_onepighomeonepigTypeandWeightandDay.setPointSize(12);
        QLabel* onepighomeonepigtype = new QLabel;
        onepighomeonepigtype->setParent(this);
        onepighomeonepigtype->setFixedSize(tempsizepix.width()/5,tempsizepix.height()/5);
        onepighomeonepigtype->move(i % 5 * 110 + 45,i / 5 * 160 + 440);
        onepighomeonepigtype->setFont(kfont_about_onepighomeonepigTypeandWeightandDay);
//        //QString  ktemptype;
        connect(DateTimer,&QTimer::timeout,[=](){
            QString  ktemptype;
            if(onepighomekpig[i]->pigtype==0)
            {
                ktemptype="_Black_";
            }
            else if(onepighomekpig[i]->pigtype==1)
            {
                ktemptype="_White_";
            }
            else if(onepighomekpig[i]->pigtype==2)
            {
                ktemptype="Colorful";
            }
             onepighomeonepigtype->setText(ktemptype);
        });
//        //onepighomeonepigtype->setText(ktemptype);

        ///////////////////////////显示猪的体重
        QLabel* onepighomeonepigweight= new QLabel;
        onepighomeonepigweight->setParent(this);
        onepighomeonepigweight->setFixedSize(tempsizepix.width()/5,tempsizepix.height()/5);
        onepighomeonepigweight->move(i % 5 * 110 + 60,i / 5 * 160 + 460);
        onepighomeonepigweight->setFont(kfont_about_onepighomeonepigTypeandWeightandDay);
        connect(DateTimer,&QTimer::timeout,[=](){
             onepighomeonepigweight->setText(QString("%1kg").arg(onepighomekpig[i]->weight));
        });

        //////////////////////////显示猪被饲养的天数
        QLabel* onepighomeonepigday= new QLabel;
        onepighomeonepigday->setParent(this);
        onepighomeonepigday->setFixedSize(tempsizepix.width()/5,tempsizepix.height()/5);
        onepighomeonepigday->move(i % 5 * 110 + 55,i / 5 * 160 + 480);
        onepighomeonepigday->setFont(kfont_about_onepighomeonepigTypeandWeightandDay);
        connect(DateTimer,&QTimer::timeout,[=](){
             onepighomeonepigday->setText(QString("%1day").arg(onepighomekpig[i]->day));
        });


        /////////////////////////显示猪是否被感染
        QLabel* onepighomeifinfected= new QLabel;
        onepighomeifinfected->setParent(this);
        onepighomeifinfected->setFixedSize(tempsizepix.width()/5,tempsizepix.height()/5);
        onepighomeifinfected->move(i % 5 * 110 + 55,i / 5 * 160 + 500);
        onepighomeifinfected->setFont(kfont_about_onepighomeonepigTypeandWeightandDay);
        connect(DateTimer,&QTimer::timeout,[=](){
            if(onepighomekpig[i]->ifinfected==false)
                onepighomeifinfected->setText(QString("NO"));
            else if(onepighomekpig[i]->ifinfected==true)
                onepighomeifinfected->setText(QString("INFECTED"));
        });




//        connect(DateTimer,&QTimer::timeout,[=](){
//            if(DateTime%90==0)//每九十天卖一批猪
//            {
//                sellallpihg();
//            }
//        });


    }


    QPushButton * infectbutton = new QPushButton;//////////感染按钮
    infectbutton->setStyleSheet("QPushButton{border:0px;}");
    QPixmap infectpix;
    infectpix.load(":/Image/infectbutton.JPG");
    infectbutton->setIcon(infectpix);
    infectbutton->setIconSize(QSize(backpix.width(),backpix.height()));
    infectbutton->setFixedSize(backpix.width(),backpix.height());
    infectbutton->setParent(this);
    infectbutton->move(this->width() - infectbutton->width()-240 , this->height() - infectbutton->height());

    ///下面执行如果这个猪圈有猪被感染每十天感染同一个猪圈里的猪
    connect(DateTimer,&QTimer::timeout,[=](){
        if(this->ifinfected==true)
            this->begininfectonepighome();
    });
    connect(infectbutton,&QPushButton::clicked,[=](){

        begininfectday=DateTime;
//        qDebug()<<begininfectday;
        this->onepigisinfected();

    });




}
kpig* onepighome::BuyAPig(int x)
{
    if(x==0)
    {
        kpig * newkpig=new kpig;
        return newkpig;
    }
    else
    {
        kpig * newkpig=new kpig(x);
        return newkpig;
    }
}

void onepighome::sellallpihg(int x)
{
    for(int i=0;i<10;i++)
    {
        if(((onepighomekpig[i]->weight>75)||(onepighomekpig[i]->day>365))&&onepighomekpig[i]->ifinfected==false)//这个猪圈没有被感染然后就可以卖猪
        {
            int tempmoney;
            if(onepighomekpig[i]->pigtype==0)
                tempmoney=onepighomekpig[i]->weight*blackmoney;
            else if(onepighomekpig[i]->pigtype==1)
                tempmoney=onepighomekpig[i]->weight*whitemoney;
            else if(onepighomekpig[i]->pigtype==2)
                tempmoney=onepighomekpig[i]->weight*colorfulmoney;

            AllMoney+=tempmoney;

            QFile kPigFarmSellFile("kPigFarmSellFile.txt");

            QTextStream out(&kPigFarmSellFile);

            kPigFarmSellFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
                out<<"The "<<x<<"th pighome! "<<"The "<<i<<"th pig! ";
                out<<"Weight: "<<onepighomekpig[i]->weight<<"  Day: "<<onepighomekpig[i]->day<<"  Type: ";
                if(onepighomekpig[i]->pigtype==0)
                    out<<"Black";
                else if(onepighomekpig[i]->pigtype==1)
                    out<<"White";
                else
                    out<<"Colorful";
                out<<" Value: "<<tempmoney<<endl;
            kPigFarmSellFile.close();



            delete onepighomekpig[i];
            //先卖再买  上面是卖  下面是买
            if(this->ifhaveblackpig==true)
                onepighomekpig[i]=BuyAPig(1);
            else
                onepighomekpig[i]=BuyAPig(2);
            if(onepighomekpig[i]->pigtype==0)
                AllMoney-=blackmoney*20;
            else if(onepighomekpig[i]->pigtype==1)
                AllMoney-=whitemoney*20;
            else if(onepighomekpig[i]->pigtype==2)
                AllMoney-=colorfulmoney*20;

            QFile kPigFarmBuyFile("kPigFarmBuyFile.txt");

            QTextStream out2(&kPigFarmBuyFile);

            kPigFarmBuyFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append);
                out2<<"The "<<x<<"th pighome! On Day: "<<DateTime<<"Buy The "<<i<<"th pig! ";
                out2<<"Weight: "<<onepighomekpig[i]->weight<<"  Type: ";
                if(onepighomekpig[i]->pigtype==0)
                    out2<<"Black";
                else if(onepighomekpig[i]->pigtype==1)
                    out2<<"White";
                else
                    out2<<"Colorful";
                out2<<endl;
            kPigFarmBuyFile.close();

        }
    }
}

int onepighome::onepighomeblackpignum()
{
    return blackpignum;
}
int onepighome::onepighomewhitepignum()
{
    return whitepignum;
}
int onepighome::onepighomecolorfulpignum()
{
    return colorfulpignum;
}



void onepighome::printDate()
{
    QLabel * onepighomeDateLabel = new QLabel;//日期label
    onepighomeDateLabel->setParent(this);
    QFont kfont_about_onepighomeDateLabel;
    kfont_about_onepighomeDateLabel.setFamily("Brush Script MT");//设置字体
    kfont_about_onepighomeDateLabel.setPointSize(30);
    onepighomeDateLabel->setFixedSize(200,100);
    onepighomeDateLabel->setFont(kfont_about_onepighomeDateLabel);
    onepighomeDateLabel->move(0,-10);
    connect(DateTimer,&QTimer::timeout,[=](){
        //qDebug()<<DateTime<<endl;
        onepighomeDateLabel->setText(QString("Day %1").arg(DateTime));
    });

}

void onepighome::printMoney()
{
    QFont kfont_about_onepighomeMoneyLabel;
    kfont_about_onepighomeMoneyLabel.setFamily("Brush Script MT");//设置字体
    kfont_about_onepighomeMoneyLabel.setPointSize(30);
    QLabel * onepighomeAllMoneyLabel = new QLabel;//Money label
    onepighomeAllMoneyLabel->setParent(this);
    onepighomeAllMoneyLabel->setFixedWidth(500);
    onepighomeAllMoneyLabel->setFont(kfont_about_onepighomeMoneyLabel);
    onepighomeAllMoneyLabel->move(0,50);
    connect(DateTimer,&QTimer::timeout,[=](){
        onepighomeAllMoneyLabel->setText(QString("Money:%1").arg(AllMoney));//每秒增加10天
    });
}


void onepighome::onepigisinfected()
{
    int num=rand()%10;
    onepighomekpig[num]->ifinfected=true;
    onepighomekpig[num]->kpigpix.load(":/Image/infectedpig.png");
    this->ifinfected=true;
}

void onepighome::begininfectonepighome()
{
    for(int i=0;i<10;i++)
    {
        if(onepighomekpig[i]->ifinfected==false)
        {
            int judgenum=rand()%2;
            if(judgenum)
            {
                onepighomekpig[i]->kpigpix.load(":/Image/infectedpig.png");
                onepighomekpig[i]->ifinfected=true;
            }
        }
    }
}


bool onepighome::ifallinfected()
{
    for(int i=0;i<10;i++)
    {
        if(onepighomekpig[i]->ifinfected==false)
            return false;
    }
    this->kpighomepix.load(":/Image/allinfected.png");//设置全感染图片
    return true;

}


bool onepighome::ifpartinfected()
{
    if(this->ifinfected==true&&this->ifallinfected()==false)
    {
        this->kpighomepix.load(":/Image/partinfected.png");
        return true;
    }
    {
        return false;
    }
}

void onepighome::refreshnoinfected()
{
    if(this->ifinfected==false)
    {
        this->kpighomepix.load(":/Image/pighome.png");
    }
}





void onepighome::paintEvent(QPaintEvent *event)
{
    QPainter kpainter(this);
    QPixmap kpix;
    kpix.load(":/Image/muchangbackgaound.jpg");
    kpainter.drawPixmap(0,0,this->width(),this->height(),kpix);
}
