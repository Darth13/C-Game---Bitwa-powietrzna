#ifndef WROG_H
#define WROG_H

#include <QGraphicsPixmapItem>
#include <QObject>

class Wrog: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Wrog(QGraphicsItem * parent=0);
public slots:
    void move();
};


#endif // WROG_H
