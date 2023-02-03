#ifndef WAFERGRIDITEM_H
#define WAFERGRIDITEM_H

#include <QGraphicsItemGroup>
#include <QObject>
#define GRID_DIE_COUNTS 100
#include <QImage>
#include <QPicture>

class QPixmap;

class WaferGridItem :
	public QObject,
	public QGraphicsItemGroup
{
	Q_OBJECT
public:
	WaferGridItem(QGraphicsObject* parent = nullptr);
	static void WaferGridInit();
private:
	void checkPixmapUpdate();
protected:
	virtual void paint(QPainter* painter,
		const QStyleOptionGraphicsItem* option,
		QWidget* widget /* = nullptr */) override;
	virtual QRectF boundingRect() const override;
	virtual void hoverEnterEvent(
		QGraphicsSceneHoverEvent* event) override;
	virtual void hoverLeaveEvent(
		QGraphicsSceneHoverEvent* event) override;

private:
	QPainter* m_painter;
	QRectF m_boundingRect;
	bool m_drawActive;
	//QPixmap* m_cachePix;
	//QPicture* m_cachePic;
	QImage* m_cacheImg;

public:
	static double die_width;
	static double die_height;
	static double die_street;
	static double die_xstep;
	static double die_ystep;

};

#endif // WAFERGRIDITEM_H
