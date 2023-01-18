#include "DieGraphicsItem.h"

DieGraphicsItem::DieGraphicsItem(
	QGraphicsItemGroup* parent,
	QPoint pos /*= QPoint(0, 0)*/) :
	QAbstractGraphicsShapeItem(parent)
{
	this->setPos(pos);
	m_pen = new QPen();
	m_brush = new QBrush();
	die_type = DieType::dCheckable;
	die_func_type = DieFuncType::dNormal;

	m_brush->setColor(die_style.die_checkableColor);

	setAcceptHoverEvents(true);
	this->setFlags(QGraphicsItem::ItemIsSelectable |
		QGraphicsItem::ItemIsFocusable);
	m_brush->setStyle(Qt::SolidPattern);
	die_rect = QRectF(-10, -10, 20, 20);
	m_curColor = die_style.die_checkableColor;
	hoverFlag = false;
}

void DieGraphicsItem::hoverEnterEvent(QGraphicsSceneHoverEvent* event)
{
	Q_UNUSED(event);
	hoverFlag = true;
	this->update();

}

void DieGraphicsItem::hoverLeaveEvent(QGraphicsSceneHoverEvent* event)
{
	Q_UNUSED(event);
	hoverFlag = false;
	this->update();
}

void DieGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /* = nullptr */)
{
	painter->setRenderHint(QPainter::Antialiasing);
	die_rect.setTopLeft(QPointF(-0.5 * die_width, -0.5 * die_height));
	die_rect.setBottomRight(QPointF(0.5 * die_width, 0.5 * die_height));

	painter->setPen(Qt::NoPen);
	switch (die_type)
	{
	case DieGraphicsItem::dNull:
		m_brush->setColor(die_style.die_nullColor);
		break;
	case DieGraphicsItem::dCheckable:
		m_brush->setColor(die_style.die_checkableColor);
		break;
	case DieGraphicsItem::dChecked:
		m_brush->setColor(die_style.die_checkColor);
		break;
	case DieGraphicsItem::dOk:
		m_brush->setColor(die_style.die_okColor);
		break;
	case DieGraphicsItem::dNG:
		m_brush->setColor(die_style.die_ngColor);
		break;
	default:
		m_brush->setColor(die_style.die_checkableColor);
		break;
	}

	painter->setBrush(*m_brush);
	painter->drawRect(die_rect);
	if (die_func_type != DieFuncType::dNormal)
	{
		//这个die有特殊用途，需要画出来
		switch (die_func_type)
		{
		case DieGraphicsItem::dRef:
			m_brush->setColor(die_style.die_refColor);
			break;
		case DieGraphicsItem::dMark:
			m_brush->setColor(die_style.die_markColor);
			break;
		default:
			break;
		}
		painter->setBrush(*m_brush);
		painter->drawRect(QRectF(
			-0.5 * die_rect.width(), 
			-0.5 * die_rect.height(),
			0.5 * die_rect.width(),
			die_rect.height()));
	}
	if (hoverFlag)
	{
		m_pen->setWidth(0.1 * die_width);
		m_pen->setColor(die_style.die_hintColor);
		painter->setPen(*m_pen);
		painter->drawRect(die_rect);
	}
	else
	{
		painter->setPen(Qt::NoPen);
	}
}

void DieGraphicsItem::updateDie()
{
	die_rect.setTopLeft(QPointF(-0.5 * die_width, -0.5 * die_height));
	die_rect.setBottomRight(QPointF(0.5 * die_width, 0.5 * die_height));
}

void DieGraphicsItem::setDieType(DieType _die_type)
{
	die_type = _die_type;
}

void DieGraphicsItem::setDieFuncType(DieFuncType _die_func_type)
{
	die_func_type = _die_func_type;
}

QPointF DieGraphicsItem::getDiePoints(int point_index)
{
	switch (point_index)
	{
	case  0:
		return mapToScene(die_rect.topLeft());
		break;
	case  1:
		return mapToScene(die_rect.bottomLeft());
		break;
	case  2:
		return mapToScene(die_rect.bottomRight());
		break;
	case  3:
		return mapToScene(die_rect.topRight());
		break;
	default:
		break;
	}
}

QRectF DieGraphicsItem::boundingRect() const
{
	return die_rect;
}

void DieGraphicsItem::mouseMoveEvent(QGraphicsSceneMouseEvent* event)
{
	Q_UNUSED(event);
}

void DieGraphicsItem::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
	Q_UNUSED(event);
}

void DieGraphicsItem::mouseReleaseEvent(QGraphicsSceneMouseEvent* event)
{
	Q_UNUSED(event);
}
