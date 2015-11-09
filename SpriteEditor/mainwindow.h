#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void xAxisTransSlot();
    void yAxisTransSlot();
    void rotateTransSlot();

private:
    Ui::MainWindow *ui;
    void populateScene();
<<<<<<< HEAD
    QGraphicsScene *spriteEditorScene;

=======
    QGraphicsScene *SpriteEditorScene;
    bool isTransformed;
    bool isRotated;
>>>>>>> origin/master
};

#endif // MAINWINDOW_H
