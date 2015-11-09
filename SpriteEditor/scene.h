#ifndef SCENE_H
#define SCENE_H
#include <QtGui>
#include <QGraphicsScene>

class QKeyEvent;
class QGraphicsSceneMouseEvent;

class Scene : public QGraphicsItem {
Q_OBJECT

public:
Scene(QObject *parent = 0);
~Scene();

signals:


protected:
void mouseMoveEvent(QGraphicsSceneMouseEvent * mouseEvent) Q_DECL_OVERRIDE;
};

#endif // SCENE_H
