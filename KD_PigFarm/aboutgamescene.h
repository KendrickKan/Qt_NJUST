#ifndef ABOUTGAMESCENE_H
#define ABOUTGAMESCENE_H

#include <QWidget>

class aboutgamescene : public QWidget
{
    Q_OBJECT
public:
    explicit aboutgamescene(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *event);

signals:


public slots:
};

#endif // ABOUTGAMESCENE_H
