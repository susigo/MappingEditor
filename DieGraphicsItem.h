#ifndef DIEGRAPHICSITEM_H
#define DIEGRAPHICSITEM_H
#include <QObject>
#include <QAbstractGraphicsShapeItem>
#include <QBrush>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "MappingData.h"

class DieGraphicsItem
	:public QObject, public QAbstractGraphicsShapeItem
{
	Q_OBJECT
public:
	//die 的质量类型
	enum DieType
	{
		dNull = 0,//空的
		dSkip,//跳过
		dCheckable,//可检测的
		dChecked,//待检测的
		dOk,//检测合格的
		dNG//检测NG的
	};
	//die 的功能类型
	enum DieFuncType
	{
		dNormal = 0,//无特殊功能die
		dRef,//golden die
		dMark//mark die
	};
public:
	explicit DieGraphicsItem(QGraphicsItemGroup* parent = nullptr, QPoint pos = QPoint(0, 0));
	~DieGraphicsItem() = default;
	void updateDie();
	void setDieType(DieType _die_type);
	DieType getDieType();
	void setDieFuncType(DieFuncType _die_func_type);
	DieFuncType getDieFuncType();
	QPointF getDiePoints(int point_index);
private:
	bool hoverFlag;
	bool selectedFlag;
	bool ctrlPressed;
	QRectF die_rect;
	QColor	m_curColor;
	QPen* m_pen;
	QBrush* m_brush;
	DieType die_type;//null,checkedbale,checked,ok,ng
	DieFuncType die_func_type;//
	QPainterPath rect_shape;
public:
	static qreal die_width;
	static qreal die_height;
	static qreal street_width;
	static MappingStyle die_style;
protected:
	virtual void hoverEnterEvent(QGraphicsSceneHoverEvent* event) override;
	virtual void hoverLeaveEvent(QGraphicsSceneHoverEvent* event) override;
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /* = nullptr */) override;
	QPainterPath shape() const override;
	virtual QRectF boundingRect() const override;
	virtual void mouseMoveEvent(QGraphicsSceneMouseEvent* event) override;
	virtual void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
	virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent* event) override;
};

#endif // DIEGRAPHICSITEM_H
