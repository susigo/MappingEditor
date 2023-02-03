#include "MappingView.h"
#include "DieGraphicsItem.h"
#include <QMouseEvent>
#include <QtOpenGL>
#include "WaferPixmapItem.h"

qreal DieGraphicsItem::die_width;
qreal DieGraphicsItem::die_height;
MappingStyle DieGraphicsItem::die_style;

MappingView::MappingView()
{
#ifndef QT_NO_OPENGL
	//this->setViewport(new QGLWidget(QGLFormat(QGL::SampleBuffers)));
#endif

	ParamInit();
	this->setViewportUpdateMode(ViewportUpdateMode::MinimalViewportUpdate);
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setDragMode(QGraphicsView::RubberBandDrag);
	this->setMouseTracking(true);
}

void MappingView::DisplayMapping(
	MappingDataStruct& _mapping_data
	, bool regen)
{

}

void MappingView::ParamInit()
{

	m_scene = new QGraphicsScene;
	m_scene->setBackgroundBrush(Qt::gray);
	m_scene->setSceneRect(-100000, -100000, 200000, 200000);
	this->setScene(m_scene);
	m_painter = new QPainter;
	draw_pen.setColor(Qt::white);
	draw_pen.setWidth(2);
	m_painter->setBrush(Qt::NoBrush);
	m_painter->setPen(draw_pen);

	WaferPixmapItem::WaferPixmapInit();

	v_line = new QGraphicsLineItem;
	h_line = new QGraphicsLineItem;
	m_wafer = new WaferPixmapItem();
	v_line->setLine(0, -1000, 0, 1000);
	h_line->setLine(-1000, 0, 1000, 0);
	m_scene->addItem(v_line);
	m_scene->addItem(h_line);
	//m_scene->addItem(m_wafer);

	v_line->setVisible(true);
	h_line->setVisible(true);

	double start_x = 0;
	double start_y = 0;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			WaferGridItem* grid_1 = new WaferGridItem();
			m_scene->addItem(grid_1);
			grid_1->setPos(start_x, start_y);
			start_x += (GRID_DIE_COUNTS * WaferGridItem::die_width);
		}
		start_y += (GRID_DIE_COUNTS * WaferGridItem::die_height);
		start_x = 0;
	}

	m_typeMenu = new QMenu();
	QAction* tmp_action = new QAction("Null");
	m_typeMenu->addAction(tmp_action);
	connect(tmp_action, &QAction::triggered, this, [=]() {
		onMenuAction(0);
		});
	tmp_action = new QAction("Skip");
	m_typeMenu->addAction(tmp_action);
	connect(tmp_action, &QAction::triggered, this, [=]() {
		onMenuAction(1);
		});
	tmp_action = new QAction("Pass");
	m_typeMenu->addAction(tmp_action);
	connect(tmp_action, &QAction::triggered, this, [=]() {
		onMenuAction(2);
		});
	tmp_action = new QAction("NG");
	m_typeMenu->addAction(tmp_action);
	connect(tmp_action, &QAction::triggered, this, [=]() {
		onMenuAction(3);
		});
	tmp_action = new QAction("Checkable");
	m_typeMenu->addAction(tmp_action);
	connect(tmp_action, &QAction::triggered, this, [=]() {
		onMenuAction(4);
		});
}

void MappingView::FitShow()
{

}

void MappingView::onMenuAction(int _type)
{

}

//void MappingView::paintEvent(QPaintEvent* event)
//{
//	QGraphicsView::paintEvent(event);
	//return;
	//Q_UNUSED(event);
	//m_painter->begin(this->viewport());
	//画坐标,白色，黑色
	//DrawLineWithArrow(*m_painter, draw_pen, QPoint(20, 20), QPoint(50, 20));
	//DrawLineWithArrow(*m_painter, draw_pen, QPoint(20, 20), QPoint(20, 50));
	//画wafer id
	//画行列
	//m_painter->end();
//}

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
	if (m_scene->selectedItems().count() > 0)
	{
		if (m_typeMenu)
		{
			m_typeMenu->exec(mapToGlobal(event->pos()));
		}
	}
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
	m_scaleMode = true;
	//QGraphicsView::wheelEvent(event);
	setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
	qreal scaleFactor = 1.0;
	if (event->angleDelta().y() > 0)
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
	//FitShow();
}

void MappingView::paintEvent(QPaintEvent* event)
{
	QGraphicsView::paintEvent(event);
	m_scaleMode = false;
}
