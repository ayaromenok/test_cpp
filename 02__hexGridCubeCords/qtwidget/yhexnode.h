#ifndef YHEXNODE_H
#define YHEXNODE_H

#include <QGraphicsItem>

class YHexView;
class QPainterPath;

class YHexNode : public QGraphicsItem
{
public:
    YHexNode(YHexView *hexView, QColor cl=Qt::gray);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;
    QPainterPath shape() const override;

private:
    QPointF         _newPos;
    QColor          _clr;
    YHexView        *_graph;
    QPainterPath    *_path;
};

#endif // YHEXNODE_H
