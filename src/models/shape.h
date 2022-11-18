#pragma once

#include <QtCore/QPoint>
#include <QtGui/QPainter>
#include <QtGui/QPen>
#include <string>

#include "gm/vector.h"

class shape {
 public:
  shape() {
    shapeId = -1;
    shapeName = "NO_VALUE";
  }

  shape(
      int id, QString name, GM::Vector<QPoint> point, QColor color, int width,
      Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join) {
    shapeId = id;
    shapeName = name;
    points = point;
    shapePen.setColor(color);
    shapePen.setWidth(width);
    shapePen.setStyle(style);
    shapePen.setCapStyle(cap);
    shapePen.setJoinStyle(join);
  }

  void setPenWidth(int width) {
    shapePen.setWidth(width);
  }

  void setPenStyle(Qt::PenStyle style) {
    shapePen.setStyle(style);
  }

  void setPenCap(Qt::PenCapStyle cap) {
    shapePen.setCapStyle(cap);
  }

  void setPenColor(QColor color) {
    shapePen.setColor(color);
  }

  void setPenJoin(Qt::PenJoinStyle joinStyle) {
    shapePen.setJoinStyle(joinStyle);
  }

  void setPenWidth(int width) {
    shapePen.setWidth(width);
  }

  void pointPush_Back(QPoint newPoint) {
    points.push_back(newPoint);
  }

  void pointPop_Back() {
    points.pop_back();
  }

  void setShapeName(QString name) {
    shapeName = name;
  }

  void setShapeId(int id) {
    shapeId = id;
  }

  QPoint &getPointAt(int x) {
    return points[x];
  }

  GM::Vector<QPoint> &getPoints() {
    return points;
  }

  int getShapeId() {
    return shapeId;
  }

  QString getShapeName() {
    return shapeName;
  }

  virtual ~shape();

 private:
  GM::Vector<QPoint> points;
  int shapeId;
  QString shapeName;
  QPen shapePen;
};
