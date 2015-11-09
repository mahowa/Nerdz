

#include "tile.h"
#include <Qt>
#include <QtWidgets>

Tile::Tile(const QColor &color, int x, int y, int width)
{
    this->x = x;
    this->y = y;
    this->color = color;
    this->squareSide = width;
    //setZValue((x + y) % 2);

    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
    setAcceptDrops(true);
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
    //QGraphicsItem::mousePressEvent(event);
    color = Qt::black;
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



