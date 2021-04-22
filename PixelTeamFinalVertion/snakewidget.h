#ifndef SNAKEWIDGET_H
#define SNAKEWIDGET_H

#include"snake.h"
#include <QWidget>
#include"food.h"
#include <QCloseEvent>

class SnakeWidget : public QWidget
{
    Q_OBJECT

public:
    SnakeWidget(QWidget *parent = 0);
    ~SnakeWidget();
    void paintEvent(QPaintEvent *e);
    Food food;
    Snake * snake1;
    QTimer *time;
    void keyPressEvent(QKeyEvent *ev);
    bool EatFood();
    void start();
    void stop();
    void closeEvent(QCloseEvent *event);
signals:
    void Backtomainscene();
};

#endif //
