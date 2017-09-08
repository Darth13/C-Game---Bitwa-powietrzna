#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QApplication>
#include "gra.h"

Gra * gra;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    gra = new Gra();
    gra->displayMainMenu();
    gra->show();

    return a.exec();
}
