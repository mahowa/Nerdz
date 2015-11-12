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

#include <QPushButton>
#include <QColorDialog>
#include <QTimer>
#include <QPalette>
#include <QSignalMapper>


//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Initialize sceneIndex
    sceneIndex = 0;

    //Start SceneTimer
    sceneTimer = new QTimer(this);
    sceneTimer->start(100);

    // Set isTransformed to false
    isTransformed = false;

    // Set isRotated to false
    isRotated = false;

    ui->speedSlider->setValue(1);
    ui->currentColorPallete->setPalette(color);

    // Connect signals to slots
    connect (ui->xAxisTrans, SIGNAL(clicked(bool)), this, SLOT(xAxisTransSlot()));
    connect (ui->yAxisTrans, SIGNAL(clicked(bool)), this, SLOT(yAxisTransSlot()));
    connect (ui->rotateTrans, SIGNAL(clicked(bool)), this, SLOT(rotateTransSlot()));
    connect (sceneTimer, SIGNAL(timeout()), this, SLOT(updateScene()));
    connect (ui->newScene, SIGNAL(clicked()), this, SLOT(newScene()));
    //connect (ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSlider_valueChanged()));
   // connect (ui->setRange, SIGNAL(toggled(bool)), this, SLOT(setRangeToggled()));


    //color = QColorDialog::getColor(Qt::white,this,"Pick a color",QColorDialog::ShowAlphaChannel);

    connect (ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSlider_valueChanged()));
    connect (ui->nextPushButton, SIGNAL(clicked()), this, SLOT(on_nextButton_clicked()));
    connect (ui->previousPushButton, SIGNAL(clicked()), this, SLOT(on_prevButton_clicked()));

    isLoad = true;
    //Set up the tiles
    populateScene();

    // Set push buttons
    ui->nextPushButton->setEnabled(false);
    ui->previousPushButton->setEnabled(false);

    // Create transparent buttons over the left side scenes and preview.
    ui->viewButton1->setStyleSheet("QPushButton{background: transparent;}");
    ui->viewButton2->setStyleSheet("QPushButton{background: transparent;}");
    ui->viewButton3->setStyleSheet("QPushButton{background: transparent;}");
    ui->viewButton4->setStyleSheet("QPushButton{background: transparent;}");
    ui->viewButton5->setStyleSheet("QPushButton{background: transparent;}");
    ui->previewButton->setStyleSheet("QPushButton{background: transparent;}");

    // Set scene display tracker
    firstSceneDisplayed = 1;

    setLeftSlots();

}

MainWindow::~MainWindow()
{
    delete ui;
}

bool boolSwap(bool a){
  return !a;
}

void MainWindow::populateScene()
{
    spriteEditorScene = new QGraphicsScene;


    /*
     * Scene is the object that has all the properties
     * for displaying what we want
     */
    ui->SpriteEditor->setScene(spriteEditorScene);



    double tilesWide = 8.0;
    double tilesTall = 16.0;

    double width = ui->SpriteEditor->width();
    double height = ui->SpriteEditor->height();

    if(isLoad){
        if(tilesWide< tilesTall){
            width *= (tilesWide/ tilesTall);
        }
        else if(tilesTall < tilesWide){
            height *=(tilesTall/tilesWide);
        }
        isLoad = false;
    }
    QRect rect;
    rect.setHeight(height);
    rect.setWidth(width);
    ui->SpriteEditor->setGeometry(rect);


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
//            tiles.push_back(item);


        }
}
    //Add current scene to scenesView
    scenes.push_back(spriteEditorScene);
    QRectF bounds = spriteEditorScene->sceneRect();
    ui->scenesView->fitInView(bounds,Qt::KeepAspectRatio);
    ui->scenesView->setFrameRect(bounds.toAlignedRect());

     // ui->scenesView->centerOn(0,0);

    //  ui->smallView1->fitInView(bounds, Qt::KeepAspectRatioByExpanding);

      //updateScene();

      //            // Small view exampl
      //            QGraphicsScene *testScene(spriteEditorScene);
      int sceneNum = scenes.size() - 1;
      //QRectF bounds;
      switch (scenes.size()) {
       case 1:
           ui->smallView1->setScene(scenes[sceneNum]);
           bounds = spriteEditorScene->itemsBoundingRect();
           ui->smallView1->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
           ui->smallView1->centerOn(0,0);
           ui->text1->setText("1");
           ui->viewButton1->setEnabled(true);
           break;
       case 2:
           ui->smallView2->setScene(scenes[sceneNum]);
           bounds = spriteEditorScene->itemsBoundingRect();
           ui->smallView2->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
           ui->smallView2->centerOn(0,0);
           ui->text2->setText("2");
           ui->viewButton2->setEnabled(true);
          break;
       case 3:
           ui->smallView3->setScene(scenes[sceneNum]);
           bounds = spriteEditorScene->itemsBoundingRect();
           ui->smallView3->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
           ui->smallView3->centerOn(0,0);
           ui->text3->setText("3");
           ui->viewButton3->setEnabled(true);
           break;
       case 4:
           ui->smallView4->setScene(scenes[sceneNum]);
           bounds = spriteEditorScene->itemsBoundingRect();
           ui->smallView4->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
           ui->smallView4->centerOn(0,0);
           ui->text4->setText("4");
           ui->viewButton4->setEnabled(true);
           break;
       case 5:
           ui->smallView5->setScene(scenes[sceneNum]);
           bounds = spriteEditorScene->itemsBoundingRect();
           ui->smallView5->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
           ui->smallView5->centerOn(0,0);
           ui->text5->setText("5");
           ui->viewButton5->setEnabled(true);
           break;
       default:
          ui->nextPushButton->setEnabled(true);
           break;
       }
}

void MainWindow::newScene()
{
    populateScene();
}

void MainWindow::updateScene()
{
   // if(ui->setRange->isChecked())
   // {
       // ui->toBox->setEnabled();
       // if(ui->fromBui->fromBox->value() > 0 || ui->toBox->value() > 0)
      //      break breakme;
   // }



    ui->scenesView->setScene(scenes[sceneIndex]);
    if(sceneIndex == scenes.size() - 1)
    {
        sceneIndex = 0;
        return;
    }

    sceneIndex++;
}



void MainWindow::xAxisTransSlot() {
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());
    QTransform mirror;

    if (isTransformed == false)
        group->setTransform(mirror.scale(1,-1));
    else
        group->setTransform(mirror.scale(1,-1));

    isTransformed = !isTransformed;
    spriteEditorScene->destroyItemGroup(group);
}

void MainWindow::yAxisTransSlot() {
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());

    QTransform mirror;

    if (isRotated == false)
        group->setTransform(mirror.scale(-1,1));
    else
        group->setTransform(mirror.scale(-1,1));


    spriteEditorScene->destroyItemGroup(group);
}

void MainWindow::rotateTransSlot() {
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());
    group->setRotation(90);
    spriteEditorScene->destroyItemGroup(group);

    isRotated = !isRotated;
}

void MainWindow::on_horizontalSlider_valueChanged()
{
    if(ui->speedSlider->value() == 0)
    {
        sceneTimer->start(1000000000);
    }
    else
   {
        int speedValue = ui->speedSlider->value();
        sceneTimer->start(100/speedValue);
    }
}

void MainWindow::on_colorChooser_clicked()
{
    color = QColorDialog::getColor(Qt::white,this,"Pick a color",QColorDialog::ShowAlphaChannel);
    QPalette pal = ui->currentColorPallete->palette();
    pal.setColor(QPalette::Window, color);
    ui->currentColorPallete->setPalette(pal);

    //emit colorChanged(mColor);
}

void MainWindow::on_SaveFileButton_clicked()
{

}

void MainWindow::on_toolButton_2_clicked()
{

}

void MainWindow::on_nextButton_clicked()
{
        QRectF bounds;
        ui->smallView1->setScene(scenes[firstSceneDisplayed]);
         bounds = spriteEditorScene->itemsBoundingRect();
         ui->smallView1->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
         ui->smallView1->centerOn(0,0);
         ui->text1->setText(QString::number(firstSceneDisplayed + 1));

         ui->smallView2->setScene(scenes[firstSceneDisplayed + 1]);
         bounds = spriteEditorScene->itemsBoundingRect();
         ui->smallView2->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
         ui->smallView2->centerOn(0,0);
         ui->text2->setText(QString::number(firstSceneDisplayed + 2));

         ui->smallView3->setScene(scenes[firstSceneDisplayed + 2]);
         bounds = spriteEditorScene->itemsBoundingRect();
         ui->smallView3->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
         ui->smallView3->centerOn(0,0);
         ui->text3->setText(QString::number(firstSceneDisplayed + 3));

         ui->smallView4->setScene(scenes[firstSceneDisplayed + 3]);
         bounds = spriteEditorScene->itemsBoundingRect();
         ui->smallView4->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
         ui->smallView4->centerOn(0,0);
         ui->text4->setText(QString::number(firstSceneDisplayed + 4));

         ui->smallView5->setScene(scenes[firstSceneDisplayed + 4]);
         bounds = spriteEditorScene->itemsBoundingRect();
         ui->smallView5->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
         ui->smallView5->centerOn(0,0);
         ui->text5->setText(QString::number(firstSceneDisplayed + 5));

         ui->previousPushButton->setEnabled(true);

         if (firstSceneDisplayed + 6 > scenes.size())
             ui->nextPushButton->setEnabled(false);

         firstSceneDisplayed++;

        setLeftSlots();
}

void MainWindow::on_prevButton_clicked()
{
     QRectF bounds;
     ui->smallView1->setScene(scenes[firstSceneDisplayed - 2]);
     bounds = spriteEditorScene->itemsBoundingRect();
     ui->smallView1->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
     ui->smallView1->centerOn(0,0);
     ui->text1->setText(QString::number(firstSceneDisplayed -1));

     ui->smallView2->setScene(scenes[firstSceneDisplayed - 1]);
     bounds = spriteEditorScene->itemsBoundingRect();
     ui->smallView2->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
     ui->smallView2->centerOn(0,0);
     ui->text2->setText(QString::number(firstSceneDisplayed));

     ui->smallView3->setScene(scenes[firstSceneDisplayed]);
     bounds = spriteEditorScene->itemsBoundingRect();
     ui->smallView3->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
     ui->smallView3->centerOn(0,0);
     ui->text3->setText(QString::number(firstSceneDisplayed + 1));

     ui->smallView4->setScene(scenes[firstSceneDisplayed + 1]);
     bounds = spriteEditorScene->itemsBoundingRect();
     ui->smallView4->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
     ui->smallView4->centerOn(0,0);
     ui->text4->setText(QString::number(firstSceneDisplayed + 2));

     ui->smallView5->setScene(scenes[firstSceneDisplayed + 2]);
     bounds = spriteEditorScene->itemsBoundingRect();
     ui->smallView5->fitInView(bounds, Qt::KeepAspectRatioByExpanding);
     ui->smallView5->centerOn(0,0);
     ui->text5->setText(QString::number(firstSceneDisplayed + 3));

     ui->nextPushButton->setEnabled(true);

     if (firstSceneDisplayed - 2 == 0)
         ui->previousPushButton->setEnabled(false);

     firstSceneDisplayed--;

     setLeftSlots();
}

void MainWindow::on_clickedScene(int scene){
    ui->SpriteEditor->setScene(scenes[scene]);
}

void MainWindow::setLeftSlots(){
    QSignalMapper *mapper = new QSignalMapper(this);

    connect(ui->viewButton1, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->viewButton1, firstSceneDisplayed - 1);

    connect(ui->viewButton2, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->viewButton2, firstSceneDisplayed);

    connect(ui->viewButton3, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->viewButton3, firstSceneDisplayed + 1);

    connect(ui->viewButton4, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->viewButton4, firstSceneDisplayed + 2);

    connect(ui->viewButton5, SIGNAL(clicked()), mapper, SLOT(map()));
    mapper->setMapping(ui->viewButton5, firstSceneDisplayed + 3);

    connect(mapper, SIGNAL(mapped(int)), this, SLOT(on_clickedScene(int)));
}
