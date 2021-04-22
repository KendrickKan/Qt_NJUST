#include "kpig.h"
#include "kglobal.h"

void kpig::kpigup()
{
    connect(DateTimer,&QTimer::timeout,[=](){

        this->weight+=(rand()%12);
        this->day+=10;
    });
}


kpig::kpig(QWidget *parent) : QWidget(parent)
{

    this->day=0;
    this->pigtype=rand()%3;
    if(this->pigtype==0)
    {
        this->kpigpix.load(":/Image/blackpig.png");
        this->kpigpixstring=":/Image/blackpig.png";
    }
    else if(this->pigtype==1)
    {
        this->kpigpix.load(":/Image/whitepig.png");
        this->kpigpixstring=":/Image/whitepig.png";
    }
    else
    {
        this->kpigpix.load(":/Image/colorfulpig.png");
        this->kpigpixstring=":/Image/colorfulpig.png";
    }
    this->weight=rand()%30+20;

    this->kpigup();

    this->ifinfected=false;
}


kpig::kpig(int x)
{
    if(x==1)//只能买黑猪
    {
        this->day=0;
        this->pigtype=0;
        this->kpigpix.load(":/Image/blackpig.png");
        this->kpigpixstring=":/Image/blackpig.png";
        this->weight=rand()%30+20;

        this->kpigup();

        this->ifinfected=false;
    }
    else if(x==2)
    {
        this->day=0;
        this->pigtype=rand()%2+1;
        if(this->pigtype==1)
        {
            this->kpigpix.load(":/Image/whitepig.png");
            this->kpigpixstring=":/Image/whitepig.png";
        }
        else
        {
            this->kpigpix.load(":/Image/colorfulpig.png");
            this->kpigpixstring=":/Image/colorfulpig.png";
        }
        this->weight=rand()%30+20;

        this->kpigup();

        this->ifinfected=false;
    }

}

