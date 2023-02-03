#include "WaferPixmapItem.h"
#include <QPainter>
#include <QDebug>

#define MAX_WAFER_DIAM 1000
#define MAX_WAFER_RADIUM 500

QPixmap* WaferPixmapItem::m_pixmap;
MappingStyle WaferPixmapItem::die_style;
MappingDataStruct WaferPixmapItem::mapping_data;

WaferPixmapItem::WaferPixmapItem(QGraphicsObject* parent)
	:QGraphicsObject(parent)
{
	m_painter = new QPainter();
	m_painter->setPen(Qt::NoPen);
	m_painter->setBrush(Qt::red);
	cur_pixmap = new QPixmap(MAX_WAFER_DIAM, MAX_WAFER_DIAM);
	dieUpdates = true;
}

void WaferPixmapItem::DrawWaferShape(QPainter* _painter, QPixmap* _pixmap)
{
	//画底层颜色
	_painter->begin(_pixmap);
	_painter->setPen(Qt::NoPen);
	_painter->setBrush(Qt::gray);
	_painter->drawRect(_pixmap->rect());
	_painter->setBrush(die_style.die_nullColor);
	_painter->drawEllipse(_pixmap->rect());

	//画notch 和 flat

	_painter->end();
}

void WaferPixmapItem::DrawDies(QPainter* _painter, QPixmap* _pixmap)
{
	//画die
	_painter->begin(_pixmap);
	_painter->setPen(Qt::NoPen);
	_painter->setBrush(die_style.die_checkableColor);

	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			_painter->drawRect(QRectF(0, 0, 1, 1));
			_painter->translate(1, 0);
		}
		_painter->translate(-1000, 1);
	}

	_painter->end();
	_painter->restore();

}

void WaferPixmapItem::WaferPixmapInit()
{
	//m_pixmap = new QPixmap();
	//if (!m_pixmap->load("E:/Downloads/codes/MappingEditor/MappingEditor/background.bmp", "bmp"))
	//{
	//	qDebug() << "load background image failed!";
	//}
}

QRectF WaferPixmapItem::boundingRect() const
{
	return QRectF(-MAX_WAFER_RADIUM, -MAX_WAFER_RADIUM, MAX_WAFER_DIAM, MAX_WAFER_DIAM);
}

void WaferPixmapItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /* = nullptr */)
{
	if (dieUpdates)
	{
		DrawWaferShape(painter, cur_pixmap);
		DrawDies(painter, cur_pixmap);
		dieUpdates = false;
	}

	painter->drawPixmap(QPoint(-MAX_WAFER_RADIUM, -MAX_WAFER_RADIUM), *cur_pixmap, cur_pixmap->rect());
}
