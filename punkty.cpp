#include "punkty.h"
#include <QFont>
#include <gra.h>
#include <boss.h>
extern Gra *gra;

Punkty::Punkty(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //inicjuj punkty do 0
    punkty=0;
    //wypisz
    setPlainText(QString("Wynik: ")+QString::number(punkty));
    setDefaultTextColor(Qt::green);
    setFont(QFont("cosmic",16));

}

void Punkty::zwieksz()
{
    punkty++;
    //wypisz
    setPlainText(QString("Wynik: ")+QString::number(punkty));
    if(punkty==15){//spawnuje bossa
        gra->zdrowie->zmniejszb();
    Boss * boss=new Boss();
    scene()->addItem(boss);
    }
    if(punkty>=15){
     setPlainText(QString("Wynik: ")+QString::number(punkty) +(QString("   Boss: ")+QString::number(gra->zdrowie->zdrowiebossa-1)));
    }
}

int Punkty::wynik()
{
    return punkty;
}



