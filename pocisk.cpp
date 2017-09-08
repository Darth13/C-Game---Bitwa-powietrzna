#include "pocisk.h"
#include <Qtimer>
#include <QGraphicsScene>
#include <typeinfo>
#include<QList>
#include <wrog.h>
#include<gra.h>
#include <boss.h>

extern Gra *gra;
Pocisk::Pocisk(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

   //obrazek
    setPixmap(QPixmap(":/tekstury/gun.png"));


       QTimer * timer = new QTimer();
       connect(timer,SIGNAL(timeout()),this,SLOT(move()));

       timer->start(50);


}
void Pocisk::move(){
   //sprawdza czy nie koliduje z przeciwnikiem
   QList<QGraphicsItem * > zderzenia= collidingItems();
   for(int i=0,n=zderzenia.size();i<n; ++i){
       if (typeid((*zderzenia[i]))==typeid(Wrog)){
           //zwieksza punkty
           gra->punkty->zwieksz();
           //usuwa zderzajace sie obiekty
           scene()->removeItem(zderzenia[i]);
           scene()->removeItem(this);
           //zwalnianie pamieci
           delete zderzenia[i];
           delete this;
           return;
       }
       if (typeid((*zderzenia[i]))==typeid(Boss)){
           //zwieksza punkty
           gra->punkty->zwieksz();
           gra->zdrowie->zmniejszb();
           //usuwa zderzajace sie obiekty

           //zwalnianie pamieci

           if(gra->zdrowie->zdrowiebossa==0){
               scene()->removeItem(zderzenia[i]);
               delete zderzenia[i];
               }
           scene()->removeItem(this);
           delete this;
           return;
       }

   }

   //porusza pociskiem do gory
    setPos(x(),y()-10);
    if(pos().y()+50 <0){
        scene()->removeItem(this);
        delete this;
    }
}
