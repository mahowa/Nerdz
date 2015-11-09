#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

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



//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set up the tiles
    populateScene();





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
    SpriteEditorScene = new QGraphicsScene;


    /*
     * Scene is the object that has all the properties
     * for displaying what we want
     */
    ui->SpriteEditor->setScene(SpriteEditorScene);



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
            SpriteEditorScene->addItem(item);

        }
    }
}
