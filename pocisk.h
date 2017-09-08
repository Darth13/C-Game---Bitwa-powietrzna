#ifndef POCISK_H
#define POCISK_H

#include <QGraphicsPixmapItem>
#include <QGraphicsItem>
#include <QObject>


class Pocisk: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Pocisk(QGraphicsItem * parent=0);
public slots:
    void move();

};

#endif // POCISK_H
