#include "donutsymbol.h"

#include <QtGui>
#include <QRegExp>

DonutSymbol::DonutSymbol(QString def):
    Symbol("donut_r", "donut_r([0-9.]+)x([0-9.]+)"), m_def(def)
{
  QRegExp rx(m_pattern);
  rx.exactMatch(def);
  QStringList caps = rx.capturedTexts();
  m_od = caps[1].toDouble();
  m_id = caps[2].toDouble();
}

QRectF DonutSymbol::boundingRect() const
{
  return QRectF(-m_od / 2, -m_od / 2, m_od, m_od);
}

void DonutSymbol::paint(QPainter* painter,
    const QStyleOptionGraphicsItem*, QWidget*)
{
  qreal rad = (m_od + m_id) / 4;
  qreal pen_width = (m_od - m_id) / 2;
  painter->setPen(QPen(Qt::red, pen_width));
  painter->drawEllipse(-rad, -rad, rad * 2, rad * 2);
}
