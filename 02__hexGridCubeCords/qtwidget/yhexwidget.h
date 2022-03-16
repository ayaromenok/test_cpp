#ifndef YHEXVIEW_H
#define YHEXVIEW_H

#include <QGraphicsView>

class YHexWidget : public QGraphicsView
{
    Q_OBJECT
public:
    YHexWidget(QWidget *parent = nullptr);
};

#endif // YHEXVIEW_H
