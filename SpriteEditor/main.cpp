#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.boolFuncTest();
   // w.newSceneCountTest();
   // w.nextSceneButtonTest();
   // w.sceneItemCount();

  //  MainWindow p;
  //  p.prevSceneButtonTest();
    w.show();

    return a.exec();
}
