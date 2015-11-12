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
#include <QFileDialog>
#include <QTextStream>

using namespace std;
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
    eraseOn = false;

    ui->speedSlider->setValue(1);
    ui->currentColorPallete->setPalette(color);

    // Connect signals to slots
    connect (ui->xAxisTrans, SIGNAL(clicked(bool)), this, SLOT(xAxisTransSlot()));
    connect (ui->yAxisTrans, SIGNAL(clicked(bool)), this, SLOT(yAxisTransSlot()));
    connect (ui->rotateTrans, SIGNAL(clicked(bool)), this, SLOT(rotateTransSlot()));
    connect (ui->newScene, SIGNAL(clicked()), this, SLOT(newScene()));
    connect (ui->submitButton, SIGNAL(clicked()), this, SLOT(submitDimensions()));
    connect (ui->erasePushButton, SIGNAL(clicked(bool)), this, SLOT(on_eraseClicked()));
    connect (ui->speedSlider, SIGNAL(valueChanged(int)), this, SLOT(on_horizontalSlider_valueChanged()));
    connect (ui->nextPushButton, SIGNAL(clicked()), this, SLOT(on_nextButton_clicked()));
    connect (ui->previousPushButton, SIGNAL(clicked()), this, SLOT(on_prevButton_clicked()));



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

    isLoad = true;

    setLeftSlots();

    //populateScene();

}

/* Destructor
 * deletes the user interface
*/
MainWindow::~MainWindow()
{
    delete ui;
}

/*
 * Swap Method
 * Returns: A boolean if a swap has been made
 * Parameters: A boolean variabe if a swap has been made
*/
bool boolSwap(bool a){
  return !a;
}


void MainWindow::submitDimensions()
{
    tilesWide = ui->width->value();
    tilesTall = ui->height->value();

    populateScene();
    connect (sceneTimer, SIGNAL(timeout()), this, SLOT(updateScene()));
    ui->submitButton->setEnabled(false);

}

void MainWindow::on_eraseClicked()
{
    eraseOn = !eraseOn;

    if (eraseOn)
    {
        color = QColor(211, 211, 211);
        color= QColor(169, 169, 169);
    }
    else
    {
        on_colorChooser_clicked();
    }
}

/* Populate Scene Method
 * Returns: Void
 * Parameters: Void
 * This method creates a new scene
 * where one can draw a sprite
 * Opens a new QGraphicsScene
*/
void MainWindow::populateScene()
{
    spriteEditorScene = new QGraphicsScene;


    /*
     * Scene is the object that has all the properties
     * for displaying what we want
     */
    ui->SpriteEditor->setScene(spriteEditorScene);



    //tilesWide = 16.0;
   // tilesTall = 16.0;

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
        }
}
    //Add current scene to scenesView
    scenes.push_back(spriteEditorScene);
    QRectF bounds = spriteEditorScene->sceneRect();
    ui->scenesView->fitInView(bounds,Qt::KeepAspectRatio);
    ui->scenesView->setFrameRect(bounds.toAlignedRect());

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

/* New Scene
 * Parameters: Void
 * Returns: Void
 * Creates a new populate scene
*/
void MainWindow::newScene()
{
    populateScene();
}

/* Update Scene
 * Returns: Void
 * Parameters: Void
 * This method adds another scene to a vector
 * which holds multiple scenes.
*/
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


/* xAxisTrans Rotation Method
 * Parameters: Void
 * Returns: Void
 * This method translates/rotates the sprite
 * image across the x-axis
 *
*/
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

/* yAxisTrans Rotation Method
 * Parameters: Void
 * Returns: Void
 * This method translates/rotates the sprite
 * image across the y-axis
 *
*/
void MainWindow::yAxisTransSlot() {
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());

    QTransform mirror;

    if (isRotated == false)
        group->setTransform(mirror.scale(-1,1));
    else
        group->setTransform(mirror.scale(-1,1));


    spriteEditorScene->destroyItemGroup(group);
}

/* TransRotation Method
 * Parameters: Void
 * Returns: Void
 * This method rotates the sprite
 * image in 45 degree increments in
 * a counter-clockwise direction
*/
void MainWindow::rotateTransSlot() {
    QGraphicsItemGroup *group = spriteEditorScene->createItemGroup(spriteEditorScene->items());
    group->setRotation(90);
    spriteEditorScene->destroyItemGroup(group);

    isRotated = !isRotated;
}

/* On_horizontalSlider_valueChanged
 * Parmeters: Void
 * Returns: Void
 * This method signals when the value
 * on the slider has changed so it
 * can be updated accordingly with the view
*/
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

/* On_colorChooser_clicked
 * Parmeters: Void
 * Returns: Void
 * This method signals when the color chooser
 * button has been clicked. The color chooser
 * is displayed and a color is selected by
 * the user and stored. Then the color that is
 * selected is displayed in the current color
 * window
*/
void MainWindow::on_colorChooser_clicked()
{
    color = QColorDialog::getColor(Qt::white,this,"Pick a color",QColorDialog::ShowAlphaChannel);
    QPalette pal = ui->currentColorPallete->palette();
    pal.setColor(QPalette::Window, color);
    ui->currentColorPallete->setPalette(pal);
}


void MainWindow::on_toolButton_2_clicked()
{

}

/*
 * On NextButton Clicked Method
 * Returns: Void
 * Parameters: Void
 * This method moves to the next scene created
 * in the list of scenes
*/
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

/*
 * On PrevButton Clicked Method
 * Returns: Void
 * Parameters: Void
 * This method moves to the previous scene created
 * in the list of scenes
*/
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

/*
 * On Clicked Scene Method
 * Returns: Void
 * Parameters: An int
 * This method selects a certain scene that
 * has been clicked in the list of scenes and loads the
 * scene in the main window
*/
void MainWindow::on_clickedScene(int scene){
    spriteEditorScene = scenes[scene];
    ui->SpriteEditor->setScene(scenes[scene]);
}

/*
 * Set Left Slots method
 * Returns: Void
 * Parameters: None
 * This method fills the left sidebar boxes with scenes.
*/
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

/*
 * On SaveFile Clicked Method
 * Returns: Void
 * Parameters: Void
 * This method saves all of the scenes created
 * and all the colors and attributes of the tiles
*/
void MainWindow::on_SaveFileButton_clicked()
{
    QList<QGraphicsItem*> TileGraphicItem;

    for(int j = 0; j<scenes.size(); j++){
        QGraphicsScene *scene = scenes[j];
        TileGraphicItem = scene->items();

        for(int i = 0; i < TileGraphicItem.count(); i++){
            Tile *t = (Tile*)TileGraphicItem.at(i);
            tileColors.push_back(t->tcolor);
        }
    }

     QString filename = QFileDialog::getSaveFileName();
     QFile file(filename);
     QTextStream stream(&file);


     if(file.open(QIODevice::ReadWrite)){
         stream<< tilesTall << " " << tilesWide <<endl;
         stream<< tilesTall * tilesWide <<endl;




         int columnCounter= 0;
         for(int j = 0; j< tileColors.size(); j++){
             columnCounter++;
             QColor color = tileColors.at(j);
             stream<< color.red() <<" " << color.green() << " " << color.blue()<< " " +color.alpha();
             if(columnCounter == tilesWide){
                 stream << endl;
                 columnCounter =  0;
             }
         }
    }

}

// Testing Functions
void MainWindow::boolFuncTest()
{
    std::cout << "Running boolFuncTest" << std::endl;
    bool startState = false;
    bool finishState = boolSwap(startState);

    std::cout << "Expected value: 1" << std::endl;
    std::cout << "Actual value: " << finishState << std::endl;
}

/*
 * New Scene Test
 * Returns: Void
 * Parameters: Void
 * This method tests to see if a new scene is created
*/
void MainWindow:: newSceneCountTest()
{
    std::cout << "Running newSceneCountTest" << std::endl;

    std::cout << "Testing Initial Starting Amount of Scenes" << std::endl;
    std::cout << "Expected value: 1" << std::endl;
    std::cout << "Actual value: " << scenes.size() << std::endl;

    std::cout << "Testing Add Frame" << std::endl;
    newScene();
    std::cout << "Expected value: 2" << std::endl;
    std::cout << "Actual value: " << scenes.size() << std::endl;
}

/*
 * Next Scene Test
 * Returns: Void
 * Parameters: Void
 * This method tests to see if a next scene is selected
 * and displayed in the main window area
*/
void MainWindow:: nextSceneButtonTest()
{
    std::cout << "Running nextSceneButtonTest" << std::endl;

    for (int i = 0; i < 5; i++)
        newScene();

    on_nextButton_clicked();

    std::cout << "Testing first scene to be displayed after Next button is clicked" << std::endl;
    std::cout << "Expected value: 2" << std::endl;
    std::cout << "Actual value: " << firstSceneDisplayed << std::endl;
}

/*
 * Prev Scene Test
 * Returns: Void
 * Parameters: Void
 * This method tests to see if a prev scene is selected
 * and displayed in the main window area
*/
void MainWindow:: prevSceneButtonTest()
{
    std::cout << "Running prevSceneButtonTest" << std::endl;

    for (int i = 0; i < 5; i++)
        newScene();

    on_nextButton_clicked();
    on_prevButton_clicked();

    std::cout << "Testing first scene to be displayed after prev button is clicked" << std::endl;
    std::cout << "Expected value: 1" << std::endl;
    std::cout << "Actual value: " << firstSceneDisplayed << std::endl;
}

/*
 * Scene Item Count Test
 * Returns: Void
 * Parameters: Void
 * This method tests to see how many scenes are in the program
*/
void MainWindow:: sceneItemCount()
{
    std::cout << "Running sceneItemCount on 16x16 scene" << std::endl;

    QList<QGraphicsItem*>itemList = spriteEditorScene->items();

    std::cout << "Expected value: 256" << std::endl;
    std::cout << "Actual value: " << itemList.size() << std::endl;

}
