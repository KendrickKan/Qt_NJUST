#include "searchbuylog.h"
#include "ui_searchbuylog.h"
#include <QFile>
#include "kglobal.h"


searchbuylog::searchbuylog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchbuylog)
{
    ui->setupUi(this);

    this->setWindowIcon(QIcon(":/Image/pigtouming.png"));
    this->setWindowTitle("Buy Log");


    connect(DateTimer,&QTimer::timeout,[=](){

        QFile kPigFarmBuyFile("kPigFarmBuyFile.txt");//参数就是读取文件的路径
        //设置打开方式
        kPigFarmBuyFile.open(QIODevice::ReadOnly);

        QByteArray kPigFarmBuyFilearray = kPigFarmBuyFile.readAll();

        ui->textEdit->setText(kPigFarmBuyFilearray);

        //对文件对象进行关闭
        kPigFarmBuyFile.close();

     });

}

searchbuylog::~searchbuylog()
{
    delete ui;
}
