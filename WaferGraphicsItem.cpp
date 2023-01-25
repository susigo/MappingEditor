#include "WaferGraphicsItem.h"
#include <fstream>
#include <QFile>

WaferGraphicsItem::WaferGraphicsItem(WaferType wType, WaferSizeEnum _wafer_size, QPoint pos /*= QPoint(0, 0)*/)
{
	m_wafer_type = wType;
	wafer_size_index = _wafer_size;
	m_brush.setColor(Qt::darkGray);
	m_brush.setStyle(Qt::SolidPattern);
	mapping_data.wafer_size = wSizeList[_wafer_size];
	wafer_rect = QRectF(-0.5 * mapping_data.wafer_size,
		-0.5 * mapping_data.wafer_size,
		mapping_data.wafer_size,
		mapping_data.wafer_size);
	setHandlesChildEvents(false);
	m_pen.setWidth(1);
	m_pen.setColor(Qt::darkBlue);
}

void WaferGraphicsItem::DrawLineWithArrow(QPainter& painter, QPen pen, QPoint start, QPoint end)
{
	painter.setRenderHint(QPainter::Antialiasing, true);

	qreal arrowSize = 2;
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

int WaferGraphicsItem::isDieInside(DieGraphicsItem* die)
{
	qreal max_dist = 0;
	if (die->x() > this->x() && die->y() >= this->y())
	{
		max_dist = getPointDist(this->pos(), die->getDiePoints(2));
	}
	else if (die->x() >= this->x() && die->y() < this->y())
	{
		max_dist = getPointDist(this->pos(), die->getDiePoints(3));
	}
	else if (die->x() <= this->x() && die->y() >= this->y())
	{
		max_dist = getPointDist(this->pos(), die->getDiePoints(1));
	}
	else if (die->x() <= this->x() && die->y() < this->y())
	{
		max_dist = getPointDist(this->pos(), die->getDiePoints(0));
	}
	if (max_dist < wafer_real_radium)
	{
		return 1;
	}
	else if (max_dist >= wafer_real_radium
		&& max_dist <= 0.5 * mapping_data.wafer_size
		)
	{
		return 0;
	}
	else if (max_dist > 0.5 * mapping_data.wafer_size) {
		return -1;
	}
}

void WaferGraphicsItem::GennerateMapping(MappingDataStruct& _mapping_data)
{
	mapping_data = _mapping_data;
	wafer_size_index = (WaferSizeEnum)_mapping_data.wafer_size;
	mapping_data.wafer_size = wSizeList[wafer_size_index];
	wafer_rect = QRectF(-0.5 * mapping_data.wafer_size,
		-0.5 * mapping_data.wafer_size,
		mapping_data.wafer_size,
		mapping_data.wafer_size);
	this->setPos(mapping_data.center_x, mapping_data.center_y);
	//this->setRotation(mapping_data.wafer_angle);
	DieGraphicsItem::die_width = mapping_data.device_width;
	DieGraphicsItem::die_height = mapping_data.device_height;

	qreal x_step = 0;
	qreal y_step = 0;
	QPointF start_point;

	//根据起始点的方位确定步长的符号
	switch (mapping_data.pos_ori_loc)
	{
	case 0:
		x_step = mapping_data.x_step;
		y_step = -mapping_data.y_step;
		break;
	case 1:
		x_step = mapping_data.x_step;
		y_step = mapping_data.y_step;
		break;
	case 2:
		x_step = -mapping_data.x_step;
		y_step = mapping_data.y_step;
		break;
	case 3:
		x_step = -mapping_data.x_step;
		y_step = -mapping_data.y_step;
		break;
	default:
		break;
	}
	start_point.setX(mapping_data.ref_x - x_step * mapping_data.ref_col);
	start_point.setY(mapping_data.ref_y - y_step * mapping_data.ref_row);
	std::shared_ptr<DieGraphicsItem> tmp_die;
	if (size_changed)
	{
		m_mapping.clear();
		for (int i = 0; i < mapping_data.rows; i++)
		{
			m_mapping.append(QList<std::shared_ptr< DieGraphicsItem>>());

			for (int j = 0; j < mapping_data.cols; j++)
			{
				tmp_die = std::make_shared<DieGraphicsItem>(this);
				m_mapping[i].append(tmp_die);
			}
		}
	}
	int die_inside = -1;
	for (int i = 0; i < mapping_data.rows; i++)
	{
		for (int j = 0; j < mapping_data.cols; j++)
		{
			tmp_die = m_mapping[i][j];
			tmp_die->setPos(start_point + QPointF(j * x_step, i * y_step));
			tmp_die->updateDie();
			tmp_die->setVisible(true);
			die_inside = isDieInside(&(*tmp_die));
			if (die_inside == -1)
			{
				tmp_die->setDieType(DieGraphicsItem::DieType::dNull);
				tmp_die->setVisible(false);
			}
			else if (die_inside == 0)
			{
				tmp_die->setDieType(DieGraphicsItem::DieType::dNull);
			}
			else if (die_inside == 1)
			{
				tmp_die->setDieType(DieGraphicsItem::DieType::dCheckable);
			}
			if (i == mapping_data.ref_row && j == mapping_data.ref_col)
			{
				tmp_die->setDieFuncType(DieGraphicsItem::DieFuncType::dRef);
			}
			else
			{
				tmp_die->setDieFuncType(DieGraphicsItem::DieFuncType::dNormal);
			}
		}
	}
	size_changed = false;
}

void WaferGraphicsItem::saveAsDigi(QString file_path)
{
	//.digi
	std::ofstream stream;
	stream.open(file_path.toStdString());
	for (int i = 0; i < m_mapping.count(); i++)
	{
		QString tmp_line;
		for (int j = 0; j < m_mapping[i].count(); j++)
		{
			switch (m_mapping[i][j]->getDieType())
			{
			case DieGraphicsItem::dNull:
				tmp_line.append('_');
				break;
			case DieGraphicsItem::dCheckable:
				tmp_line.append('1');
				break;
			case DieGraphicsItem::dOk:
				tmp_line.append('1');
				break;
			case DieGraphicsItem::dNG:
				tmp_line.append('0');
				break;
			case DieGraphicsItem::dSkip:
				tmp_line.append('1');
				break;
			}
			switch (m_mapping[i][j]->getDieFuncType())
			{
			case DieGraphicsItem::dRef:
				tmp_line.append('R');
				break;
			default:
				break;
			}
		}
		tmp_line += '\n';
		stream << tmp_line.toStdString();
	}
	stream.close();
}

MappingDataStruct WaferGraphicsItem::readFromDigi(QString file_path)
{
	MappingDataStruct tmp_mappingdata;
	QList<QList<std::shared_ptr< DieGraphicsItem>>> tmp_mapping;
	//digit 格式只有行列信息，没有尺寸与位置信息。
	QFile tmp_file(file_path);
	QByteArray tmp_line;
	int mapping_rows = 0;
	std::shared_ptr<DieGraphicsItem> tmp_die;
	while (tmp_file.canReadLine())
	{
		tmp_mapping.append(QList< std::shared_ptr< DieGraphicsItem>>());
		tmp_line = tmp_file.readLine();
		int mapping_cols = tmp_line.count() - 1;

		for (auto elem : tmp_line)
		{
			if (elem == '\n')
			{
				break;
			}
			tmp_die = std::make_shared<DieGraphicsItem>();
			switch (elem)
			{
			case '_':
				tmp_mapping[mapping_rows].push_back(tmp_die);
				break;
			case '1':
				break;
			case '0':
				break;
			case 'R':
				break;
			default:
				break;
			}
		}

		mapping_rows++;
	}

	return tmp_mappingdata;
}

void WaferGraphicsItem::setWafer(WaferType wType, WaferSizeEnum _wafer_size, QPoint pos /*= QPoint(0, 0)*/)
{
	wafer_size_index = _wafer_size;
	m_wafer_type = wType;
	mapping_data.wafer_size = wSizeList[_wafer_size];
	wafer_real_radium = 0.5 * mapping_data.wafer_size - 2;
	this->setPos(pos);
	this->update();
}

void WaferGraphicsItem::setWaferType(WaferType wType)
{
	m_wafer_type = wType;
	this->update();
}

void WaferGraphicsItem::setWaferSize(WaferSizeEnum _wafer_size)
{
	wafer_size_index = _wafer_size;
	mapping_data.wafer_size = wSizeList[_wafer_size];
	wafer_real_radium = 0.5 * mapping_data.wafer_size - 2;
	this->update();
}

double WaferGraphicsItem::getWafersize(WaferSizeEnum _wafer_size)
{
	return wSizeList[wafer_size_index];
}

void WaferGraphicsItem::setRealWaferSize(qreal _real_size)
{
	if (_real_size == 0)
	{
		return;
	}
	wafer_real_radium = _real_size * 0.5;
}

void WaferGraphicsItem::setWaferPos(QPoint pos)
{
	this->setPos(pos);
	this->update();
}

void WaferGraphicsItem::sizeChanged()
{
	size_changed = true;
}

qreal WaferGraphicsItem::width()
{
	return mapping_data.wafer_size;
}

qreal WaferGraphicsItem::height()
{
	return mapping_data.wafer_size;
}

qreal WaferGraphicsItem::getPointDist(QPointF point1, QPointF point2)
{
	QPointF diff = point2 - point1;
	return std::sqrtf(std::powf(diff.x(), 2) + std::powf(diff.y(), 2));
}

void WaferGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget /* = nullptr */)
{
	painter->setPen(Qt::NoPen);
	m_brush.setColor(Qt::darkGray);
	painter->setBrush(m_brush);
	painter->setRenderHint(QPainter::Antialiasing);
	m_pen.setWidthF(0.1);

	painter->rotate(mapping_data.flat_notch_angle);
	//平口
	if (mapping_data.flat_notch == 0)
	{
		painter->drawChord(QRectF(-0.5 * mapping_data.wafer_size,
			-0.5 * mapping_data.wafer_size,
			mapping_data.wafer_size,
			mapping_data.wafer_size),
			(-90 + 0.5 * wAnlge[wafer_size_index]) * 16,
			(360 - wAnlge[wafer_size_index]) * 16);

		painter->setPen(m_pen);
		painter->setBrush(Qt::NoBrush);
		painter->drawArc(QRectF(-wafer_real_radium,
			-wafer_real_radium,
			2 * wafer_real_radium,
			2 * wafer_real_radium),
			(-90 + 0.5 * wAnlge[wafer_size_index]) * 16,
			(360 - wAnlge[wafer_size_index]) * 16);
	}
	if (wAnlge[wafer_size_index] < 0 || mapping_data.flat_notch == 1)
	{
		painter->drawEllipse(m_center, 0.5 * mapping_data.wafer_size, 0.5 * mapping_data.wafer_size);
		//缺口，开口角度90，槽深1.0mm
		m_brush.setColor(Qt::gray);
		painter->setBrush(m_brush);
		painter->translate(0, 0.5 * mapping_data.wafer_size);
		painter->rotate(45);
		painter->drawRect(QRectF(
			-0.5 * notchDeeoth,
			-0.5 * notchDeeoth,
			notchDeeoth,
			notchDeeoth));
		painter->restore();

		painter->setPen(m_pen);
		painter->setBrush(Qt::NoBrush);
		painter->drawEllipse(m_center, wafer_real_radium, wafer_real_radium);
	}
	//painter->restore();
	int gap = 1;
	int lenght = 5;
	QPointF pt0 = wafer_rect.bottomLeft();
	QPointF ptl = wafer_rect.topLeft();
	QPointF pt2 = wafer_rect.topRight();
	QPointF pt3 = wafer_rect.bottomRight();

	switch (mapping_data.pos_ori_loc)
	{
	case 0:
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.bottomLeft().toPoint() + QPoint(gap, -gap),
			wafer_rect.bottomLeft().toPoint() + QPoint((gap + lenght), -gap));
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.bottomLeft().toPoint() + QPoint(gap, -gap),
			wafer_rect.bottomLeft().toPoint() + QPoint(gap, -(gap + lenght)));
		break;
	case 1:
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.topLeft().toPoint() + QPoint(gap, gap),
			wafer_rect.topLeft().toPoint() + QPoint((gap + lenght), gap));
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.topLeft().toPoint() + QPoint(gap, gap),
			wafer_rect.topLeft().toPoint() + QPoint(gap, (gap + lenght)));
		break;
	case 2:
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.topRight().toPoint() + QPoint(-gap, gap),
			wafer_rect.topRight().toPoint() + QPoint(-(gap + lenght), gap));
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.topRight().toPoint() + QPoint(-gap, gap),
			wafer_rect.topRight().toPoint() + QPoint(-gap, (gap + lenght)));
		break;
	case 3:
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.bottomRight().toPoint() + QPoint(-gap, -gap),
			wafer_rect.bottomRight().toPoint() + QPoint(-(gap + lenght), -gap));
		DrawLineWithArrow(*painter, m_pen,
			wafer_rect.bottomRight().toPoint() + QPoint(-gap, -gap),
			wafer_rect.bottomRight().toPoint() + QPoint(-gap, -(gap + lenght)));
		break;
	default:
		break;
	}
}

QRectF WaferGraphicsItem::boundingRect() const
{
	return wafer_rect;
}
