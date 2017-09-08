#ifndef PRZYCISK_H
#define PRZYCISK_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>

class Przycisk:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    // konstruktor
    Przycisk(QString name, QGraphicsItem* parent=NULL);

    // eventy
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);
signals:
    void clicked();
private:
    QGraphicsTextItem* text;
};
#endif // PRZYCISK_H
