#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <spriteeditorview.h>

// Testing Includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
/*
 * Tile
 */
#include "tile.h"

/*
 * QT Includes
 */
#include <QT>
#include <QColor>
#include <QRgb>
#include<QGraphicsRectItem>
#include<QMouseEvent>

#include<QColorDialog>

#include <QPushButton>
#include <QColorDialog>
#include <QTimer>



//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize sceneIndex
    sceneIndex = 0;

    //Start SceneTimer
    sceneTimer = new QTimer(this);
    sceneTimer->start(100);

    // Connect signals to slots
    connect (ui->xAxisTrans, SIGNAL(clicked(bool)), this, SLOT(xAxisTransSlot()));
    connect (ui->yAxisTrans, SIGNAL(clicked(bool)), this, SLOT(yAxisTransSlot()));
    connect (ui->rotateTrans, SIGNAL(clicked(bool)), this, SLOT(rotateTransSlot()));
    connect (sceneTimer, SIGNAL(timeout()), this, SLOT(updateScene()));
    connect (ui->newScene, SIGNAL(clicked()), this, SLOT(newScene()));


    isLoad = true;
    //Set up the tiles
    populateScene();


}

MainWindow::~MainWindow()
{
    delete ui;
}

bool boolSwap(bool a){
    return !a;
}
bool load = true;
void MainWindow::populateScene()
{
    spriteEditorScene = new QGraphicsScene;


    /*
     * Scene is the object that has all the properties
     * for displaying what we want
     */
    ui->SpriteEditor->setScene(spriteEditorScene);


    /*
     * EQUATION FOR ADJUSTING THE ASPECT RATIO
     * adjusted height = <user-chosen width> * original height / original width
     * adjusted width = <user-chosen height> * original width / original height
     */
    double tilesWide = 8.0;
    double tilesTall = 4.0;

    double width = ui->SpriteEditor->width();
    double height = ui->SpriteEditor->height();
    double swidth = ui->scenesView->width();
    double sheight = ui->scenesView->height();

    if(isLoad){
        if(tilesWide< tilesTall){
            width *= (tilesWide/ tilesTall);
            swidth *= (tilesWide/ tilesTall);
        }
        else if(tilesTall < tilesWide){
            height *=(tilesTall/tilesWide);
            sheight *=(tilesTall/tilesWide);
        }
        isLoad = false;
    }
    QRect rect;
    rect.setHeight(height);
    rect.setWidth(width);
    ui->SpriteEditor->setGeometry(rect);


//    rect.setHeight(sheight);
//    rect.setWidth(swidth);
//    ui->scenesView->setGeometry(rect);

    //Number of tiles per row & height
    int squareCount = 24;



    int counter = 0;
    bool isSwap = true;


    double smallestDim = std::min(width,height);
    int smallestTileLength = std::min(tilesWide,tilesTall);
    double tilesize = smallestDim/smallestTileLength;



    /*
     * Traverse the Scene in the Y direction starting
     * int the top left. (0,0) in our coordinate system
     * is in the center of the QGraphicsView
     */
    for (double i = -height/2; i < height/2; i += tilesize) {

        //If the dimentions are even numbers we must swap each row
        if(squareCount % 2 == 0)
            isSwap = boolSwap(isSwap);

        /*
         * Traverse the Scene in the X Directions
         */
        for (double j = -width/2; j < width/2; j += tilesize) {

            //Every Column swap the color
            isSwap = boolSwap(isSwap);

            QColor color;
            if(isSwap)
                color= QColor(169, 169, 169);
            else
                color = QColor(211, 211, 211);
            counter++;


            QGraphicsItem *item = new Tile(color, j, i, tilesize, this);

            item->setPos(QPointF(j, i));
            spriteEditorScene->addItem(item);

        }

      //Add current scene to scenesView
      scenes.push_back(spriteEditorScene);
      QRectF bounds = spriteEditorScene->sceneRect();
      //ui->scenesView->fitInView(bounds, Qt::KeepAspectRatio);

    }
}



void MainWindow::newScene()
{
    populateScene();
}


void MainWindow::updateScene()
{

    ui->scenesView->setScene(scenes[sceneIndex]);
    if(sceneIndex == scenes.size() - 1)
    {
        sceneIndex = 0;
        return;
    }

    sceneIndex++;
}



void MainWindow::xAxisTransSlot() {
    std::cout<<"X"<<std::endl;
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());
    QTransform mirror;
    group->setTransform(mirror.scale(1,-1));



    spriteEditorScene->destroyItemGroup(group);
}

void MainWindow::yAxisTransSlot() {
    std::cout<<"Y"<<std::endl;
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());

    QTransform mirror;
    group->setTransform(mirror.scale(-1,1));


    spriteEditorScene->destroyItemGroup(group);
}

void MainWindow::rotateTransSlot() {
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());
    group->setRotation(90);
    spriteEditorScene->destroyItemGroup(group);

}



