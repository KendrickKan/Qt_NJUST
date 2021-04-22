#ifndef ALLPIGFARMSCENE_H
#define ALLPIGFARMSCENE_H

#include <QMainWindow>
#include <QPushButton>
#include "onepighome.h"
#include "searchselllog.h"
#include "searchbuylog.h"

class allpigfarmscene : public QMainWindow
{
    Q_OBJECT
public:
    allpigfarmscene();

    void paintEvent(QPaintEvent *event);

    onepighome* kpighome [100];//初始化100个猪圈
    searchselllog * ksearchselllog;
    searchbuylog * ksearchbuylog;

    bool ifallpighomeinfected();
    bool ifinfected;
    void onpighomeinfectneiboronepighome(int num);//相邻猪圈比会被传染
    void bianlionepighomeinfect();
    void clearpighouse();
    bool ifinfectedfunction();


signals:

    void Backtomainscene();

public slots:
};

#endif // ALLPIGFARMSCENE_H
