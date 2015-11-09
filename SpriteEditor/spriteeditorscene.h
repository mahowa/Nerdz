#ifndef SPRITEEDITORSCENE_H
#define SPRITEEDITORSCENE_H
#include <QGraphicsScene>
#include <QObject>

class SpriteEditorScene : public QGraphicsScene
{
    Q_OBJECT
public:
    SpriteEditorScene();

protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) Q_DECL_OVERRIDE;
signals:

public slots:
};

#endif // SPRITEEDITORSCENE_H
