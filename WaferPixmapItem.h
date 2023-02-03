#ifndef WAFERPIXMAPITEM_H
#define WAFERPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsObject>
#include "MappingData.h"

class QPainter;

class WaferPixmapItem : public QGraphicsObject
{
	Q_OBJECT
public:
	explicit WaferPixmapItem(QGraphicsObject* parent = nullptr);
	~WaferPixmapItem() = default;
	static void WaferPixmapInit();
private:
	void DrawWaferShape(QPainter* _painter, QPixmap* _pixmap);
	void DrawDies(QPainter* _painter, QPixmap* _pixmap);
private:
	static QPixmap* m_pixmap;
	static MappingStyle die_style;
	static MappingDataStruct mapping_data;

	QPixmap* cur_pixmap;
	QPainter* m_painter;
	bool dieUpdates = false;

protected:
	virtual QRectF boundingRect() const override;
	virtual void paint(
		QPainter* painter,
		const QStyleOptionGraphicsItem* option,
		QWidget* widget /* = nullptr */) override;
};

#endif // WAFERPIXMAPITEM_H
