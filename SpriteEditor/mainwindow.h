#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QColor>


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


private:
    Ui::MainWindow *ui;
    void populateScene();

    QGraphicsScene *spriteEditorScene;
    bool isTransformed;
    bool isRotated;

};

#endif // MAINWINDOW_H
