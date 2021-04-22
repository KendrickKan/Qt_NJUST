/********************************************************************************
** Form generated from reading UI file 'searchselllog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHSELLLOG_H
#define UI_SEARCHSELLLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchselllog
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *searchselllog)
    {
        if (searchselllog->objectName().isEmpty())
            searchselllog->setObjectName(QStringLiteral("searchselllog"));
        searchselllog->resize(411, 302);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(searchselllog->sizePolicy().hasHeightForWidth());
        searchselllog->setSizePolicy(sizePolicy);
        textEdit = new QTextEdit(searchselllog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 411, 301));

        retranslateUi(searchselllog);

        QMetaObject::connectSlotsByName(searchselllog);
    } // setupUi

    void retranslateUi(QWidget *searchselllog)
    {
        searchselllog->setWindowTitle(QApplication::translate("searchselllog", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class searchselllog: public Ui_searchselllog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHSELLLOG_H
