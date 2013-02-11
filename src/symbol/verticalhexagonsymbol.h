#ifndef __VERTICALHEXAGONSYMBOL_H__
#define __VERTICALHEXAGONSYMBOL_H__

#include "symbol.h"

class VerticalHexagonSymbol: public Symbol {
public:

  VerticalHexagonSymbol(QString def, Polarity polarity);

  virtual QPainterPath painterPath(void);

protected:

private:
  QString m_def;
  qreal m_w;
  qreal m_h;
  qreal m_r;
};

#endif /* __VERTICALHEXAGONSYMBOL_H__ */
