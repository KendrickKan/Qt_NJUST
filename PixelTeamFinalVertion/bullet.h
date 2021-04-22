#ifndef BULLET_H
#define BULLET_H

#include <QWidget>
#include<QLabel>
#include<QTimer>
class Bullet : public QLabel
{
    Q_OBJECT
public:
    explicit Bullet(int x,int y,QWidget *parent = nullptr);
    int id;
    int bulletx;
    int bullety;
    QTimer *timer;
    QList<Bullet*> *list;
    void setlist(QList<Bullet*> *);

signals:
    void shouldDelete(int id);
public slots:
};

#endif // BULLET_H
