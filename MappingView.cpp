#include "MappingView.h"
#include "DieGraphicsItem.h"
#include <QMouseEvent>

qreal DieGraphicsItem::die_width;
qreal DieGraphicsItem::die_height;
MappingStyle DieGraphicsItem::die_style;

MappingView::MappingView()
{
	ParamInit();
	this->setViewportUpdateMode(ViewportUpdateMode::FullViewportUpdate);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void MappingView::DisplayMapping(MappingDataStruct& _mapping_data)
{
	edge_circle->setVisible(true);
	edge_circle->GennerateMapping(_mapping_data);
	FitShow();
}


void MappingView::DisplayMapping(WaferGraphicsItem& wafer)
{
	edge_circle = &wafer;
	//m_scene->removeItem(edge_circle);
	m_scene->addItem(edge_circle);
	FitShow();
}

void MappingView::ParamInit()
{
	m_scene = new QGraphicsScene;
	m_scene->setBackgroundBrush(Qt::gray);
	m_scene->setSceneRect(-500, -500, 1000, 1000);
	this->setScene(m_scene);
	m_painter = new QPainter;
	draw_pen.setColor(Qt::white);
	draw_pen.setWidth(2);
	m_painter->setBrush(Qt::NoBrush);
	m_painter->setPen(draw_pen);


	//v_line = new QGraphicsLineItem;
	//h_line = new QGraphicsLineItem;
	//v_line->setLine(0, -300, 0, 300);
	//h_line->setLine(-300, 0, 300, 0);
	//m_scene->addItem(v_line);
	//m_scene->addItem(h_line);

	//edge_circle = new WaferGraphicsItem(WaferGraphicsItem::Flat, WaferGraphicsItem::Wafer150MM);
	//m_scene->addItem(edge_circle);

	//v_line->setVisible(false);
	//h_line->setVisible(false);
	//edge_circle->setVisible(true);
}

void MappingView::DrawLineWithArrow(QPainter& painter, QPen pen, QPoint start, QPoint end)
{
	painter.setRenderHint(QPainter::Antialiasing, true);

	qreal arrowSize = 10;
	painter.setPen(pen);
	painter.setBrush(pen.color());

	QLineF line(end, start);

	double angle = std::atan2(-line.dy(), line.dx());
	QPointF arrowP1 = line.p1() + QPointF(sin(angle + M_PI / 3) * arrowSize,
		cos(angle + M_PI / 3) * arrowSize);
	QPointF arrowP2 = line.p1() + QPointF(sin(angle + M_PI - M_PI / 3) * arrowSize,
		cos(angle + M_PI - M_PI / 3) * arrowSize);

	QPolygonF arrowHead;
	arrowHead.clear();
	arrowHead << line.p1() << arrowP1 << arrowP2;
	painter.drawLine(line);
	painter.drawPolygon(arrowHead);
}

void MappingView::FitShow()
{
	if (edge_circle == nullptr)
	{
		return;
	}
	qreal w_ratio = 0.95 * this->width() / edge_circle->width();
	qreal h_ratio = 0.95 * this->height() / edge_circle->height();
	if (w_ratio > h_ratio)
	{
		m_scale = h_ratio;
	}
	else
	{
		m_scale = w_ratio;
	}

	m_transform.reset();

	m_transform.scale(m_scale, m_scale);
	this->setTransform(m_transform);
	//m_centerPos = QPointF(mapping_data.wafer_size * 0.5, mapping_data.wafer_size * 0.5);
	centerOn(edge_circle->pos());

}

void MappingView::paintEvent(QPaintEvent* event)
{
	QGraphicsView::paintEvent(event);
	//return;
	//Q_UNUSED(event);
	m_painter->begin(this->viewport());
	//画坐标,白色，黑色
	//DrawLineWithArrow(*m_painter, draw_pen, QPoint(20, 20), QPoint(50, 20));
	//DrawLineWithArrow(*m_painter, draw_pen, QPoint(20, 20), QPoint(20, 50));
	//画wafer id

	//画行列

	m_painter->end();
}

void MappingView::mousePressEvent(QMouseEvent* event)
{
	QGraphicsView::mousePressEvent(event);
	if (event->button() == Qt::MiddleButton)
	{
		m_lastMousePos = mapToScene(event->pos());
		view_mode = ViewMode::tTranslate;
	}
}

void MappingView::mouseReleaseEvent(QMouseEvent* event)
{
	QGraphicsView::mouseReleaseEvent(event);
	view_mode = ViewMode::tNone;
}

void MappingView::mouseMoveEvent(QMouseEvent* event)
{
	QGraphicsView::mouseMoveEvent(event);
	m_cur_pos_view = event->pos();
	m_cur_pos_scene = mapToScene(m_cur_pos_view.toPoint());
	if (view_mode == ViewMode::tTranslate)
	{
		m_centerPos.setX(m_centerPos.x() - m_cur_pos_scene.x() + m_lastMousePos.x());
		m_centerPos.setY(m_centerPos.y() - m_cur_pos_scene.y() + m_lastMousePos.y());
		centerOn(m_centerPos);
	}
}

void MappingView::wheelEvent(QWheelEvent* event)
{
	//QGraphicsView::wheelEvent(event);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	qreal scaleFactor = 1.0;
	if (event->delta() > 0)
	{
		scaleFactor = 1.2;
	}
	else
	{
		scaleFactor = 1 / 1.2;
	}

	m_scale = transform().scale(scaleFactor, scaleFactor).mapRect(QRectF(0, 0, 1, 1)).width();

	scale(scaleFactor, scaleFactor);
}

void MappingView::resizeEvent(QResizeEvent* event)
{
	QGraphicsView::resizeEvent(event);
	FitShow();
}

