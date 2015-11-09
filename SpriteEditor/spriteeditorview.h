#ifndef SPRITEEDITORVIEW_H
#define SPRITEEDITORVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>

class SpriteEditorView : public QGraphicsView
{
public:
    SpriteEditorView();
protected:
    void mouseMoveEvent( QMouseEvent* e );
signals:

public slots:
};

#endif // SPRITEEDITORVIEW_H
