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
#include<QColorDialog>

//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set up the tiles
    populateScene();

    // Set isTransformed to false
    isTransformed = false;

    // Set isRotated to false
    isRotated = false;


    // Connect signals to slots
    connect (ui->xAxisTrans, SIGNAL(clicked(bool)), this, SLOT(xAxisTransSlot()));
    connect (ui->yAxisTrans, SIGNAL(clicked(bool)), this, SLOT(yAxisTransSlot()));
    connect (ui->rotateTrans, SIGNAL(clicked(bool)), this, SLOT(rotateTransSlot()));


    color = QColorDialog::getColor(Qt::white,this,"Pick a color",QColorDialog::ShowAlphaChannel);

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


            QGraphicsItem *item = new Tile(color, j, i, tileWidth, this);
            //QGraphicsRectItem *item = new QGraphicsRectItem();
            //item->setRect( -tileWidth/2.0, tileHeight/2.0, tileWidth, tileHeight);
            //item->setBrush(color);

            item->setPos(QPointF(j, i));
            spriteEditorScene->addItem(item);

        }
    }
}



void MainWindow::xAxisTransSlot() {
    std::cout << "Printing X-Axis Transformation" << std::endl;
    //QTransform xAxisTrans(Qt::XAxis);
    //ui->SpriteEditor->transform();
   // QTransform transform;
    //transform.rotate(90, Qt::;
    //ui->SpriteEditor->setTransform(transform);
   // ui->SpriteEditor->show();
    //ui->SpriteEditor->rotate(180);
   // ui->SpriteEditor->setTransform(QTransform::fromScale(-1,1));
   // ui->SpriteEditor->setTransform(QTransform::fromTranslate(-1,1));
   // ui->SpriteEditor->show();
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
    //ui->SpriteEditor->rotate(90);
    //ui->SpriteEditor->setTransform(QTransform().translate(0, 0).rotate(90).translate(-0, -0));

    if (isTransformed == true)
        ui->SpriteEditor->rotate(-90);
    else
        ui->SpriteEditor->rotate(90);

    if (isRotated == false)
        isRotated = true;
    else
        isRotated = false;

}

