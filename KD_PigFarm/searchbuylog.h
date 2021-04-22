#ifndef SEARCHBUYLOG_H
#define SEARCHBUYLOG_H

#include <QWidget>

namespace Ui {
class searchbuylog;
}

class searchbuylog : public QWidget
{
    Q_OBJECT

public:
    explicit searchbuylog(QWidget *parent = 0);
    ~searchbuylog();

private:
    Ui::searchbuylog *ui;
};

#endif // SEARCHBUYLOG_H
