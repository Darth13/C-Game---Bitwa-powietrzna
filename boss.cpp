#include "boss.h"
#include <Qtimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <gra.h>
#include <laser.h>
#include <QMediaPlayer>
#include <stdlib.h>
extern Gra *gra;
Boss::Boss(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

  //ustawia losowa pozycje
  setPos(0,0);

  setPixmap(QPixmap(":/tekstury/boss.png")); //tworzy obraz
  dzwieklasera= new QMediaPlayer();
  dzwieklasera->setMedia(QUrl("qrc:/dzwiek/laser.mp3"));

  QTimer * timer = new QTimer(); //laczy slot, co 1s porusza obiektem
  connect(timer,SIGNAL(timeout()),this,SLOT(strzal()));

  timer->start(1000);


}
void Boss::strzal(){

   //porusza przeciwnikiem w dol
    if(gra->zdrowie->zdrowie>0){
    Laser * laser = new Laser();
    laser->setPos(gra->gracz->x()+40,y()+155);
    scene()->addItem(laser);
    //odtwarzaj dzwiek pocisku
    if(dzwieklasera->state()== QMediaPlayer::PlayingState){
    dzwieklasera->setPosition(0);
    }
    else if(dzwieklasera->state()==QMediaPlayer::StoppedState){
        dzwieklasera->play();
    }
    }}


