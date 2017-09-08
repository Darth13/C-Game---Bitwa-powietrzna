#ifndef GRACZ_H
#define GRACZ_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <QGraphicsItem>

class Gracz: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Gracz(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer * dzwiekpocisku;
};

#endif // GRACZ_H
