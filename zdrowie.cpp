#include "zdrowie.h"
#include "przycisk.h"
#include "gra.h"
#include <QFont>

extern Gra *gra;
Zdrowie::Zdrowie(QGraphicsItem *parent):QGraphicsTextItem(parent)
{

    zdrowie=3;
    zdrowiebossa=21;
    //wypisz
    setPlainText(QString("Zdrowie: ")+QString::number(zdrowie));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));

}

void Zdrowie::zmniejsz()
{
    if(zdrowie>0){
    zdrowie--;
    //wypisz
    setPlainText(QString("Zdrowie: ")+QString::number(zdrowie));
    QString wiadomosc;
    if(zdrowie==0){
        wiadomosc="Przegrales!";
        gra->displayGameOverWindow(wiadomosc);
        }
}}

int Zdrowie::getZdrowie()
{
    return zdrowie;
}

void Zdrowie::zmniejszb()
{
    if(zdrowiebossa>0){
    zdrowiebossa--;
    //wypisz
    QString wiadomosc;
    if(zdrowiebossa==0){
        wiadomosc="Wygrales!";
        gra->displayGameOverWindow(wiadomosc);
    }
    }}

int Zdrowie::getZdrowieb()
{
    return zdrowiebossa;
}



