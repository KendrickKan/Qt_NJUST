#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>

namespace Ui {
class MainScene;
}

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainScene(QWidget *parent = 0);
    ~MainScene();

    void paintEvent(QPaintEvent *event);


private:
    Ui::MainScene *ui;
};

#endif // MAINSCENE_H
