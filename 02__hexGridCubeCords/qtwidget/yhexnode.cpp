#include "yhexnode.h"
#include "yhexwidget.h"

#include <math.h>

#include <QDebug>

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QStyleOption>

YHexNode::YHexNode(YHexWidget *hexView, QColor clr, float size){
    setFlag(ItemSendsGeometryChanges);
    setZValue(-1);
    _s = size;
    _s_2 = size/2;
    _sS = _s+_s_2;
    _r=sqrt(3)*size/6;
    _R=sqrt(3)*size/3;
    _rR = (_r+_R);
    _rR2 = _rR*2;

    _path = new QPainterPath;
    _path->moveTo(0,_s);
    _path->lineTo(_rR,_s_2);
    _path->lineTo(_rR,-_s_2);
    _path->lineTo(0,-_s);
    _path->lineTo(-_rR,-_s_2);
    _path->lineTo(-_rR,_s_2);
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
    return QRectF(-_s,-_s, _s,_s);
}

QPainterPath
YHexNode::shape() const {
    return *_path;
}

void
YHexNode::setPosQrs(qint32 q, qint32 r, qint32 s){
    qInfo() << __FUNCTION__ << q << r << s;
    if ((q>0)&(r==0)){
        setPos(_rR2,0);
        qInfo() << "right";
    } else if ((q<0)&(r==0)){
        setPos(-_rR2,0);
        qInfo() << "left";
    }  else if ((q==0)&(r<0)){
        setPos(-_rR,-_sS);
        qInfo() << "left top";
    }  else if ((q>0)&(s==0)){
        setPos(_rR,-_sS);
        qInfo() << "right top";
    }  else if ((q==0)&(r>0)){
        setPos(_rR,_sS);
        qInfo() << "right bot";
    }  else if ((q<0)&(s==0)){
        setPos(-_rR,_sS);
        qInfo() << "left bot";
    }
    else {
        qInfo()<< "NoP";
    }
}

void
YHexNode::setPosQrs(QVector3D qrs){
    setPosQrs(qrs.x(),qrs.y(),qrs.z());
}
