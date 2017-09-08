#ifndef ZDROWIE_H
#define ZDROWIE_H
#include <QGraphicsTextItem>
#include <QGraphicsScene>

class Zdrowie: public QGraphicsTextItem{

public:
    Zdrowie(QGraphicsItem * parent=0);
    void zmniejsz();
    int getZdrowie();
    void zmniejszb();
    int getZdrowieb();
    int zdrowie;
    int zdrowiebossa;

};
#endif // ZDROWIE_H
