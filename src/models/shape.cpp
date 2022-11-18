#include "models/shape.h"

shape::shape() {
  shapeId = -1;
  shapeName = "NO_VALUE";
}

shape::shape(
    int id, QString name, GM::Vector<QPoint> point, QColor color, int width,
    Qt::PenStyle style, Qt::PenCapStyle cap, Qt::PenJoinStyle join) {
  this->shapeId = id;
  this->shapeName = name;
  this->points = point;
  this->shapePen.setColor(color);
  this->shapePen.setWidth(width);
  this->shapePen.setStyle(style);
  this->shapePen.setCapStyle(cap);
  this->shapePen.setJoinStyle(join);
}

void shape::setPenWidth(int width) {
  this->shapePen.setWidth(width);
}

void shape::setPenStyle(Qt::PenStyle style) {
  this->shapePen.setStyle(style);
}

void shape::setPenCap(Qt::PenCapStyle cap) {
  this->shapePen.setCapStyle(cap);
}

void shape::setPenColor(QColor color) {
  this->shapePen.setColor(color);
}

void shape::setPenJoin(Qt::PenJoinStyle joinStyle) {
  this->shapePen.setJoinStyle(joinStyle);
}

void shape::setPenWidth(int width) {
  this->shapePen.setWidth(width);
}

void shape::pointPush_Back(QPoint newPoint) {
  this->points.push_back(newPoint);
}

void shape::pointPop_Back() {
  this->points.pop_back();
}

void shape::setShapeName(QString name) {
  this->shapeName = name;
}

void shape::setShapeId(int id) {
  this->shapeId = id;
}

QPoint &shape::getPointAt(int x) {
  return this->points[x];
}

GM::Vector<QPoint> &shape::getPoints() {
  return this->points;
}

int shape::getShapeId() {
  return this->shapeId;
}

QString shape::getShapeName() {
  return this->shapeName;
}