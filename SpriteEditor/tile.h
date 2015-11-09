#ifndef TILE
#define TILE

#include <QColor>
#include <QGraphicsItem>

class Tile : public QGraphicsItem
{
public:
    Tile(const QColor &color, int x, int y, int width);

    QRectF boundingRect() const Q_DECL_OVERRIDE;
    //QPainterPath shape() const Q_DECL_OVERRIDE;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) Q_DECL_OVERRIDE;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
    void dragEnterEvent(QGraphicsSceneDragDropEvent * event)Q_DECL_OVERRIDE;
    void hoverEnterEvent(QGraphicsSceneHoverEvent * event)Q_DECL_OVERRIDE;
    void hoverLeaveEvent(QGraphicsSceneHoverEvent * event)Q_DECL_OVERRIDE;
    //virtual void leaveEvent(QEvent * event);
    //bool sceneEvent ( QEvent * event )Q_DECL_OVERRIDE;


private:
    int x;
    int y;
    int squareSide;
    QColor color;
    QVector<QPointF> stuff;
};





#endif // TILE

