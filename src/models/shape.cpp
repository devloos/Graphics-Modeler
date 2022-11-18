#include "models/shape.h"

Shape::Shape() {}
Shape::~Shape() noexcept {}

Shape::Shape(
    int id, const QString &name, GM::Vector<QPoint> point, QColor color, int width,
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

void Shape::setPenStyle(Qt::PenStyle style) {
  this->shapePen.setStyle(style);
}

void Shape::setPenCap(Qt::PenCapStyle cap) {
  this->shapePen.setCapStyle(cap);
}

void Shape::setPenColor(QColor color) {
  this->shapePen.setColor(color);
}

void Shape::setPenJoin(Qt::PenJoinStyle joinStyle) {
  this->shapePen.setJoinStyle(joinStyle);
}

void Shape::setPenWidth(int width) {
  this->shapePen.setWidth(width);
}

void Shape::pointPushBack(QPoint newPoint) {
  this->points.push_back(newPoint);
}

void Shape::pointPopBack() {
  this->points.pop_back();
}

void Shape::setShapeName(const QString &name) {
  this->shapeName = name;
}

void Shape::setShapeId(int id) {
  this->shapeId = id;
}

QPoint &Shape::getPointAt(int x) {
  return this->points[x];
}

GM::Vector<QPoint> &Shape::getPoints() {
  return this->points;
}

int Shape::getShapeId() const {
  return this->shapeId;
}

QString Shape::getShapeName() const {
  return this->shapeName;
}