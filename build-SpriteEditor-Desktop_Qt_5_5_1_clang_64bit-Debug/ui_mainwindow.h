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
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
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
    QToolButton *colorChooser;
    QGraphicsView *scenesView;
    QPushButton *newScene;
    QSpinBox *fromBox;
    QSpinBox *toBox;
    QLabel *label;
    QLabel *label_2;
    QRadioButton *setRange;
    QSlider *speedSlider;
    QSpinBox *spinBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *frameDock;
    QWidget *dockWidgetContents_2;
    QGraphicsView *smallView1;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1189, 785);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SpriteEditor = new QGraphicsView(centralWidget);
        SpriteEditor->setObjectName(QStringLiteral("SpriteEditor"));
        SpriteEditor->setGeometry(QRect(0, 0, 640, 640));
        SpriteEditor->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CrossCursor)));
        SpriteEditor->setFrameShape(QFrame::Box);
        SpriteEditor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        SpriteEditor->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        yAxisTrans = new QToolButton(centralWidget);
        yAxisTrans->setObjectName(QStringLiteral("yAxisTrans"));
        yAxisTrans->setGeometry(QRect(640, 0, 81, 71));
        QIcon icon;
        icon.addFile(QStringLiteral(":/yAxisTrans.png"), QSize(), QIcon::Normal, QIcon::Off);
        yAxisTrans->setIcon(icon);
        yAxisTrans->setIconSize(QSize(81, 71));
        xAxisTrans = new QToolButton(centralWidget);
        xAxisTrans->setObjectName(QStringLiteral("xAxisTrans"));
        xAxisTrans->setGeometry(QRect(640, 70, 81, 71));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/xAxisTrans.png"), QSize(), QIcon::Normal, QIcon::Off);
        xAxisTrans->setIcon(icon1);
        xAxisTrans->setIconSize(QSize(81, 71));
        rotateTrans = new QToolButton(centralWidget);
        rotateTrans->setObjectName(QStringLiteral("rotateTrans"));
        rotateTrans->setGeometry(QRect(640, 140, 81, 71));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        rotateTrans->setIcon(icon2);
        rotateTrans->setIconSize(QSize(81, 71));
        colorChooser = new QToolButton(centralWidget);
        colorChooser->setObjectName(QStringLiteral("colorChooser"));
        colorChooser->setGeometry(QRect(640, 210, 81, 71));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/colorPickerIcon.png"), QSize(), QIcon::Normal, QIcon::Off);
        colorChooser->setIcon(icon3);
        colorChooser->setIconSize(QSize(81, 71));
        scenesView = new QGraphicsView(centralWidget);
        scenesView->setObjectName(QStringLiteral("scenesView"));
        scenesView->setGeometry(QRect(800, 0, 200, 200));
        scenesView->setFrameShape(QFrame::StyledPanel);
        scenesView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scenesView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        newScene = new QPushButton(centralWidget);
        newScene->setObjectName(QStringLiteral("newScene"));
        newScene->setGeometry(QRect(530, 660, 112, 34));
        fromBox = new QSpinBox(centralWidget);
        fromBox->setObjectName(QStringLiteral("fromBox"));
        fromBox->setGeometry(QRect(860, 240, 45, 25));
        toBox = new QSpinBox(centralWidget);
        toBox->setObjectName(QStringLiteral("toBox"));
        toBox->setEnabled(false);
        toBox->setGeometry(QRect(950, 240, 45, 25));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(810, 240, 68, 19));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(920, 240, 68, 19));
        setRange = new QRadioButton(centralWidget);
        setRange->setObjectName(QStringLiteral("setRange"));
        setRange->setGeometry(QRect(800, 210, 119, 23));
        speedSlider = new QSlider(centralWidget);
        speedSlider->setObjectName(QStringLiteral("speedSlider"));
        speedSlider->setGeometry(QRect(800, 290, 160, 22));
        speedSlider->setMaximum(30);
        speedSlider->setOrientation(Qt::Horizontal);
        spinBox = new QSpinBox(centralWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(970, 290, 48, 24));
        spinBox->setMinimum(0);
        spinBox->setMaximum(30);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1189, 31));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        frameDock = new QDockWidget(MainWindow);
        frameDock->setObjectName(QStringLiteral("frameDock"));
        frameDock->setMinimumSize(QSize(91, 50));
        frameDock->setFeatures(QDockWidget::NoDockWidgetFeatures);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QStringLiteral("dockWidgetContents_2"));
        smallView1 = new QGraphicsView(dockWidgetContents_2);
        smallView1->setObjectName(QStringLiteral("smallView1"));
        smallView1->setGeometry(QRect(0, 0, 91, 91));
        smallView1->setMinimumSize(QSize(50, 50));
        smallView1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        smallView1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        frameDock->setWidget(dockWidgetContents_2);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), frameDock);

        retranslateUi(MainWindow);
        QObject::connect(speedSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), speedSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Sprite Creator", 0));
        yAxisTrans->setText(QApplication::translate("MainWindow", "...", 0));
        xAxisTrans->setText(QApplication::translate("MainWindow", "...", 0));
        rotateTrans->setText(QApplication::translate("MainWindow", "...", 0));
        colorChooser->setText(QApplication::translate("MainWindow", "...", 0));
        newScene->setText(QApplication::translate("MainWindow", "New", 0));
        label->setText(QApplication::translate("MainWindow", "From:", 0));
        label_2->setText(QApplication::translate("MainWindow", "To:", 0));
        setRange->setText(QApplication::translate("MainWindow", "Set Range", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
