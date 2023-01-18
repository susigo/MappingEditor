#ifndef WAFERGRAPHICSITEM_H
#define WAFERGRAPHICSITEM_H
#include <QObject>
#include <QAbstractGraphicsShapeItem>
#include <QBrush>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include "MappingData.h"
#include "DieGraphicsItem.h"

class WaferGraphicsItem
	:public QObject, public QGraphicsItemGroup
{
public:
	enum WaferType
	{
		Notch = 0,
		Flat
	};
	enum WaferSizeEnum {
		Wafer2Inch = 0,
		Wafer3Inch,
		Wafer100MM,
		Wafer125MM,
		Wafer150MM,
		Wafer200MM,
		Wafer300MM,
		Wafer450MM
	};
public:
	WaferGraphicsItem(WaferType wType, WaferSizeEnum _wafer_size, QPoint pos = QPoint(0, 0));
	~WaferGraphicsItem() = default;
	void GennerateMapping(MappingDataStruct& mapping_data);

	int isDieInside(DieGraphicsItem* die);
	void setWafer(WaferType wType, WaferSizeEnum _wafer_size, QPoint pos = QPoint(0, 0));
	void setWaferType(WaferType wType);
	void setWaferSize(WaferSizeEnum _wafer_size);
	double getWafersize(WaferSizeEnum _wafer_size);
	void setRealWaferSize(qreal _real_size);
	void setWaferPos(QPoint pos);
	qreal width();
	qreal height();
private:
	qreal getPointDist(QPointF point1, QPointF point2);
private:
	QList<QList<std::shared_ptr< DieGraphicsItem>>> m_mapping;
	MappingDataStruct mapping_data;
	WaferSizeEnum wafer_size_index;
	WaferType m_wafer_type;
	QPointF m_center;
	QBrush m_brush;
	QPen m_pen;

	double wafer_real_radium = 75.0;
	QRectF wafer_rect;
	double wSizeList[8] = { 50.8,76.2,100,125,150,200,300,450 };
	//flat 长度
	double wFlatLenght[8] = { 15.88,22.22,32.5,42.5,57.5,-1,-1,-1 };
	double wAnlge[8] = { 36.43, 33.91, 37.93,39.75, 45.06,-1,-1,-1 };
	//notch 角度为90，深1.0
	double notchAngle = 90;
	double notchDeeoth = 2.0;
protected:
	virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /* = nullptr */) override;
	QRectF boundingRect() const override;
};
#endif // WAFERGRAPHICSITEM_H
