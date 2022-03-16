#ifndef YHEXNODE_H
#define YHEXNODE_H

#include <QGraphicsItem>
#include <QVector3D>

class YHexWidget;
class QPainterPath;

class YHexNode : public QGraphicsItem
{
public:
    YHexNode(YHexWidget *hexView, QColor cl=Qt::gray, float size=30);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setPosQrs(qint32 q, qint32 r, qint32 s);
    void setPosQrs(QVector3D qrs);

private:
    float           _s, _s_2, _sS;
    float           _r,_R, _rR,_rR2;
    QPointF         _newPos;
    QColor          _clr;
    YHexWidget      *_graph;
    QPainterPath    *_path;
};

#endif // YHEXNODE_H
