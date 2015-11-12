#include "tile.h"
#include <Qt>
#include <QtWidgets>
#include "mainwindow.h"
#include <QColor>

/*Tile Class
 * This class is used to display the
 * tiles that are drawn upon.
 * There are variables to say what color
 * the tile is supposed to be and where
 * it is at on the display.
*/

/*Tile Constructor
 * Parameters: A QColor, a x-coordinate, a y-coordinate, a width, and a Mainwindow object pointer
 * Returns: Void
 * This sets all the values of the tile class
*/
Tile::Tile(const QColor &color, int x, int y, int width, MainWindow *main)
{
    this->x = x;
    this->y = y;
    this->tcolor = color;
    this->squareSide = width;
    this->main = main;

    QGraphicsItem::setFlags(ItemIsSelectable);
    QGraphicsItem::setAcceptHoverEvents(true);
    QGraphicsItem::setAcceptDrops(true);
}



QRectF Tile::boundingRect() const
{
    return QRectF(0, 0, squareSide, squareSide);
}


/* Paint Method
 * Parameters: A painter object pointer, a QStyleOptionGraphicsItem object pointer, a QWidget object pointer
 * Returns: Void
 * This method sets the paint brush to the color picked
*/
void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    QPen pen(tcolor);
    painter->setBrush(tcolor);
    painter->setPen(Qt::black);
    painter->drawRect(rect);

}

/* MousePressEvent
 * Parameters: A QGraphicsSceneMouseEvent event
 * Retuns: Void
 * This signals when a mouse is clicked and stores the
 * gets the color to be painted with.
 *
*/
void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    tcolor = main->color;
    update();

}

/* MouseReleasedEvent
 * Parameters: A QGraphicsSceneMouseEvent event
 * Retuns: Void
 * This signals when a mouse is released and stores the
 * sets the color to be painted with.
 *
*/
void Tile::mouseClickReleaseEvent(QGraphicsSceneMouseEvent *event) {

    QGraphicsItem::mouseReleaseEvent(event);
    tcolor = main->color;
    update();
}

/* MouseMovedEvent
 * Parameters: A QGraphicsSceneMouseEvent event
 * Retuns: Void
 * This signals when a mouse is moved and records the
 * coordinates of where it is located
*/
void Tile::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mouseMoveEvent(event);

    //Start A drag event
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);
    drag->exec();
    mousePressEvent(event);
}

/* Drage Enter Event
 * Parameters: A QGraphicsSceneMouseEvent event
 * Retuns: Void
 * Sets color picked
*/
void Tile::dragEnterEvent(QGraphicsSceneDragDropEvent * event){
    QGraphicsItem::dragEnterEvent(event);

      tcolor = main->color;
      update();
}

/* Hover Enter Event
 * Parameters: A QGraphicsSceneMouseEvent event
 * Retuns: Void
 * Sets the aplha of the color
 *
*/
void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent * event){

    int curAlph = tcolor.alpha();
    curAlph -= 75;
    tcolor.setAlpha(curAlph);
    update();

}

/* Hover Leave Event
 * Parameters: A QGraphicsSceneMouseEvent event
 * Retuns: Void
 * This signals when a mouse is clicked and stores the
 * gets the color to be painted with.
 *
*/
void Tile::hoverLeaveEvent(QGraphicsSceneHoverEvent * event){

    int curAlph = tcolor.alpha();
    curAlph += 75;
    tcolor.setAlpha(curAlph);
    update();

}





