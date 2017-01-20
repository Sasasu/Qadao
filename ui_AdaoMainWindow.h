/********************************************************************************
** Form generated from reading UI file 'AdaoMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADAOMAINWINDOW_H
#define UI_ADAOMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdaoMainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *ForumList;
    QListWidget *Threadlist;
    QPushButton *nextpageButton;
    QPushButton *prepageButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *AdaoMainWindow)
    {
        if (AdaoMainWindow->objectName().isEmpty())
            AdaoMainWindow->setObjectName(QStringLiteral("AdaoMainWindow"));
        AdaoMainWindow->resize(938, 478);
        centralwidget = new QWidget(AdaoMainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ForumList = new QListWidget(centralwidget);
        ForumList->setObjectName(QStringLiteral("ForumList"));
        ForumList->setGeometry(QRect(0, 0, 141, 461));
        Threadlist = new QListWidget(centralwidget);
        Threadlist->setObjectName(QStringLiteral("Threadlist"));
        Threadlist->setGeometry(QRect(140, 0, 751, 461));
        nextpageButton = new QPushButton(centralwidget);
        nextpageButton->setObjectName(QStringLiteral("nextpageButton"));
        nextpageButton->setGeometry(QRect(890, 400, 41, 31));
        prepageButton = new QPushButton(centralwidget);
        prepageButton->setObjectName(QStringLiteral("prepageButton"));
        prepageButton->setGeometry(QRect(890, 0, 51, 31));
        AdaoMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdaoMainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 938, 23));
        AdaoMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdaoMainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        AdaoMainWindow->setStatusBar(statusbar);

        retranslateUi(AdaoMainWindow);

        QMetaObject::connectSlotsByName(AdaoMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdaoMainWindow)
    {
        AdaoMainWindow->setWindowTitle(QString());
        nextpageButton->setText(QApplication::translate("AdaoMainWindow", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        prepageButton->setText(QApplication::translate("AdaoMainWindow", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AdaoMainWindow: public Ui_AdaoMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADAOMAINWINDOW_H
