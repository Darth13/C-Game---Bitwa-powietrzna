#include "gra.h"
#include <QTimer>
#include <QFont>
#include "wrog.h"
#include <QMediaPlayer>
#include <QImage>
#include <QFont>
#include <QGraphicsTextItem>
#include <zdrowie.h>
#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
extern Gra *gra;

Gra::Gra(QWidget *parent){
    // tworzy scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // 800x600
    setBackgroundBrush(QBrush(QImage(":/tekstury/bg.jpg")));
    //wizualizuje scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

   // muzyka w tle
    QMediaPlayer *muzyka=new QMediaPlayer();
    muzyka->setMedia(QUrl("qrc:/dzwiek/background.mp3"));
    muzyka->play();


    show();
}

void Gra::displayMainMenu()
{
    QGraphicsTextItem* tytul = new QGraphicsTextItem(QString("Bitwa Powietrzna"));
       QFont titleFont("comic sans",50);
        tytul->setFont(titleFont);
        int txPos = this->width()/2 - tytul->boundingRect().width()/2;
        int tyPos = 150;
        tytul->setPos(txPos,tyPos);
        scene->addItem(tytul);

         //tworzy przycisk graj
        Przycisk* graj = new Przycisk(QString("Graj"));
        int bxPos = this->width()/2 - graj->boundingRect().width()/2;
        int byPos = 275;
        graj->setPos(bxPos,byPos);
        connect(graj,SIGNAL(clicked()),this,SLOT(graj2()));
        scene->addItem(graj);

         //tworzy przycisk wyjdz
        Przycisk* wyjdz1 = new Przycisk(QString("Wyjdz"));
        int qxPos = this->width()/2 - wyjdz1->boundingRect().width()/2;
        int qyPos = 350;
        wyjdz1->setPos(qxPos,qyPos);
        connect(wyjdz1,SIGNAL(clicked()),this,SLOT(close()));
        scene->addItem(wyjdz1);
}

void Gra::gameOver()
{
    QString wiadomosc;
    if(zdrowie->zdrowie==0){
        wiadomosc="Przegrales!";
        displayGameOverWindow(wiadomosc);
    }

}

void Gra::displayGameOverWindow(QString text)
{

    for(size_t i=0,n=scene->items().size();i<n; i++){
        scene->items()[i]->setEnabled(false);
    }
     // wyswietl okno
    stworzPanel(0,0,800,600,Qt::black,0.65);
    stworzPanel(200,150,400,350,Qt::lightGray,0.75);
    //przegrana/wygrana
    Przycisk * przegrana=new Przycisk(QString(text));
    przegrana->setPos(300,200);
    scene->addItem(przegrana);

    //gra ponowna
    Przycisk * grajponownie=new Przycisk(QString("Graj Ponownie"));
    grajponownie->setPos(300,300);
    scene->addItem(grajponownie);
    connect(grajponownie,SIGNAL(clicked()),this,SLOT(restartuj()));
    //wyjdz
     Przycisk * wyjdz=new Przycisk(QString("Wyjdz"));
     wyjdz->setPos(300,400);
     scene->addItem(wyjdz);
     connect(wyjdz,SIGNAL(clicked()),this,SLOT(close()));


}

void Gra::restartuj()
{
    scene->clear();
    // tworzy scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // 800x600
    setBackgroundBrush(QBrush(QImage(":/tekstury/bg.jpg")));
    // wizualizuje scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // tworzy gracza
    gracz = new Gracz();
   // ustawia pozycje gracza
    gracz->setPos(400,500);
    gracz->setFlag(QGraphicsItem::ItemIsFocusable);
    gracz->setFocus();
    // dodaje gracza d osceny
    scene->addItem(gracz);

    // tworzenie wyniku i zdrowia
    punkty = new Punkty();
    scene->addItem(punkty);
    zdrowie = new Zdrowie();
    zdrowie->setPos(zdrowie->x(),zdrowie->y()+25);
    scene->addItem(zdrowie);

    // tworzenie wrogow
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),gracz,SLOT(spawn()));
    timer->start(2000);


    show();

}

void Gra::graj2()
{
    scene->clear();
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/tekstury/bg.jpg")));

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);


    gracz = new Gracz();

    gracz->setPos(400,500);
    gracz->setFlag(QGraphicsItem::ItemIsFocusable);
    gracz->setFocus();

    scene->addItem(gracz);


    punkty = new Punkty();
    scene->addItem(punkty);
    zdrowie = new Zdrowie();
    zdrowie->setPos(zdrowie->x(),zdrowie->y()+25);
    scene->addItem(zdrowie);


    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),gracz,SLOT(spawn()));
    timer->start(2000);



    show();

}

void Gra::stworzPanel(int x, int y, int width, int height, QColor color, double opacity)
{

        QGraphicsRectItem* panel = new QGraphicsRectItem(x,y,width,height);
        QBrush brush;
        brush.setStyle(Qt::SolidPattern);
        brush.setColor(color);
        panel->setBrush(brush);
        panel->setOpacity(opacity);
        scene->addItem(panel);
  }



