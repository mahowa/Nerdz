#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>
#include <spriteeditorview.h>

// Testing Includes
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

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
#include <QPushButton>
#include <QColorDialog>


//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize sceneIndex
    sceneIndex = 0;

    //Set up the tiles
    populateScene();

    //Start SceneTimer
    //Dan: This timer dictatets how fast the upperright window moves through scenes. Am going to add a slider bar widget
    //to allow user to control this. Can't figure out why the connect using this widget won't work.
   // sceneTimer->start(1000);

    // Set isTransformed to false
    isTransformed = false;

    // Set isRotated to false
    isRotated = false;


    // Connect signals to slots
    connect (ui->xAxisTrans, SIGNAL(clicked(bool)), this, SLOT(xAxisTransSlot()));
    connect (ui->yAxisTrans, SIGNAL(clicked(bool)), this, SLOT(yAxisTransSlot()));
    connect (ui->rotateTrans, SIGNAL(clicked(bool)), this, SLOT(rotateTransSlot()));

    //**Dan:For some reason when this connect is uncommented the program fails. I can't figure it out.
    //Did Same thing in another project and worked fine to use timer to udate upper right hand window.
    //connect (this->sceneTimer, SIGNAL(timeout()), this, SLOT(updateScene()));

    connect (ui->newScene, SIGNAL(clicked()), this, SLOT(newScene()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool boolSwap(bool a){
    if(a)
        return false;
    else return true;
}

void MainWindow::populateScene()
{
    spriteEditorScene = new QGraphicsScene;


    /*
     * Scene is the object that has all the properties
     * for displaying what we want
     */
    ui->SpriteEditor->setScene(spriteEditorScene);



    //Number of tiles per row & height
    int squareCount = 16;

    int width = ui->SpriteEditor->width();
    int height = ui->SpriteEditor->height();

    int counter = 0;
    bool isSwap = true;
    int tileWidth = width/squareCount;
    int tileHeight= height/squareCount;
    //    //QImage image();


    /*
     * Traverse the Scene in the Y direction starting
     * int the top left. (0,0) in our coordinate system
     * is in the center of the QGraphicsView
     */
    for (int i = -height/2; i < height/2; i += tileHeight) {

        //If the dimentions are even numbers we must swap each row
        if(squareCount % 2 == 0)
            isSwap = boolSwap(isSwap);

        /*
         * Traverse the Scene in the X Directions
         */
        for (int j = -width/2; j < width/2; j += tileWidth) {

            //Every Column swap the color
            isSwap = boolSwap(isSwap);

            QColor color;
            if(isSwap)
                color= QColor(169, 169, 169);
            else
                color = QColor(211, 211, 211);
            counter++;


            QGraphicsItem *item = new Tile(color, j, i, tileWidth);
            //QGraphicsRectItem *item = new QGraphicsRectItem();
            //item->setRect( -tileWidth/2.0, tileHeight/2.0, tileWidth, tileHeight);
            //item->setBrush(color);

            item->setPos(QPointF(j, i));
            spriteEditorScene->addItem(item);


            // Small view example
            QGraphicsScene *testScene(spriteEditorScene);
            ui->smallView1->setScene(testScene);
            QRectF bounds = testScene->itemsBoundingRect();
            ui->smallView1->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
            ui->smallView1->centerOn(0,0);

        }

      //Add current scene to scenesView
      QGraphicsScene *testScene(spriteEditorScene);
      scenes.push_back(testScene);

    }
}

//**Dan: Im thinking this will just call populate scene to refresh the main scene. A pointer
//to the main scene gets put into the vector scenes which are shown on right and left. Also, We will
//have to implement it so that a scene in thelist of scenes on the left can be clicked and a
//different type of populate is called that brings that scene up.
void MainWindow::newScene()
{
    populateScene();
}

//Dan: Can't get this method connected to sceneTimer. It looks exactly how I do it in a seperate project which is working
//fine. Will work on it more tomorrow.
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
    std::cout << "Printing X-Axis Transformation" << std::endl;

    if (isRotated == false)
        ui->SpriteEditor->scale(1,-1);
    else
        ui->SpriteEditor->scale(-1,1);
     // ui->SpriteEditor->setMatrix();

      if (isTransformed == false)
          isTransformed = true;
      else
          isTransformed = false;
}

void MainWindow::yAxisTransSlot() {
    std::cout << "Printing Y-Axis Transformation" << std::endl;
    if (isRotated == false)
        ui->SpriteEditor->scale(-1,1);
    else
        ui->SpriteEditor->scale(1,-1);

    if (isTransformed == false)
        isTransformed = true;
    else
        isTransformed = false;
}

void MainWindow::rotateTransSlot() {
    std::cout << "Printing Rotate Transformation" << std::endl;

    if (isTransformed == true)
        ui->SpriteEditor->rotate(-90);
    else
        ui->SpriteEditor->rotate(90);

    if (isRotated == false)
        isRotated = true;
    else
        isRotated = false;

}

