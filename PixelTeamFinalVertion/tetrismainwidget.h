#ifndef TETRISMAINWIDGET_H
#define TETRISMAINWIDGET_H

#include <QMainWindow>
#include <QCloseEvent>
namespace Ui {
class TetrisMainWidget;
}

class TetrisMainWidget : public QMainWindow
{
    Q_OBJECT

public:
    explicit TetrisMainWidget(QWidget *parent = nullptr);
    ~TetrisMainWidget();
    virtual void keyPressEvent (QKeyEvent *);
    static int running;
    static int score;
     void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_clicked();
signals:
    void Backtomainscene();

private:
    Ui::TetrisMainWidget *ui;
};
#endif // TETRISMAINWIDGET_H
