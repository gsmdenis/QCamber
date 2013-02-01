#include "octagonsymbol.h"

#include <QtGui>
#include <QRegExp>

OctagonSymbol::OctagonSymbol(QString def):
    Symbol("oct", "oct([0-9.]+)x([0-9.]+)x([0-9.]+)"), m_def(def)
{
  QRegExp rx(m_pattern);
  rx.exactMatch(def);
  QStringList caps = rx.capturedTexts();
  m_w = caps[1].toDouble();
  m_h = caps[2].toDouble();
  m_r = caps[3].toDouble();
}

QRectF OctagonSymbol::boundingRect() const
{
  return QRectF(-m_w / 2, -m_h / 2, m_w, m_h);
}

void OctagonSymbol::paint(QPainter* painter,
    const QStyleOptionGraphicsItem*, QWidget*)
{
  painter->setPen(QPen(Qt::red, 0));
  painter->setBrush(Qt::red);
  QPainterPath path;
  addOctagon(path, QRectF(-m_w / 2, -m_h / 2, m_w, m_h), m_r);
  painter->drawPath(path);
}

void OctagonSymbol::addOctagon(QPainterPath& path, const QRectF& rect,
    qreal c)
{
  QRectF r = rect.normalized();

  if (r.isNull())
    return;

  qreal x = r.x();
  qreal y = r.y();
  qreal w = r.width();
  qreal h = r.height();

  path.moveTo(x, y+h-c);
  path.lineTo(x, y+c);
  path.lineTo(x+c, y);
  path.lineTo(x+w-c, y);
  path.lineTo(x+w, y+c);
  path.lineTo(x+w, y+h-c);
  path.lineTo(x+w-c, y+h);
  path.lineTo(x+c, y+h);
  path.closeSubpath();
}
