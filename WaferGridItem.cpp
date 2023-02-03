#include "WaferGridItem.h"
#include <QPainter>
#include <QStyleOptionGraphicsItem>
#include <QDebug>
#include <chrono>
#include <QPixmap>

using std::chrono::steady_clock;

double WaferGridItem::die_width = 1.5;
double WaferGridItem::die_height = 1.5;
double WaferGridItem::die_street = 0.1;
double WaferGridItem::die_xstep = 3.1;
double WaferGridItem::die_ystep = 3.1;

WaferGridItem::WaferGridItem(QGraphicsObject* parent) :
	QGraphicsItemGroup(parent)
	, m_drawActive(true)
{
	m_boundingRect = QRectF(0, 0,
		GRID_DIE_COUNTS * die_width,
		GRID_DIE_COUNTS * die_height);
	//m_cachePix = new QPixmap(
	//	GRID_DIE_COUNTS * die_width,
	//	GRID_DIE_COUNTS * die_height);
	//m_cachePix->fill(Qt::blue);

	m_cacheImg = new QImage(
		GRID_DIE_COUNTS * die_width,
		GRID_DIE_COUNTS * die_height, QImage::Format_BGR888);
	m_cacheImg->fill(Qt::blue);

	this->setAcceptHoverEvents(true);
	this->setCacheMode(QGraphicsItem::CacheMode::ItemCoordinateCache);

	m_painter = new QPainter();

	checkPixmapUpdate();

}

void WaferGridItem::WaferGridInit()
{

}

void WaferGridItem::checkPixmapUpdate()
{
	if (!m_drawActive)
	{
		return;
	}
	//m_painter->begin(m_cachePix);
	//m_painter->begin(m_cachePix);
	m_painter->begin(m_cacheImg);
	m_painter->setBrush(Qt::blue);
	m_painter->drawRect(m_boundingRect);

	m_painter->setPen(Qt::cyan);
	m_painter->setBrush(Qt::darkCyan);

	double start_x = 0;
	double start_y = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			m_painter->drawRect(start_x, start_y,
				WaferGridItem::die_width,
				WaferGridItem::die_height);
			start_x += WaferGridItem::die_width;
		}
		start_y += WaferGridItem::die_height;
		start_x = 0;
	}
	m_painter->end();

}

void WaferGridItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /* = nullptr */)
{
	steady_clock::time_point start_point = steady_clock::now();


	m_boundingRect = QRectF(0, 0,
		GRID_DIE_COUNTS * die_width,
		GRID_DIE_COUNTS * die_height);


	checkPixmapUpdate();
	//painter->drawPixmap(m_cachePix->rect(), *m_cachePix);
	//painter->drawPixmap(m_cachePix->rect(), *m_cachePix);
	painter->drawImage(m_cacheImg->rect(), *m_cacheImg);
	if (option->state & QStyle::State_MouseOver)
	{
		painter->setPen(Qt::red);
	}
	else
	{
		painter->setPen(Qt::black);
	}
	painter->setBrush(Qt::NoBrush);
	painter->drawRect(m_boundingRect);
	steady_clock::duration total_time = steady_clock::now() - start_point;
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(total_time);

	qDebug() << "draw time " << int_ms.count() << " ms";
}

QRectF WaferGridItem::boundingRect() const
{
	return m_boundingRect;
}

void WaferGridItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	QGraphicsItemGroup::hoverEnterEvent(event);
	//m_drawActive = true;
}

void WaferGridItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	QGraphicsItemGroup::hoverLeaveEvent(event);
	m_drawActive = false;
}
