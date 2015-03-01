#include "mainwindow.h"
#include <QApplication>
#include "mapsystem.h"

int main(int argc, char *argv[])
{
    if(argc == 1 && argv[0] == "--test")
    {
        MapSystem * mapSystem = new MapSystem;

        delete mapSystem;
        return 0;
    }
    else
    {
        MapSystem * mapSystem = new MapSystem;
        QApplication a(argc, argv);
        MainWindow w (mapSystem);
        w.show();
        delete mapSystem;

        return a.exec();
    }