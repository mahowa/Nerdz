#include "tile.h"
#include <Qt>
#include <QtWidgets>
#include "mainwindow.h"

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



void Tile::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();

    QPen pen(tcolor);
    painter->setBrush(tcolor);
    painter->setPen(Qt::black);
    painter->drawRect(rect);

}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    tcolor = main->color;
    update();

}

void Tile::mouseClickReleaseEvent(QGraphicsSceneMouseEvent *event) {

    QGraphicsItem::mouseReleaseEvent(event);
    tcolor = main->color;
    update();
}

void Tile::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    QGraphicsItem::mouseMoveEvent(event);

    //Start A drag event
    QDrag *drag = new QDrag(event->widget());
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);
    drag->exec();
    mousePressEvent(event);
}
void Tile::dragEnterEvent(QGraphicsSceneDragDropEvent * event){
    QGraphicsItem::dragEnterEvent(event);

      tcolor = main->color;
      update();
}

void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent * event){

    int curAlph = tcolor.alpha();
    curAlph -= 75;
    tcolor.setAlpha(curAlph);
    update();

}
void Tile::hoverLeaveEvent(QGraphicsSceneHoverEvent * event){

    int curAlph = tcolor.alpha();
    curAlph += 75;
    tcolor.setAlpha(curAlph);
    update();

}



