/********************************************************************************
** Form generated from reading UI file 'tetrismainwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRISMAINWIDGET_H
#define UI_TETRISMAINWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <gamewidget.h>
#include <nextblock.h>

QT_BEGIN_NAMESPACE

class Ui_TetrisMainWidget
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    NextBlock *next;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QSpacerItem *horizontalSpacer_2;
    GameWidget *game;
    QWidget *info;
    QVBoxLayout *verticalLayout;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QWidget *widget_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TetrisMainWidget)
    {
        if (TetrisMainWidget->objectName().isEmpty())
            TetrisMainWidget->setObjectName(QStringLiteral("TetrisMainWidget"));
        TetrisMainWidget->resize(790, 362);
        TetrisMainWidget->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(TetrisMainWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        next = new NextBlock(centralWidget);
        next->setObjectName(QStringLiteral("next"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(1);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(next->sizePolicy().hasHeightForWidth());
        next->setSizePolicy(sizePolicy);

        gridLayout->addWidget(next, 0, 1, 1, 1);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setStyleSheet(QStringLiteral("color: rgb(255, 0, 0);"));

        horizontalLayout->addWidget(label);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        gridLayout->addWidget(widget, 2, 1, 1, 1);

        game = new GameWidget(centralWidget);
        game->setObjectName(QStringLiteral("game"));
        game->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(3);
        sizePolicy1.setVerticalStretch(3);
        sizePolicy1.setHeightForWidth(game->sizePolicy().hasHeightForWidth());
        game->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(game, 0, 0, 3, 1);

        info = new QWidget(centralWidget);
        info->setObjectName(QStringLiteral("info"));
        sizePolicy.setHeightForWidth(info->sizePolicy().hasHeightForWidth());
        info->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(info);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        widget_5 = new QWidget(info);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        horizontalLayout_2 = new QHBoxLayout(widget_5);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget_5);
        label_2->setObjectName(QStringLiteral("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);
        label_2->setStyleSheet(QStringLiteral("color: rgb(0, 0, 255);"));

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(info);
        widget_6->setObjectName(QStringLiteral("widget_6"));
        horizontalLayout_3 = new QHBoxLayout(widget_6);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        pushButton = new QPushButton(widget_6);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        sizePolicy2.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy2);
        pushButton->setFocusPolicy(Qt::ClickFocus);
        pushButton->setStyleSheet(QStringLiteral("color: rgb(255, 0, 127);"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(info);
        widget_7->setObjectName(QStringLiteral("widget_7"));
        horizontalLayout_4 = new QHBoxLayout(widget_7);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(widget_7);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);
        label_3->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));

        horizontalLayout_4->addWidget(label_3);


        verticalLayout->addWidget(widget_7);

        widget_8 = new QWidget(info);
        widget_8->setObjectName(QStringLiteral("widget_8"));
        horizontalLayout_5 = new QHBoxLayout(widget_8);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_4 = new QLabel(widget_8);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);
        label_4->setStyleSheet(QStringLiteral("color: rgb(85, 170, 255);"));

        horizontalLayout_5->addWidget(label_4);


        verticalLayout->addWidget(widget_8);


        gridLayout->addWidget(info, 1, 1, 1, 1);

        TetrisMainWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TetrisMainWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 790, 26));
        TetrisMainWidget->setMenuBar(menuBar);
        statusBar = new QStatusBar(TetrisMainWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TetrisMainWidget->setStatusBar(statusBar);

        retranslateUi(TetrisMainWidget);

        QMetaObject::connectSlotsByName(TetrisMainWidget);
    } // setupUi

    void retranslateUi(QMainWindow *TetrisMainWidget)
    {
        TetrisMainWidget->setWindowTitle(QApplication::translate("TetrisMainWidget", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("TetrisMainWidget", "by\357\274\232LGT", Q_NULLPTR));
        label_2->setText(QApplication::translate("TetrisMainWidget", "\345\275\223\345\211\215\345\276\227\345\210\206:0", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TetrisMainWidget", "\347\202\271\345\207\273\345\274\200\345\247\213", Q_NULLPTR));
        label_3->setText(QApplication::translate("TetrisMainWidget", "\347\251\272\346\240\274\346\232\202\345\201\234", Q_NULLPTR));
        label_4->setText(QApplication::translate("TetrisMainWidget", "\344\270\212\344\270\213\345\267\246\345\217\263\347\247\273\345\212\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TetrisMainWidget: public Ui_TetrisMainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRISMAINWIDGET_H
