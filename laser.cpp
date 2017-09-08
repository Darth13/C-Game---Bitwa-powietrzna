#include "laser.h"
#include <Qtimer>
#include <QGraphicsScene>
#include <typeinfo>
#include<QList>
#include <wrog.h>
#include<gra.h>

extern Gra *gra;
Laser::Laser(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

   //obrazek
    setPixmap(QPixmap(":/tekstury/laser.png"));


       QTimer * timer = new QTimer();
       connect(timer,SIGNAL(timeout()),this,SLOT(move()));

       timer->start(20);


}
void Laser::move(){
   //sprawdza czy nie koliduje z graczem
   QList<QGraphicsItem * > zderzenia= collidingItems();
   for(int i=0,n=zderzenia.size();i<n; ++i){
       if (typeid((*zderzenia[i]))==typeid(Gracz)){
           //zmniejsza zdrowie
           gra->zdrowie->zmniejsz();
           scene()->removeItem(this);
           delete this;

           return;
           }


   }//porusza laserem w dol
    setPos(x(),y()+12);
    if(pos().y()+50 >600){
        scene()->removeItem(this);
        delete this;
    }
}
