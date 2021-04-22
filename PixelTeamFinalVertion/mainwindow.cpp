#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "snakewidget.h"
#include "planemainwidget.h"
#include "tetrismainwidget.h"
#include <QPainter>
#include <QWidget>
#include <QIcon>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/img/Tetris.ico"));
    ui->snakeBtn->setFont(QFont("Ink Free", 12 , 1 ) );
    connect( ui->snakeBtn , &QPushButton::clicked , [=](){
        SnakeWidget * snake = new SnakeWidget;
        connect(snake,&SnakeWidget::Backtomainscene,[=](){
            snake->hide();
            this->show();
        });
        this->hide();
        snake->show();
    });
    ui->planebutton->setFont(QFont("Ink Free", 12 , 1 ));
    connect(ui->planebutton,&QPushButton::clicked,[=](){
        planemainwidget * plane = new planemainwidget;
        connect(plane,&planemainwidget::Backtomainscene,[=](){
            plane->hide();
            this->show();
        });
        this->hide();
        plane->show();
    });
    ui->Tetris->setFont(QFont("Ink Free", 12 , 1 ));
    connect(ui->Tetris,&QPushButton::clicked,[=](){
        TetrisMainWidget * tetris = new TetrisMainWidget;
        connect(tetris,&TetrisMainWidget::Backtomainscene,[=](){
            tetris->hide();
            this->show();
        });
        this->hide();
        tetris->show();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    Q_UNUSED( e );
    QPainter qpainter(this);
    QPixmap qpix;
    qpix.load(":/img/background.png");                                                  //需要背景图路径
    qpainter.drawPixmap(0,0,this->width(),this->height(),qpix);
}
