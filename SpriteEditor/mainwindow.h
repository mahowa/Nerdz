#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>

#include <QColor>

#include <QLabel>
#include <QWidget>
#include <vector>
#include <QTimer>



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
    void colorChanged(QColor pcolor);

public slots:
    void xAxisTransSlot();
    void yAxisTransSlot();
    void rotateTransSlot();
    void newScene();
    void updateScene();
    void on_horizontalSlider_valueChanged();
    void submitDimensions();


private slots:
    void on_colorChooser_clicked();
    void on_SaveFileButton_clicked();
    void on_toolButton_2_clicked();
    void on_nextButton_clicked();
    void on_prevButton_clicked();
    void on_clickedScene(int scene);
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
    bool eraseOn;

};

#endif // MAINWINDOW_H
