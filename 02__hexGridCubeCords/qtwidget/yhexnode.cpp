#include "yhexnode.h"
#include "yhexview.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOption>

YHexNode::YHexNode(YHexWidget *hexView, QColor clr){
    setFlag(ItemSendsGeometryChanges);
    setZValue(-1);
    _path = new QPainterPath;
    _path->moveTo(0,22.3);
    _path->lineTo(20,10);
    _path->lineTo(20,-10);
    _path->lineTo(0,-22.3);
    _path->lineTo(-20,-10);
    _path->lineTo(-20,10);
    _path->lineTo(0,22.3);
    _clr = clr;
}

void
YHexNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setPen(Qt::NoPen);
    painter->setBrush(_clr);
    painter->drawPath(*_path);
}


QRectF
YHexNode::boundingRect() const {
    return QRectF(-2,-2, 2,2);
}

QPainterPath
YHexNode::shape() const {
    return *_path;
}
