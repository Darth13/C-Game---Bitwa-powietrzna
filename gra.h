#ifndef GRA_H
#define GRA_H

#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsTextItem>
#include <QFont>
#include <QGraphicsScene>
#include <gracz.h>
#include <punkty.h>
#include <zdrowie.h>
#include <przycisk.h>
class Gra: public QGraphicsView {
    Q_OBJECT
public:
    Gra(QWidget * parent=NULL);
    QGraphicsScene *scene;
    Gracz* gracz;
    Punkty *punkty;
    Zdrowie *zdrowie;
    void displayMainMenu();
    void gameOver();
    void displayGameOverWindow(QString text);
public slots:
    void restartuj();
    void graj2();
private:
    void stworzPanel(int x, int y, int width, int height, QColor color, double opacity);

};

#endif // GRA_H
