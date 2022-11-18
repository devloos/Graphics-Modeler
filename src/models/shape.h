#pragma once

#include <QtCore/QPoint>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <string>

#include "gm/vector.h"

class Shape {
 public:
  Shape();

  Shape(
      int id, QString name, GM::Vector<QPoint> point, QColor color, int width,
      Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join);

  void setPenStyle(Qt::PenStyle style);

  void setPenCap(Qt::PenCapStyle cap);

  void setPenColor(QColor color);

  void setPenJoin(Qt::PenJoinStyle joinStyle);

  void setPenWidth(int width);

  void pointPushBack(QPoint newPoint);

  void pointPopBack();

  void setShapeName(QString name);

  void setShapeId(int id);

  QPoint &getPointAt(int x);

  GM::Vector<QPoint> &getPoints();

  int getShapeId() const;

  QString getShapeName() const;

  virtual ~Shape() noexcept;

 private:
  GM::Vector<QPoint> points;
  int shapeId = 0;
  QString shapeName;
  QPen shapePen;
};
