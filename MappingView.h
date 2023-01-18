#ifndef MAPPINGVIEW_H
#define MAPPINGVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include "MappingData.h"
#include "DieGraphicsItem.h"
#include "WaferGraphicsItem.h"


class MappingView : public QGraphicsView
{
	Q_OBJECT
public:
	enum class ViewMode
	{
		tNone,
		tTranslate,
		tRotate,
		tZoom,
		tDrawing
	};
public:
	MappingView();
	void DisplayMapping(MappingDataStruct& mapping_data);
	void DisplayMapping(WaferGraphicsItem& wafer);
private:
	void ParamInit();
	void FitShow();
private:
	QTransform m_transform;
	QPointF m_centerPos;
	QGraphicsScene* m_scene;
	QPainter* m_painter;
	QPen draw_pen;
	QBrush draw_brush;
	QGraphicsLineItem* v_line;
	QGraphicsLineItem* h_line;
	WaferGraphicsItem* edge_circle = nullptr;
	qreal m_scale = 1.0;
	ViewMode view_mode;
	QPointF m_cur_pos_view;
	QPointF m_cur_pos_scene;
	QPointF m_lastMousePos;

protected:
	virtual void paintEvent(QPaintEvent* event) override;

	virtual void mousePressEvent(QMouseEvent* event) override;

	virtual void mouseReleaseEvent(QMouseEvent* event) override;

	virtual void mouseMoveEvent(QMouseEvent* event) override;

	virtual void wheelEvent(QWheelEvent* event) override;

	virtual void resizeEvent(QResizeEvent* event) override;

};

#endif // MAPPINGVIEW_H
