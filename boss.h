#ifndef BOSS_H
#define BOSS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>
#include <gra.h>

class Boss: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Boss(QGraphicsItem * parent=0);
public slots:
    void strzal();
private:
    QMediaPlayer * dzwieklasera;


};

#endif // BOSS_H
