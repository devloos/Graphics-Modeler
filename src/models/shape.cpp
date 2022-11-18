#include "models/shape.h"

shape::shape() {
  shapeId = -1;
  shapeName = "NO_VALUE";
}

shape::shape(
    int id, QString name, GM::Vector<QPoint> point, QColor color, int width,
    Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join) {
  shape::shapeId = id;
  shape::shapeName = name;
  shape::points = point;
  shape::shapePen.setColor(color);
  shape::shapePen.setWidth(width);
  shape::shapePen.setStyle(style);
  shape::shapePen.setCapStyle(cap);
  shape::shapePen.setJoinStyle(join);
}

void shape::setPenWidth(int width) {
  shape::shapePen.setWidth(width);
}

void shape::setPenStyle(Qt::PenStyle style) {
  shape::shapePen.setStyle(style);
}

void shape::setPenCap(Qt::PenCapStyle cap) {
  shape::shapePen.setCapStyle(cap);
}

void shape::setPenColor(QColor color) {
  shape::shapePen.setColor(color);
}

void shape::setPenJoin(Qt::PenJoinStyle joinStyle) {
  shape::shapePen.setJoinStyle(joinStyle);
}

void shape::setPenWidth(int width) {
  shape::shapePen.setWidth(width);
}

void shape::pointPush_Back(QPoint newPoint) {
  shape::points.push_back(newPoint);
}

void shape::pointPop_Back() {
  shape::points.pop_back();
}

void shape::setShapeName(QString name) {
  shape::shapeName = name;
}

void shape::setShapeId(int id) {
  shape::shapeId = id;
}

QPoint &shape::getPointAt(int x) {
  return shape::points[x];
}

GM::Vector<QPoint> &shape::getPoints() {
  return shape::points;
}

int shape::getShapeId() {
  return shape::shapeId;
}

QString shape::getShapeName() {
  return shape::shapeName;
}