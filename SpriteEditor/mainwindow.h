#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
<<<<<<< HEAD
#include <QColor>
=======
#include <QLabel>
#include <QWidget>
#include <vector>
#include <QTimer>
>>>>>>> origin/master


namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QColor color;

public slots:
    void xAxisTransSlot();
    void yAxisTransSlot();
    void rotateTransSlot();
    void newScene();
    void updateScene();
    //void on_horizontalSlider_valueChanged();


private slots:
   // void on_horizontalSlider_valueChanged(int value);


private:
    Ui::MainWindow *ui;
    void populateScene();

    std::vector<QGraphicsScene*> scenes;
    QTimer* sceneTimer;
    int sceneIndex;

    QGraphicsScene *spriteEditorScene;
<<<<<<< HEAD
=======

>>>>>>> origin/master
    bool isTransformed;
    bool isRotated;

};

#endif // MAINWINDOW_H
