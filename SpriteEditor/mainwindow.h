#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include <QColor>

#include <QLabel>
#include <QWidget>
#include <vector>
#include <QTimer>

/*
 * Main Window Class
 * This is the main window that displays everything
 * It is made up of a drawing area where the sprite can
 * be drawn.  Multiple buttons which have functions of rotating the
 * sprite about the y-axis, rotating the sprite about the x-axis, rotating
 * the sprite in a complete 45 degree rotations, a save file button, a new
 * file button, and a slider that determines how fast the scene is animated.
 * There is a window that displays the animation. There is also a screen that
 * shows the current color being used
 *
*/

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_PROPERTY(QColor pcolor READ pcolor  NOTIFY colorChanged)

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QColor color;

    //Class for the color that is chosen to draw with
    //Returns: The color picked to be drawn with
    QColor pcolor() const {
        return mColor;
    }

    // Testing Functions
    void boolFuncTest();
    void newSceneCountTest();
    void nextSceneButtonTest();
    void prevSceneButtonTest();
    void sceneItemCount();

signals :
    //Callback signaling that a new color has been picked
    void colorChanged(QColor pcolor);

public slots:
    //method where the sprite is translated accross the x-axis
    void xAxisTransSlot();
    //method where the sprite is translated accross the x-axis
    void yAxisTransSlot();
    //method where the sprite rotated
    void rotateTransSlot();
    //method that triggers a new file to create a new sprite
    void newScene();
    //method that updates the current sprite scene as one is drawing
    void updateScene();
    //method that updates the value of the slider being changed that
    //animates the sprites drawn
    void on_horizontalSlider_valueChanged();
    // Sets dimensions form user input
    void submitDimensions();


private slots:
    //method that triggers opening the color chooser button clicked
    void on_colorChooser_clicked();
    //method that triggers the save file button clicked
    void on_SaveFileButton_clicked();
<<<<<<< HEAD
    void on_LoadFileButton_clicked();
=======
    //method triggers a new file button click
    void on_toolButton_2_clicked();
    // method updates the slides on left side bar to show more
>>>>>>> origin/master
    void on_nextButton_clicked();
    // method updates on the left side bar to show previous frames
    void on_prevButton_clicked();
    // method sets the new scene when a different scene has been clicked
    void on_clickedScene(int scene);
    // method erases
    void on_eraseClicked();

private:
    Ui::MainWindow *ui;
    void populateScene();
    void setLeftSlots();

    std::vector<QGraphicsScene*> scenes;
    QTimer* sceneTimer;
    int sceneIndex;
    bool isLoad;
    QGraphicsScene *spriteEditorScene;
    QList<QColor> tileColors;
    bool isTransformed;
    bool isRotated;
    bool firstRun;
    QColor mColor;
    int firstSceneDisplayed;
    int tilesWide;
    int tilesTall;
<<<<<<< HEAD
    int totalScenes;
=======
    bool eraseOn;
>>>>>>> origin/master

};

#endif // MAINWINDOW_H
