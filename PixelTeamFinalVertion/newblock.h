#ifndef NEWBLOCK_H
#define NEWBLOCK_H

#include <QWidget>

class NewBlock : public QWidget
{
    Q_OBJECT
public:
    explicit NewBlock(QWidget *parent = nullptr);
    void paintEvent (QPaintEvent *e);
signals:

public slots:
};

#endif // NEWBLOCK_H
