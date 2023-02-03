#ifndef MAPPINGVIEW_H
#define MAPPINGVIEW_H

#include <QGraphicsView>
#include <QObject>
#include <QWidget>
#include <QGraphicsScene>
#include <QPainter>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QMenu>
#include <QThreadPool>


#include "MappingData.h"
#include "DieGraphicsItem.h"
#include "WaferGraphicsItem.h"
#include "WaferPixmapItem.h"
#include "WaferGridItem.h"

//线程池中的线程使用的堆栈字节数
#define BUTIANYUN_STACK_SIZE_BYTES   (1024 * 1024 * 64)
//线程池中最大的线程数量
#define BUTIANYUN_THREADPOOL_MAX_THREAD_COUNT 16


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
	void DisplayMapping(MappingDataStruct& mapping_data, bool regen = true);
private:
	void ParamInit();
	void FitShow();
signals:

	void sign_lineItemReady(
		QVector<std::shared_ptr< DieGraphicsItem>>* tmp_col,
		int col);
	void sign_waferDieChanged();

private slots:
	void onMenuAction(int);

private:
	QThreadPool* threadPool = nullptr;
	QTransform m_transform;
	QPointF m_centerPos;
	QGraphicsScene* m_scene;
	QPainter* m_painter;
	QPen draw_pen;
	QBrush draw_brush;
	WaferPixmapItem* m_wafer;
	QGraphicsLineItem* v_line;
	QGraphicsLineItem* h_line;
	qreal m_scale = 1.0;
	ViewMode view_mode;
	QPointF m_cur_pos_view;
	QPointF m_cur_pos_scene;
	QPointF m_lastMousePos;
	QMenu* m_typeMenu;
	bool m_scaleMode = false;
protected:
	//virtual void paintEvent(QPaintEvent* event) override;

	virtual void mousePressEvent(QMouseEvent* event) override;

	virtual void mouseReleaseEvent(QMouseEvent* event) override;

	virtual void mouseMoveEvent(QMouseEvent* event) override;

	virtual void wheelEvent(QWheelEvent* event) override;

	virtual void resizeEvent(QResizeEvent* event) override;

	virtual void paintEvent(QPaintEvent* event) override;

};

#endif // MAPPINGVIEW_H
