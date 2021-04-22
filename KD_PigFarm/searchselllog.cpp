#include "searchselllog.h"
#include "ui_searchselllog.h"
#include <QFile>
#include "kglobal.h"

searchselllog::searchselllog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchselllog)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Image/pigtouming.png"));
    this->setWindowTitle("Sell Log");


    connect(DateTimer,&QTimer::timeout,[=](){

        QFile kPigFarmSellFile("kPigFarmSellFile.txt");//参数就是读取文件的路径
        //设置打开方式
        kPigFarmSellFile.open(QIODevice::ReadOnly);

        QByteArray kPigFarmSellFilearray = kPigFarmSellFile.readAll();

        ui->textEdit->setText(kPigFarmSellFilearray);

        //对文件对象进行关闭
        kPigFarmSellFile.close();

     });

}

searchselllog::~searchselllog()
{
    delete ui;
}
