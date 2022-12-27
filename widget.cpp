#include "widget.h"
#include "ui_widget.h"
#include <QLabel>
#include <QGraphicsItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle("QLabel");
    resize(500,500);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QPen blackPen (Qt::black);





    blackPen.setWidth(width);

    square1 = new MySquare();

    scene->addItem(square1);

//    ellipse = scene->addEllipse(10,10,100,100, blackPen, redBrush);
//    rectangle = scene->addRect(-120,-120,80,80,blackPen, blueBrush);

//    ellipse->setFlag(QGraphicsItem::ItemIsMovable);
//    rectangle->setFlag(QGraphicsItem::ItemIsMovable);
//    line1 = scene->addLine(50,50,100,100, blackPen);


}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{


    square1->lines.clear();
    square1->intersectionPoints.clear();
    square1->bank_intersect.clear();
    square1->update();


//    QPen newPen (Qt::green);
//    newPen.setWidth(width);
//    ui->graphicsView->rotate(-10);
//    width += 1;
//    line1->setPen(newPen);
}


void Widget::on_pushButton_2_clicked()
{
    ui->graphicsView->rotate(10);
}

