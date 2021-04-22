/********************************************************************************
** Form generated from reading UI file 'searchbuylog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHBUYLOG_H
#define UI_SEARCHBUYLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchbuylog
{
public:
    QTextEdit *textEdit;

    void setupUi(QWidget *searchbuylog)
    {
        if (searchbuylog->objectName().isEmpty())
            searchbuylog->setObjectName(QStringLiteral("searchbuylog"));
        searchbuylog->resize(411, 302);
        textEdit = new QTextEdit(searchbuylog);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(0, 0, 411, 301));

        retranslateUi(searchbuylog);

        QMetaObject::connectSlotsByName(searchbuylog);
    } // setupUi

    void retranslateUi(QWidget *searchbuylog)
    {
        searchbuylog->setWindowTitle(QApplication::translate("searchbuylog", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class searchbuylog: public Ui_searchbuylog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHBUYLOG_H
