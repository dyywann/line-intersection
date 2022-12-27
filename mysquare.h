#ifndef MYSQUARE_H
#define MYSQUARE_H
#include <QPainter>
#include <QGraphicsItem>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <vector>



class MySquare : public QGraphicsItem
{
public:
    MySquare();
    bool pressed;

    QRectF boundingRect() const;
    QLineF line;
    QList<QPointF> bank_end;
    QList<QPointF> lower;
    QList<QPointF> upper;
    QPointF start = QPointF(0,0);
    QPointF end = QPointF(0,0);
    std::vector< QLineF > lines;
    std::vector< QPointF > intersectionPoints;
    QList< std::vector <QPointF>> bank_intersect;

protected:
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem *option,
               QWidget *widget);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);


};



#endif // MYSQUARE_H
