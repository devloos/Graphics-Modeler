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
    pointVect = point;
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
    pointVect.push_back(newPoint);
  }

  void pointPop_Back() {
    pointVect.pop_back();
  }

  void setName(QString name) {
    shapeName = name;
  }

  void setshapeId(int id) {
    shapeId = id;
  }

  QPoint &getPointAt(int x) {
    return pointVect[x];
  }

  GM::Vector<QPoint> &getPoints() {
    return pointVect;
  }

  int getShapeId() {
    return shapeId;
  }

  QString getShapeName() {
    return shapeName;
  }

  virtual ~shape();

 private:
  GM::Vector<QPoint> pointVect;
  int shapeId;
  QString shapeName;
  QPen shapePen;
};
