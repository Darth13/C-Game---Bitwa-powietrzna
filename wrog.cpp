#include "wrog.h"
#include <Qtimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <gra.h>
extern Gra *gra;
Wrog::Wrog(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

  //ustawia losowa pozycje
  int random_number=rand()%700;
  setPos(random_number,0);

  setPixmap(QPixmap(":/tekstury/wrog.png")); //tworzy obraz


  QTimer * timer = new QTimer(); //laczy slot, co 50 ms porusza obiektem
  connect(timer,SIGNAL(timeout()),this,SLOT(move()));

  timer->start(50);


}
void Wrog::move(){
   //porusza przeciwnikiem w dol
    setPos(x(),y()+5);
    if(pos().y() >600){
        //zmniejsz zdrowie
        gra->zdrowie->zmniejsz();
        scene()->removeItem(this);
        delete this;
    }
}


