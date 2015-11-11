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

signals :
    void colorChanged(QColor pcolor);

public slots:
    void xAxisTransSlot();
    void yAxisTransSlot();
    void rotateTransSlot();
    void newScene();
    void updateScene();
    void on_horizontalSlider_valueChanged();


private slots:
    void on_colorChooser_clicked();

private:
    Ui::MainWindow *ui;
    void populateScene();

    std::vector<QGraphicsScene*> scenes;
    QTimer* sceneTimer;
    int sceneIndex;

    QGraphicsScene *spriteEditorScene;

    bool isTransformed;
    bool isRotated;
    QColor mColor;


};

#endif // MAINWINDOW_H
