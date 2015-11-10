

#include "tile.h"
#include <Qt>
#include <QtWidgets>
#include "mainwindow.h"

Tile::Tile(const QColor &color, int x, int y, int width, MainWindow *main)
{
    this->x = x;
    this->y = y;
    this->color = color;
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

    QPen pen(color);
    painter->setBrush(color);
    painter->setPen(Qt::black);
    painter->drawRect(rect);

}

void Tile::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    color = main->color;
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

      color = main->color;
      update();
}

void Tile::hoverEnterEvent(QGraphicsSceneHoverEvent * event){
    color = color.lighter(50);
    update();

}
void Tile::hoverLeaveEvent(QGraphicsSceneHoverEvent * event){

    color = color.darker(50);
    update();

}



