#include "mainwindow.h"
#include <QApplication>

/*
 * The commented out function calls are tests for the program.
 * In order for them to run properly, you must set the fixed
 * dimensions in the populatescene() function in mainwindow.cpp
 * and uncomment the populatescene() call in the constructor of mainwindow.cpp.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
   // w.boolFuncTest();
   // w.newSceneCountTest();
   // w.nextSceneButtonTest();
  //  w.sceneItemCount();

  //  MainWindow p;
   // p.prevSceneButtonTest();
    w.show();

    return a.exec();
}
