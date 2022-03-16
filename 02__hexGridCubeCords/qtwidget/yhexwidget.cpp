#include "yhexwidget.h"
#include "yhexnode.h"

YHexWidget::YHexWidget(QWidget *parent)
    : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setItemIndexMethod(QGraphicsScene::NoIndex);
    scene->setSceneRect(-200,-200,400,400);
    setScene(scene);
    setMinimumSize(400,400);

    setWindowTitle("hex test");
    YHexNode *node0 = new YHexNode(this, Qt::gray);
    YHexNode *node1 = new YHexNode(this, Qt::green);
    YHexNode *node2 = new YHexNode(this, Qt::darkGreen);
    YHexNode *node3 = new YHexNode(this, Qt::blue);
    YHexNode *node4 = new YHexNode(this, Qt::darkBlue);
    YHexNode *node5 = new YHexNode(this, Qt::red);
    YHexNode *node6 = new YHexNode(this, Qt::darkRed);

    scene->addItem(node0);
    scene->addItem(node1);
    scene->addItem(node2);
    scene->addItem(node3);
    scene->addItem(node4);
    scene->addItem(node5);
    scene->addItem(node6);

    node0->setPos(20,32.3);
    node1->setPos(40,0);
    node2->setPos(0,64.6);
    node3->setPos(40,64.6);

    node4->setPos(-20,32.3);
    node5->setPos(0,0);
    node6->setPos(60,32.3);
}
