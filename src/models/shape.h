#pragma once

#include <QtCore/QPoint>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <string>

#include "gm/vector.h"

class Shape {
 public:
  Shape();
  Shape(int id, const QString &name, const QPen &pen);
  virtual ~Shape() noexcept;

 public:
  void setPenStyle(Qt::PenStyle style);
  void setPenCap(Qt::PenCapStyle cap);
  void setPenColor(QColor color);
  void setPenJoin(Qt::PenJoinStyle joinStyle);
  void setPenWidth(int width);
  void setPenBrush(const QBrush &brush);
  void setShapeName(const QString &name);
  void setShapeId(int id);

 public:
  QPoint &getPointAt(int x);
  GM::Vector<QPoint> &getPoints();
  int getShapeId() const;
  QString getShapeName() const;
  QBrush getPenBrush() const;

 public:
  void pushPoint(QPoint newPoint);
  void popPoint();

 private:
  int id_ = 0;
  QString name_;
  QPen pen_;
  GM::Vector<QPoint> points_;
};
