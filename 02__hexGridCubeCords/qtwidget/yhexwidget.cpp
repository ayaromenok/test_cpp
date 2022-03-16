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
    YHexNode *node1 = new YHexNode(this, Qt::darkBlue);
    YHexNode *node2 = new YHexNode(this, Qt::blue);
    YHexNode *node3 = new YHexNode(this, Qt::darkRed);
    YHexNode *node4 = new YHexNode(this, Qt::red);
    YHexNode *node5 = new YHexNode(this, Qt::green);
    YHexNode *node6 = new YHexNode(this, Qt::darkGreen);


    scene->addItem(node0);
    scene->addItem(node1);
    scene->addItem(node2);
    scene->addItem(node3);
    scene->addItem(node4);
    scene->addItem(node5);
    scene->addItem(node6);

    node0->setPosQrs(0,0,0);
    node1->setPosQrs(-1, 0, 1);
    node2->setPosQrs( 1, 0,-1);
    node3->setPosQrs( 0,-1, 1);
    node4->setPosQrs( 1,-1, 0);
    node5->setPosQrs( 0, 1, -1);
    node6->setPosQrs(-1, 1 ,0);
    //*/
}
