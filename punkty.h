#ifndef PUNKTY_H
#define PUNKTY_H
#include <QGraphicsTextItem>


class Punkty: public QGraphicsTextItem{

public:
    Punkty(QGraphicsItem * parent=0);
    void zwieksz();
    int wynik();
private:
    int punkty;
};

#endif // PUNKTY_H
