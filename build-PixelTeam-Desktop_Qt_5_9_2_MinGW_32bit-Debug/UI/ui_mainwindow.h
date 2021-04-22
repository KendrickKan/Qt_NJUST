/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *snakeBtn;
    QPushButton *planebutton;
    QPushButton *Tetris;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 736);
        QIcon icon;
        icon.addFile(QStringLiteral("img/Tetris.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        snakeBtn = new QPushButton(centralWidget);
        snakeBtn->setObjectName(QStringLiteral("snakeBtn"));
        snakeBtn->setGeometry(QRect(250, 620, 93, 28));
        planebutton = new QPushButton(centralWidget);
        planebutton->setObjectName(QStringLiteral("planebutton"));
        planebutton->setGeometry(QRect(430, 630, 93, 28));
        Tetris = new QPushButton(centralWidget);
        Tetris->setObjectName(QStringLiteral("Tetris"));
        Tetris->setGeometry(QRect(640, 640, 93, 28));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Pixel game", Q_NULLPTR));
        snakeBtn->setText(QApplication::translate("MainWindow", "Snake", Q_NULLPTR));
        planebutton->setText(QApplication::translate("MainWindow", "Plane", Q_NULLPTR));
        Tetris->setText(QApplication::translate("MainWindow", "Tetris", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
