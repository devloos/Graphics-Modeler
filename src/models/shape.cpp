#include "shape.h"

Shape::Shape(QQuickItem* parent) : QQuickPaintedItem(parent) {}

Shape::~Shape() noexcept {}

Shape::Shape(int id, const QString &name, const QPen &pen_) {
  this->id_ = id;
  this->name_ = name;
  this->pen_ = pen_;
}
bool Shape::operator<(const Shape &rhs) const {
  return this->id_ < rhs.id_;
}

bool Shape::operator==(const Shape &rhs) const {
  return this->id_ == rhs.id_;
}

// Setters
void Shape::setPenStyle(Qt::PenStyle style) {
  this->pen_.setStyle(style);
}

void Shape::setPenCap(Qt::PenCapStyle cap) {
  this->pen_.setCapStyle(cap);
}

void Shape::setPenColor(QColor color) {
  this->pen_.setColor(color);
}

void Shape::setPenJoin(Qt::PenJoinStyle joinStyle) {
  this->pen_.setJoinStyle(joinStyle);
}

void Shape::setPenWidth(int width) {
  this->pen_.setWidth(width);
}

void Shape::setShapeName(const QString &name) {
  this->name_ = name;
}

void Shape::setShapeId(int id) {
  this->id_ = id;
}

// Getters
QPoint &Shape::getPointAt(int x) {
  return this->points_[x];
}

GM::Vector<QPoint> &Shape::getPoints() {
  return this->points_;
}

int Shape::getShapeId() const {
  return this->id_;
}

QString Shape::getShapeName() const {
  return this->name_;
}

void Shape::pushPoint(QPoint newPoint) {
  this->points_.push_back(newPoint);
}

void Shape::popPoint() {
  this->points_.pop_back();
}

void Shape::setPenBrush(const QBrush &brush) {
  this->pen_.setBrush(brush);
}

QBrush Shape::getPenBrush() const {
  return this->pen_.brush();
}

QPen &Shape::getPen() {
  return pen_;
}