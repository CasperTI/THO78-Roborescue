#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include "Logic.h"

int main(int argc, char *argv[])
{
    Logic *logic = new Logic();
    delete logic;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
