#ifndef PLANEGAMEWIDGET_H
#define PLANEGAMEWIDGET_H

#include <QWidget>
#include "myplane.h"
#include<QTimer>
class planegamewidget: public QWidget
{
    Q_OBJECT
public:
    explicit planegamewidget(QWidget *parent = nullptr);
    void setstart(QWidget *start);
    void init();
protected:
    void paintEvent(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *ev);
private:
    MyPlane * myplane;
    QTimer *plane1;
    QTimer *plane2;
    QTimer *plane3;
    QWidget * start;
    int controlplane;
signals:

public slots:
    void Gameover();
};


#endif // PLANEGAMEWIDGET_H
