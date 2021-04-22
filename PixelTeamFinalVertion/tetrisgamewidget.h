#ifndef TETRISGAMEWIDGET_H
#define TETRISGAMEWIDGET_H

#include <QWidget>
#include "blockcontrol.h"
class TetrisGameWidget : public QWidget
{
    Q_OBJECT
public:
    //这个是游戏主窗口
    //这里主要绘制图像和捕捉按键事件 而具体的逻辑 交给control类实现
    explicit TetrisGameWidget(QWidget *parent = nullptr);
    static BlockControl con;
    static BlockControl anotherCon;
    static QTimer *timer;
    static QVector<QColor> color;
    static bool gameOver;
signals:
    void GameOver();
public slots:
protected:
    //virtual void keyPressEvent (QKeyEvent *);
    virtual void paintEvent (QPaintEvent *);//？？？？
};

#endif // TETRISGAMEWIDGET_H
