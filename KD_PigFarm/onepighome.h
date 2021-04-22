#ifndef ONEPIGHOME_H
#define ONEPIGHOME_H

#include <QWidget>
#include "kpig.h"
#include <QPushButton>

class onepighome : public QWidget
{
    Q_OBJECT
public:
    onepighome();
    int blackpignum;
    int whitepignum;
    int colorfulpignum;
    bool ifinfected;
    bool ifhaveblackpig;
    QPixmap kpighomepix;

    kpig* onepighomekpig[10];
    QPushButton * onepighomekpigpushbutton[10];

    kpig* BuyAPig(int x);

    void paintEvent(QPaintEvent *event);
    void sellallpihg(int x);//传进来的参数代表的是哪一个onepighome 便于存档
    int onepighomeblackpignum();
    int onepighomewhitepignum();
    int onepighomecolorfulpignum();
    void printPixLabel();
    void printDate();
    void printMoney();
    void printPig(int i,kpig * kpigtemp,QPixmap buttonpix);
    void onepigisinfected();//在一个猪圈里随机选择一头猪开始感染；
    void begininfectonepighome();//在同一个猪圈里以50%的概率感染每一头猪；
    bool ifallinfected();
    bool ifpartinfected();
    void refreshnoinfected();//刷新没有被感染 图标

signals:

    void Backtoallpigfarmscene();

public slots:
};

#endif // ONEPIGHOME_H
