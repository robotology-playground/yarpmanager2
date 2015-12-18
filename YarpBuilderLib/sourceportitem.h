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
    friend class Arrow;
public:
    SourcePortItem(QString itemName, bool isInApp = false, QList<QGraphicsItem *> *itemsList = NULL,
                   bool editOnStart = false, Application *app = NULL,BuilderItem * parent = 0);
    ~SourcePortItem();
    QRectF boundingRect() const;
    QPointF connectionPoint();
    int type() const ;
    void setAvailable(bool);

    void editingFinished();

private:
    Application *app;
    BuilderItem *parent;
    bool portAvailable;
    bool isInApp;
    QGraphicsProxyWidget *lineEditWidget;
    QList<QGraphicsItem *> *itemsList;

protected:
    void paint(QPainter * painter, const QStyleOptionGraphicsItem * option, QWidget * widget = 0);
    void mouseDoubleClickEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
    QVariant itemChange(GraphicsItemChange change, const QVariant &value);

};

#endif // SOURCEPORTITEM_H
