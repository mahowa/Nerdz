/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGraphicsView *SpriteEditor;
    QToolButton *yAxisTrans;
    QToolButton *xAxisTrans;
    QToolButton *rotateTrans;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1189, 785);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SpriteEditor = new QGraphicsView(centralWidget);
        SpriteEditor->setObjectName(QStringLiteral("SpriteEditor"));
        SpriteEditor->setGeometry(QRect(120, 10, 640, 640));
        SpriteEditor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SpriteEditor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        yAxisTrans = new QToolButton(centralWidget);
        yAxisTrans->setObjectName(QStringLiteral("yAxisTrans"));
        yAxisTrans->setGeometry(QRect(760, 10, 81, 71));
        QIcon icon;
        icon.addFile(QStringLiteral(":/yAxisTrans.png"), QSize(), QIcon::Normal, QIcon::Off);
        yAxisTrans->setIcon(icon);
        yAxisTrans->setIconSize(QSize(81, 71));
        xAxisTrans = new QToolButton(centralWidget);
        xAxisTrans->setObjectName(QStringLiteral("xAxisTrans"));
        xAxisTrans->setGeometry(QRect(760, 80, 81, 71));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/xAxisTrans.png"), QSize(), QIcon::Normal, QIcon::Off);
        xAxisTrans->setIcon(icon1);
        xAxisTrans->setIconSize(QSize(81, 71));
        rotateTrans = new QToolButton(centralWidget);
        rotateTrans->setObjectName(QStringLiteral("rotateTrans"));
        rotateTrans->setGeometry(QRect(760, 150, 81, 71));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotateTrans->setIcon(icon2);
        rotateTrans->setIconSize(QSize(81, 71));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1189, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        yAxisTrans->setText(QApplication::translate("MainWindow", "...", 0));
        xAxisTrans->setText(QApplication::translate("MainWindow", "...", 0));
        rotateTrans->setText(QApplication::translate("MainWindow", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
