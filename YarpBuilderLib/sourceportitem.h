#ifndef SOURCEPORTITEM_H
#define SOURCEPORTITEM_H


#include <QObject>
#include <QPainter>
#include <QGraphicsPolygonItem>

#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>

#include "commons.h"
#include "arrow.h"
#include "itemsignalhandler.h"
#include "builderitem.h"

class ItemSignalHandler;
class Arrow;

class SourcePortItem : public BuilderItem
{
public:
    SourcePortItem(QString itemName,bool isInApp = false, BuilderItem * parent = 0);
    ~SourcePortItem();
    QRectF boundingRect() const;
    QPointF connectionPoint();
    int type() const ;
    void setAvailable(bool);

    void editingFinished();

private:
    bool portAvailable;
    bool isInApp;
    QGraphicsProxyWidget *lineEditWidget;

protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

};

#endif // SOURCEPORTITEM_H
