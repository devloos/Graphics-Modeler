#pragma once

#include <QtCore/QPoint>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <string>

#include "gm/vector.h"

class shape {
 public:
  shape();

  shape(
      int id, QString name, GM::Vector<QPoint> point, QColor color, int width,
      Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);

  void setPenWidth(int width);

  void setPenStyle(Qt::PenStyle style);

  void setPenCap(Qt::PenCapStyle cap);

  void setPenColor(QColor color);

  void setPenJoin(Qt::PenJoinStyle joinStyle);

  void setPenWidth(int width);

  void pointPush_Back(QPoint newPoint);

  void pointPop_Back();

  void setShapeName(QString name);

  void setShapeId(int id);

  QPoint &getPointAt(int x);

  GM::Vector<QPoint> &getPoints();

  int getShapeId();

  QString getShapeName();

  virtual ~shape();

 private:
  GM::Vector<QPoint> points;
  int shapeId;
  QString shapeName;
  QPen shapePen;
};
