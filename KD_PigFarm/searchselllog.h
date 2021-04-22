#ifndef SEARCHSELLLOG_H
#define SEARCHSELLLOG_H

#include <QWidget>

namespace Ui {
class searchselllog;
}

class searchselllog : public QWidget
{
    Q_OBJECT

public:
    explicit searchselllog(QWidget *parent = 0);
    ~searchselllog();
    Ui::searchselllog *ui;
};

#endif // SEARCHSELLLOG_H
