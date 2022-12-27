#include "mysquare.h"

MySquare::MySquare()
{
    pressed = false;
}

QRectF MySquare::boundingRect() const {
    return QRectF(-500,-500,500,500);
}

void MySquare::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::gray);
    pen.setWidth(2);
    QPen pointPen(Qt::blue);
    pointPen.setWidth(5);

    QPointF *intersectPoint = new QPointF;
    line.setPoints(start,end);


    for(int a = 0; a < lines.size() ; a++){
        QLineF line1 = lines.back();
        QLineF line2 = lines[a];

        if(line1.intersects(line2, intersectPoint) == 1){
        intersectionPoints.push_back(intersectPoint->toPoint());
        }

        // y1 = y2
        // mx1 + c1 = mx2 + c2
        // mx1 - mx2 = c2 - c1
        // m(x1 - x2) = c2 - c1

//            int m1 = (line1.p2().y() - line1.p1().y()) / (line1.p2().x() - line1.p1().x());
//            int m2 = (line2.p2().y() - line2.p1().y()) / (line2.p2().x() - line2.p1().x());

//            int c1 = line1.p1().y() - m1 * line1.p1().x();
//            int c2 = line2.p1().y() - m1 * line2.p1().x();

//            int X = (c2-c1)/(m1-m2);
//            int Y = m1  * X + c1;
    }



    qDebug() << "intersects" << intersectionPoints;

    for(QPointF point : intersectionPoints){
        painter->setPen(pointPen);
        painter->drawPoint(point);
    }

    for(QLineF line : lines){
        painter->setPen(pen);
        painter->drawLine(line);
    }
    bank_intersect.append(intersectionPoints);
    qDebug() << " bank_intersect " << bank_intersect;

}

void MySquare::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    pressed = false;
    bank_end.append(end);
    end = event->scenePos().toPoint();
//    qDebug() << "Pressed, end " << start;
    line.setPoints(start,end);
    lines.push_back(line);
    update();
    QGraphicsItem::mouseReleaseEvent(event);


    if(start.y() < end.y()){
        lower.append(start);
        upper.append(end);
    }
    else if(start.y() > end.y()){
        lower.append(end);
        upper.append(start);
    }
    qDebug() << "Upper " << lower;
    qDebug() << "Lower " << upper;
}

void MySquare::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    start = event->scenePos().toPoint();
//    qDebug() << "Pressed, start: " << start;
    pressed = true;

}

void MySquare::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(pressed){
        end = event->scenePos().toPoint();
//        qDebug() << "Moving, start: " << start << "  end: " << end;
        line.setPoints(start, end);
    }
    QGraphicsItem::mousePressEvent(event);
}



