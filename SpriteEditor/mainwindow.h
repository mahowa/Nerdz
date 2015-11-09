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
    QGraphicsScene *SpriteEditorScene;
    bool isTransformed;
    bool isRotated;
};

#endif // MAINWINDOW_H
