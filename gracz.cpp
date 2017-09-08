#include "gracz.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "pocisk.h"
#include <wrog.h>
#include <windows.h>
#include <boss.h>

extern Gra *gra;

Gracz::Gracz(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    dzwiekpocisku= new QMediaPlayer();
    dzwiekpocisku->setMedia(QUrl("qrc:/dzwiek/gunshot.mp3"));
    setPixmap(QPixmap(":/tekstury/gracz.png"));
}

void Gracz::keyPressEvent(QKeyEvent *event){
    if (event->key() == Qt::Key_Left){
        if(pos().x()>0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right ){
        if(pos().x()+100<800)
        setPos(x()+10,y());
    }

    if (event->key() == Qt::Key_Space){
        // create a bullet
        Pocisk * pocisk = new Pocisk();
        pocisk->setPos(x()+45,y()-45);
        scene()->addItem(pocisk);
        //odtwarzaj dzwiek pocisku
        if(dzwiekpocisku->state()== QMediaPlayer::PlayingState){
        dzwiekpocisku->setPosition(0);
        }
        else if(dzwiekpocisku->state()==QMediaPlayer::StoppedState){
            dzwiekpocisku->play();
        }

    }
}

void Gracz::spawn()
{
    if(gra->zdrowie->zdrowiebossa>0&&gra->zdrowie->zdrowie>0){
        if(gra->zdrowie->zdrowiebossa==21){
    Wrog * wrog =new Wrog();
    scene()->addItem(wrog);}
}
}

