#ifndef KPIG_H
#define KPIG_H

#include <QWidget>

class kpig : public QWidget
{
    Q_OBJECT
public:
    explicit kpig(QWidget *parent = nullptr);
    kpig(int x);

    double weight;
    int day;
    int pigtype;// 0 black 1 white 2 colorful
    QString kpigpixstring;
    QPixmap kpigpix;
    bool ifinfected;//如果没被感染 那么就按照原本的颜色显示 如果被感染了 就显示红色的


    void kpigup();


signals:

public slots:
};

#endif // KPIG_H
